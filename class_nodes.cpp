#include "class_nodes.h"

#include <string>
#include <iostream>

using namespace std;

int globNodeId = 0;

// Создаёт корневой узел программы.
ProgramNode::ProgramNode(ItemListNode* itemlist) {
    this->NodeId = ++globNodeId;
    this->itemlist = itemlist;
}

// Создаёт узел объявления или реализации подпрограммы.
SubProgramItemNode::SubProgramItemNode(
    type Type,
    string* name,
    FuncParamListNode* paramlist,
    TypeNode* varrtype,
    DeclarationListNode* decllist,
    StmtListNode* stmtlst
) {
    this->NodeId = ++globNodeId;
    this->Type = Type;
    this->name = name;
    this->paramlist = paramlist;
    this->varrtype = varrtype;
    this->decllist = decllist;
    this->stmtlst = stmtlst;
}

// Создаёт список подпрограмм с первым элементом.
ItemListNode::ItemListNode(SubProgramItemNode* item) {
    this->NodeId = ++globNodeId;
    this->items = new list<SubProgramItemNode*>{item};
}

// Создаёт новый узел списка, используя существующие элементы.
ItemListNode::ItemListNode(ItemListNode* list) {
    this->NodeId = ++globNodeId;
    this->items = list->items;
}

// Добавляет подпрограмму в список.
ItemListNode* ItemListNode::Append(
    ItemListNode* list,
    SubProgramItemNode* item
) {
    list->items->push_back(item);
    return list;
}

// Создаёт объявление пользовательского типа.
DeclarationNode* DeclarationNode::TypeDeclaration(
    type Type,
    string* name,
    RangeNode* rng,
    TypeNode* varrtype
) {
    DeclarationNode* dec = new DeclarationNode(DeclarationNode::type_dec);
    dec->Type = Type;
    dec->name = name;
    dec->rng = rng;
    dec->varrtype = varrtype;
    return dec;
}

// Создаёт объявление переменных.
DeclarationNode* DeclarationNode::VarDeclaration(
    type Type,
    VarListNode* vlist,
    TypeNode* varrtype
) {
    DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
    dec->vlist = vlist;
    dec->varrtype = varrtype;
    return dec;
}

// Создаёт объявление переменных с диапазоном массива.
DeclarationNode* DeclarationNode::VarDeclarationArray(
    type Type,
    VarListNode* vlist,
    RangeNode* rng,
    TypeNode* varrtype
) {
    DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
    dec->vlist = vlist;
    dec->rng = rng;
    dec->varrtype = varrtype;
    return dec;
}

// Создаёт объявление переменных с начальным значением.
DeclarationNode* DeclarationNode::VarDeclarationAssignment(
    type Type,
    VarListNode* vlist,
    TypeNode* varrtype,
    ExprNode* expr
) {
    DeclarationNode* dec = new DeclarationNode(DeclarationNode::var_dec);
    dec->vlist = vlist;
    dec->varrtype = varrtype;
    dec->expr = expr;
    return dec;
}

DeclarationNode::DeclarationNode(DeclarationNode::type Type)
{
    this->NodeId = ++globNodeId;
    this->Type = Type;
}

// Добавляет объявление в список.
DeclarationListNode* DeclarationListNode::Append(
    DeclarationListNode* list,
    DeclarationNode* dec
) {
    list->decs->push_back(dec);
    return list;
}

// Создаёт список имён переменных.
VarListNode::VarListNode(string* name) {
    VarName* var = new VarName(name);
    this->NodeId = ++globNodeId;
    this->vars = new list<VarName*>{var};
}

// Создаёт новый узел списка на основе существующего.
VarListNode::VarListNode(VarListNode* varlst) {
    this->NodeId = ++globNodeId;
    this->vars = varlst->vars;
}

// Добавляет имя переменной в список.
VarListNode* VarListNode::Append(VarListNode* list, string* name) {
    VarName* var = new VarName(name);
    list->vars->push_back(var);
    return list;
}

// Создаёт узел имени переменной.
VarName::VarName(string* name) {
    this->NodeId = ++globNodeId;
    this->name = name;
}

