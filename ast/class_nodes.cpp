
#include "class_nodes.h"
#include "ast_extensions.h"

#include <iostream>
#include <string>

using namespace std;

// Единый счётчик идентификаторов узлов AST.
static int globNodeId = 0;

// Выдаёт следующий уникальный идентификатор узла.
static int nextNodeId() {
    return ++globNodeId;
}

// Возвращает отступ для заданной глубины дерева.
static string indent(int depth) {
    return string(static_cast<size_t>(depth) * 2, ' ');
}

// Печатает заголовок узла с его идентификатором.
static void printNodeLabel(
    int depth,
    const string& label,
    int nodeId
) {
    cout << indent(depth) << label
         << " [id=" << nodeId << "]\n";
}

// Создаёт корневой узел программы.
ProgramNode::ProgramNode(ItemListNode* itemlist) {
    NodeId = nextNodeId();
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
    NodeId = nextNodeId();
    this->Type = Type;
    this->name = name;
    this->paramlist = paramlist;
    this->varrtype = varrtype;
    this->decllist = decllist;
    this->stmtlst = stmtlst;
}

// Создаёт список подпрограмм с первым элементом.
ItemListNode::ItemListNode(SubProgramItemNode* item) {
    NodeId = nextNodeId();
    items = new list<SubProgramItemNode*>{item};
}

// Создаёт новый узел списка на основе существующего списка.
ItemListNode::ItemListNode(ItemListNode* source) {
    NodeId = nextNodeId();
    items = source ? source->items : new list<SubProgramItemNode*>();
}

// Добавляет подпрограмму в список.
ItemListNode* ItemListNode::Append(
    ItemListNode* source,
    SubProgramItemNode* item
) {
    if (!source) {
        return new ItemListNode(item);
    }

    if (source->items) {
        source->items->push_back(item);
    }

    return source;
}

// Создаёт узел объявления.
DeclarationNode::DeclarationNode(DeclarationNode::type Type) {
    NodeId = nextNodeId();
    this->Type = Type;
}

// Создаёт объявление вложенной подпрограммы.
DeclarationNode* DeclarationNode::SubProgramDeclaration(
    SubProgramItemNode* item
) {
    DeclarationNode* dec = new DeclarationNode(subprog_dec);
    dec->subprog = item;
    return dec;
}

// Создаёт объявление пользовательского типа.
DeclarationNode* DeclarationNode::TypeDeclaration(
    type Type,
    string* name,
    RangeNode* rng,
    TypeNode* varrtype
) {
    DeclarationNode* dec = new DeclarationNode(type_dec);
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
    DeclarationNode* dec = new DeclarationNode(var_dec);
    dec->Type = Type;
    dec->vlist = vlist;
    dec->varrtype = varrtype;
    return dec;
}

// Создаёт объявление массива с диапазоном.
DeclarationNode* DeclarationNode::VarDeclarationArray(
    type Type,
    VarListNode* vlist,
    RangeNode* rng,
    TypeNode* varrtype
) {
    DeclarationNode* dec = new DeclarationNode(var_dec);
    dec->Type = Type;
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
    DeclarationNode* dec = new DeclarationNode(var_dec);
    dec->Type = Type;
    dec->vlist = vlist;
    dec->varrtype = varrtype;
    dec->expr = expr;
    return dec;
}

// Устанавливает режим параметра и признак константы.
void DeclarationNode::SetParameterProperties(
    ParameterMode mode,
    bool constant
) {
    parameter_mode = mode;
    is_constant = constant;
}

// Создаёт список объявлений с первым элементом.
DeclarationListNode::DeclarationListNode(DeclarationNode* dec) {
    NodeId = nextNodeId();
    decs = new list<DeclarationNode*>{dec};
}

// Создаёт новый узел списка объявлений.
DeclarationListNode::DeclarationListNode(DeclarationListNode* source) {
    NodeId = nextNodeId();
    decs = source ? source->decs : new list<DeclarationNode*>();
}

