
/*
%define parse.trace
*/

%code requires {
#include <string>
#include <list>
#include "class_nodes.h"
#include "ast_extensions.h"
using namespace std;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <iterator>
#include <string>
#include <list>
#include "class_nodes.h"
#include "ast_extensions.h"

void yyerror(char const* s);
extern int yylex(void);

ProgramNode* global_program = nullptr;

/* создаёт объявление пользовательского типа. */
static DeclarationNode* make_type_declaration(
    string* name,
    TypeDefinitionNode* definition,
    RangeNode* range = nullptr,
    TypeNode* base_type = nullptr
) {
    DeclarationNode* result = DeclarationNode::TypeDeclaration(
        DeclarationNode::type_dec, name, range, base_type
    );
    result->definition = definition;
    return result;
}

/* объединяет два списка операторов. */
static StmtListNode* append_statement_lists(
    StmtListNode* first,
    StmtListNode* second
) {
    if (!first) return second;
    if (!second) return first;

    if (second->stmts) {
        for (auto* statement : *second->stmts) {
            first->stmts->push_back(statement);
        }
    }

    return first;
}
%}

/* лексические токены. */
%token INTEGER BOOLEAN FLOAT CHARACTER STRING
%token WHILE FOR IN OF LOOP IF THEN ELSIF ELSE
%token ASSIGNMENT
%token ARRAY TYPE ID
%token CONST_STRING CONST_INTEGER CONST_FLOAT CONST_CHARACTER CONST_BOOL
%token RANGE EXIT WHEN FUNCTION PROCEDURE IS RETURN
%token BEGIN_TOKEN END
%token WITH USE RECORD CONSTANT CASE EXCEPTION OTHERS OUT
%token ARROW DOUBLE_DOT
%token OR XOR AND NOT ABS MOD REM
%token NOT_EQUAL LESS_OR_EQUAL MORE_OR_EQUAL

/* дополнительные токены расширенной грамматики. */
%token POWER CONCAT NULL_TOKEN

/* приоритеты логических и арифметических операций. */
%left OR XOR
%left AND

/* операции сравнения. */
%left '=' NOT_EQUAL '<' LESS_OR_EQUAL '>' MORE_OR_EQUAL

/* сложение, вычитание и конкатенация. */
%left '+' '-'
%left CONCAT

/* умножение, деление и целочисленные операции. */
%left '*' '/' MOD REM

/* возведение в степень правоассоциативно. */
%right POWER

/* унарные операции. */
%precedence NOT
%precedence ABS
%precedence UMINUS

/* выбор компонента и доступ к атрибуту. */
%precedence '.'
%precedence APOSTROPHE

/* типы семантических значений. */
%union {
    ProgramNode* prg;
    int int_const;
    float float_const;
    string* string_const;
    string* id_const;
    char char_const;

    SubProgramItemNode* item;
    ItemListNode* itemlst;
    DeclarationListNode* decl_lst;
    DeclarationNode* decl;
    VarListNode* var_lst;
    FuncParamListNode* param_lst;
    StmtListNode* stmt_lst;
    StmtNode* stmt;
    ElseStmtNode* els_stmt;
    ElsifStmtNode* elsf_stmt;
    ElsifStmtListNode* elsf_lst_stmt;
    ExprNode* expr;
    ExprListNode* expr_list;
    RangeNode* rng;
    TypeNode* v_type;

    TypeDefinitionNode* type_definition;
    ArrayIndexNode* array_index;
    CaseChoiceNode* case_choice;
    CaseAlternativeNode* case_alternative;
    CaseAlternativeListNode* case_alternative_list;
    list<CaseChoiceNode*>* choice_list;
}

/* форматирование значений токенов при отладочной печати. */
%printer { fprintf(yyo, "%s", $$ ? $$->c_str() : "null"); } <id_const> <string_const>
%printer { fprintf(yyo, "%d", $$); } <int_const>
%printer { fprintf(yyo, "%f", $$); } <float_const>
%printer { fprintf(yyo, "%c", $$); } <char_const>

/* типы значений нетерминалов. */
%type <prg> program program_body
%type <id_const> ID
%type <string_const> CONST_STRING
%type <int_const> CONST_INTEGER CONST_BOOL
%type <float_const> CONST_FLOAT
%type <char_const> CONST_CHARACTER

%type <item> item func_declaration proc_declaration
%type <item> func_implementation proc_implementation
%type <itemlst> item_list