// Создаёт список параметров с первым параметром.
FuncParamListNode::FuncParamListNode(DeclarationNode* var_dec) {
    this->NodeId = ++globNodeId;
    this->params = new list<DeclarationNode*>{var_dec};
}

// Создаёт новый узел списка параметров.
FuncParamListNode::FuncParamListNode(FuncParamListNode* list) {
    this->NodeId = ++globNodeId;
    this->params = list->params;
}

// Добавляет параметр в список.
FuncParamListNode* FuncParamListNode::Append(
    FuncParamListNode* list,
    DeclarationNode* var_dec
) {
    list->params->push_back(var_dec);
    return list;
}

// Создаёт оператор возврата.
StmtNode* StmtNode::StmtFromReturn(ExprNode* Expr) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = return_;
    stmt->Expr = Expr;
    return stmt;
}

// Создаёт цикл while.
StmtNode* StmtNode::StmtFromWhileLoop(
    ExprNode* Expr,
    StmtListNode* list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = whileloop;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт цикл for.
StmtNode* StmtNode::StmtFromForLoop(
    string* name,
    RangeNode* range,
    StmtListNode* list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = forloop;
    stmt->Name = name;
    stmt->rng = range;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт бесконечный цикл.
StmtNode* StmtNode::StmtFromSimpleLoop(StmtListNode* list) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = simpleLoop;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт вызов процедуры или оператора с именем.
StmtNode* StmtNode::StmtFromIdAndExpr(
    string* Name,
    ExprListNode* Expr_list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = id_;
    stmt->Name = Name;
    stmt->Expr_list = Expr_list;
    return stmt;
}

// Создаёт условный оператор с ветвями elsif и else.
StmtNode* StmtNode::StmtFromIfWithElsif(
    ExprNode* Expr,
    StmtListNode* list,
    ElsifStmtListNode* elsif_lst,
    ElseStmtNode* else_stmt
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = if_;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    stmt->elsif_lst = elsif_lst;
    stmt->else_stmt = else_stmt;
    return stmt;
}

// Создаёт условный оператор if с необязательной ветвью else.
StmtNode* StmtNode::StmtFromIf(
    ExprNode* Expr,
    StmtListNode* list,
    ElseStmtNode* else_stmt
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = if_;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    stmt->else_stmt = else_stmt;
    return stmt;
}

// Создаёт оператор выхода из цикла.
StmtNode* StmtNode::StmtFromExit(ExprNode* Expr) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = exit_;
    stmt->Expr = Expr;
    return stmt;
}

// Создаёт оператор присваивания.
StmtNode* StmtNode::StmtFromAssigment(
    ExprNode* left,
    ExprNode* right
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = ++globNodeId;
    stmt->Type = assigment_;
    stmt->Left_operator = left;
    stmt->Right_operator = right;
    return stmt;
}

// Создаёт список ветвей elsif.
ElsifStmtListNode::ElsifStmtListNode(ElsifStmtNode* elsif) {
    this->NodeId = ++globNodeId;
    this->elsifs = new list<ElsifStmtNode*>{elsif};
}

// Создаёт новый узел списка ветвей elsif.
ElsifStmtListNode::ElsifStmtListNode(ElsifStmtListNode* list) {
    this->NodeId = ++globNodeId;
    this->elsifs = list->elsifs;
}

// Добавляет ветвь elsif в список.
ElsifStmtListNode* ElsifStmtListNode::Append(
    ElsifStmtListNode* list,
    ElsifStmtNode* elsif
) {
    list->elsifs->push_back(elsif);
    return list;
}

// Создаёт ветвь elsif.
ElsifStmtNode::ElsifStmtNode(ExprNode* expr, StmtListNode* lst) {
    this->NodeId = ++globNodeId;
    this->Expr = expr;
    this->stmtlst = lst;
}

// Создаёт ветвь else.
ElseStmtNode::ElseStmtNode(StmtListNode* lst) {
    this->NodeId = ++globNodeId;
    this->stmtlst = lst;
}

// Создаёт список операторов с первым элементом.
StmtListNode::StmtListNode(StmtNode* stmt) {
    this->NodeId = ++globNodeId;
    this->stmts = new list<StmtNode*>{stmt};
}

// Создаёт новый узел списка операторов.
StmtListNode::StmtListNode(StmtListNode* list) {
    this->NodeId = ++globNodeId;
    this->stmts = list->stmts;
}

// Добавляет оператор в список.
StmtListNode* StmtListNode::Append(
    StmtListNode* list,
    StmtNode* stmt
) {
    list->stmts->push_back(stmt);
    return list;
}

// Создаёт символьную константу.
ExprNode* ExprNode::ExprFromCharConst(type Type, char value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Char = value;
    return expr;
}

// Создаёт логическую константу.
ExprNode* ExprNode::ExprFromBoolConst(type Type, bool value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Bool = value;
    return expr;
}

// Создаёт строковую константу.
ExprNode* ExprNode::ExprFromStringConst(type Type, string* value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->String = value;
    return expr;
}

// Создаёт целочисленную константу.
ExprNode* ExprNode::ExprFromIntConst(type Type, int value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Integer = value;
    return expr;
}

// Создаёт вещественную константу.
ExprNode* ExprNode::ExprFromFloatConst(type Type, float value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Float = value;
    return expr;
}

// Создаёт выражение, содержащее имя переменной.
ExprNode* ExprNode::ExprFromId(type Type, string* Name) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Name = Name;
    return expr;
}

