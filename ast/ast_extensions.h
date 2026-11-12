
#pragma once

#include "class_nodes.h"
#include <list>
#include <string>

// Узел одного индекса массива.
// Для ограниченного индекса используется range.
// Для неограниченного индекса используется index_type и unconstrained = true.
class ArrayIndexNode : public Node {
public:
    RangeNode* range = nullptr;
    TypeNode* index_type = nullptr;
    bool unconstrained = false;

    // Создаёт описание индекса массива.
    ArrayIndexNode(
        RangeNode* range,
        TypeNode* index_type,
        bool unconstrained
    );
};

// Описание составного пользовательского типа:
// массива, перечисления или записи.
class TypeDefinitionNode : public Node {
public:
    enum Kind {
        array_type,
        enum_type,
        record_type
    };

    Kind kind;

    // Индексы массива.
    std::list<ArrayIndexNode*>* indexes = nullptr;

    // Литералы перечислимого типа.
    std::list<std::string*>* literals = nullptr;

    // Поля записи.
    std::list<DeclarationNode*>* fields = nullptr;

    // Тип элементов массива.
    TypeNode* element_type = nullptr;

    // Создаёт описание типа и инициализирует списки.
    explicit TypeDefinitionNode(Kind kind);

    // Добавляет индекс массива.
    void addIndex(ArrayIndexNode* index);

    // Добавляет литерал перечисления.
    void addLiteral(std::string* literal);

    // Добавляет поле записи.
    void addField(DeclarationNode* field);
};

// Один вариант выбора в операторе CASE или обработчике EXCEPTION.
// Вариант может быть выражением, диапазоном или OTHERS.
class CaseChoiceNode : public Node {
public:
    ExprNode* expression = nullptr;
    RangeNode* range = nullptr;
    bool others = false;

    // Создаёт вариант OTHERS.
    explicit CaseChoiceNode(bool is_others);

    // Создаёт вариант с выражением.
    explicit CaseChoiceNode(ExprNode* expression);

    // Создаёт вариант с диапазоном.
    explicit CaseChoiceNode(RangeNode* range);
};

// Одна альтернатива оператора CASE.
// Содержит варианты выбора и отдельный список операторов.
class CaseAlternativeNode : public Node {
public:
    std::list<CaseChoiceNode*>* choices = nullptr;
    StmtListNode* statements = nullptr;

    // Создаёт альтернативу с первым вариантом выбора.
    CaseAlternativeNode(
        CaseChoiceNode* choice,
        StmtListNode* statements
    );

    // Добавляет дополнительный вариант выбора.
    void addChoice(CaseChoiceNode* choice);
};

// Список альтернатив оператора CASE.
class CaseAlternativeListNode : public Node {
public:
    std::list<CaseAlternativeNode*>* alternatives = nullptr;

    // Создаёт список с первой альтернативой.
    explicit CaseAlternativeListNode(
        CaseAlternativeNode* alternative
    );

    // Добавляет альтернативу в список.
    void add(CaseAlternativeNode* alternative);
};

// Один обработчик исключения.
// Сохраняет варианты WHEN и тело обработчика отдельно.
class ExceptionHandlerNode : public Node {
public:
    std::list<CaseChoiceNode*>* choices = nullptr;
    StmtListNode* statements = nullptr;

    // Создаёт обработчик с первым вариантом выбора.
    ExceptionHandlerNode(
        CaseChoiceNode* choice,
        StmtListNode* statements
    );

    // Добавляет дополнительный вариант WHEN.
    void addChoice(CaseChoiceNode* choice);
};

// Список обработчиков исключений.
class ExceptionHandlerListNode : public Node {
public:
    std::list<ExceptionHandlerNode*>* handlers = nullptr;

    // Создаёт список с первым обработчиком.
    explicit ExceptionHandlerListNode(
        ExceptionHandlerNode* handler
    );

    // Добавляет обработчик в список.
    void add(ExceptionHandlerNode* handler);
};

// Список литералов перечислимого типа.
// В грамматике можно использовать TypeDefinitionNode напрямую;
// этот класс оставлен для совместимости с существующим AST.
class EnumLiteralListNode : public Node {
public:
    std::list<std::string*>* literals = nullptr;

    // Создаёт список с первым литералом.
    explicit EnumLiteralListNode(std::string* literal);

    // Добавляет литерал в список.
    void add(std::string* literal);
};

// Список полей записи.
// В грамматике можно использовать TypeDefinitionNode напрямую;
// этот класс оставлен для совместимости с существующим AST.
class RecordFieldListNode : public Node {
public:
    std::list<DeclarationNode*>* fields = nullptr;

    // Создаёт список с первым полем.
    explicit RecordFieldListNode(DeclarationNode* field);

    // Добавляет поле в список.
    void add(DeclarationNode* field);
};
