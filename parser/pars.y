%code requires {
#include <string>
#include <list>
#include "class_nodes.h"
using namespace std;
}
%{
#include <stdio.h>
#include <stdlib.h>
#include "class_nodes.h"
void yyerror(char const* s);
extern int yylex(void);
ProgramNode* global_program;
%}
%token INTEGER BOOLEAN FLOAT CHARACTER STRING
%token WHILE
%token FOR
%token IN
%token OF
%token LOOP
%token IF
%token THEN
%token ELSIF
%token ELSE
%token ASSIGNMENT
%left OR AND XOR
%left '=' NOT_EQUAL '<' LESS_OR_EQUAL '>' MORE_OR_EQUAL
%left '+' '-'
%left '*' '/' ABS
%left MOD REM
%precedence NOT
%precedence UMINUS
%precedence '.'
%token ARRAY
%token TYPE
%token ID
%token CONST_STRING
%token CONST_INTEGER
%token CONST_FLOAT
%token CONST_CHARACTER
%token CONST_BOOL
%token RANGE
%token EXIT
%token WHEN
%token FUNCTION
%token PROCEDURE
%token IS
%token RETURN
%token BEGIN_TOKEN END
%token ','
%token DOUBLE_DOT
%token  ':'
%token ';'
%token WITH USE
%token RECORD
%token CONSTANT
%token CASE
%token EXCEPTION
%token OTHERS
%token OUT
%token MOD REM
%token ARROW
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
}
%printer { fprintf(yyo, "%s", $$ ? $$->c_str() : "null"); } <id_const> <string_const>
%printer { fprintf(yyo, "%d", $$); } <int_const>
%printer { fprintf(yyo, "%f", $$); } <float_const>
%printer { fprintf(yyo, "%c", $$); } <char_const>
%type <prg> program
%type <id_const> ID
%type <string_const> CONST_STRING
%type <int_const> CONST_INTEGER
%type <float_const> CONST_FLOAT
%type <char_const> CONST_CHARACTER
%type <int_const> CONST_BOOL
%type <item> item
%type <item> func_declaration
%type <item> proc_declaration
%type <item> func_implementation
%type <item> proc_implementation
%type <itemlst> item_list
%type <decl_lst> declaration_list_empty
%type <decl> declaration
%type <decl> type_declaration
%type <decl> var_declaration
%type <var_lst> var_list
%type <param_lst> func_param_list
%type <stmt_lst> stmt_list
%type <stmt_lst> stmt_list_empty
%type <stmt> stmt
%type <stmt> return_stmt
%type <stmt> loop_stmt
%type <stmt> for_stmt
%type <stmt> while_stmt
%type <stmt> simple_loop_stmt
%type <stmt> exit_stmt
%type <stmt> if_stmt
%type <stmt> assigment_stmt
%type <els_stmt> else_stmt
%type <elsf_stmt> elsif_stmt
%type <elsf_lst_stmt> elsif_stmt_list
%type <expr> expression
%type <expr> arg
%type <expr_list> expression_list
%type <expr_list> expression_list_empty
%type <rng> range
%type <v_type> var_type
%type <prg> program_body
%type <stmt> case_stmt
%type <stmt_lst> exception_part
%type <stmt_lst> exception_handler_list
%type <stmt_lst> exception_handler
%start program
%%
program:
      context_list program_body   { $$ = global_program = $2; }
    ;
program_body:
      item_list   { $$ = new ProgramNode($1); }
    ;
context_list:
      %empty
    | context_list context_item
    ;
context_item:
      WITH dotted_name ';'
    | USE  dotted_name ';'
    ;
dotted_name:
      ID
    | dotted_name '.' ID
    ;
item_list : item {$$ = new ItemListNode($1);}
         | item_list item  { $$ = ItemListNode::Append($1, $2); }
         ;
item: func_declaration {$$ = $1;}
    | proc_declaration {$$ = $1;}
    | func_implementation {$$ = $1;}
    | proc_implementation {$$ = $1;}
    ;
