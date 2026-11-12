
#pragma once

#include <iostream>
#include <cstring>
#include <list>
#include <string>

using namespace std;

// Предварительные объявления классов AST.
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
class TypeDefinitionNode;
class CaseAlternativeListNode;
class ExceptionHandlerListNode;

// Вспомогательные функции для построения DOT-графа.
void connectVerticesDots(string& s, int parentId, int childId);
void createVertexDot(
    string& s,
    int id,
    string value = "",
    string type = "",
    string pos = ""
);

// Базовый класс всех узлов абстрактного синтаксического дерева.
class Node {
public:
    virtual ~Node() = default;
    int NodeId = 0;
};

// Корневой узел программы.
class ProgramNode : public Node {
public:
    ItemListNode* itemlist = nullptr;

    explicit ProgramNode(ItemListNode* itemlist);
};

// Узел объявления или реализации функции/процедуры.
class SubProgramItemNode : public Node {
public:
    enum type {
        func_dec,
        proc_dec,
        func_imp,
        proc_imp
    };

    type Type;
    string* name = nullptr;
    FuncParamListNode* paramlist = nullptr;
    TypeNode* varrtype = nullptr;
    DeclarationListNode* decllist = nullptr;
    StmtListNode* stmtlst = nullptr;

    // Обработчики EXCEPTION хранятся отдельно от обычных операторов.
    ExceptionHandlerListNode* exception_handlers = nullptr;

    SubProgramItemNode(
        type Type,
        string* name,
        FuncParamListNode* paramlist,
        TypeNode* varrtype,
        DeclarationListNode* decllist,
        StmtListNode* stmtlst
    );

};

// Список подпрограмм верхнего уровня.
class ItemListNode : public Node {
public:
    list<SubProgramItemNode*>* items = nullptr;

    explicit ItemListNode(SubProgramItemNode* item);
    explicit ItemListNode(ItemListNode* list);

    static ItemListNode* Append(
        ItemListNode* list,
        SubProgramItemNode* item
    );

};

// Узел объявления типа, переменной или вложенной подпрограммы.
class DeclarationNode : public Node {
public:
    enum type {
        type_dec,
        var_dec,
        subprog_dec
    };

    // Режим передачи параметра подпрограммы.
    enum ParameterMode {
        mode_default,
        mode_in,
        mode_out,
        mode_in_out
    };

    SubProgramItemNode* subprog = nullptr;

    type Type;
    TypeNode* varrtype = nullptr;
    ExprNode* expr = nullptr;
    RangeNode* rng = nullptr;
    string* name = nullptr;
    VarListNode* vlist = nullptr;
    TypeDefinitionNode* definition = nullptr;

    // Дополнительные свойства объявления.
    ParameterMode parameter_mode = mode_default;
    bool is_constant = false;

    explicit DeclarationNode(DeclarationNode::type Type);

    // Создаёт объявление вложенной функции или процедуры.
    static DeclarationNode* SubProgramDeclaration(
        SubProgramItemNode* item
    );

    // Создаёт объявление пользовательского типа.
    static DeclarationNode* TypeDeclaration(
        type Type,
        string* name,
        RangeNode* rng,
        TypeNode* varrtype
    );

    // Создаёт объявление переменных.
    static DeclarationNode* VarDeclaration(
        type Type,
        VarListNode* vlist,
        TypeNode* varrtype
    );

    // Создаёт объявление массива с диапазоном.
    static DeclarationNode* VarDeclarationArray(
        type Type,
        VarListNode* vlist,
        RangeNode* rng,
        TypeNode* varrtype
    );

    // Создаёт объявление массива с полным описанием индексов.
    static DeclarationNode* VarDeclarationArray(
        type Type,
        VarListNode* vlist,
        TypeDefinitionNode* definition,
        TypeNode* varrtype
    );

    // Создаёт объявление переменных с начальным значением.
    static DeclarationNode* VarDeclarationAssignment(
        type Type,
        VarListNode* vlist,
        TypeNode* varrtype,
        ExprNode* expr
    );

    // Устанавливает режим параметра и признак константы.
    void SetParameterProperties(
        ParameterMode mode,
        bool constant = false
    );

};

// Список объявлений в декларативной части.
class DeclarationListNode : public Node {
public:
    list<DeclarationNode*>* decs = nullptr;