%type <decl_lst> declaration_list_empty decl_body_list
%type <decl> declaration type_declaration var_declaration
%type <var_lst> var_list
%type <param_lst> func_param_list

%type <stmt_lst> stmt_list stmt_list_empty exception_part
%type <stmt_lst> exception_handler_list exception_handler
%type <stmt> stmt return_stmt loop_stmt for_stmt while_stmt
%type <stmt> simple_loop_stmt exit_stmt if_stmt assigment_stmt case_stmt

%type <els_stmt> else_stmt
%type <elsf_stmt> elsif_stmt
%type <elsf_lst_stmt> elsif_stmt_list

%type <expr> expression arg
%type <expr_list> expression_list expression_list_empty
%type <rng> range
%type <v_type> var_type

%type <type_definition> array_type_definition array_index_list
%type <type_definition> enum_id_list record_field_list

%type <array_index> array_index
%type <choice_list> choice_list
%type <case_choice> case_choice
%type <case_alternative> case_alternative
%type <case_alternative_list> case_alternative_list

%start program

%%

/* корневое правило программы. */
program:
      context_list program_body
      { $$ = global_program = $2; }
    ;

/* тело программы содержит список подпрограмм. */
program_body:
      item_list
      { $$ = new ProgramNode($1); }
    ;

/* контекстные предложения with и use необязательны. */
context_list:
      %empty
    | context_list context_item
    ;

/* подключение пакета или составного имени. */
context_item:
      WITH dotted_name ';'
    | USE dotted_name ';'
    ;

/* составное имя, например Ada.Text_IO. */
dotted_name:
      ID
    | dotted_name '.' ID
    ;

/* список элементов верхнего уровня. */
item_list:
      item
      { $$ = new ItemListNode($1); }
    | item_list item
      { $$ = ItemListNode::Append($1, $2); }
    ;

item:
      func_declaration      { $$ = $1; }
    | proc_declaration      { $$ = $1; }
    | func_implementation   { $$ = $1; }
    | proc_implementation   { $$ = $1; }
    ;

/* объявление функции без тела. */
func_declaration:
      FUNCTION ID '(' func_param_list ')' RETURN var_type ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, $4, $7, NULL, NULL); }
    | FUNCTION ID RETURN var_type ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, NULL, $4, NULL, NULL); }
    ;

/* объявление процедуры без тела. */
proc_declaration:
      PROCEDURE ID '(' func_param_list ')' ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, $4, NULL, NULL, NULL); }
    | PROCEDURE ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, NULL, NULL, NULL, NULL); }
    ;

/* реализация функции с параметрами. */
func_implementation:
      FUNCTION ID '(' func_param_list ')' RETURN var_type
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, $4, $7, $9, $11); }
    | FUNCTION ID RETURN var_type
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, NULL, $4, $6, $8); }
    ;

/* реализация процедуры с параметрами. */
proc_implementation:
      PROCEDURE ID '(' func_param_list ')'
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, $4, NULL, $7, $9); }
    | PROCEDURE ID
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, NULL, NULL, $4, $6); }
    ;

/* декларативная часть может быть пустой. */
declaration_list_empty:
      %empty
      { $$ = nullptr; }
    | decl_body_list
      { $$ = $1; }
    ;

/* объявления и вложенные подпрограммы. */
decl_body_list:
      declaration ';'
      { $$ = new DeclarationListNode($1); }
    | decl_body_list declaration ';'
      { $$ = DeclarationListNode::Append($1, $2); }
    | item
      { $$ = new DeclarationListNode(DeclarationNode::SubProgramDeclaration($1)); }
    | decl_body_list item
      { $$ = DeclarationListNode::Append($1, DeclarationNode::SubProgramDeclaration($2)); }
    ;

/* объявления типов и переменных. */
declaration:
      type_declaration { $$ = $1; }
    | var_declaration  { $$ = $1; }
    ;

/* определения пользовательских типов. */
type_declaration:
      TYPE ID IS array_type_definition
      { $$ = make_type_declaration($2, $4); }
    | TYPE ID IS '(' enum_id_list ')'
      { $$ = make_type_declaration($2, $5); }
    | TYPE ID IS RANGE range
      { $$ = DeclarationNode::TypeDeclaration(DeclarationNode::type_dec, $2, $5, nullptr); }
    | TYPE ID IS RECORD record_field_list END RECORD
      { $$ = make_type_declaration($2, $5); }
    ;

