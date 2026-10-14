/* =====================================================================
   ada_lexer.l -- Лексический анализатор языка Ada (генератор: flex).
   Читает исходный текст и печатает список лексем в формате "ТИП   значение".
   ===================================================================== */

%option noyywrap
%option caseless  /* Ada нечувствителен к регистру */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

static int line_num = 1; /* Текущий номер строки для ошибок */

/* Выводит лексему в формате "ТИП   значение" */
static void print_tok(const char *type, const char *value) {
    printf("%-20s %s\n", type, value);
}

/* Буфер для накопления строкового литерала */
#define STRBUF_MAX 2048
static char strbuf[STRBUF_MAX];
static int  strbuf_len = 0;

static void strbuf_reset(void) { strbuf_len = 0; strbuf[0] = '\0'; }

static void strbuf_append(const char *text, int len) {
    for (int i = 0; i < len && strbuf_len < STRBUF_MAX - 1; i++)
        strbuf[strbuf_len++] = text[i];
    strbuf[strbuf_len] = '\0';
}

/* Убирает символы '_' из числового текста ("1_000" -> "1000") */
static void strip_underscores(const char *src, char *dst) {
    while (*src) {
        if (*src != '_') *dst++ = *src;
        src++;
    }
    *dst = '\0';
}

/* Обработка десятичного целого (42, 1_000, 3E2) */
static void handle_decimal_int(const char *text) {
    char buf[256];
    strip_underscores(text, buf);
    char *epos = strpbrk(buf, "eE");
    long v;
    if (epos) {
        *epos = '\0';
        v = strtol(buf, NULL, 10);
        v = (long)(v * pow(10.0, atoi(epos + 1)));
    } else {
        v = strtol(buf, NULL, 10);
    }
    char out[64];
    snprintf(out, sizeof(out), "%ld", v);
    print_tok("NUMBER_INT", out);
}

/* Обработка десятичного вещественного (3.14, 1_000.5E-2) */
static void handle_decimal_real(const char *text) {
    char buf[256];
    strip_underscores(text, buf);
    double v = strtod(buf, NULL);
    char out[64];
    snprintf(out, sizeof(out), "%g", v);
    print_tok("NUMBER_REAL", out);
}

/* Обработка целого в другой СС (16#FF#, 2#1010#) */
static void handle_based_int(const char *text) {
    char buf[256];
    strip_underscores(text, buf);
    int base = atoi(buf);
    char *hash1 = strchr(buf, '#');
    char *hash2 = strrchr(buf, '#');
    char digits[128];
    int len = (int)(hash2 - hash1 - 1);
    strncpy(digits, hash1 + 1, len);
    digits[len] = '\0';
    long v = strtol(digits, NULL, base);
    char *exp_ptr = hash2 + 1;
    if (*exp_ptr == 'e' || *exp_ptr == 'E')
        v = (long)(v * pow(10.0, atoi(exp_ptr + 1)));
    char out[64];
    snprintf(out, sizeof(out), "%ld", v);
    print_tok("NUMBER_BASED_INT", out);
}

/* Обработка вещественного в другой СС (16#F.8#, 2#101.01#E2) */
static void handle_based_real(const char *text) {
    char buf[256];
    strip_underscores(text, buf);
    int base = atoi(buf);

    char *hash1 = strchr(buf, '#');
    char *hash2 = strrchr(buf, '#');
    char body[128];
    int len = (int)(hash2 - hash1 - 1);
    strncpy(body, hash1 + 1, len);
    body[len] = '\0';

    char *exp_ptr = hash2 + 1;
    int exponent = 0;
    if (*exp_ptr == 'e' || *exp_ptr == 'E') exponent = atoi(exp_ptr + 1);

    char *dot = strchr(body, '.');
    double value;
    if (dot) {
        *dot = '\0';
        long ival = strtol(body, NULL, base);
        double fval = 0.0, scale = 1.0 / base;
        for (char *p = dot + 1; *p; p++) {
            int d = isdigit((unsigned char)*p) ? *p - '0'
                                                : toupper((unsigned char)*p) - 'A' + 10;
            fval += d * scale;
            scale /= base;
        }
        value = ival + fval;
    } else {
        value = (double)strtol(body, NULL, base);
    }

    if (exponent != 0) value *= pow(10.0, exponent);

    char out[64];
    snprintf(out, sizeof(out), "%g", value);
    print_tok("NUMBER_BASED_REAL", out);
}