    explicit DeclarationListNode(DeclarationNode* dec);
    explicit DeclarationListNode(DeclarationListNode* list);

    static DeclarationListNode* Append(
        DeclarationListNode* list,
        DeclarationNode* dec
    );

};

// Список имён переменных одного объявления.
class VarListNode : public Node {
public:
    list<VarName*>* vars = nullptr;

    explicit VarListNode(string* name);
    explicit VarListNode(VarListNode* varlst);

    static VarListNode* Append(
        VarListNode* list,
        string* name
    );

};

// Имя отдельной переменной.
class VarName : public Node {
public:
    string* name = nullptr;

    explicit VarName(string* name);
};

// Список параметров подпрограммы.
class FuncParamListNode : public Node {
public:
    list<DeclarationNode*>* params = nullptr;

    explicit FuncParamListNode(DeclarationNode* var_dec);
    explicit FuncParamListNode(FuncParamListNode* list);

    static FuncParamListNode* Append(
        FuncParamListNode* list,
        DeclarationNode* var_dec
    );

};

// Узел оператора языка Ada.
class StmtNode : public Node {
public:
    enum type {
        return_,
        whileloop,
        forloop,
        simpleLoop,
        id_,
        if_,
        exit_,
        assigment_,
        case_,
        null_
    };

    type Type;

    ExprNode* Expr = nullptr;
    ExprListNode* Expr_list = nullptr;
    string* Name = nullptr;

    ExprNode* Left_operator = nullptr;
    ExprNode* Right_operator = nullptr;

    StmtListNode* stmtlst = nullptr;
    RangeNode* rng = nullptr;

    ElseStmtNode* else_stmt = nullptr;
    ElsifStmtListNode* elsif_lst = nullptr;

    CaseAlternativeListNode* case_alternatives = nullptr;

    // Создаёт оператор возврата.
    static StmtNode* StmtFromReturn(ExprNode* Expr);

    // Создаёт цикл WHILE.
    static StmtNode* StmtFromWhileLoop(
        ExprNode* Expr,
        StmtListNode* list
    );

    // Создаёт цикл FOR.
    static StmtNode* StmtFromForLoop(
        string* name,
        RangeNode* range,
        StmtListNode* list
    );

    // Создаёт простой цикл LOOP.
    static StmtNode* StmtFromSimpleLoop(StmtListNode* list);

    // Создаёт вызов процедуры.
    static StmtNode* StmtFromIdAndExpr(
        string* Name,
        ExprListNode* Expr_list
    );

    // Создаёт условный оператор с ветвями ELSIF и ELSE.
    static StmtNode* StmtFromIfWithElsif(
        ExprNode* Expr,
        StmtListNode* list,
        ElsifStmtListNode* elsif_lst,
        ElseStmtNode* else_stmt
    );

    // Создаёт условный оператор IF с необязательной ветвью ELSE.
    static StmtNode* StmtFromIf(
        ExprNode* Expr,
        StmtListNode* list,
        ElseStmtNode* else_stmt
    );

    // Создаёт оператор EXIT.
    static StmtNode* StmtFromExit(ExprNode* Expr);

    // Создаёт оператор присваивания.
    static StmtNode* StmtFromAssigment(
        ExprNode* left,
        ExprNode* right
    );

    // Создаёт оператор CASE.
    static StmtNode* StmtFromCase(
        ExprNode* expression,
        CaseAlternativeListNode* alternatives
    );

    // Создаёт пустой оператор null.
    static StmtNode* StmtFromNull();

};

// Список ветвей ELSIF.
class ElsifStmtListNode : public Node {
public:
    list<ElsifStmtNode*>* elsifs = nullptr;

    explicit ElsifStmtListNode(ElsifStmtNode* elsif);
    explicit ElsifStmtListNode(ElsifStmtListNode* list);

    static ElsifStmtListNode* Append(
        ElsifStmtListNode* list,
        ElsifStmtNode* elsif
    );

};

// Одна ветвь ELSIF.
class ElsifStmtNode : public Node {
public:
    ExprNode* Expr = nullptr;
    StmtListNode* stmtlst = nullptr;

    ElsifStmtNode(ExprNode* expr, StmtListNode* lst);

};

// Ветка ELSE.
class ElseStmtNode : public Node {
public:
    StmtListNode* stmtlst = nullptr;