/* определение массива. */
array_type_definition:
      ARRAY '(' array_index_list ')' OF var_type
      {
          $$ = $3;
          $$->element_type = $6;
      }
    ;

/* список индексов массива. */
array_index_list:
      array_index
      {
          $$ = new TypeDefinitionNode(TypeDefinitionNode::array_type);
          $$->addIndex($1);
      }
    | array_index_list ',' array_index
      {
          $$ = $1;
          $$->addIndex($3);
      }
    ;

/* индекс массива: ограниченный или неограниченный. */
array_index:
      range
      { $$ = new ArrayIndexNode($1, nullptr, false); }
    | var_type RANGE '<' '>'
      { $$ = new ArrayIndexNode(nullptr, $1, true); }
    | var_type RANGE range
      { $$ = new ArrayIndexNode($3, $1, false); }
    ;

/* литералы перечислимого типа. */
enum_id_list:
      ID
      {
          $$ = new TypeDefinitionNode(TypeDefinitionNode::enum_type);
          $$->addLiteral($1);
      }
    | enum_id_list ',' ID
      {
          $$ = $1;
          $$->addLiteral($3);
      }
    ;

/* поля записи. */
record_field_list:
      var_declaration ';'
      {
          $$ = new TypeDefinitionNode(TypeDefinitionNode::record_type);
          $$->addField($1);
      }
    | record_field_list var_declaration ';'
      {
          $$ = $1;
          $$->addField($2);
      }
    ;

/* объявления переменных, параметров и констант. */
var_declaration:
      var_list ':' var_type
      { $$ = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, $1, $3); }
    | var_list ':' IN var_type
      { $$ = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, $1, $4); }
    | var_list ':' OUT var_type
      { $$ = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, $1, $4); }
    | var_list ':' IN OUT var_type
      { $$ = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, $1, $5); }
    | var_list ':' CONSTANT var_type
      { $$ = DeclarationNode::VarDeclaration(DeclarationNode::var_dec, $1, $4); }
    | var_list ':' CONSTANT var_type ASSIGNMENT expression
      { $$ = DeclarationNode::VarDeclarationAssignment(DeclarationNode::var_dec, $1, $4, $6); }
    | var_list ':' ARRAY '(' array_index_list ')' OF var_type
      {
          DeclarationNode* declaration = DeclarationNode::VarDeclaration(
              DeclarationNode::var_dec, $1, $8
          );
          declaration->definition = $5;
          declaration->definition->element_type = $8;
          $$ = declaration;
      }
    | var_list ':' var_type ASSIGNMENT expression
      { $$ = DeclarationNode::VarDeclarationAssignment(DeclarationNode::var_dec, $1, $3, $5); }
    ;

/* список имён переменных. */
var_list:
      ID
      { $$ = new VarListNode($1); }
    | var_list ',' ID
      { $$ = VarListNode::Append($1, $3); }
    ;

/* параметры подпрограммы разделяются точкой с запятой. */
func_param_list:
      var_declaration
      { $$ = new FuncParamListNode($1); }
    | func_param_list ';' var_declaration
      { $$ = FuncParamListNode::Append($1, $3); }
    ;

/* список операторов тела, включая необязательную секцию исключений. */
stmt_list_empty:
      %empty
      { $$ = nullptr; }
    | stmt_list
      { $$ = $1; }
    | stmt_list exception_part
      { $$ = append_statement_lists($1, $2); }
    ;

/* непустой список операторов. */
stmt_list:
      stmt
      { $$ = new StmtListNode($1); }
    | stmt_list stmt
      { $$ = StmtListNode::Append($1, $2); }
    ;

/* поддерживаемые операторы языка. */
stmt:
      return_stmt
      { $$ = $1; }
    | loop_stmt
      { $$ = $1; }
    | ID '(' expression_list_empty ')' ';'
      { $$ = StmtNode::StmtFromIdAndExpr($1, $3); }
    | if_stmt
      { $$ = $1; }
    | exit_stmt
      { $$ = $1; }
    | assigment_stmt
      { $$ = $1; }
    | case_stmt
      { $$ = $1; }
    | ID ';'
      { $$ = StmtNode::StmtFromIdAndExpr($1, nullptr); }
    ;

/* оператор return с выражением или без него. */
return_stmt:
      RETURN expression ';'
      { $$ = StmtNode::StmtFromReturn($2); }
    | RETURN ';'
      { $$ = StmtNode::StmtFromReturn(nullptr); }
    ;