// Добавляет объявление в список.
DeclarationListNode* DeclarationListNode::Append(
    DeclarationListNode* source,
    DeclarationNode* dec
) {
    if (!source) {
        return new DeclarationListNode(dec);
    }

    if (source->decs) {
        source->decs->push_back(dec);
    }

    return source;
}

// Создаёт список имён переменных.
VarListNode::VarListNode(string* name) {
    NodeId = nextNodeId();
    vars = new list<VarName*>{new VarName(name)};
}

// Создаёт новый список на основе существующего.
VarListNode::VarListNode(VarListNode* source) {
    NodeId = nextNodeId();
    vars = source ? source->vars : new list<VarName*>();
}

// Добавляет имя переменной в список.
VarListNode* VarListNode::Append(
    VarListNode* source,
    string* name
) {
    if (!source) {
        return new VarListNode(name);
    }

    if (source->vars) {
        source->vars->push_back(new VarName(name));
    }

    return source;
}

// Создаёт узел имени переменной.
VarName::VarName(string* name) {
    NodeId = nextNodeId();
    this->name = name;
}

// Создаёт список параметров с первым параметром.
FuncParamListNode::FuncParamListNode(DeclarationNode* var_dec) {
    NodeId = nextNodeId();
    params = new list<DeclarationNode*>{var_dec};
}

// Создаёт новый список параметров на основе существующего.
FuncParamListNode::FuncParamListNode(FuncParamListNode* source) {
    NodeId = nextNodeId();
    params = source ? source->params : new list<DeclarationNode*>();
}

// Добавляет параметр в список.
FuncParamListNode* FuncParamListNode::Append(
    FuncParamListNode* source,
    DeclarationNode* var_dec
) {
    if (!source) {
        return new FuncParamListNode(var_dec);
    }

    if (source->params) {
        source->params->push_back(var_dec);
    }

    return source;
}

// Создаёт оператор возврата.
StmtNode* StmtNode::StmtFromReturn(ExprNode* Expr) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = return_;
    stmt->Expr = Expr;
    return stmt;
}

// Создаёт цикл WHILE.
StmtNode* StmtNode::StmtFromWhileLoop(
    ExprNode* Expr,
    StmtListNode* list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = whileloop;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт цикл FOR.
StmtNode* StmtNode::StmtFromForLoop(
    string* name,
    RangeNode* range,
    StmtListNode* list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = forloop;
    stmt->Name = name;
    stmt->rng = range;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт простой цикл LOOP.
StmtNode* StmtNode::StmtFromSimpleLoop(StmtListNode* list) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = simpleLoop;
    stmt->stmtlst = list;
    return stmt;
}

// Создаёт вызов процедуры.
StmtNode* StmtNode::StmtFromIdAndExpr(
    string* Name,
    ExprListNode* Expr_list
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = id_;
    stmt->Name = Name;
    stmt->Expr_list = Expr_list;
    return stmt;
}

// Создаёт IF с ветвями ELSIF и ELSE.
StmtNode* StmtNode::StmtFromIfWithElsif(
    ExprNode* Expr,
    StmtListNode* list,
    ElsifStmtListNode* elsif_lst,
    ElseStmtNode* else_stmt
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = if_;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    stmt->elsif_lst = elsif_lst;
    stmt->else_stmt = else_stmt;
    return stmt;
}

// Создаёт IF с необязательной ветвью ELSE.
StmtNode* StmtNode::StmtFromIf(
    ExprNode* Expr,
    StmtListNode* list,
    ElseStmtNode* else_stmt
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = if_;
    stmt->Expr = Expr;
    stmt->stmtlst = list;
    stmt->else_stmt = else_stmt;
    return stmt;
}

// Создаёт оператор EXIT.
StmtNode* StmtNode::StmtFromExit(ExprNode* Expr) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
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
    stmt->NodeId = nextNodeId();
    stmt->Type = assigment_;
    stmt->Left_operator = left;
    stmt->Right_operator = right;
    return stmt;
}