/* Обработка символьного литерала ('A', ''') */
static void handle_char_literal(const char *text) {
    char out[32];
    char c = (strcmp(text, "'''") == 0) ? '\'' : text[1];
    snprintf(out, sizeof(out), "'%c' (code %d)", c, (int)(unsigned char)c);
    print_tok("CHAR_LITERAL", out);
}
%}

DIGIT   [0-9]
EXP     ([eE][+-]?{DIGIT}+)?
BASE    {DIGIT}{1,2}

%x STRLIT /* Стартовое состояние для тела строкового литерала */

%%

 /* Пропуск комментариев, пробелов и переводов строк */
"--".*                      { /* комментарий */ }
[ \t\r]+                    { /* пробелы */ }
\n                           { line_num++; }

 /* Числовые литералы (Flex сам выберет самое длинное совпадение) */
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"."[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP}   { handle_based_real(yytext); }
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP}                                  { handle_based_int(yytext); }
{DIGIT}(_?{DIGIT})*"."{DIGIT}(_?{DIGIT})*{EXP}                                { handle_decimal_real(yytext); }
{DIGIT}(_?{DIGIT})*{EXP}                                                      { handle_decimal_int(yytext); }

 /* Символьные литералы */
\'\'\'                       { handle_char_literal(yytext); }
\'[^'\n]\'                   { handle_char_literal(yytext); }

 /* Строковые литералы (используется состояние STRLIT) */
