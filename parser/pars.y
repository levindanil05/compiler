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

/* Создаёт объявление пользовательского типа и прикрепляет его определение. */
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

/* Объединяет два списка операторов, корректно обрабатывая пустые списки. */
static StmtListNode* append_statement_lists(
    StmtListNode* first,
    StmtListNode* second
) {
    if (!first) return second;
    if (!second) return first;
    if (second->stmts) {
        for (auto* statement : *second->stmts)
            first->stmts->push_back(statement);
    }
    return first;
}
%}

/* Лексические токены, возвращаемые yylex() из lexer.l. */
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

/* Приоритеты операторов от низшего к высшему; бинарные операции левоассоциативны. */
%left OR XOR
%left AND
%left '=' NOT_EQUAL '<' LESS_OR_EQUAL '>' MORE_OR_EQUAL
%left '+' '-'
%left '*' '/' MOD REM
%precedence NOT
%precedence ABS
%precedence UMINUS
%precedence '.'

/*
 * Типизированные значения семантических атрибутов Bison.
 * Для каждого нетерминала ниже указан соответствующий тип через %type.
 */
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

/* Форматирование значений токенов при включённой отладочной печати Bison. */
%printer { fprintf(yyo, "%s", $$ ? $$->c_str() : "null"); } <id_const> <string_const>
%printer { fprintf(yyo, "%d", $$); } <int_const>
%printer { fprintf(yyo, "%f", $$); } <float_const>
%printer { fprintf(yyo, "%c", $$); } <char_const>

/* Типы семантических значений нетерминалов. */
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

/* Корневое правило: контекстные предложения WITH/USE и тело программы. */
program:
      context_list program_body
      { $$ = global_program = $2; }
    ;

/* Верхний уровень программы хранит список функций и процедур. */
program_body:
      item_list
      { $$ = new ProgramNode($1); }
    ;

/* Контекстная часть необязательна и может содержать несколько предложений. */
context_list:
      %empty
    | context_list context_item
    ;

/* Подключение пакета или другого составного имени. */
context_item:
      WITH dotted_name ';'
    | USE dotted_name ';'
    ;

/* Составное имя вида Ada.Text_IO. */
dotted_name:
      ID
    | dotted_name '.' ID
    ;

/* Список элементов верхнего уровня; новые элементы добавляются в конец. */
item_list:
      item
      { $$ = new ItemListNode($1); }
    | item_list item
      { $$ = ItemListNode::Append($1, $2); }
    ;

item:
      func_declaration       { $$ = $1; }
    | proc_declaration       { $$ = $1; }
    | func_implementation    { $$ = $1; }
    | proc_implementation   { $$ = $1; }
    ;

/* Прототип функции: с параметрами или без них. */
func_declaration:
      FUNCTION ID '(' func_param_list ')' RETURN var_type ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, $4, $7, NULL, NULL); }
    | FUNCTION ID RETURN var_type ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, NULL, $4, NULL, NULL); }
    ;

/* Прототип процедуры: с параметрами или без них. */
proc_declaration:
      PROCEDURE ID '(' func_param_list ')' ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, $4, NULL, NULL, NULL); }
    | PROCEDURE ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, NULL, NULL, NULL, NULL); }
    ;

/* Полная функция: заголовок, декларативная часть, операторы и END. */
func_implementation:
      FUNCTION ID '(' func_param_list ')' RETURN var_type
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, $4, $7, $9, $11); }
    | FUNCTION ID RETURN var_type
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, NULL, $4, $6, $8); }
    ;

/* Полная процедура. Декларативная часть допускает вложенные подпрограммы. */
proc_implementation:
      PROCEDURE ID '(' func_param_list ')'
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, $4, NULL, $7, $9); }
    | PROCEDURE ID
      IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';'
      { $$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, NULL, NULL, $4, $6); }
    ;

/* Декларативная часть может быть пустой. */
declaration_list_empty:
      %empty { $$ = nullptr; }
    | decl_body_list { $$ = $1; }
    ;

/* Объявления внутри подпрограммы. item преобразуется в декларацию подпрограммы,
 * поэтому функции и процедуры могут быть вложенными. */
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

declaration:
      type_declaration { $$ = $1; }
    | var_declaration  { $$ = $1; }
    ;

/* Type declarations retain their complete definition in the AST. */
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

/* Полное определение массива: список индексов и тип элементов. */
array_type_definition:
      ARRAY '(' array_index_list ')' OF var_type
      {
          $$ = $3;
          $$->element_type = $6;
      }
    ;

/* Один или несколько измерений массива, разделённых запятыми. */
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

/* Both constrained and unconstrained Ada array indexes are supported. */
/*
 * Индекс массива:
 * - range задаёт ограниченный диапазон без явного имени индексного типа;
 * - var_type RANGE <> задаёт неограниченный индекс;
 * - var_type RANGE range задаёт типизированный ограниченный индекс.
 */