// Создаёт оператор CASE.
StmtNode* StmtNode::StmtFromCase(
    ExprNode* expression,
    CaseAlternativeListNode* alternatives
) {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = case_;
    stmt->Expr = expression;
    stmt->case_alternatives = alternatives;
    return stmt;
}

// Создаёт пустой оператор NULL.
StmtNode* StmtNode::StmtFromNull() {
    StmtNode* stmt = new StmtNode();
    stmt->NodeId = nextNodeId();
    stmt->Type = null_;
    return stmt;
}

// Создаёт список ветвей ELSIF.
ElsifStmtListNode::ElsifStmtListNode(ElsifStmtNode* elsif) {
    NodeId = nextNodeId();
    elsifs = new list<ElsifStmtNode*>{elsif};
}

// Создаёт новый список ветвей ELSIF.
ElsifStmtListNode::ElsifStmtListNode(ElsifStmtListNode* source) {
    NodeId = nextNodeId();
    elsifs = source ? source->elsifs : new list<ElsifStmtNode*>();
}

// Добавляет ветвь ELSIF.
ElsifStmtListNode* ElsifStmtListNode::Append(
    ElsifStmtListNode* source,
    ElsifStmtNode* elsif
) {
    if (!source) {
        return new ElsifStmtListNode(elsif);
    }

    if (source->elsifs) {
        source->elsifs->push_back(elsif);
    }

    return source;
}

// Создаёт ветвь ELSIF.
ElsifStmtNode::ElsifStmtNode(ExprNode* expr, StmtListNode* lst) {
    NodeId = nextNodeId();
    Expr = expr;
    stmtlst = lst;
}

// Создаёт ветвь ELSE.
ElseStmtNode::ElseStmtNode(StmtListNode* lst) {
    NodeId = nextNodeId();
    stmtlst = lst;
}

// Создаёт список операторов с первым элементом.
StmtListNode::StmtListNode(StmtNode* stmt) {
    NodeId = nextNodeId();
    stmts = new list<StmtNode*>{stmt};
}

// Создаёт новый список операторов на основе существующего.
StmtListNode::StmtListNode(StmtListNode* source) {
    NodeId = nextNodeId();
    stmts = source ? source->stmts : new list<StmtNode*>();
}

// Добавляет оператор в список.
StmtListNode* StmtListNode::Append(
    StmtListNode* source,
    StmtNode* stmt
) {
    if (!source) {
        return new StmtListNode(stmt);
    }

    if (source->stmts) {
        source->stmts->push_back(stmt);
    }

    return source;
}

// Создаёт символьную константу.
ExprNode* ExprNode::ExprFromCharConst(type Type, char value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Char = value;
    return expr;
}

// Создаёт логическую константу.
ExprNode* ExprNode::ExprFromBoolConst(type Type, bool value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Bool = value;
    return expr;
}

// Создаёт строковую константу.
ExprNode* ExprNode::ExprFromStringConst(type Type, string* value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->String = value;
    return expr;
}

// Создаёт целочисленную константу.
ExprNode* ExprNode::ExprFromIntConst(type Type, int value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Integer = value;
    return expr;
}

// Создаёт вещественную константу.
ExprNode* ExprNode::ExprFromFloatConst(type Type, float value) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Float = value;
    return expr;
}

// Создаёт выражение-идентификатор.
ExprNode* ExprNode::ExprFromId(type Type, string* Name) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Name = Name;
    return expr;
}

// Создаёт унарную или бинарную операцию.
ExprNode* ExprNode::ExprOperation(
    type Type,
    ExprNode* left,
    ExprNode* right
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Left_operator = left;
    expr->Right_operator = right;
    return expr;
}

// Создаёт вызов функции.
ExprNode* ExprNode::ExprFromFuncCall(
    type Type,
    string* Name,
    ExprListNode* Expr_list
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Name = Name;
    expr->Expr_list = Expr_list;
    return expr;
}

// Создаёт список выражений или агрегат.
ExprNode* ExprNode::ExprFromExprLiteral(
    type Type,
    ExprListNode* Expr_list
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = Type;
    expr->Expr_list = Expr_list;
    return expr;
}