func_declaration: FUNCTION ID '(' func_param_list ')' RETURN var_type ';' {$$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, $4, $7, NULL, NULL);}
                | FUNCTION ID RETURN var_type ';' {$$ = new SubProgramItemNode(SubProgramItemNode::func_dec, $2, NULL, $4, NULL, NULL);}
                ;
proc_declaration: PROCEDURE ID '(' func_param_list ')' ';' {$$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, $4, NULL, NULL, NULL);}
                | PROCEDURE ID ';' {$$ = new SubProgramItemNode(SubProgramItemNode::proc_dec, $2, NULL, NULL, NULL, NULL);}
                ;
func_implementation: FUNCTION ID '(' func_param_list ')'  RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';' {$$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, $4, $7, $9, $11);}
                | FUNCTION ID RETURN var_type IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';' {$$ = new SubProgramItemNode(SubProgramItemNode::func_imp, $2, NULL, $4, $6, $8);}
               ;
proc_implementation: PROCEDURE ID '(' func_param_list ')' IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';' {$$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, $4, NULL, $7, $9);}
                | PROCEDURE ID IS declaration_list_empty BEGIN_TOKEN stmt_list_empty END ID ';' {$$ = new SubProgramItemNode(SubProgramItemNode::proc_imp, $2, NULL, NULL, $4, $6);}
               ;
declaration_list_empty:
      %empty          { $$ = 0; }
    | decl_body_list       { $$ = 0; }
    ;
decl_body_list:
      declaration ';'                       { }
    | item                                  { }
    | decl_body_list declaration ';'        { }
    | decl_body_list item                   { }
    ;
declaration: type_declaration {$$ = $1;}
            | var_declaration {$$ = $1;}
            ;
type_declaration:
      TYPE ID IS ARRAY '(' array_index_list ')' OF var_type
        {$$ = new DeclarationNode(DeclarationNode::type_dec);}
    | TYPE ID IS '(' enum_id_list ')'
        {$$ = new DeclarationNode(DeclarationNode::type_dec);}
    | TYPE ID IS RANGE range
        {$$ = new DeclarationNode(DeclarationNode::type_dec);}
    | TYPE ID IS RECORD record_field_list END RECORD
        {$$ = new DeclarationNode(DeclarationNode::type_dec);}
    ;
array_index_list:
      expression
    | range
    | expression ',' expression
    ;
enum_id_list:
      ID
    | enum_id_list ',' ID
    ;
record_field_list:
      var_declaration ';'   { }
    | record_field_list var_declaration ';'   { }
    ;
var_declaration:
      var_list ':' var_type
        {$$ = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, $1,$3);}
    | var_list ':' IN var_type
        {$$ = new DeclarationNode(DeclarationNode::var_dec);}
    | var_list ':' OUT var_type
        {$$ = new DeclarationNode(DeclarationNode::var_dec);}
    | var_list ':' IN OUT var_type
        {$$ = new DeclarationNode(DeclarationNode::var_dec);}
    | var_list ':' CONSTANT var_type
        {$$ = DeclarationNode::VarDeclaration (DeclarationNode::var_dec, $1,$4);}
    | var_list ':' CONSTANT var_type ASSIGNMENT expression
        {$$ = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, $1,$4,$6);}
    | var_list ':' ARRAY '(' array_index_list ')' OF var_type
        {$$ = new DeclarationNode(DeclarationNode::var_dec);}
    | var_list ':' var_type ASSIGNMENT expression
        {$$ = DeclarationNode::VarDeclarationAssignment (DeclarationNode::var_dec, $1,$3,$5);}
    ;
var_list : ID { $$ = new VarListNode($1);}
         | var_list ',' ID  { $$ = VarListNode::Append($1, $3); }
         ;
func_param_list: var_declaration {$$ = new FuncParamListNode($1);}
               | func_param_list ';' var_declaration   { $$ = FuncParamListNode::Append($1, $3); }
               ;
stmt_list_empty:
      %empty                    { $$ = 0; }
    | stmt_list                      { $$ = new StmtListNode($1); }
    | stmt_list exception_part       { $$ = new StmtListNode($1); }
    ;
stmt_list : stmt { $$ = new StmtListNode($1); }
          | stmt_list stmt { $$ = StmtListNode::Append($1, $2); }
          ;
