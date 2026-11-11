#pragma once

#include "class_nodes.h"
#include <list>
#include <string>

// Один индекс массива. range == nullptr при unconstrained-индексе.
class ArrayIndexNode : public Node {
public:
    RangeNode* range = nullptr;
    TypeNode* index_type = nullptr;
    bool unconstrained = false;

    ArrayIndexNode(RangeNode* range, TypeNode* index_type, bool unconstrained);
};

// Дополнительное описание составного пользовательского типа.
class TypeDefinitionNode : public Node {
public:
    enum Kind { array_type, enum_type, record_type };

    Kind kind;
    std::list<ArrayIndexNode*>* indexes;
    std::list<std::string*>* literals;
    std::list<DeclarationNode*>* fields;
    TypeNode* element_type;

    explicit TypeDefinitionNode(Kind kind);
    void addIndex(ArrayIndexNode* index);
    void addLiteral(std::string* literal);
    void addField(DeclarationNode* field);
};

// Выбор в альтернативе case.
class CaseChoiceNode : public Node {
public:
    ExprNode* expression;
    RangeNode* range;
    bool others;

    explicit CaseChoiceNode(bool is_others);
    explicit CaseChoiceNode(ExprNode* expression);
    explicit CaseChoiceNode(RangeNode* range);
};

// Одна самостоятельная ветвь when.
class CaseAlternativeNode : public Node {
public:
    std::list<CaseChoiceNode*>* choices;
    StmtListNode* statements;

    CaseAlternativeNode(CaseChoiceNode* choice, StmtListNode* statements);
    void addChoice(CaseChoiceNode* choice);
};

// Список альтернатив case.
class CaseAlternativeListNode : public Node {
public:
    std::list<CaseAlternativeNode*>* alternatives;

    explicit CaseAlternativeListNode(CaseAlternativeNode* alternative);
    void add(CaseAlternativeNode* alternative);
};

// Список литералов перечислимого типа.
class EnumLiteralListNode : public Node {
public:
    std::list<std::string*>* literals;

    explicit EnumLiteralListNode(std::string* literal);
    void add(std::string* literal);
};

// Список полей record.
class RecordFieldListNode : public Node {
public:
    std::list<DeclarationNode*>* fields;

    explicit RecordFieldListNode(DeclarationNode* field);
    void add(DeclarationNode* field);
};
