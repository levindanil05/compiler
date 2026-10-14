%option noyywrap
%option caseless

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pars.tab.h"

extern int yyparse(void);
extern FILE* yyin;

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
    print_tok("CONST_INTEGER", out);
    yylval.int_const = (int)v;
}

/* Обработка десятичного вещественного (3.14, 1_000.5E-2) */
static void handle_decimal_real(const char *text) {
    char buf[256];
    strip_underscores(text, buf);
    double v = strtod(buf, NULL);
    char out[64];
    snprintf(out, sizeof(out), "%g", v);
    print_tok("CONST_FLOAT", out);
    yylval.float_const = (float)v;
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
    print_tok("CONST_INTEGER", out);
    yylval.int_const = (int)v;
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
    print_tok("CONST_FLOAT", out);
    yylval.float_const = (float)value;
}

/* Обработка символьного литерала ('A', ''') */
static void handle_char_literal(const char *text) {
    char out[32];
    char c = (strcmp(text, "'''") == 0) ? '\'' : text[1];
    snprintf(out, sizeof(out), "'%c' (code %d)", c, (int)(unsigned char)c);
    print_tok("CONST_CHARACTER", out);
    yylval.char_const = c;
}
%}

DIGIT   [0-9]
EXP     ([eE][+-]?{DIGIT}+)?
BASE    {DIGIT}{1,2}

%x STRLIT 

%%

 /* Пропуск комментариев, пробелов и переводов строк */
"--".*                      { /* комментарий */ }
[ \t\r]+                    { /* пробелы */ }
\n                           { line_num++; }

 /* Числовые литералы (Flex сам выберет самое длинное совпадение) */
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"."[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP}   { handle_based_real(yytext); return CONST_FLOAT; }
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP}                                  { handle_based_int(yytext); return CONST_INTEGER; }
{DIGIT}(_?{DIGIT})*"."{DIGIT}(_?{DIGIT})*{EXP}                                { handle_decimal_real(yytext); return CONST_FLOAT; }
{DIGIT}(_?{DIGIT})*{EXP}                                                      { handle_decimal_int(yytext); return CONST_INTEGER; }

 /* Символьные литералы */
\'\'\'                       { handle_char_literal(yytext); return CONST_CHARACTER; }
\'[^'\n]\'                   { handle_char_literal(yytext); return CONST_CHARACTER; }

 /* Строковые литералы (используется состояние STRLIT) */
\"                            { strbuf_reset(); BEGIN(STRLIT); }
<STRLIT>\"\"                  { strbuf_append("\"", 1); }
<STRLIT>[^"\n]+               { strbuf_append(yytext, yyleng); }
<STRLIT>\"                    {
                                print_tok("CONST_STRING", strbuf);
                                yylval.string_const = new string(strbuf);
                                BEGIN(INITIAL);
                                return CONST_STRING;
                              }
<STRLIT>\n                    { fprintf(stderr, "Lexical error at line %d: newline inside string literal\n", line_num);
                                 line_num++; BEGIN(INITIAL); }
<STRLIT><<EOF>>               { fprintf(stderr, "Lexical error at line %d: unterminated string literal\n", line_num);
                                 BEGIN(INITIAL); yyterminate(); }

 /* Двухсимвольные разделители */
":="    { print_tok("ASSIGNMENT",    ":="); return ASSIGNMENT; }
".."    { print_tok("DOUBLE_DOT",    ".."); return DOUBLE_DOT; }
"/="    { print_tok("NOT_EQUAL",     "/="); return NOT_EQUAL; }
">="    { print_tok("MORE_OR_EQUAL", ">="); return MORE_OR_EQUAL; }
"<="    { print_tok("LESS_OR_EQUAL", "<="); return LESS_OR_EQUAL; }

 /* Односимвольные разделители и знаки операций */
