
#include "ast_extensions.h"

// Возвращает уникальный идентификатор дополнительного узла AST.
// Диапазон идентификаторов начинается с 1000001,
// чтобы не пересекаться с идентификаторами основных узлов.
static int nextExtensionNodeId() {
    static int id = 1000000;
    return ++id;
}

// Создаёт узел индекса массива.
ArrayIndexNode::ArrayIndexNode(
    RangeNode* range_value,
    TypeNode* index_type_value,
    bool is_unconstrained
)
    : range(range_value),
      index_type(index_type_value),
      unconstrained(is_unconstrained) {
    NodeId = nextExtensionNodeId();
}

// Создаёт описание массива, перечисления или записи.
// Все списки инициализируются, чтобы добавление элементов
// не требовало предварительной проверки на nullptr.
TypeDefinitionNode::TypeDefinitionNode(Kind value)
    : kind(value),
      indexes(new std::list<ArrayIndexNode*>()),
      literals(new std::list<std::string*>()),
      fields(new std::list<DeclarationNode*>()),
      element_type(nullptr) {
    NodeId = nextExtensionNodeId();
}

// Добавляет индекс массива, если передан корректный указатель.
void TypeDefinitionNode::addIndex(ArrayIndexNode* index) {
    if (index != nullptr) {
        indexes->push_back(index);
    }
}

// Добавляет литерал перечислимого типа.
void TypeDefinitionNode::addLiteral(std::string* literal) {
    if (literal != nullptr) {
        literals->push_back(literal);
    }
}

// Добавляет поле записи.
void TypeDefinitionNode::addField(DeclarationNode* field) {
    if (field != nullptr) {
        fields->push_back(field);
    }
}

// Создаёт вариант OTHERS для CASE или EXCEPTION.
CaseChoiceNode::CaseChoiceNode(bool is_others)
    : expression(nullptr),
      range(nullptr),
      others(is_others) {
    NodeId = nextExtensionNodeId();
}

// Создаёт вариант выбора, заданный выражением.
CaseChoiceNode::CaseChoiceNode(ExprNode* value)
    : expression(value),
      range(nullptr),
      others(false) {
    NodeId = nextExtensionNodeId();
}

// Создаёт вариант выбора, заданный диапазоном.
CaseChoiceNode::CaseChoiceNode(RangeNode* value)
    : expression(nullptr),
      range(value),
      others(false) {
    NodeId = nextExtensionNodeId();
}

// Создаёт альтернативу CASE с первым вариантом выбора.
CaseAlternativeNode::CaseAlternativeNode(
    CaseChoiceNode* choice,
    StmtListNode* body
)
    : choices(new std::list<CaseChoiceNode*>()),
      statements(body) {
    NodeId = nextExtensionNodeId();
    addChoice(choice);
}

// Добавляет вариант выбора в альтернативу CASE.
void CaseAlternativeNode::addChoice(CaseChoiceNode* choice) {
    if (choice != nullptr) {
        choices->push_back(choice);
    }
}

// Создаёт список альтернатив CASE.
CaseAlternativeListNode::CaseAlternativeListNode(
    CaseAlternativeNode* alternative
)
    : alternatives(new std::list<CaseAlternativeNode*>()) {
    NodeId = nextExtensionNodeId();
    add(alternative);
}

// Добавляет альтернативу CASE.
void CaseAlternativeListNode::add(
    CaseAlternativeNode* alternative
) {
    if (alternative != nullptr) {
        alternatives->push_back(alternative);
    }
}

// Создаёт обработчик исключения с первым вариантом WHEN.
ExceptionHandlerNode::ExceptionHandlerNode(
    CaseChoiceNode* choice,
    StmtListNode* body
)
    : choices(new std::list<CaseChoiceNode*>()),
      statements(body) {
    NodeId = nextExtensionNodeId();
    addChoice(choice);
}

// Добавляет дополнительный вариант WHEN в обработчик.
void ExceptionHandlerNode::addChoice(CaseChoiceNode* choice) {
    if (choice != nullptr) {
        choices->push_back(choice);
    }
}

// Создаёт список обработчиков исключений.
ExceptionHandlerListNode::ExceptionHandlerListNode(
    ExceptionHandlerNode* handler
)
    : handlers(new std::list<ExceptionHandlerNode*>()) {
    NodeId = nextExtensionNodeId();
    add(handler);
}

// Добавляет обработчик исключения в список.
void ExceptionHandlerListNode::add(ExceptionHandlerNode* handler) {
    if (handler != nullptr) {
        handlers->push_back(handler);
    }
}

// Создаёт список литералов перечисления.
EnumLiteralListNode::EnumLiteralListNode(std::string* literal)
    : literals(new std::list<std::string*>()) {
    NodeId = nextExtensionNodeId();
    add(literal);
}

// Добавляет литерал в список.
void EnumLiteralListNode::add(std::string* literal) {
    if (literal != nullptr) {
        literals->push_back(literal);
    }
}

// Создаёт список полей записи.
RecordFieldListNode::RecordFieldListNode(DeclarationNode* field)
    : fields(new std::list<DeclarationNode*>()) {
    NodeId = nextExtensionNodeId();
    add(field);
}

// Добавляет поле записи.
void RecordFieldListNode::add(DeclarationNode* field) {
    if (field != nullptr) {
        fields->push_back(field);
    }
}