    explicit ElseStmtNode(StmtListNode* lst);
};

// Список операторов.
class StmtListNode : public Node {
public:
    list<StmtNode*>* stmts = nullptr;

    explicit StmtListNode(StmtNode* stmt);
    explicit StmtListNode(StmtListNode* list);

    static StmtListNode* Append(
        StmtListNode* list,
        StmtNode* stmt
    );

};

// Узел выражения.
class ExprNode : public Node {
public:
    enum type {
        const_bool,
        const_character,
        const_string,
        const_integer,
        const_float,

        id_,

        expr_more_expr,
        expr_less_expr,
        expr_more_equal_expr,
        expr_less_equal_expr,
        expr_equal_expr,
        expr_not_equal_expr,

        expr_plus_expr,
        expr_minus_expr,
        expr_mult_expr,
        expr_div_expr,
        expr_power_expr,
        expr_concat_expr,

        expr_abs_expr,
        uminus_expr,

        expr_or_expr,
        expr_and_expr,
        expr_xor_expr,
        not_expr,

        func_call,
        literal,
        expr_mod_expr,
        expr_rem_expr,

        // Выбор компонента: Record.Field.
        selected_component,

        // Атрибут Ada: Type'First, Array'Range и т. п.
        attribute_ref,

        // Именованная ассоциация аргумента: Name => Value.
        named_association
    };

    type Type;

    char Char = 0;
    string* String = nullptr;
    int Integer = 0;
    float Float = 0;
    bool Bool = false;

    string* Name = nullptr;
    string* Attribute = nullptr;

    ExprNode* Left_operator = nullptr;
    ExprNode* Right_operator = nullptr;
    ExprListNode* Expr_list = nullptr;

    // Создаёт символьную константу.
    static ExprNode* ExprFromCharConst(type Type, char value);

    // Создаёт логическую константу.
    static ExprNode* ExprFromBoolConst(type Type, bool value);

    // Создаёт строковую константу.
    static ExprNode* ExprFromStringConst(type Type, string* value);

    // Создаёт целочисленную константу.
    static ExprNode* ExprFromIntConst(type Type, int value);

    // Создаёт вещественную константу.
    static ExprNode* ExprFromFloatConst(type Type, float value);

    // Создаёт выражение-идентификатор.
    static ExprNode* ExprFromId(type Type, string* Name);

    // Создаёт унарную или бинарную операцию.
    static ExprNode* ExprOperation(
        type Type,
        ExprNode* left,
        ExprNode* right
    );

    // Создаёт вызов функции.
    static ExprNode* ExprFromFuncCall(
        type Type,
        string* Name,
        ExprListNode* Expr_list
    );

    // Создаёт список выражений или агрегат.
    static ExprNode* ExprFromExprLiteral(
        type Type,
        ExprListNode* Expr_list
    );

    // Создаёт выбор компонента вида Object.Field.
    static ExprNode* ExprFromSelectedComponent(
        ExprNode* prefix,
        string* component
    );

    // Создаёт ссылку на атрибут вида Type'First.
    static ExprNode* ExprFromAttribute(
        ExprNode* prefix,
        string* attribute
    );

    // Создаёт именованную ассоциацию Name => Value.
    static ExprNode* ExprFromNamedAssociation(
        string* name,
        ExprNode* value
    );

};

// Список выражений.
class ExprListNode : public Node {
public:
    list<ExprNode*>* exprs = nullptr;

    explicit ExprListNode(ExprNode* expr);
    explicit ExprListNode(ExprListNode* exprs_list);

    static ExprListNode* Append(
        ExprListNode* list,
        ExprNode* expr
    );

};

// Диапазон значений.
class RangeNode : public Node {
public:
    ExprNode* Left_operator = nullptr;
    ExprNode* Right_operator = nullptr;

    RangeNode(ExprNode* left, ExprNode* right);
};

// Узел типа данных.
class TypeNode : public Node {
public:
    enum type {
        const_bool,
        const_character,
        const_string,
        const_integer,
        const_float,
        array_,
        id_
    };

    type Type;
    string* Name = nullptr;

    explicit TypeNode(type Type);
    TypeNode(type Type, string* Name);

};

// Выводит абстрактное синтаксическое дерево в консоль.
void printTree(ProgramNode* root);
