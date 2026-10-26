%option noyywrap
%option caseless

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>

#include "pars.tab.h"

#include "class_nodes.h"

extern ProgramNode* global_program;
void printTree(ProgramNode* root);

extern int yyparse(void);
extern FILE* yyin;

/* Текущий номер строки. Используется для вывода сообщений об ошибках. */
static int line_num = 1;

/* Выводит найденный токен и его значение. */
static void print_tok(const char *type, const char *value) {
    printf("%-20s %s\n", type, value);
}

/* Буфер для накопления содержимого строкового литерала. Ограничение размера предотвращает запись за пределами буфера. */
#define STRBUF_MAX 2048
static char strbuf[STRBUF_MAX];
static int strbuf_len = 0;

/* Очищает буфер перед обработкой новой строки. */
static void strbuf_reset(void) {
    strbuf_len = 0;
    strbuf[0] = '\0';
}

/* Добавляет фрагмент текста в буфер строкового литерала. */
static void strbuf_append(const char *text, int len) {
    for (int i = 0; i < len && strbuf_len < STRBUF_MAX - 1; i++) {
        strbuf[strbuf_len++] = text[i];
    }
    strbuf[strbuf_len] = '\0';
}

/* Удаляет символы подчёркивания из числа. "1_000" преобразуется в "1000". */
static void strip_underscores(const char *src, char *dst) {
    while (*src) {
        if (*src != '_') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

/* Обрабатывает десятичное целое число. Поддерживаются подчёркивания и десятичная экспонента: 42, 1_000, 3E2. */
static void handle_decimal_int(const char *text) {
    char buf[256];
    strip_underscores(text, buf);

/* Ищем показатель степени, если он указан. */
    char *epos = strpbrk(buf, "eE");
    long v;

    if (epos) {
        *epos = '\0';
        v = strtol(buf, NULL, 10);
        v = (long)(v * pow(10.0, atoi(epos + 1)));
    } else {
        v = strtol(buf, NULL, 10);
    }

/* Выводим число и передаём его парсеру через yylval. */
    char out[64];
    snprintf(out, sizeof(out), "%ld", v);
    print_tok("CONST_INTEGER", out);
    yylval.int_const = (int)v;
}

/* Обрабатывает десятичное вещественное число. */
static void handle_decimal_real(const char *text) {
    char buf[256];
    strip_underscores(text, buf);

    double v = strtod(buf, NULL);

    char out[64];
    snprintf(out, sizeof(out), "%g", v);
    print_tok("CONST_FLOAT", out);

/* Вещественное значение, передаваемое синтаксическому анализатору. */
    yylval.float_const = (float)v;
}

/* Обрабатывает целые числа в системе счисления с основанием base. */
static void handle_based_int(const char *text) {
    char buf[256];
    strip_underscores(text, buf);

/* Основание системы счисления находится перед первым символом '#'. */
    int base = atoi(buf);
    char *hash1 = strchr(buf, '#');
    char *hash2 = strrchr(buf, '#');

/* Копируем цифры между символами '#'. */
    char digits[128];
    int len = (int)(hash2 - hash1 - 1);
    strncpy(digits, hash1 + 1, len);
    digits[len] = '\0';

    long v = strtol(digits, NULL, base);

/* При наличии экспоненты умножаем число на соответствующую степень 10. */
    char *exp_ptr = hash2 + 1;
    if (*exp_ptr == 'e' || *exp_ptr == 'E') {
        v = (long)(v * pow(10.0, atoi(exp_ptr + 1)));
    }

    char out[64];
    snprintf(out, sizeof(out), "%ld", v);
    print_tok("CONST_INTEGER", out);
    yylval.int_const = (int)v;
}

/* Обрабатывает вещественные числа в системе счисления с заданным основанием. */
static void handle_based_real(const char *text) {
    char buf[256];
    strip_underscores(text, buf);

/* Получаем основание и границы числовой части. */
    int base = atoi(buf);
    char *hash1 = strchr(buf, '#');
    char *hash2 = strrchr(buf, '#');

    char body[128];
    int len = (int)(hash2 - hash1 - 1);
    strncpy(body, hash1 + 1, len);
    body[len] = '\0';

/* Считываем показатель степени, если он присутствует. */
    char *exp_ptr = hash2 + 1;
    int exponent = 0;
    if (*exp_ptr == 'e' || *exp_ptr == 'E') {
        exponent = atoi(exp_ptr + 1);
    }

/* Разделяем целую и дробную части по точке. */
    char *dot = strchr(body, '.');
    double value;

    if (dot) {
        *dot = '\0';

        long ival = strtol(body, NULL, base);
        double fval = 0.0;
        double scale = 1.0 / base;

/* Переводим каждую цифру дробной части в десятичное значение. */
        for (char *p = dot + 1; *p; p++) {
            int d = isdigit((unsigned char)*p)
                ? *p - '0'
                : toupper((unsigned char)*p) - 'A' + 10;

            fval += d * scale;
            scale /= base;
        }

        value = ival + fval;
    } else {
        value = (double)strtol(body, NULL, base);
    }

/* Применяем экспоненту. */
    if (exponent != 0) {
        value *= pow(10.0, exponent);
    }

    char out[64];
    snprintf(out, sizeof(out), "%g", value);
    print_tok("CONST_FLOAT", out);
    yylval.float_const = (float)value;
}

/* Обрабатывает символьный литерал. Например: 'A'. Последовательность из трёх апострофов интерпретируется как символ апострофа. */
static void handle_char_literal(const char *text) {
    char out[32];

    char c = (strcmp(text, "'''") == 0) ? '\'' : text[1];

    snprintf(
        out,
        sizeof(out),
        "'%c' (code %d)",
        c,
        (int)(unsigned char)c
    );

    print_tok("CONST_CHARACTER", out);
    yylval.char_const = c;
}
%}

/* Именованные части регулярных выражений: DIGIT — десятичная цифра; EXP — необязательная экспонента; BASE — основание системы счисления из одной или двух цифр. */
DIGIT   [0-9]
EXP     ([eE][+-]?{DIGIT}+)?
BASE    {DIGIT}{1,2}

%x STRLIT

%%



    /* Комментарий начинается с двух дефисов и продолжается до конца строки. */
"--".*                      { /* Комментарий пропускается. */ }

    /* Пробелы и табуляция не образуют токенов. */
[ \t\r]+                    { /* Пропускаем пробельные символы. */ }

    /* При переходе на новую строку обновляем счётчик строк. */
\n                          { line_num++; }


    /* Вещественное число в другой системе счисления. */
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"."[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP} {
    handle_based_real(yytext);
    return CONST_FLOAT;
}


    /* Целое число в другой системе счисления. */
{BASE}"#"[0-9A-Fa-f](_?[0-9A-Fa-f])*"#"{EXP} {
    handle_based_int(yytext);
    return CONST_INTEGER;
}


    /* Десятичное вещественное число, например 3.14 или 1_000.5E-2. */
{DIGIT}(_?{DIGIT})*"."{DIGIT}(_?{DIGIT})*{EXP} {
    handle_decimal_real(yytext);
    return CONST_FLOAT;
}


    /* Десятичное целое число, в том числе с экспонентой. */
{DIGIT}(_?{DIGIT})*{EXP} {
    handle_decimal_int(yytext);
    return CONST_INTEGER;
}


    /* Три апострофа обозначают сам символ апострофа. */
\'\'\'                      {
                                handle_char_literal(yytext);
                                return CONST_CHARACTER;
                            }

    /* Обычный символьный литерал: один символ между апострофами. */
