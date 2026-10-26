#pragma once

#include <iostream>
#include <cstring>
#include <list>
#include <string>

using namespace std;

// Предварительные объявления классов узлов AST.
class Node;
class ProgramNode;
class SubProgramItemNode;
class ItemListNode;
class DeclarationListNode;
class DeclarationNode;
class VarListNode;
class VarName;
class FuncParamListNode;
class StmtListNode;
class StmtNode;
class ElseStmtNode;
class ElsifStmtNode;
class ElsifStmtListNode;
class ExprNode;
class ExprListNode;
class RangeNode;
class TypeNode;

// Вспомогательные функции для формирования графического представления AST.
void connectVerticesDots(string& s, int parentId, int childId);
void createVertexDot(string& s, int id, string value = "", string type = "", string pos = "");

// Базовый класс узлов синтаксического дерева.
class Node {
public:
    virtual ~Node() = default;
    int NodeId = 0;
};

// Корневой узел программы.
class ProgramNode : public Node {
public:
    ItemListNode* itemlist = NULL;

    ProgramNode(ItemListNode* itemlist);
    void toDot(string& dot);
};

// Узел объявления или реализации подпрограммы.
class SubProgramItemNode : public Node {
public:
    enum type { func_dec, proc_dec, func_imp, proc_imp };

    type Type;
    string* name = NULL;
    FuncParamListNode* paramlist = NULL;
    TypeNode* varrtype = NULL;
    DeclarationListNode* decllist = NULL;
    StmtListNode* stmtlst = NULL;

    SubProgramItemNode(type Type, string* name,
        FuncParamListNode* paramlist, TypeNode* varrtype,
        DeclarationListNode* decllist, StmtListNode* stmtlst);

    void toDot(string& dot);
};

// Список подпрограмм программы.
class ItemListNode : public Node {
public:
    list<SubProgramItemNode*>* items = NULL;

    ItemListNode(SubProgramItemNode* item);
    ItemListNode(ItemListNode* list);

    static ItemListNode* Append(ItemListNode* list, SubProgramItemNode* item);
    void toDot(string& dot);
};

// Узел объявления типа или переменных.
class DeclarationNode : public Node {
public:
    enum type { type_dec, var_dec };

    type Type;
    TypeNode* varrtype = NULL;
    ExprNode* expr = NULL;
    RangeNode* rng = NULL;
    string* name = NULL;
    VarListNode* vlist = NULL;

    DeclarationNode(type Type);

    static DeclarationNode* TypeDeclaration(type Type, string* name,
        RangeNode* rng, TypeNode* varrtype);

    static DeclarationNode* VarDeclaration(type Type,
        VarListNode* vlist, TypeNode* varrtype);

    static DeclarationNode* VarDeclarationArray(type Type,
        VarListNode* vlist, RangeNode* rng, TypeNode* varrtype);

    static DeclarationNode* VarDeclarationAssignment(type Type,
        VarListNode* vlist, TypeNode* varrtype, ExprNode* expr);

    void toDot(string& dot);
};

// Список объявлений.
class DeclarationListNode : public Node {
public:
    list<DeclarationNode*>* decs = NULL;

    DeclarationListNode(DeclarationNode* dec);
    DeclarationListNode(DeclarationListNode* list);

    static DeclarationListNode* Append(DeclarationListNode* list, DeclarationNode* dec);
    void toDot(string& dot);
};

// Список имён переменных.
class VarListNode : public Node {
public:
    list<VarName*>* vars = NULL;

    VarListNode(string* name);
    VarListNode(VarListNode* varlst);

    static VarListNode* Append(VarListNode* list, string* name);
    void toDot(string& dot);
};

// Имя переменной.
class VarName : public Node {
public:
    string* name = NULL;

    VarName(string* name);
    void toDot(string& dot);
};

// Список параметров подпрограммы.
class FuncParamListNode : public Node {
public:
    list<DeclarationNode*>* params = NULL;

    FuncParamListNode(DeclarationNode* var_dec);
    FuncParamListNode(FuncParamListNode* list);

    static FuncParamListNode* Append(FuncParamListNode* list, DeclarationNode* var_dec);
    void toDot(string& dot);
};

// Узел оператора языка.
class StmtNode : public Node {
public:
    enum type {
        return_, whileloop, forloop, simpleLoop,
        id_, if_, exit_, assigment_
    };

    type Type;
    ExprNode* Expr = NULL;
    ExprListNode* Expr_list = NULL;
    string* Name = NULL;
    ExprNode* Left_operator = NULL;
    ExprNode* Right_operator = NULL;
    StmtListNode* stmtlst = NULL;
    RangeNode* rng = NULL;
    ElseStmtNode* else_stmt = NULL;
    ElsifStmtListNode* elsif_lst = NULL;