\"                            { strbuf_reset(); BEGIN(STRLIT); }
<STRLIT>\"\"                  { strbuf_append("\"", 1); }
<STRLIT>[^"\n]+               { strbuf_append(yytext, yyleng); }
<STRLIT>\"                    { print_tok("STRING_LITERAL", strbuf); BEGIN(INITIAL); }
<STRLIT>\n                    { fprintf(stderr, "Lexical error at line %d: newline inside string literal\n", line_num);
                                 line_num++; BEGIN(INITIAL); }
<STRLIT><<EOF>>               { fprintf(stderr, "Lexical error at line %d: unterminated string literal\n", line_num);
                                 BEGIN(INITIAL); yyterminate(); }

 /* Двухсимвольные разделители */
"=>"    { print_tok("DELIM_ARROW",       "=>"); }
".."    { print_tok("DELIM_DOTDOT",      ".."); }
"**"    { print_tok("DELIM_STARSTAR",    "**"); }
":="    { print_tok("DELIM_ASSIGN",      ":="); }
"/="    { print_tok("DELIM_NOTEQUAL",    "/="); }
">="    { print_tok("DELIM_GE",          ">="); }
"<="    { print_tok("DELIM_LE",          "<="); }
"<<"    { print_tok("DELIM_LABEL_OPEN",  "<<"); }
">>"    { print_tok("DELIM_LABEL_CLOSE", ">>"); }
"<>"    { print_tok("DELIM_BOX",         "<>"); }

 /* Односимвольные разделители и знаки операций */
"&"     { print_tok("DELIM_AMPERSAND", "&"); }
"'"     { print_tok("DELIM_TICK",      "'"); }
"("     { print_tok("DELIM_LPAREN",    "("); }
")"     { print_tok("DELIM_RPAREN",    ")"); }
"*"     { print_tok("DELIM_STAR",      "*"); }
"+"     { print_tok("DELIM_PLUS",      "+"); }
","     { print_tok("DELIM_COMMA",     ","); }
"-"     { print_tok("DELIM_MINUS",     "-"); }
"."     { print_tok("DELIM_DOT",       "."); }
"/"     { print_tok("DELIM_SLASH",     "/"); }
":"     { print_tok("DELIM_COLON",     ":"); }
";"     { print_tok("DELIM_SEMICOLON", ";"); }
"<"     { print_tok("DELIM_LESS",      "<"); }
"="     { print_tok("DELIM_EQUAL",     "="); }
">"     { print_tok("DELIM_GREATER",   ">"); }
"|"     { print_tok("DELIM_BAR",       "|"); }

 /* Зарезервированные слова (обязательно идут до правила для идентификаторов) */
"abort"         { print_tok("KEYWORD", "abort"); }
"abs"           { print_tok("KEYWORD", "abs"); }
"abstract"      { print_tok("KEYWORD", "abstract"); }
"accept"        { print_tok("KEYWORD", "accept"); }
"access"        { print_tok("KEYWORD", "access"); }
"aliased"       { print_tok("KEYWORD", "aliased"); }
"all"           { print_tok("KEYWORD", "all"); }
"and"           { print_tok("KEYWORD", "and"); }
"array"         { print_tok("KEYWORD", "array"); }
"at"            { print_tok("KEYWORD", "at"); }
"begin"         { print_tok("KEYWORD", "begin"); }
"body"          { print_tok("KEYWORD", "body"); }
"case"          { print_tok("KEYWORD", "case"); }
"constant"      { print_tok("KEYWORD", "constant"); }
"declare"       { print_tok("KEYWORD", "declare"); }
"delay"         { print_tok("KEYWORD", "delay"); }
"delta"         { print_tok("KEYWORD", "delta"); }
"digits"        { print_tok("KEYWORD", "digits"); }
"do"            { print_tok("KEYWORD", "do"); }
"else"          { print_tok("KEYWORD", "else"); }
"elsif"         { print_tok("KEYWORD", "elsif"); }
"end"           { print_tok("KEYWORD", "end"); }
"entry"         { print_tok("KEYWORD", "entry"); }
"exception"     { print_tok("KEYWORD", "exception"); }
"exit"          { print_tok("KEYWORD", "exit"); }
"for"           { print_tok("KEYWORD", "for"); }
"function"      { print_tok("KEYWORD", "function"); }
"generic"       { print_tok("KEYWORD", "generic"); }
"goto"          { print_tok("KEYWORD", "goto"); }
"if"            { print_tok("KEYWORD", "if"); }
"in"            { print_tok("KEYWORD", "in"); }
"interface"     { print_tok("KEYWORD", "interface"); }
"is"            { print_tok("KEYWORD", "is"); }
"limited"       { print_tok("KEYWORD", "limited"); }
"loop"          { print_tok("KEYWORD", "loop"); }
"mod"           { print_tok("KEYWORD", "mod"); }
"new"           { print_tok("KEYWORD", "new"); }
"not"           { print_tok("KEYWORD", "not"); }
"null"          { print_tok("KEYWORD", "null"); }
"of"            { print_tok("KEYWORD", "of"); }
"or"            { print_tok("KEYWORD", "or"); }
"others"        { print_tok("KEYWORD", "others"); }
"out"           { print_tok("KEYWORD", "out"); }
"overriding"    { print_tok("KEYWORD", "overriding"); }
"package"       { print_tok("KEYWORD", "package"); }
"parallel"      { print_tok("KEYWORD", "parallel"); }
"pragma"        { print_tok("KEYWORD", "pragma"); }
"private"       { print_tok("KEYWORD", "private"); }
"procedure"     { print_tok("KEYWORD", "procedure"); }
"protected"     { print_tok("KEYWORD", "protected"); }
"raise"         { print_tok("KEYWORD", "raise"); }
"range"         { print_tok("KEYWORD", "range"); }
"record"        { print_tok("KEYWORD", "record"); }
"rem"           { print_tok("KEYWORD", "rem"); }
"renames"       { print_tok("KEYWORD", "renames"); }
"requeue"       { print_tok("KEYWORD", "requeue"); }
"return"        { print_tok("KEYWORD", "return"); }
"reverse"       { print_tok("KEYWORD", "reverse"); }
"select"        { print_tok("KEYWORD", "select"); }
"separate"      { print_tok("KEYWORD", "separate"); }
"some"          { print_tok("KEYWORD", "some"); }
"subtype"       { print_tok("KEYWORD", "subtype"); }
"synchronized"  { print_tok("KEYWORD", "synchronized"); }
"tagged"        { print_tok("KEYWORD", "tagged"); }
"task"          { print_tok("KEYWORD", "task"); }
"terminate"     { print_tok("KEYWORD", "terminate"); }
"then"          { print_tok("KEYWORD", "then"); }
"type"          { print_tok("KEYWORD", "type"); }
"until"         { print_tok("KEYWORD", "until"); }
"use"           { print_tok("KEYWORD", "use"); }
"when"          { print_tok("KEYWORD", "when"); }
"while"         { print_tok("KEYWORD", "while"); }
"with"          { print_tok("KEYWORD", "with"); }
"xor"           { print_tok("KEYWORD", "xor"); }

 /* Идентификаторы */
[A-Za-z][A-Za-z0-9_]*   { print_tok("IDENTIFIER", yytext); }

 /* Ловушка для лексических ошибок */
.   { fprintf(stderr, "Lexical error at line %d: unexpected character '%c'\n", line_num, yytext[0]); }

%%

/* Точка входа: читает из файла (если передан аргумент) или из stdin */
int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    }
    yylex();
    if (argc > 1) fclose(yyin);
    return 0;
}