\'[^'\n]\'                  {
                                handle_char_literal(yytext);
                                return CONST_CHARACTER;
                            }



    /* Открывающая кавычка: очищаем буфер и переходим в состояние STRLIT. */
\"                          {
                                strbuf_reset();
                                BEGIN(STRLIT);
                            }

    /* Две кавычки внутри строки обозначают одну кавычку в её содержимом. Например, "" внутри строки добавляет один символ ". */
<STRLIT>\"\"                {
                                strbuf_append("\"", 1);
                            }

    /* Добавляем обычные символы строки в буфер. */
<STRLIT>[^"\n]+             {
                                strbuf_append(yytext, yyleng);
                            }

    /* Закрывающая кавычка: 1. Выводим строковый токен. 2. Сохраняем значение в yylval для парсера. 3. Возвращаемся в обычное состояние лексера. */
<STRLIT>\"                  {
                                print_tok("CONST_STRING", strbuf);
                                yylval.string_const = new string(strbuf);
                                BEGIN(INITIAL);
                                return CONST_STRING;
                            }

    /* Перевод строки до закрывающей кавычки означает ошибку. */
<STRLIT>\n                  {
                                fprintf(
                                    stderr,
                                    "Lexical error at line %d: "
                                    "newline inside string literal\n",
                                    line_num
                                );
                                line_num++;
                                BEGIN(INITIAL);
                            }

    /* Конец файла до закрывающей кавычки означает незавершённую строку. */
