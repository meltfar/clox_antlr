//
// Created by zhouplus on 21/03/2024.
//

#ifndef CHUNK_H
#define CHUNK_H
#include <variant>

#include "compiler.h"

enum OpCode {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_GET_PROPERTY,
    OP_SET_PROPERTY,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_LOOP,
    OP_CALL,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,
    OP_RETURN,
    OP_CLASS,
    OP_METHOD
};

enum ValueType {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
    VAL_OBJ,
};

struct LoxValue {
    std::variant<bool, double, std::unique_ptr<Object> > data;

    explicit LoxValue(double n) {
        this->data = n;
    }

    explicit LoxValue(bool n) {
        this->data = n;
    }

    explicit LoxValue(Object n) {
        this->data = std::make_unique<Object>(n);
    }
};

#endif //CHUNK_H