// Создаёт выражение с одним или двумя операндами.
ExprNode* ExprNode::ExprOperation(
    type Type,
    ExprNode* left,
    ExprNode* right
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Left_operator = left;
    expr->Right_operator = right;
    return expr;
}

// Создаёт выражение вызова функции.
ExprNode* ExprNode::ExprFromFuncCall(
    type Type,
    string* Name,
    ExprListNode* Expr_list
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Name = Name;
    expr->Expr_list = Expr_list;
    return expr;
}

// Создаёт выражение, состоящее из списка выражений.
ExprNode* ExprNode::ExprFromExprLiteral(
    type Type,
    ExprListNode* Expr_list
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = ++globNodeId;
    expr->Type = Type;
    expr->Expr_list = Expr_list;
    return expr;
}

// Создаёт список выражений с первым элементом.
ExprListNode::ExprListNode(ExprNode* expr) {
    this->NodeId = ++globNodeId;
    this->exprs = new list<ExprNode*>{expr};
}

// Создаёт новый узел списка выражений.
ExprListNode::ExprListNode(ExprListNode* exprs_list) {
    this->NodeId = ++globNodeId;
    this->exprs = exprs_list->exprs;
}

// Добавляет выражение в список.
ExprListNode* ExprListNode::Append(
    ExprListNode* list,
    ExprNode* expr
) {
    list->exprs->push_back(expr);
    return list;
}

// Создаёт диапазон значений.
RangeNode::RangeNode(ExprNode* left, ExprNode* right) {
    this->NodeId = ++globNodeId;
    this->Left_operator = left;
    this->Right_operator = right;
}

// Создаёт узел встроенного типа данных.
TypeNode::TypeNode(type Type) {
    this->NodeId = ++globNodeId;
    this->Type = Type;
}

// Создаёт узел именованного типа данных.
TypeNode::TypeNode(type Type, string* Name) {
    this->NodeId = ++globNodeId;
    this->Type = Type;
    this->Name = Name;
}

// Создаёт список объявлений с первым элементом.
DeclarationListNode::DeclarationListNode(DeclarationNode* dec) {
    this->NodeId = ++globNodeId;
    this->decs = new list<DeclarationNode*>{dec};
}

// Создаёт новый узел списка объявлений.
DeclarationListNode::DeclarationListNode(DeclarationListNode* list) {
    this->NodeId = ++globNodeId;
    this->decs = list->decs;
}