array_index:
      range
      { $$ = new ArrayIndexNode($1, nullptr, false); }
    | var_type RANGE '<' '>'
      { $$ = new ArrayIndexNode(nullptr, $1, true); }
    | var_type RANGE range
      { $$ = new ArrayIndexNode($3, $1, false); }
    ;

/* Литералы перечислимого типа сохраняются в TypeDefinitionNode. */
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

/* Поля записи сохраняются как отдельные объявления переменных. */
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

/* Объявление переменных, параметров и локальных массивов. Поддерживаются
 * режимы IN/OUT, константы и начальная инициализация. */
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

/* Несколько имён могут относиться к одному объявлению типа. */
var_list:
      ID { $$ = new VarListNode($1); }
    | var_list ',' ID { $$ = VarListNode::Append($1, $3); }
    ;

/* Параметры подпрограммы разделяются точкой с запятой. */
func_param_list:
      var_declaration { $$ = new FuncParamListNode($1); }
    | func_param_list ';' var_declaration { $$ = FuncParamListNode::Append($1, $3); }
    ;

/* Список операторов может быть пустым; обработчики EXCEPTION добавляются
 * к списку операторов в текущей модели AST. */
stmt_list_empty:
      %empty { $$ = nullptr; }
    | stmt_list { $$ = $1; }
    | stmt_list exception_part
      { $$ = append_statement_lists($1, $2); }
    ;

/* Непустой список операторов тела подпрограммы или управляющей конструкции. */
stmt_list:
      stmt { $$ = new StmtListNode($1); }
    | stmt_list stmt { $$ = StmtListNode::Append($1, $2); }
    ;

/* Все поддерживаемые операторы объединены этим нетерминалом. */
stmt:
      return_stmt { $$ = $1; }
    | loop_stmt { $$ = $1; }
    | ID '(' expression_list_empty ')' ';'
      { $$ = StmtNode::StmtFromIdAndExpr($1, $3); }
    | if_stmt { $$ = $1; }
    | exit_stmt { $$ = $1; }
    | assigment_stmt { $$ = $1; }
    | case_stmt { $$ = $1; }
    | ID ';' { $$ = StmtNode::StmtFromIdAndExpr($1, nullptr); }
    ;

/* RETURN может завершать функцию с результатом или без выражения. */
return_stmt:
      RETURN expression ';' { $$ = StmtNode::StmtFromReturn($2); }
    | RETURN ';' { $$ = StmtNode::StmtFromReturn(nullptr); }
    ;

/* Три поддерживаемые формы цикла: WHILE, FOR и простой LOOP. */
loop_stmt:
      while_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | simple_loop_stmt { $$ = $1; }
    ;

/* Цикл FOR по диапазону либо по выражению. */
for_stmt:
      FOR ID IN range LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromForLoop($2, $4, $6); }
    | FOR ID IN expression LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromForLoop($2, nullptr, $6); }
    ;

/* Цикл WHILE проверяет условие перед каждой итерацией. */
while_stmt:
      WHILE expression LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromWhileLoop($2, $4); }
    ;

/* Безусловный LOOP; обычно завершается оператором EXIT. */
simple_loop_stmt:
      LOOP stmt_list_empty END LOOP ';'
      { $$ = StmtNode::StmtFromSimpleLoop($2); }
    ;

/* EXIT без условия или с условием WHEN. */
exit_stmt:
      EXIT ';' { $$ = StmtNode::StmtFromExit(nullptr); }
    | EXIT WHEN expression ';' { $$ = StmtNode::StmtFromExit($3); }
    ;

/* Условный оператор с необязательными ветвями ELSIF и ELSE. */
if_stmt:
      IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'
      { $$ = StmtNode::StmtFromIfWithElsif($2, $4, $5, $6); }
    | IF expression THEN stmt_list_empty else_stmt END IF ';'
      { $$ = StmtNode::StmtFromIf($2, $4, $5); }
    ;

/* CASE выбирает одну из альтернатив WHEN по значению выражения. */
case_stmt:
      CASE expression IS case_alternative_list END CASE ';'
      { $$ = StmtNode::StmtFromCase($2, $4); }
    ;

/* Альтернативы CASE сохраняются отдельно: список больше не сплющивает
 * операторы разных ветвей в один общий список. */
case_alternative_list:
      case_alternative
      { $$ = new CaseAlternativeListNode($1); }
    | case_alternative_list case_alternative
      { $$ = $1; $$->add($2); }
    ;

/* Одна ветвь WHEN содержит список вариантов выбора и собственное тело. */
case_alternative:
      WHEN choice_list ARROW stmt_list
      {
          auto it = $2->begin();
          $$ = new CaseAlternativeNode(*it, $4);
          for (++it; it != $2->end(); ++it)
              $$->addChoice(*it);
      }
    | WHEN OTHERS ARROW stmt_list
      { $$ = new CaseAlternativeNode(new CaseChoiceNode(true), $4); }
    ;