/* три формы циклов. */
loop_stmt:
      while_stmt
      { $$ = $1; }
    | for_stmt
      { $$ = $1; }
    | simple_loop_stmt
      { $$ = $1; }
    ;

/* цикл for по диапазону или выражению. */
for_stmt:
      FOR ID IN range LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromForLoop($2, $4, $6); }
    | FOR ID IN expression LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromForLoop($2, nullptr, $6); }
    ;

/* цикл while. */
while_stmt:
      WHILE expression LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromWhileLoop($2, $4); }
    ;

/* простой цикл loop. */
simple_loop_stmt:
      LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromSimpleLoop($2); }
    ;

/* оператор exit с необязательным условием. */
exit_stmt:
      EXIT ';'
      { $$ = StmtNode::StmtFromExit(nullptr); }
    | EXIT WHEN expression ';'
      { $$ = StmtNode::StmtFromExit($3); }
    ;

/* условный оператор if. */
if_stmt:
      IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'
      { $$ = StmtNode::StmtFromIfWithElsif($2, $4, $5, $6); }
    | IF expression THEN stmt_list_empty else_stmt END IF ';'
      { $$ = StmtNode::StmtFromIf($2, $4, $5); }
    ;

/* оператор case. */
case_stmt:
      CASE expression IS case_alternative_list END CASE ';'
      { $$ = StmtNode::StmtFromCase($2, $4); }
    ;

/* список альтернатив case. */
case_alternative_list:
      case_alternative
      { $$ = new CaseAlternativeListNode($1); }
    | case_alternative_list case_alternative
      {
          $$ = $1;
          $$->add($2);
      }
    ;

/* отдельная ветвь when. */
case_alternative:
      WHEN choice_list ARROW stmt_list
      {
          auto it = $2->begin();
          $$ = new CaseAlternativeNode(*it, $4);

          for (++it; it != $2->end(); ++it) {
              $$->addChoice(*it);
          }
      }
    | WHEN OTHERS ARROW stmt_list
      { $$ = new CaseAlternativeNode(new CaseChoiceNode(true), $4); }
    ;

/* секция обработчиков исключений. */
exception_part:
      EXCEPTION exception_handler_list
      { $$ = $2; }
    ;

/* список обработчиков исключений. */
exception_handler_list:
      exception_handler
      { $$ = $1; }
    | exception_handler_list exception_handler
      { $$ = append_statement_lists($1, $2); }
    ;

/* отдельный обработчик исключения. */
exception_handler:
      WHEN choice_list ARROW stmt_list
      { $$ = $4; }
    | WHEN OTHERS ARROW stmt_list
      { $$ = $4; }
    ;

/* варианты выбора в when. */
choice_list:
      case_choice
      {
          $$ = new list<CaseChoiceNode*>();
          $$->push_back($1);
      }
    | choice_list '|' case_choice
      {
          $$ = $1;
          $$->push_back($3);
      }
    ;

/* выражение или диапазон в альтернативе case. */
case_choice:
      expression
      { $$ = new CaseChoiceNode($1); }
    | range
      { $$ = new CaseChoiceNode($1); }
    ;

/* список ветвей elsif. */
elsif_stmt_list:
      elsif_stmt
      { $$ = new ElsifStmtListNode($1); }
    | elsif_stmt_list elsif_stmt
      { $$ = ElsifStmtListNode::Append($1, $2); }
    ;

/* отдельная ветвь elsif. */
elsif_stmt:
      ELSIF expression THEN stmt_list_empty
      { $$ = new ElsifStmtNode($2, $4); }
    ;

/* необязательная ветвь else. */
else_stmt:
      %empty
      { $$ = nullptr; }
    | ELSE stmt_list_empty
      { $$ = new ElseStmtNode($2); }
    ;

/* оператор присваивания. */
assigment_stmt:
      expression ASSIGNMENT expression ';'
      { $$ = StmtNode::StmtFromAssigment($1, $3); }
    ;

/* необязательный список аргументов. */
expression_list_empty:
      %empty
      { $$ = nullptr; }
    | expression_list
      { $$ = new ExprListNode($1); }
    ;

/* список аргументов вызова. */
expression_list:
      arg
      { $$ = new ExprListNode($1); }
    | expression_list ',' arg
      { $$ = ExprListNode::Append($1, $3); }
    ;