namespace {

// Выводит узел с отступом, соответствующим его глубине в дереве.
void printNode(const Node* node, const string& label, int depth) {
    if (!node) return;

    cout << string(static_cast<size_t>(depth) * 2, ' ')
         << label << " [id=" << node->NodeId << "]\n";
}

// Возвращает текстовое название выражения.
string expressionLabel(const ExprNode* expr) {
    if (!expr) return "Expression";

    switch (expr->Type) {
        case ExprNode::const_bool:
            return string("Boolean: ") + (expr->Bool ? "true" : "false");
        case ExprNode::const_character:
            return string("Character: ") + expr->Char;
        case ExprNode::const_string:
            return "String: " + (expr->String ? *expr->String : string(""));
        case ExprNode::const_integer:
            return "Integer: " + to_string(expr->Integer);
        case ExprNode::const_float:
            return "Float: " + to_string(expr->Float);
        case ExprNode::id_:
            return "Identifier: " + (expr->Name ? *expr->Name : string(""));
        case ExprNode::expr_plus_expr: return "Operator: +";
        case ExprNode::expr_minus_expr: return "Operator: -";
        case ExprNode::expr_mult_expr: return "Operator: *";
        case ExprNode::expr_div_expr: return "Operator: /";
        case ExprNode::expr_more_expr: return "Operator: >";
        case ExprNode::expr_less_expr: return "Operator: <";
        case ExprNode::expr_more_equal_expr: return "Operator: >=";
        case ExprNode::expr_less_equal_expr: return "Operator: <=";
        case ExprNode::expr_equal_expr: return "Operator: =";
        case ExprNode::expr_not_equal_expr: return "Operator: /=";
        case ExprNode::expr_or_expr: return "Operator: or";
        case ExprNode::expr_and_expr: return "Operator: and";
        case ExprNode::expr_xor_expr: return "Operator: xor";
        case ExprNode::not_expr: return "Operator: not";
        case ExprNode::uminus_expr: return "Unary operator: -";
        case ExprNode::expr_abs_expr: return "Operator: abs";
        case ExprNode::func_call:
            return "Function call: " + (expr->Name ? *expr->Name : string(""));
        case ExprNode::literal:
            return "Expression list";
        default:
            return "Expression";
    }
}

// Выводит выражение и его операнды.
void printExpr(const ExprNode* expr, int depth);

// Выводит список выражений.
void printExprList(const ExprListNode* exprList, int depth) {
    if (!exprList || !exprList->exprs) return;

    for (const auto* expr : *exprList->exprs) {
        printExpr(expr, depth);
    }
}

void printExpr(const ExprNode* expr, int depth) {
    if (!expr) return;

    printNode(expr, expressionLabel(expr), depth);
    printExpr(expr->Left_operator, depth + 1);
    printExpr(expr->Right_operator, depth + 1);
    printExprList(expr->Expr_list, depth + 1);
}

// Выводит диапазон и его границы.
void printRange(const RangeNode* range, int depth) {
    if (!range) return;

    printNode(range, "Range", depth);
    printExpr(range->Left_operator, depth + 1);
    printExpr(range->Right_operator, depth + 1);
}

// Выводит тип данных.
void printType(const TypeNode* type, int depth) {
    if (!type) return;

    string label;

    switch (type->Type) {
        case TypeNode::const_bool: label = "Type: Boolean"; break;
        case TypeNode::const_character: label = "Type: Character"; break;
        case TypeNode::const_string: label = "Type: String"; break;
        case TypeNode::const_integer: label = "Type: Integer"; break;
        case TypeNode::const_float: label = "Type: Float"; break;
        case TypeNode::array_: label = "Type: Array"; break;
        case TypeNode::id_:
            label = "Type: " + (type->Name ? *type->Name : string("identifier"));
            break;
    }

    printNode(type, label, depth);
}

// Выводит объявление переменной или типа.
void printDeclaration(const DeclarationNode* dec, int depth) {
    if (!dec) return;

    printNode(
        dec,
        dec->Type == DeclarationNode::type_dec
            ? "Type declaration"
            : "Variable declaration",
        depth
    );

    if (dec->name) {
        cout << string(static_cast<size_t>(depth + 1) * 2, ' ')
             << "Name: " << *dec->name << '\n';
    }

    if (dec->vlist && dec->vlist->vars) {
        for (const auto* var : *dec->vlist->vars) {
            if (var && var->name) {
                cout << string(static_cast<size_t>(depth + 1) * 2, ' ')
                     << "Variable: " << *var->name << '\n';
            }
        }
    }

    printType(dec->varrtype, depth + 1);
    printRange(dec->rng, depth + 1);
    printExpr(dec->expr, depth + 1);
}

// Выводит список объявлений.
void printDeclarationList(const DeclarationListNode* declarations, int depth) {
    if (!declarations || !declarations->decs) return;

    for (const auto* dec : *declarations->decs) {
        printDeclaration(dec, depth);
    }
}

void printStmtList(const StmtListNode* stmtList, int depth);

// Выводит оператор и его дочерние узлы.
void printStmt(const StmtNode* stmt, int depth) {
    if (!stmt) return;

    string label;

    switch (stmt->Type) {
        case StmtNode::return_: label = "Return"; break;
        case StmtNode::whileloop: label = "While loop"; break;
        case StmtNode::forloop: label = "For loop"; break;
        case StmtNode::simpleLoop: label = "Loop"; break;
        case StmtNode::id_:
            label = "Call: " + (stmt->Name ? *stmt->Name : string(""));
            break;
        case StmtNode::if_: label = "If statement"; break;
        case StmtNode::exit_: label = "Exit"; break;
        case StmtNode::assigment_: label = "Assignment"; break;
    }

    printNode(stmt, label, depth);

    if (stmt->Name && stmt->Type == StmtNode::forloop) {
        cout << string(static_cast<size_t>(depth + 1) * 2, ' ')
             << "Iterator: " << *stmt->Name << '\n';
    }

    printExpr(stmt->Expr, depth + 1);
    printExpr(stmt->Left_operator, depth + 1);
    printExpr(stmt->Right_operator, depth + 1);
    printExprList(stmt->Expr_list, depth + 1);
    printRange(stmt->rng, depth + 1);
    printStmtList(stmt->stmtlst, depth + 1);

    if (stmt->elsif_lst && stmt->elsif_lst->elsifs) {
        for (const auto* branch : *stmt->elsif_lst->elsifs) {
            if (!branch) continue;

            printNode(branch, "Elsif branch", depth + 1);
            printExpr(branch->Expr, depth + 2);
            printStmtList(branch->stmtlst, depth + 2);
        }
    }

    if (stmt->else_stmt) {
        printNode(stmt->else_stmt, "Else branch", depth + 1);
        printStmtList(stmt->else_stmt->stmtlst, depth + 2);
    }
}

// Выводит список операторов.
void printStmtList(const StmtListNode* stmtList, int depth) {
    if (!stmtList || !stmtList->stmts) return;

    for (const auto* stmt : *stmtList->stmts) {
        printStmt(stmt, depth);
    }
}

}

