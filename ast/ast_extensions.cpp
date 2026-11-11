#include "ast_extensions.h"

static int nextExtensionNodeId() {
    static int id = 1000000;
    return ++id;
}

// Индекс массива.
ArrayIndexNode::ArrayIndexNode(
    RangeNode* range_value,
    TypeNode* index_type_value,
    bool is_unconstrained
) : range(range_value),
    index_type(index_type_value),
    unconstrained(is_unconstrained) {
    NodeId = nextExtensionNodeId();
}

// Описание массива, перечисления или записи.
TypeDefinitionNode::TypeDefinitionNode(Kind value)
    : kind(value),
      indexes(new std::list<ArrayIndexNode*>()),
      literals(new std::list<std::string*>()),
      fields(new std::list<DeclarationNode*>()),
      element_type(nullptr) {
    NodeId = nextExtensionNodeId();
}

void TypeDefinitionNode::addIndex(ArrayIndexNode* index) {
    if (index) indexes->push_back(index);
}

void TypeDefinitionNode::addLiteral(std::string* literal) {
    if (literal) literals->push_back(literal);
}

void TypeDefinitionNode::addField(DeclarationNode* field) {
    if (field) fields->push_back(field);
}

// Элемент выбора для case.
CaseChoiceNode::CaseChoiceNode(bool is_others)
    : expression(nullptr), range(nullptr), others(is_others) {
    NodeId = nextExtensionNodeId();
}

CaseChoiceNode::CaseChoiceNode(ExprNode* value)
    : expression(value), range(nullptr), others(false) {
    NodeId = nextExtensionNodeId();
}

CaseChoiceNode::CaseChoiceNode(RangeNode* value)
    : expression(nullptr), range(value), others(false) {
    NodeId = nextExtensionNodeId();
}

// Одна ветвь when.
CaseAlternativeNode::CaseAlternativeNode(
    CaseChoiceNode* choice,
    StmtListNode* body
) : choices(new std::list<CaseChoiceNode*>()),
    statements(body) {
    NodeId = nextExtensionNodeId();
    addChoice(choice);
}

void CaseAlternativeNode::addChoice(CaseChoiceNode* choice) {
    if (choice) choices->push_back(choice);
}

// Список ветвей case.
CaseAlternativeListNode::CaseAlternativeListNode(
    CaseAlternativeNode* alternative
) : alternatives(new std::list<CaseAlternativeNode*>()) {
    NodeId = nextExtensionNodeId();
    add(alternative);
}

void CaseAlternativeListNode::add(CaseAlternativeNode* alternative) {
    if (alternative) alternatives->push_back(alternative);
}

// Литералы перечислимого типа.
EnumLiteralListNode::EnumLiteralListNode(std::string* literal)
    : literals(new std::list<std::string*>()) {
    NodeId = nextExtensionNodeId();
    add(literal);
}

void EnumLiteralListNode::add(std::string* literal) {
    if (literal) literals->push_back(literal);
}

// Поля записи.
RecordFieldListNode::RecordFieldListNode(DeclarationNode* field)
    : fields(new std::list<DeclarationNode*>()) {
    NodeId = nextExtensionNodeId();
    add(field);
}

void RecordFieldListNode::add(DeclarationNode* field) {
    if (field) fields->push_back(field);
}