<STRLIT><<EOF>>             {
                                fprintf(
                                    stderr,
                                    "Lexical error at line %d: "
                                    "unterminated string literal\n",
                                    line_num
                                );
                                BEGIN(INITIAL);
                                yyterminate();
                            }



    /* Присваивание. */
":="    { print_tok("ASSIGNMENT",    ":="); return ASSIGNMENT; }

    /* Обозначение диапазона. */
".."    { print_tok("DOUBLE_DOT",    ".."); return DOUBLE_DOT; }

    /* Операторы сравнения. */
"/="    { print_tok("NOT_EQUAL",     "/="); return NOT_EQUAL; }
">="    { print_tok("MORE_OR_EQUAL", ">="); return MORE_OR_EQUAL; }
"<="    { print_tok("LESS_OR_EQUAL", "<="); return LESS_OR_EQUAL; }

    /* Стрелка, используемая в синтаксисе языка. */
"=>"    { print_tok("ARROW",         "=>"); return ARROW; }


    /* Для односимвольных токенов возвращается код самого символа. */
"&"     { print_tok("&", "&"); return '&'; }
"'"     { print_tok("'", "'"); return '\''; }
"("     { print_tok("(", "("); return '('; }
")"     { print_tok(")", ")"); return ')'; }
"*"     { print_tok("*", "*"); return '*'; }
"+"     { print_tok("+", "+"); return '+'; }
","     { print_tok(",", ","); return ','; }
"-"     { print_tok("-", "-"); return '-'; }
"."     { print_tok(".", "."); return '.'; }
"/"     { print_tok("/", "/"); return '/'; }
":"     { print_tok(":", ":"); return ':'; }
";"     { print_tok(";", ";"); return ';'; }
"<"     { print_tok("<", "<"); return '<'; }
"="     { print_tok("=", "="); return '='; }
">"     { print_tok(">", ">"); return '>'; }
"|"     { print_tok("|", "|"); return '|'; }


    /* Правила ключевых слов размещаются перед правилом идентификаторов. Благодаря этому, например, слово "while" возвращает токен WHILE, а не токен ID. Опция %option caseless позволяет распознавать слова без учёта регистра. */

"integer"       { print_tok("INTEGER",    "integer");   return INTEGER; }
"boolean"       { print_tok("BOOLEAN",    "boolean");   return BOOLEAN; }
"float"         { print_tok("FLOAT",      "float");     return FLOAT; }
"character"     { print_tok("CHARACTER",  "character"); return CHARACTER; }
"string"        { print_tok("STRING",     "string");    return STRING; }

"while"         { print_tok("WHILE",      "while");     return WHILE; }
"for"           { print_tok("FOR",        "for");       return FOR; }
"in"            { print_tok("IN",         "in");        return IN; }
"of"            { print_tok("OF",         "of");        return OF; }
"loop"          { print_tok("LOOP",       "loop");      return LOOP; }