/* Раздел обработчиков исключений после основного тела. */
exception_part:
      EXCEPTION exception_handler_list { $$ = $2; }
    ;

/* Список обработчиков исключений. */
exception_handler_list:
      exception_handler { $$ = $1; }
    | exception_handler_list exception_handler
      { $$ = append_statement_lists($1, $2); }
    ;

/* Обработчик конкретного выбора либо OTHERS. */
exception_handler:
      WHEN choice_list ARROW stmt_list { $$ = $4; }
    | WHEN OTHERS ARROW stmt_list { $$ = $4; }
    ;

/* Варианты выбора в WHEN разделяются вертикальной чертой. */
choice_list:
      case_choice
      {
          $$ = new list<CaseChoiceNode*>();
          $$->push_back($1);
      }
    | choice_list '|' case_choice
      { $$ = $1; $$->push_back($3); }
    ;

/* Один вариант CASE: выражение, диапазон или OTHERS. */
case_choice:
      expression { $$ = new CaseChoiceNode($1); }
    | range { $$ = new CaseChoiceNode($1); }
    ;

/* Список ветвей ELSIF. */
elsif_stmt_list:
      elsif_stmt { $$ = new ElsifStmtListNode($1); }
    | elsif_stmt_list elsif_stmt { $$ = ElsifStmtListNode::Append($1, $2); }
    ;

/* Одна ветвь ELSIF с условием и телом. */
elsif_stmt:
      ELSIF expression THEN stmt_list_empty
      { $$ = new ElsifStmtNode($2, $4); }
    ;

/* Ветка ELSE необязательна. */
else_stmt:
      %empty { $$ = nullptr; }
    | ELSE stmt_list_empty { $$ = new ElseStmtNode($2); }
    ;

/* Присваивание выражения целевому выражению. */
assigment_stmt:
      expression ASSIGNMENT expression ';'
      { $$ = StmtNode::StmtFromAssigment($1, $3); }
    ;

/* Список аргументов вызова может быть пустым. */
expression_list_empty:
      %empty { $$ = nullptr; }
    | expression_list { $$ = new ExprListNode($1); }
    ;

/* Аргументы вызова разделяются запятыми. */
expression_list:
      arg { $$ = new ExprListNode($1); }
    | expression_list ',' arg { $$ = ExprListNode::Append($1, $3); }
    ;

/* Аргумент может быть позиционным или именованным (Name => Value). */
arg:
      expression { $$ = $1; }
    | ID ARROW expression
      {
          $$ = ExprNode::ExprOperation(
              ExprNode::expr_equal_expr,
              ExprNode::ExprFromId(ExprNode::id_, $1), $3
          );
      }
    ;

/* Выражения: литералы, имена, вызовы, арифметика, сравнения, логика,
 * выбор полей и скобочные выражения. Приоритеты заданы выше. */
expression:
      CONST_BOOL { $$ = ExprNode::ExprFromBoolConst(ExprNode::const_bool, $1); }
    | CONST_CHARACTER { $$ = ExprNode::ExprFromCharConst(ExprNode::const_character, $1); }
    | CONST_STRING { $$ = ExprNode::ExprFromStringConst(ExprNode::const_string, $1); }
    | CONST_INTEGER { $$ = ExprNode::ExprFromIntConst(ExprNode::const_integer, $1); }
    | CONST_FLOAT { $$ = ExprNode::ExprFromFloatConst(ExprNode::const_float, $1); }
    | ID { $$ = ExprNode::ExprFromId(ExprNode::id_, $1); }

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

    | expression '.' ID %prec '.'
      { $$ = ExprNode::ExprFromFuncCall(ExprNode::func_call, $3, new ExprListNode($1)); }
    | ID '\'' ID
      { $$ = ExprNode::ExprFromId(ExprNode::id_, $1); }
    | ID '\'' ID '(' expression_list ')'
      {
          $$ = ExprNode::ExprFromFuncCall(
              ExprNode::func_call, new string(*$1 + "'" + *$3), $5
          );
      }
    | '(' expression_list ')'
      {
          if ($2 && $2->exprs->size() == 1)
              $$ = $2->exprs->front();
          else
              $$ = ExprNode::ExprFromExprLiteral(ExprNode::literal, $2);
      }
    ;

/* Диапазон Ada: нижняя и верхняя границы разделены токеном DOUBLE_DOT. */
range:
      expression DOUBLE_DOT expression
      { $$ = new RangeNode($1, $3); }
    ;

/* Встроенный тип либо имя пользовательского типа. */
var_type:
      INTEGER { $$ = new TypeNode(TypeNode::const_integer); }
    | BOOLEAN { $$ = new TypeNode(TypeNode::const_bool); }
    | FLOAT { $$ = new TypeNode(TypeNode::const_float); }
    | CHARACTER { $$ = new TypeNode(TypeNode::const_character); }
    | STRING { $$ = new TypeNode(TypeNode::const_string); }
    | ID { $$ = new TypeNode(TypeNode::id_, $1); }
    ;

%%