// Создаёт выбор компонента Object.Field.
ExprNode* ExprNode::ExprFromSelectedComponent(
    ExprNode* prefix,
    string* component
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = selected_component;
    expr->Left_operator = prefix;
    expr->Name = component;
    return expr;
}

// Создаёт ссылку на атрибут Type'First.
ExprNode* ExprNode::ExprFromAttribute(
    ExprNode* prefix,
    string* attribute
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = attribute_ref;
    expr->Left_operator = prefix;
    expr->Attribute = attribute;
    return expr;
}

// Создаёт именованную ассоциацию Name => Value.
ExprNode* ExprNode::ExprFromNamedAssociation(
    string* name,
    ExprNode* value
) {
    ExprNode* expr = new ExprNode();
    expr->NodeId = nextNodeId();
    expr->Type = named_association;
    expr->Name = name;
    expr->Right_operator = value;
    return expr;
}

// Создаёт список выражений с первым элементом.
ExprListNode::ExprListNode(ExprNode* expr) {
    NodeId = nextNodeId();
    exprs = new list<ExprNode*>{expr};
}

// Создаёт новый список выражений на основе существующего.
ExprListNode::ExprListNode(ExprListNode* source) {
    NodeId = nextNodeId();
    exprs = source ? source->exprs : new list<ExprNode*>();
}

// Добавляет выражение в список.
ExprListNode* ExprListNode::Append(
    ExprListNode* source,
    ExprNode* expr
) {
    if (!source) {
        return new ExprListNode(expr);
    }

    if (source->exprs) {
        source->exprs->push_back(expr);
    }

    return source;
}

// Создаёт диапазон значений.
RangeNode::RangeNode(ExprNode* left, ExprNode* right) {
    NodeId = nextNodeId();
    Left_operator = left;
    Right_operator = right;
}

// Создаёт узел встроенного типа.
TypeNode::TypeNode(type Type) {
    NodeId = nextNodeId();
    this->Type = Type;
}

// Создаёт узел именованного типа.
TypeNode::TypeNode(type Type, string* Name) {
    NodeId = nextNodeId();
    this->Type = Type;
    this->Name = Name;
}

// Печатает список выражений в исходном порядке.
static void printExprList(ExprListNode* listNode, int depth);

// Печатает диапазон и его границы.
static void printRange(RangeNode* range, int depth);

// Печатает определение пользовательского типа.
static void printTypeDefinition(TypeDefinitionNode* definition, int depth);

// Печатает объявление, включая вложенные подпрограммы.
static void printDeclaration(DeclarationNode* dec, int depth);

// Печатает список объявлений.
static void printDeclarationList(DeclarationListNode* listNode, int depth);

// Печатает список операторов.
static void printStmtList(StmtListNode* listNode, int depth);

// Печатает узел выражения и его дочерние узлы.
static void printExpr(ExprNode* expr, int depth);

// Печатает альтернативы оператора CASE.
static void printCaseAlternatives(
    CaseAlternativeListNode* alternatives,
    int depth
);

// Печатает одну подпрограмму.
static void printSubProgram(SubProgramItemNode* item, int depth);

// Печатает тип данных.
static void printType(TypeNode* type, int depth) {
    if (!type) return;

    string label = "Type";

    switch (type->Type) {
        case TypeNode::const_bool:      label = "Type: Boolean"; break;
        case TypeNode::const_character: label = "Type: Character"; break;
        case TypeNode::const_string:    label = "Type: String"; break;
        case TypeNode::const_integer:   label = "Type: Integer"; break;
        case TypeNode::const_float:     label = "Type: Float"; break;
        case TypeNode::array_:          label = "Type: Array"; break;
        case TypeNode::id_:
            label = "Type: " + (type->Name ? *type->Name : string("<unnamed>"));
            break;
    }

    printNodeLabel(depth, label, type->NodeId);
}