"&"     { print_tok("&", "&"); return '&'; }
"'"     { print_tok("'",  "'"); return '\''; }
"("     { print_tok("(",  "("); return '('; }
")"     { print_tok(")",  ")"); return ')'; }
"*"     { print_tok("*",  "*"); return '*'; }
"+"     { print_tok("+",  "+"); return '+'; }
","     { print_tok(",",  ","); return ','; }
"-"     { print_tok("-",  "-"); return '-'; }
"."     { print_tok(".",  "."); return '.'; }
"/"     { print_tok("/",  "/"); return '/'; }
":"     { print_tok(":",  ":"); return ':'; }
";"     { print_tok(";",  ";"); return ';'; }
"<"     { print_tok("<",  "<"); return '<'; }
"="     { print_tok("=",  "="); return '='; }
">"     { print_tok(">",  ">"); return '>'; }
"|"     { print_tok("|",  "|"); return '|'; }

 /* Зарезервированные слова (обязательно идут до правила для идентификаторов) */
"integer"       { print_tok("INTEGER",     "integer"); return INTEGER; }
"boolean"       { print_tok("BOOLEAN",     "boolean"); return BOOLEAN; }
"float"         { print_tok("FLOAT",       "float");   return FLOAT; }
"character"     { print_tok("CHARACTER",   "character"); return CHARACTER; }
"string"        { print_tok("STRING",      "string");  return STRING; }
"while"         { print_tok("WHILE",       "while");   return WHILE; }
"for"           { print_tok("FOR",         "for");     return FOR; }
"in"            { print_tok("IN",          "in");      return IN; }
"of"            { print_tok("OF",          "of");      return OF; }
"loop"          { print_tok("LOOP",        "loop");    return LOOP; }
"if"            { print_tok("IF",          "if");      return IF; }
"then"          { print_tok("THEN",        "then");    return THEN; }
"elsif"         { print_tok("ELSIF",       "elsif");   return ELSIF; }
"else"          { print_tok("ELSE",        "else");    return ELSE; }
"array"         { print_tok("ARRAY",       "array");   return ARRAY; }
"type"          { print_tok("TYPE",        "type");    return TYPE; }
"range"         { print_tok("RANGE",       "range");   return RANGE; }
"exit"          { print_tok("EXIT",        "exit");    return EXIT; }
"when"          { print_tok("WHEN",        "when");    return WHEN; }
"function"      { print_tok("FUNCTION",    "function"); return FUNCTION; }
"procedure"     { print_tok("PROCEDURE",   "procedure"); return PROCEDURE; }
"is"            { print_tok("IS",          "is");      return IS; }
"return"        { print_tok("RETURN",      "return");  return RETURN; }
"begin"         { print_tok("BEGIN_TOKEN", "begin");   return BEGIN_TOKEN; }
"end"           { print_tok("END",         "end");     return END; }
"abs"           { print_tok("ABS",         "abs");     return ABS; }
"not"           { print_tok("NOT",         "not");     return NOT; }
"and"           { print_tok("AND",         "and");     return AND; }
"or"            { print_tok("OR",          "or");      return OR; }
"xor"           { print_tok("XOR",         "xor");     return XOR; }
"true"          { print_tok("CONST_BOOL",  "true");  yylval.int_const = 1; return CONST_BOOL; }
"false"         { print_tok("CONST_BOOL",  "false"); yylval.int_const = 0; return CONST_BOOL; }

 /* Идентификаторы */
[A-Za-z][A-Za-z0-9_]*   {
                            print_tok("ID", yytext);
                            yylval.id_const = new string(yytext);
                            return ID;
                        }

 /* Ловушка для лексических ошибок */
.   { fprintf(stderr, "Lexical error at line %d: unexpected character '%c'\n", line_num, yytext[0]); }

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", line_num, s);
}

/* Точка входа: читает из файла (если передан аргумент) или из stdin */
int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    }
    yyparse();
    if (argc > 1) fclose(yyin);
    return 0;
}