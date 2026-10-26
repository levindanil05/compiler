#include "class_nodes.h"

#include <string>
#include <iostream>
#include <stack>

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

DeclarationNode* DeclarationNode::SubProgramDeclaration(SubProgramItemNode* item) {
    DeclarationNode* dec = new DeclarationNode(DeclarationNode::subprog_dec);
    dec->subprog = item;
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

// Структура для хранения задачи в стеке
struct TraversalTask {
    enum Type { PROGRAM, ITEM, ITEM_LIST, DECL, DECL_LIST, STMT, STMT_LIST, EXPR, EXPR_LIST, TYPE, RANGE, ELSE_STMT, ELSIF_STMT } type;
    void* node;
    int depth;
};

// Итеративный вывод дерева (без рекурсии)
void printTree(ProgramNode* root) {
    if (!root) {
        cout << "AST is empty: parsing did not produce a program.\n";
        return;
    }

    cout << "\n=== Abstract Syntax Tree ===\n";
    cout << "Program [id=" << root->NodeId << "]\n";

    if (!root->itemlist || !root->itemlist->items) {
        cout << "=== End of AST ===\n";
        return;
    }

    std::stack<TraversalTask> stack;

    // Кладем элементы в стек в ОБРАТНОМ порядке, чтобы они выводились слева направо
    for (auto it = root->itemlist->items->rbegin(); it != root->itemlist->items->rend(); ++it) {
        stack.push({TraversalTask::ITEM, *it, 1});
    }

    while (!stack.empty()) {
        TraversalTask task = stack.top();
        stack.pop();

        string indent(task.depth * 2, ' ');

        if (task.type == TraversalTask::ITEM) {
            auto* item = static_cast<SubProgramItemNode*>(task.node);
            if (!item) continue;

            string label = "SubProgram";
            if (item->Type == SubProgramItemNode::func_dec) label = "Function declaration";
            if (item->Type == SubProgramItemNode::proc_dec) label = "Procedure declaration";
            if (item->Type == SubProgramItemNode::func_imp) label = "Function implementation";
            if (item->Type == SubProgramItemNode::proc_imp) label = "Procedure implementation";
            
            if (item->name) label += ": " + *item->name;
            cout << indent << label << " [id=" << item->NodeId << "]\n";

            if (item->stmtlst) stack.push({TraversalTask::STMT_LIST, item->stmtlst, task.depth + 1});
            if (item->decllist) stack.push({TraversalTask::DECL_LIST, item->decllist, task.depth + 1});
            if (item->varrtype) stack.push({TraversalTask::TYPE, item->varrtype, task.depth + 1});
            
            if (item->paramlist && item->paramlist->params) {
                for (auto p_it = item->paramlist->params->rbegin(); p_it != item->paramlist->params->rend(); ++p_it) {
                     stack.push({TraversalTask::DECL, *p_it, task.depth + 1});
                }
            }
        } 
        else if (task.type == TraversalTask::STMT_LIST) {
            auto* list = static_cast<StmtListNode*>(task.node);
            if (!list || !list->stmts) continue;
            for (auto it = list->stmts->rbegin(); it != list->stmts->rend(); ++it) {
                stack.push({TraversalTask::STMT, *it, task.depth});
            }
        }
        else if (task.type == TraversalTask::STMT) {
            auto* stmt = static_cast<StmtNode*>(task.node);
            if (!stmt) continue;
            
            string label = "Statement";
            if (stmt->Type == StmtNode::return_) label = "Return";
            if (stmt->Type == StmtNode::whileloop) label = "While loop";
            if (stmt->Type == StmtNode::forloop) label = "For loop";
            if (stmt->Type == StmtNode::simpleLoop) label = "Loop";
            if (stmt->Type == StmtNode::if_) label = "If statement";
            if (stmt->Type == StmtNode::exit_) label = "Exit";
            if (stmt->Type == StmtNode::assigment_) label = "Assignment";
            if (stmt->Type == StmtNode::id_) label = "Call: " + (stmt->Name ? *stmt->Name : string(""));
            
            cout << indent << label << " [id=" << stmt->NodeId << "]\n";

            if (stmt->else_stmt) stack.push({TraversalTask::ELSE_STMT, stmt->else_stmt, task.depth + 1});
            if (stmt->elsif_lst && stmt->elsif_lst->elsifs) {
                for (auto it = stmt->elsif_lst->elsifs->rbegin(); it != stmt->elsif_lst->elsifs->rend(); ++it) {
                    stack.push({TraversalTask::ELSIF_STMT, *it, task.depth + 1});
                }
            }
            if (stmt->stmtlst) stack.push({TraversalTask::STMT_LIST, stmt->stmtlst, task.depth + 1});
            if (stmt->rng) stack.push({TraversalTask::RANGE, stmt->rng, task.depth + 1});
            if (stmt->Expr_list && stmt->Expr_list->exprs) {
                for (auto it = stmt->Expr_list->exprs->rbegin(); it != stmt->Expr_list->exprs->rend(); ++it) {
                    stack.push({TraversalTask::EXPR, *it, task.depth + 1});
                }
            }
            if (stmt->Right_operator) stack.push({TraversalTask::EXPR, stmt->Right_operator, task.depth + 1});
            if (stmt->Left_operator) stack.push({TraversalTask::EXPR, stmt->Left_operator, task.depth + 1});
            if (stmt->Expr) stack.push({TraversalTask::EXPR, stmt->Expr, task.depth + 1});
        }
		    else if (task.type == TraversalTask::ELSE_STMT) {
            auto* els = static_cast<ElseStmtNode*>(task.node);
            if (!els) continue;
            cout << indent << "Else branch [id=" << els->NodeId << "]\n";
            if (els->stmtlst) stack.push({TraversalTask::STMT_LIST, els->stmtlst, task.depth + 1});
        }
        else if (task.type == TraversalTask::ELSIF_STMT) {
            auto* elsf = static_cast<ElsifStmtNode*>(task.node);
            if (!elsf) continue;
            cout << indent << "Elsif branch [id=" << elsf->NodeId << "]\n";
            if (elsf->stmtlst) stack.push({TraversalTask::STMT_LIST, elsf->stmtlst, task.depth + 1});
            if (elsf->Expr) stack.push({TraversalTask::EXPR, elsf->Expr, task.depth + 1});
        }
        else if (task.type == TraversalTask::EXPR) {
            auto* expr = static_cast<ExprNode*>(task.node);
            if (!expr) continue;
            
            string label = "Expression";
            if (expr->Type == ExprNode::const_bool) label = "Boolean: " + string(expr->Bool ? "true" : "false");
            if (expr->Type == ExprNode::const_character) label = "Character: " + string(1, expr->Char);
            if (expr->Type == ExprNode::const_string) label = "String: " + (expr->String ? *expr->String : string(""));
            if (expr->Type == ExprNode::const_integer) label = "Integer: " + to_string(expr->Integer);
            if (expr->Type == ExprNode::const_float) label = "Float: " + to_string(expr->Float);
            if (expr->Type == ExprNode::id_) label = "Identifier: " + (expr->Name ? *expr->Name : string(""));
            if (expr->Type == ExprNode::expr_plus_expr) label = "Operator: +";
            if (expr->Type == ExprNode::expr_minus_expr) label = "Operator: -";
            if (expr->Type == ExprNode::expr_mult_expr) label = "Operator: *";
            if (expr->Type == ExprNode::expr_div_expr) label = "Operator: /";
			if (expr->Type == ExprNode::expr_mod_expr) label = "Operator: mod";
            if (expr->Type == ExprNode::expr_rem_expr) label = "Operator: rem";
            if (expr->Type == ExprNode::expr_more_expr) label = "Operator: >";
            if (expr->Type == ExprNode::expr_less_expr) label = "Operator: <";
            if (expr->Type == ExprNode::expr_more_equal_expr) label = "Operator: >=";
            if (expr->Type == ExprNode::expr_less_equal_expr) label = "Operator: <=";
            if (expr->Type == ExprNode::expr_equal_expr) label = "Operator: =";
            if (expr->Type == ExprNode::expr_not_equal_expr) label = "Operator: /=";
            if (expr->Type == ExprNode::expr_or_expr) label = "Operator: or";
            if (expr->Type == ExprNode::expr_and_expr) label = "Operator: and";
            if (expr->Type == ExprNode::expr_xor_expr) label = "Operator: xor";
            if (expr->Type == ExprNode::not_expr) label = "Operator: not";
            if (expr->Type == ExprNode::uminus_expr) label = "Unary operator: -";
            if (expr->Type == ExprNode::expr_abs_expr) label = "Operator: abs";
            if (expr->Type == ExprNode::func_call) label = "Function call: " + (expr->Name ? *expr->Name : string(""));
            if (expr->Type == ExprNode::literal) label = "Expression list";
            
            cout << indent << label << " [id=" << expr->NodeId << "]\n";

            if (expr->Expr_list && expr->Expr_list->exprs) {
                for (auto it = expr->Expr_list->exprs->rbegin(); it != expr->Expr_list->exprs->rend(); ++it) {
                    stack.push({TraversalTask::EXPR, *it, task.depth + 1});
                }
            }
            if (expr->Right_operator) stack.push({TraversalTask::EXPR, expr->Right_operator, task.depth + 1});
            if (expr->Left_operator) stack.push({TraversalTask::EXPR, expr->Left_operator, task.depth + 1});
        }
        else if (task.type == TraversalTask::TYPE) {
            auto* type = static_cast<TypeNode*>(task.node);
            if (!type) continue;
            string label = "Type";
            if (type->Type == TypeNode::const_bool) label = "Type: Boolean";
            if (type->Type == TypeNode::const_character) label = "Type: Character";
            if (type->Type == TypeNode::const_string) label = "Type: String";
            if (type->Type == TypeNode::const_integer) label = "Type: Integer";
            if (type->Type == TypeNode::const_float) label = "Type: Float";
            if (type->Type == TypeNode::array_) label = "Type: Array";
            if (type->Type == TypeNode::id_) label = "Type: " + (type->Name ? *type->Name : string("identifier"));
            cout << indent << label << " [id=" << type->NodeId << "]\n";
        }
        else if (task.type == TraversalTask::RANGE) {
            auto* rng = static_cast<RangeNode*>(task.node);
            if (!rng) continue;
            cout << indent << "Range [id=" << rng->NodeId << "]\n";
            if (rng->Right_operator) stack.push({TraversalTask::EXPR, rng->Right_operator, task.depth + 1});
            if (rng->Left_operator) stack.push({TraversalTask::EXPR, rng->Left_operator, task.depth + 1});
        }
        else if (task.type == TraversalTask::DECL_LIST) {
            auto* list = static_cast<DeclarationListNode*>(task.node);
            if (!list || !list->decs) continue;
            for (auto it = list->decs->rbegin(); it != list->decs->rend(); ++it) {
                stack.push({TraversalTask::DECL, *it, task.depth});
            }
        }
                else if (task.type == TraversalTask::DECL) {
            auto* dec = static_cast<DeclarationNode*>(task.node);
            if (!dec) continue;

            if (dec->Type == DeclarationNode::subprog_dec) {
                auto* item = dec->subprog;
                string label = "SubProgram";
                if (item->Type == SubProgramItemNode::func_dec) label = "Function declaration";
                if (item->Type == SubProgramItemNode::proc_dec) label = "Procedure declaration";
                if (item->Type == SubProgramItemNode::func_imp) label = "Function implementation";
                if (item->Type == SubProgramItemNode::proc_imp) label = "Procedure implementation";
                if (item->name) label += ": " + *item->name;
                cout << indent << label << " [id=" << item->NodeId << "]\n";

                if (item->stmtlst) stack.push(TraversalTask{TraversalTask::STMT_LIST, item->stmtlst, task.depth + 1});
                if (item->decllist) stack.push(TraversalTask{TraversalTask::DECL_LIST, item->decllist, task.depth + 1});
                if (item->varrtype) stack.push(TraversalTask{TraversalTask::TYPE, item->varrtype, task.depth + 1});
                if (item->paramlist && item->paramlist->params) {
                    for (auto p_it = item->paramlist->params->rbegin(); p_it != item->paramlist->params->rend(); ++p_it) {
                         stack.push(TraversalTask{TraversalTask::DECL, *p_it, task.depth + 1});
                    }
                }
                continue; 
            }

            string label = (dec->Type == DeclarationNode::type_dec) ? "Type declaration" : "Variable declaration";
            cout << indent << label << " [id=" << dec->NodeId << "]\n";
            
            if (dec->expr) stack.push(TraversalTask{TraversalTask::EXPR, dec->expr, task.depth + 1});
            if (dec->rng) stack.push(TraversalTask{TraversalTask::RANGE, dec->rng, task.depth + 1});
            if (dec->varrtype) stack.push(TraversalTask{TraversalTask::TYPE, dec->varrtype, task.depth + 1});
            if (dec->vlist && dec->vlist->vars) {
                for (auto it = dec->vlist->vars->begin(); it != dec->vlist->vars->end(); ++it) {
                    if (*it && (*it)->name) {
                         cout << string((task.depth + 1) * 2, ' ') << "Variable: " << *((*it)->name) << '\n';
                    }
                }
            }
            if (dec->name) {
                cout << string((task.depth + 1) * 2, ' ') << "Name: " << *dec->name << '\n';
            }
        }
    }
    cout << "=== End of AST ===\n";
}