// Печатает диапазон значений.
static void printRange(RangeNode* range, int depth) {
    if (!range) return;

    printNodeLabel(depth, "Range", range->NodeId);
    printExpr(range->Left_operator, depth + 1);
    printExpr(range->Right_operator, depth + 1);
}

// Печатает список выражений.
static void printExprList(ExprListNode* listNode, int depth) {
    if (!listNode || !listNode->exprs) return;

    printNodeLabel(depth, "Expression list", listNode->NodeId);

    for (ExprNode* expr : *listNode->exprs) {
        printExpr(expr, depth + 1);
    }
}

// Печатает выражение.
static void printExpr(ExprNode* expr, int depth) {
    if (!expr) return;

    string label = "Expression";

    switch (expr->Type) {
        case ExprNode::const_bool:
            label = string("Boolean: ") + (expr->Bool ? "true" : "false");
            break;

        case ExprNode::const_character:
            label = "Character: " + string(1, expr->Char);
            break;

        case ExprNode::const_string:
            label = "String: " + (expr->String ? *expr->String : string());
            break;

        case ExprNode::const_integer:
            label = "Integer: " + to_string(expr->Integer);
            break;

        case ExprNode::const_float:
            label = "Float: " + to_string(expr->Float);
            break;

        case ExprNode::id_:
            label = "Identifier: " + (expr->Name ? *expr->Name : string());
            break;

        case ExprNode::expr_more_expr:       label = "Operator: >"; break;
        case ExprNode::expr_less_expr:       label = "Operator: <"; break;
        case ExprNode::expr_more_equal_expr: label = "Operator: >="; break;
        case ExprNode::expr_less_equal_expr: label = "Operator: <="; break;
        case ExprNode::expr_equal_expr:      label = "Operator: ="; break;
        case ExprNode::expr_not_equal_expr:  label = "Operator: /="; break;
        case ExprNode::expr_plus_expr:       label = "Operator: +"; break;
        case ExprNode::expr_minus_expr:      label = "Operator: -"; break;
        case ExprNode::expr_mult_expr:       label = "Operator: *"; break;
        case ExprNode::expr_div_expr:        label = "Operator: /"; break;
        case ExprNode::expr_power_expr:      label = "Operator: **"; break;
        case ExprNode::expr_concat_expr:     label = "Operator: &"; break;
        case ExprNode::expr_abs_expr:        label = "Operator: abs"; break;
        case ExprNode::uminus_expr:          label = "Unary operator: -"; break;
        case ExprNode::expr_or_expr:         label = "Operator: or"; break;
        case ExprNode::expr_and_expr:        label = "Operator: and"; break;
        case ExprNode::expr_xor_expr:        label = "Operator: xor"; break;
        case ExprNode::not_expr:             label = "Operator: not"; break;
        case ExprNode::expr_mod_expr:        label = "Operator: mod"; break;
        case ExprNode::expr_rem_expr:        label = "Operator: rem"; break;

        case ExprNode::func_call:
            label = "Function call: " + (expr->Name ? *expr->Name : string());
            break;

        case ExprNode::literal:
            label = "Aggregate / expression list";
            break;

        case ExprNode::selected_component:
            label = "Selected component: " +
                (expr->Name ? *expr->Name : string());
            break;

        case ExprNode::attribute_ref:
            label = "Attribute: " +
                (expr->Attribute ? *expr->Attribute : string());
            break;

        case ExprNode::named_association:
            label = "Named association: " +
                (expr->Name ? *expr->Name : string());
            break;
    }

    printNodeLabel(depth, label, expr->NodeId);

    printExpr(expr->Left_operator, depth + 1);
    printExpr(expr->Right_operator, depth + 1);
    printExprList(expr->Expr_list, depth + 1);
}