stmt: return_stmt  {$$ = $1;}
    | loop_stmt {$$ = $1;}
    | ID '(' expression_list_empty ')' ';' {$$ = StmtNode:: StmtFromIdAndExpr ($1,$3);}
    | if_stmt  {$$ = $1;}
    | exit_stmt  {$$ = $1;}
    | assigment_stmt  {$$ = $1;}
    | case_stmt {$$ = 0;}
    | ID ';' {$$ = StmtNode:: StmtFromIdAndExpr ($1, NULL);}
    ;
return_stmt : RETURN expression ';' {$$ = StmtNode:: StmtFromReturn ($2);}
            | RETURN ';' {$$ = StmtNode:: StmtFromReturn (NULL);}
            ;
loop_stmt: while_stmt {$$ = $1;}
         | for_stmt {$$ = $1;}
         | simple_loop_stmt {$$ = $1;}
         ;
for_stmt:
      FOR ID IN range LOOP stmt_list_empty END LOOP ';'
        {$$ = StmtNode:: StmtFromForLoop ($2,$4,$6);}
    | FOR ID IN expression LOOP stmt_list_empty END LOOP ';'
        {$$ = StmtNode:: StmtFromForLoop ($2, NULL, $6);}
    ;
while_stmt: WHILE expression LOOP stmt_list_empty END LOOP ';' {$$ = StmtNode:: StmtFromWhileLoop ($2,$4);}
          ;
simple_loop_stmt: LOOP stmt_list_empty END LOOP ';' {$$ = StmtNode:: StmtFromSimpleLoop ($2);}
                ;
exit_stmt: EXIT ';' {$$ = StmtNode:: StmtFromExit (NULL);}
        | EXIT WHEN expression ';' {$$ = StmtNode:: StmtFromExit ($3);}
        ;
if_stmt: IF expression THEN stmt_list_empty elsif_stmt_list else_stmt END IF ';'  {$$ = StmtNode:: StmtFromIfWithElsif ($2, $4, $5, $6);}
        | IF expression THEN stmt_list_empty else_stmt END IF ';'       {$$ = StmtNode:: StmtFromIf ($2, $4, $5);}
        ;
case_stmt:
      CASE expression IS case_alternative_list END CASE ';'
        {$$ = 0;}
    ;
case_alternative_list:
      case_alternative
    | case_alternative_list case_alternative
    ;
case_alternative:
      WHEN choice_list ARROW stmt_list
    | WHEN OTHERS ARROW stmt_list
    ;
exception_part:
      EXCEPTION exception_handler_list   { $$ = $2; }
    ;
exception_handler_list:
      exception_handler
    | exception_handler_list exception_handler
    ;
exception_handler:
      WHEN choice_list ARROW stmt_list   { $$ = $4; }
    | WHEN OTHERS ARROW stmt_list        { $$ = $4; }
    ;
choice_list:
      expression
    | range
    | choice_list '|' expression
    | choice_list '|' range
    ;
elsif_stmt_list: elsif_stmt { $$ = new ElsifStmtListNode($1); }
                | elsif_stmt_list elsif_stmt { $$ = ElsifStmtListNode::Append($1, $2); }
                ;
elsif_stmt: ELSIF expression THEN stmt_list_empty      { $$ = new ElsifStmtNode($2, $4); }
          ;
else_stmt:     %empty  { $$ = 0; }
         | ELSE stmt_list_empty     { $$ = new ElseStmtNode($2); }
         ;
assigment_stmt: expression ASSIGNMENT expression ';' {$$ = StmtNode:: StmtFromAssigment ($1,$3);}
                ;
expression_list_empty:  %empty  { $$ = 0; }
                   | expression_list { $$ = new ExprListNode($1); }
                   ;
expression_list:
      arg                       { $$ = new ExprListNode($1); }
    | expression_list ',' arg   { $$ = ExprListNode::Append($1, $3); }
    ;
arg:
      expression                { $$ = $1; }
    | ID ARROW expression       { $$ = ExprNode::ExprFromId (ExprNode::id_,$1); }
    ;