    static StmtNode* StmtFromReturn(ExprNode* Expr);
    static StmtNode* StmtFromWhileLoop(ExprNode* Expr, StmtListNode* list);
    static StmtNode* StmtFromForLoop(string* name, RangeNode* range, StmtListNode* list);
    static StmtNode* StmtFromSimpleLoop(StmtListNode* list);
    static StmtNode* StmtFromIdAndExpr(string* Name, ExprListNode* Expr_list);
    static StmtNode* StmtFromIfWithElsif(ExprNode* Expr, StmtListNode* list,
        ElsifStmtListNode* elsif_lst, ElseStmtNode* else_stmt);
    static StmtNode* StmtFromIf(ExprNode* Expr, StmtListNode* list,
        ElseStmtNode* else_stmt);
    static StmtNode* StmtFromExit(ExprNode* Expr);
    static StmtNode* StmtFromAssigment(ExprNode* left, ExprNode* right);

    void toDot(string& dot);
};

// Список ветвей elsif.
class ElsifStmtListNode : public Node {
public:
    list<ElsifStmtNode*>* elsifs = NULL;

    ElsifStmtListNode(ElsifStmtNode* elsif);
    ElsifStmtListNode(ElsifStmtListNode* list);

    static ElsifStmtListNode* Append(ElsifStmtListNode* list, ElsifStmtNode* elsif);
    void toDot(string& dot);
};

// Одна ветвь elsif.
class ElsifStmtNode : public Node {
public:
    ExprNode* Expr = NULL;
    StmtListNode* stmtlst = NULL;

    ElsifStmtNode(ExprNode* expr, StmtListNode* lst);
    void toDot(string& dot);
};

// Ветка else.
class ElseStmtNode : public Node {
public:
    StmtListNode* stmtlst = NULL;

    ElseStmtNode(StmtListNode* lst);
    void toDot(string& dot);
};

// Список операторов.
class StmtListNode : public Node {
public:
    list<StmtNode*>* stmts = NULL;

    StmtListNode(StmtNode* stmt);
    StmtListNode(StmtListNode* list);

    static StmtListNode* Append(StmtListNode* list, StmtNode* stmt);
    void toDot(string& dot);
};

// Узел выражения.
class ExprNode : public Node {
public:
    enum type {
        const_bool, const_character, const_string, const_integer, const_float,
        id_, expr_more_expr, expr_less_expr, expr_more_equal_expr,
        expr_less_equal_expr, expr_equal_expr, expr_not_equal_expr,
        expr_plus_expr, expr_minus_expr, expr_mult_expr, expr_div_expr,
        expr_abs_expr, uminus_expr, expr_or_expr, expr_and_expr,
        expr_xor_expr, not_expr, func_call, literal, expr_mod_expr, expr_rem_expr
    };

    type Type;

    char Char = 0;
    string* String = NULL;
    int Integer = 0;
    float Float = 0;
    bool Bool = false;

    string* Name = NULL;
    ExprNode* Left_operator = NULL;
    ExprNode* Right_operator = NULL;
    ExprListNode* Expr_list = NULL;

    static ExprNode* ExprFromCharConst(type Type, char value);
    static ExprNode* ExprFromBoolConst(type Type, bool value);
    static ExprNode* ExprFromStringConst(type Type, string* value);
    static ExprNode* ExprFromIntConst(type Type, int value);
    static ExprNode* ExprFromFloatConst(type Type, float value);
    static ExprNode* ExprFromId(type Type, string* Name);
    static ExprNode* ExprOperation(type Type, ExprNode* left, ExprNode* right);
    static ExprNode* ExprFromFuncCall(type Type, string* Name, ExprListNode* Expr_list);
    static ExprNode* ExprFromExprLiteral(type Type, ExprListNode* Expr_list);

    void toDot(string& dot);
};

// Список выражений.
class ExprListNode : public Node {
public:
    list<ExprNode*>* exprs = NULL;

    ExprListNode(ExprNode* expr);
    ExprListNode(ExprListNode* exprs_list);

    static ExprListNode* Append(ExprListNode* list, ExprNode* expr);
    void toDot(string& dot);
};

// Диапазон значений.
class RangeNode : public Node {
public:
    ExprNode* Left_operator = NULL;
    ExprNode* Right_operator = NULL;

    RangeNode(ExprNode* left, ExprNode* right);
    void toDot(string& dot);
};

// Тип данных.
class TypeNode : public Node {
public:
    enum type { const_bool, const_character, const_string, const_integer, const_float, array_, id_ };

    type Type;
    string* Name = NULL;

    TypeNode(type Type);
    TypeNode(type Type, string* Name);

    void toDot(string& dot);
};

// Выводит абстрактное синтаксическое дерево программы в консоль.
void printTree(ProgramNode* root);