// Выводит AST программы в консоль.
void printTree(ProgramNode* root) {
    if (!root) {
        cout << "AST is empty: parsing did not produce a program.\n";
        return;
    }

    cout << "\n=== Abstract Syntax Tree ===\n";
    printNode(root, "Program", 0);

    if (!root->itemlist || !root->itemlist->items) {
        cout << "=== End of AST ===\n";
        return;
    }

    for (const auto* item : *root->itemlist->items) {
        if (!item) continue;

        string label;

        switch (item->Type) {
            case SubProgramItemNode::func_dec:
                label = "Function declaration";
                break;
            case SubProgramItemNode::proc_dec:
                label = "Procedure declaration";
                break;
            case SubProgramItemNode::func_imp:
                label = "Function implementation";
                break;
            case SubProgramItemNode::proc_imp:
                label = "Procedure implementation";
                break;
        }

        if (item->name) {
            label += ": " + *item->name;
        }

        printNode(item, label, 1);

        if (item->paramlist && item->paramlist->params) {
            for (const auto* param : *item->paramlist->params) {
                printDeclaration(param, 2);
            }
        }

        printType(item->varrtype, 2);
        printDeclarationList(item->decllist, 2);
        printStmtList(item->stmtlst, 2);
    }

    cout << "=== End of AST ===\n";
}