/* позиционный или именованный аргумент. */
arg:
      expression
      { $$ = $1; }
    | ID ARROW expression
      {
          $$ = ExprNode::ExprOperation(
              ExprNode::expr_equal_expr,
              ExprNode::ExprFromId(ExprNode::id_, $1),
              $3
          );
      }
    ;

/* выражения, литералы, вызовы и операции. */
expression:
      CONST_BOOL
      { $$ = ExprNode::ExprFromBoolConst(ExprNode::const_bool, $1); }
    | CONST_CHARACTER
      { $$ = ExprNode::ExprFromCharConst(ExprNode::const_character, $1); }
    | CONST_STRING
      { $$ = ExprNode::ExprFromStringConst(ExprNode::const_string, $1); }
    | CONST_INTEGER
      { $$ = ExprNode::ExprFromIntConst(ExprNode::const_integer, $1); }
    | CONST_FLOAT
      { $$ = ExprNode::ExprFromFloatConst(ExprNode::const_float, $1); }
    | ID
      { $$ = ExprNode::ExprFromId(ExprNode::id_, $1); }

    /* сравнение. */
    | expression '>' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_more_expr, $1, $3); }
    | expression '<' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_less_expr, $1, $3); }
    | expression MORE_OR_EQUAL expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_more_equal_expr, $1, $3); }
    | expression LESS_OR_EQUAL expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_less_equal_expr, $1, $3); }
    | expression '=' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_equal_expr, $1, $3); }
    | expression NOT_EQUAL expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_not_equal_expr, $1, $3); }

    /* арифметика. */
    | expression '+' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_plus_expr, $1, $3); }
    | expression '-' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_minus_expr, $1, $3); }
    | expression '*' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_mult_expr, $1, $3); }
    | expression MOD expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_mod_expr, $1, $3); }
    | expression REM expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_rem_expr, $1, $3); }
    | expression '/' expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_div_expr, $1, $3); }

    /* дополнительные арифметические операции. */
    | expression POWER expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_power_expr, $1, $3); }
    | expression CONCAT expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_concat_expr, $1, $3); }

    /* унарная арифметика и логика. */
    | ABS expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_abs_expr, $2, nullptr); }
    | '-' expression %prec UMINUS
      { $$ = ExprNode::ExprOperation(ExprNode::uminus_expr, $2, nullptr); }
    | expression OR expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_or_expr, $1, $3); }
    | expression AND expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_and_expr, $1, $3); }
    | expression XOR expression
      { $$ = ExprNode::ExprOperation(ExprNode::expr_xor_expr, $1, $3); }
    | NOT expression
      { $$ = ExprNode::ExprOperation(ExprNode::not_expr, $2, nullptr); }

    /* вызовы функций и преобразования типов. */
    | ID '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, $1, $3); }
    | INTEGER '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Integer"), $3); }
    | FLOAT '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Float"), $3); }
    | BOOLEAN '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Boolean"), $3); }
    | CHARACTER '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("Character"), $3); }
    | STRING '(' expression_list_empty ')'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, new string("String"), $3); }

    /* выбор компонента составного объекта. */
    | expression '.' ID %prec '.'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, $3, new ExprListNode($1)); }

    /* ссылка на атрибут объекта. */
    | ID '\'' ID
      { $$ = ExprNode::ExprFromId(ExprNode::id_, $1); }
    | ID '\'' ID '(' expression_list ')'
      {
          $$ = ExprNode::ExprFromFuncCall(
              ExprNode::func_call,
              new string(*$1 + "'" + *$3),
              $5
          );
      }

    /* выражение в скобках. */
    | '(' expression_list ')'
      {
          if ($2 && $2->exprs->size() == 1) {
              $$ = $2->exprs->front();
          } else {
              $$ = ExprNode::ExprFromExprLiteral(ExprNode::literal, $2);
          }
      }
    ;

/* диапазон значений. */
range:
      expression DOUBLE_DOT expression
      { $$ = new RangeNode($1, $3); }
    ;

/* встроенный или пользовательский тип. */
var_type:
      INTEGER
      { $$ = new TypeNode(TypeNode::const_integer); }
    | BOOLEAN
      { $$ = new TypeNode(TypeNode::const_bool); }
    | FLOAT
      { $$ = new TypeNode(TypeNode::const_float); }
    | CHARACTER
      { $$ = new TypeNode(TypeNode::const_character); }
    | STRING
      { $$ = new TypeNode(TypeNode::const_string); }
    | ID
      { $$ = new TypeNode(TypeNode::id_, $1); }
    ;

%%