"if"            { print_tok("IF",         "if");        return IF; }
"then"          { print_tok("THEN",       "then");      return THEN; }
"elsif"         { print_tok("ELSIF",      "elsif");     return ELSIF; }
"else"          { print_tok("ELSE",       "else");      return ELSE; }

"array"         { print_tok("ARRAY",      "array");     return ARRAY; }
"type"          { print_tok("TYPE",       "type");      return TYPE; }
"range"         { print_tok("RANGE",      "range");     return RANGE; }
"exit"          { print_tok("EXIT",       "exit");      return EXIT; }
"when"          { print_tok("WHEN",       "when");      return WHEN; }

"function"      { print_tok("FUNCTION",   "function");  return FUNCTION; }
"procedure"     { print_tok("PROCEDURE",  "procedure"); return PROCEDURE; }
"is"            { print_tok("IS",         "is");        return IS; }
"return"        { print_tok("RETURN",     "return");    return RETURN; }
"begin"         { print_tok("BEGIN_TOKEN","begin");     return BEGIN_TOKEN; }
"end"           { print_tok("END",        "end");       return END; }

"abs"           { print_tok("ABS",        "abs");       return ABS; }
"not"           { print_tok("NOT",        "not");       return NOT; }
"and"           { print_tok("AND",        "and");       return AND; }
"or"            { print_tok("OR",         "or");        return OR; }
"xor"           { print_tok("XOR",        "xor");       return XOR; }

    /* Логические константы передаются как целые значения 1 и 0. */
"true"          {
                    print_tok("CONST_BOOL", "true");
                    yylval.int_const = 1;
                    return CONST_BOOL;
                }

"false"         {
                    print_tok("CONST_BOOL", "false");
                    yylval.int_const = 0;
                    return CONST_BOOL;
                }

"with"          { print_tok("WITH",       "with");      return WITH; }
"use"           { print_tok("USE",        "use");       return USE; }
"record"        { print_tok("RECORD",     "record");    return RECORD; }
"constant"      { print_tok("CONSTANT",   "constant");  return CONSTANT; }
"case"          { print_tok("CASE",       "case");      return CASE; }
"exception"     { print_tok("EXCEPTION",  "exception"); return EXCEPTION; }
"others"        { print_tok("OTHERS",     "others");    return OTHERS; }
"out"           { print_tok("OUT",        "out");       return OUT; }
"mod"           { print_tok("MOD",        "mod");       return MOD; }
"rem"           { print_tok("REM",        "rem");       return REM; }


    /* Идентификатор начинается с латинской буквы и может содержать буквы, цифры и подчёркивания. Текст идентификатора сохраняется в строке и передаётся парсеру. */
[A-Za-z][A-Za-z0-9_]* {
                                print_tok("ID", yytext);
                                yylval.id_const = new string(yytext);
                                return ID;
                            }

    /* Если ни одно правило выше не подошло, символ считается ошибочным. Сообщение содержит номер строки и неожиданный символ. */
. {
    fprintf(
        stderr,
        "Lexical error at line %d: unexpected character '%c'\n",
        line_num,
        yytext[0]
    );
}
%%

/* Функция обработки синтаксических ошибок. Bison вызывает её, когда последовательность токенов не соответствует грамматике языка. */
void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", line_num, s);
}

/* Точка входа в программу. Если имя файла передано аргументом командной строки, читаем исходный код из этого файла. В противном случае используем стандартный ввод. После чтения вызываем yyparse(), который запускает синтаксический анализ. */
int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");

        if (!yyin) {
            perror("fopen");
            return 1;
        }
    }
	
	extern int yydebug; // Объявляем внешнюю переменную
    yydebug = 1;        // Включаем дебаг Bison
	
    int result = yyparse();

    if (argc > 1) {
        fclose(yyin);
    }

    if (result == 0 && global_program != nullptr) {
        printTree(global_program);
    }

    return result;
}