// Печатает определение массива, перечисления или записи.
static void printTypeDefinition(
    TypeDefinitionNode* definition,
    int depth
) {
    if (!definition) return;

    string label = "Type definition";

    switch (definition->kind) {
        case TypeDefinitionNode::array_type:
            label = "Array type definition";
            break;
        case TypeDefinitionNode::enum_type:
            label = "Enumeration type definition";
            break;
        case TypeDefinitionNode::record_type:
            label = "Record type definition";
            break;
    }

    printNodeLabel(depth, label, definition->NodeId);

    if (definition->indexes) {
        for (ArrayIndexNode* index : *definition->indexes) {
            if (!index) continue;

            printNodeLabel(
                depth + 1,
                index->unconstrained ? "Unconstrained array index"
                                     : "Array index",
                index->NodeId
            );

            printType(index->index_type, depth + 2);
            printRange(index->range, depth + 2);
        }
    }

    if (definition->literals) {
        for (string* literal : *definition->literals) {
            cout << indent(depth + 1) << "Enumeration literal: "
                 << (literal ? *literal : string()) << '\n';
        }
    }

    if (definition->fields) {
        for (DeclarationNode* field : *definition->fields) {
            printDeclaration(field, depth + 1);
        }
    }

    printType(definition->element_type, depth + 1);
}

// Печатает одну альтернативу CASE.
static void printCaseAlternatives(
    CaseAlternativeListNode* alternatives,
    int depth
) {
    if (!alternatives || !alternatives->alternatives) return;

    printNodeLabel(depth, "Case alternatives", alternatives->NodeId);

    for (CaseAlternativeNode* alternative : *alternatives->alternatives) {
        if (!alternative) continue;

        printNodeLabel(depth + 1, "When alternative", alternative->NodeId);

        if (alternative->choices) {
            for (CaseChoiceNode* choice : *alternative->choices) {
                if (!choice) continue;

                if (choice->others) {
                    printNodeLabel(depth + 2, "Choice: others", choice->NodeId);
                } else if (choice->range) {
                    printNodeLabel(depth + 2, "Choice range", choice->NodeId);
                    printRange(choice->range, depth + 3);
                } else {
                    printNodeLabel(depth + 2, "Choice", choice->NodeId);
                    printExpr(choice->expression, depth + 3);
                }
            }
        }

        printStmtList(alternative->statements, depth + 2);
    }
}

// Печатает объявление переменной, типа или вложенной подпрограммы.
static void printDeclaration(DeclarationNode* dec, int depth) {
    if (!dec) return;

    if (dec->Type == DeclarationNode::subprog_dec) {
        printSubProgram(dec->subprog, depth);
        return;
    }

    string label = dec->Type == DeclarationNode::type_dec
        ? "Type declaration"
        : "Variable declaration";

    printNodeLabel(depth, label, dec->NodeId);

    if (dec->name) {
        cout << indent(depth + 1) << "Name: " << *dec->name << '\n';
    }

    if (dec->vlist && dec->vlist->vars) {
        for (VarName* var : *dec->vlist->vars) {
            if (var && var->name) {
                cout << indent(depth + 1) << "Variable: "
                     << *var->name << '\n';
            }
        }
    }

    if (dec->is_constant) {
        cout << indent(depth + 1) << "Constant: true\n";
    }

    switch (dec->parameter_mode) {
        case DeclarationNode::mode_in:
            cout << indent(depth + 1) << "Parameter mode: IN\n";
            break;
        case DeclarationNode::mode_out:
            cout << indent(depth + 1) << "Parameter mode: OUT\n";
            break;
        case DeclarationNode::mode_in_out:
            cout << indent(depth + 1) << "Parameter mode: IN OUT\n";
            break;
        default:
            break;
    }

    printType(dec->varrtype, depth + 1);
    printRange(dec->rng, depth + 1);
    printTypeDefinition(dec->definition, depth + 1);
    printExpr(dec->expr, depth + 1);
}

// Печатает список объявлений.
static void printDeclarationList(
    DeclarationListNode* listNode,
    int depth
) {
    if (!listNode || !listNode->decs) return;

    printNodeLabel(depth, "Declarations", listNode->NodeId);

    for (DeclarationNode* dec : *listNode->decs) {
        printDeclaration(dec, depth + 1);
    }
}