expression: CONST_BOOL {$$ = ExprNode::ExprFromBoolConst (ExprNode::const_bool,$1); }
          | CONST_CHARACTER {$$ = ExprNode::ExprFromCharConst (ExprNode::const_character,$1); }
          | CONST_STRING {$$ = ExprNode::ExprFromStringConst (ExprNode::const_string,$1); }
          | CONST_INTEGER {$$ = ExprNode::ExprFromIntConst (ExprNode::const_integer,$1); }
          | CONST_FLOAT {$$ = ExprNode::ExprFromFloatConst (ExprNode::const_float,$1); }
          | ID {$$ = ExprNode::ExprFromId (ExprNode::id_,$1); }
          | expression '>' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_more_expr,$1,$3); }
          | expression '<' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_less_expr,$1,$3); }
          | expression MORE_OR_EQUAL expression {$$ = ExprNode::ExprOperation (ExprNode::expr_more_equal_expr,$1,$3); }
          | expression LESS_OR_EQUAL expression {$$ = ExprNode::ExprOperation (ExprNode::expr_less_equal_expr,$1,$3); }
          | expression '=' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_equal_expr,$1,$3); }
          | expression NOT_EQUAL expression {$$ = ExprNode::ExprOperation (ExprNode::expr_not_equal_expr,$1,$3); }
          | expression '+' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_plus_expr,$1,$3); }
          | expression '-' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_minus_expr,$1,$3); }
          | expression '*' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_mult_expr,$1,$3); }
          | expression MOD expression {$$ = ExprNode::ExprOperation (ExprNode::expr_mult_expr,$1,$3); }
          | expression REM expression {$$ = ExprNode::ExprOperation (ExprNode::expr_mult_expr,$1,$3); }
          | expression '/' expression {$$ = ExprNode::ExprOperation (ExprNode::expr_div_expr,$1,$3); }
          | expression ABS expression {$$ = ExprNode::ExprOperation (ExprNode::expr_abs_expr,$1,$3); }
          | '-' expression %prec UMINUS {$$ = ExprNode::ExprOperation (ExprNode::uminus_expr,$2, NULL); }
          | expression OR expression {$$ = ExprNode::ExprOperation (ExprNode::expr_or_expr,$1,$3); }
          | expression AND expression {$$ = ExprNode::ExprOperation (ExprNode::expr_and_expr,$1,$3); }
          | expression XOR expression {$$ = ExprNode::ExprOperation (ExprNode::expr_xor_expr,$1,$3); }
          | NOT expression {$$ = ExprNode::ExprOperation (ExprNode::not_expr,$2, NULL); }
          | ID '(' expression_list_empty ')'  {$$ = ExprNode::ExprFromFuncCall (ExprNode::func_call,$1, $3); }
          | INTEGER '(' expression_list_empty ')'  {$$ = 0; }
          | FLOAT '(' expression_list_empty ')'    {$$ = 0; }
          | BOOLEAN '(' expression_list_empty ')'  {$$ = 0; }
          | CHARACTER '(' expression_list_empty ')' {$$ = 0; }
          | STRING '(' expression_list_empty ')'   {$$ = 0; }
          | expression '.' ID %prec '.' {$$ = ExprNode::ExprOperation (ExprNode::id_,$1, NULL); }
          | ID '\'' ID {$$ = ExprNode::ExprFromId (ExprNode::id_,$1); }
          | ID '\'' ID '(' expression_list ')' {$$ = ExprNode::ExprFromFuncCall (ExprNode::func_call,$1, $5); }
          | '(' expression_list ')' {$$ = ExprNode::ExprFromExprLiteral (ExprNode::literal,$2); }
          ;
range : expression DOUBLE_DOT expression  {$$ = new RangeNode($1,$3);}
      ;
var_type: INTEGER { $$ = new TypeNode(TypeNode::const_integer); }
    | BOOLEAN { $$ = new TypeNode(TypeNode::const_bool); }
    | FLOAT { $$ = new TypeNode(TypeNode::const_float); }
    | CHARACTER { $$ = new TypeNode(TypeNode::const_character); }
    | STRING { $$ = new TypeNode(TypeNode::const_string); }
    | ID { $$ = new TypeNode(TypeNode::id_,$1); }
    ;
%%