// Печатает список операторов.
static void printStmtList(StmtListNode* listNode, int depth) {
    if (!listNode || !listNode->stmts) return;

    printNodeLabel(depth, "Statements", listNode->NodeId);

    for (StmtNode* stmt : *listNode->stmts) {
        if (!stmt) continue;

        string label = "Statement";

        switch (stmt->Type) {
            case StmtNode::return_:     label = "Return"; break;
            case StmtNode::whileloop:   label = "While loop"; break;
            case StmtNode::forloop:     label = "For loop"; break;
            case StmtNode::simpleLoop:  label = "Loop"; break;
            case StmtNode::id_:
                label = "Procedure call: " +
                    (stmt->Name ? *stmt->Name : string());
                break;
            case StmtNode::if_:         label = "If statement"; break;
            case StmtNode::exit_:       label = "Exit"; break;
            case StmtNode::assigment_:  label = "Assignment"; break;
            case StmtNode::case_:       label = "Case statement"; break;
            case StmtNode::null_:       label = "Null statement"; break;
        }

        printNodeLabel(depth, label, stmt->NodeId);

        printExpr(stmt->Expr, depth + 1);
        printExpr(stmt->Left_operator, depth + 1);
        printExpr(stmt->Right_operator, depth + 1);
        printRange(stmt->rng, depth + 1);
        printExprList(stmt->Expr_list, depth + 1);
        printStmtList(stmt->stmtlst, depth + 1);

        if (stmt->elsif_lst && stmt->elsif_lst->elsifs) {
            for (ElsifStmtNode* elsif : *stmt->elsif_lst->elsifs) {
                if (!elsif) continue;

                printNodeLabel(depth + 1, "Elsif branch", elsif->NodeId);
                printExpr(elsif->Expr, depth + 2);
                printStmtList(elsif->stmtlst, depth + 2);
            }
        }

        if (stmt->else_stmt) {
            printNodeLabel(
                depth + 1,
                "Else branch",
                stmt->else_stmt->NodeId
            );
            printStmtList(stmt->else_stmt->stmtlst, depth + 2);
        }

        printCaseAlternatives(stmt->case_alternatives, depth + 1);
    }
}

// Возвращает текстовое название вида подпрограммы.
static string subProgramKind(SubProgramItemNode::type type) {
    switch (type) {
        case SubProgramItemNode::func_dec:
            return "Function declaration";
        case SubProgramItemNode::proc_dec:
            return "Procedure declaration";
        case SubProgramItemNode::func_imp:
            return "Function implementation";
        case SubProgramItemNode::proc_imp:
            return "Procedure implementation";
    }

    return "Subprogram";
}

// Печатает подпрограмму со всеми её частями.
static void printSubProgram(SubProgramItemNode* item, int depth) {
    if (!item) return;

    string label = subProgramKind(item->Type);

    if (item->name) {
        label += ": " + *item->name;
    }

    printNodeLabel(depth, label, item->NodeId);

    if (item->paramlist && item->paramlist->params) {
        printNodeLabel(
            depth + 1,
            "Parameters",
            item->paramlist->NodeId
        );

        for (DeclarationNode* param : *item->paramlist->params) {
            printDeclaration(param, depth + 2);
        }
    }

    printType(item->varrtype, depth + 1);
    printDeclarationList(item->decllist, depth + 1);
    printStmtList(item->stmtlst, depth + 1);

    // Обработчики EXCEPTION находятся в отдельном списке.
    // Их обход будет добавлен вместе с согласованными определениями
    // ExceptionHandlerNode и ExceptionHandlerListNode в ast_extensions.h.
}

// Выводит AST программы.
void printTree(ProgramNode* root) {
    if (!root) {
        cout << "AST is empty: parsing did not produce a program.\n";
        return;
    }

    cout << "\n=== Abstract Syntax Tree ===\n";
    printNodeLabel(0, "Program", root->NodeId);

    if (root->itemlist && root->itemlist->items) {
        for (SubProgramItemNode* item : *root->itemlist->items) {
            printSubProgram(item, 1);
        }
    }

    cout << "=== End of AST ===\n";
}
