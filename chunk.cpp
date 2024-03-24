//
// Created by zhouplus on 21/03/2024.
//

#include "chunk.h"

std::string value_type_to_string(const ValueType &vt) {
    std::string name{};
    switch (vt) {
        case VAL_BOOL: {
            name = "VAL_BOOL";
            break;
        }
        case VAL_NIL: {
            name = "VAL_NIL";
            break;
        }
        case VAL_NUMBER: {
            name = "VAL_NUMBER";
            break;
        }
        case VAL_OBJ: {
            name = "VAL_OBJ";
            break;
        }
    }
    return name;
}

std::string op_code_to_string(const OpCode &op) {
    std::string name{};
    switch (op) {
        case OP_CONSTANT_16: {
            name = "OP_CONSTANT_16";
            break;
        }
        case OP_NIL: {
            name = "OP_NIL";
            break;
        }
        case OP_TRUE: {
            name = "OP_TRUE";
            break;
        }
        case OP_FALSE: {
            name = "OP_FALSE";
            break;
        }
        case OP_POP: {
            name = "OP_POP";
            break;
        }
        case OP_GET_LOCAL: {
            name = "OP_GET_LOCAL";
            break;
        }
        case OP_SET_LOCAL: {
            name = "OP_SET_LOCAL";
            break;
        }
        case OP_GET_GLOBAL: {
            name = "OP_GET_GLOBAL";
            break;
        }
        case OP_DEFINE_GLOBAL: {
            name = "OP_DEFINE_GLOBAL";
            break;
        }
        case OP_SET_GLOBAL: {
            name = "OP_SET_GLOBAL";
            break;
        }
        case OP_GET_UPVALUE: {
            name = "OP_GET_UPVALUE";
            break;
        }
        case OP_SET_UPVALUE: {
            name = "OP_SET_UPVALUE";
            break;
        }
        case OP_GET_PROPERTY: {
            name = "OP_GET_PROPERTY";
            break;
        }
        case OP_SET_PROPERTY: {
            name = "OP_SET_PROPERTY";
            break;
        }
        case OP_EQUAL: {
            name = "OP_EQUAL";
            break;
        }
        case OP_GREATER: {
            name = "OP_GREATER";
            break;
        }
        case OP_LESS: {
            name = "OP_LESS";
            break;
        }
        case OP_ADD: {
            name = "OP_ADD";
            break;
        }
        case OP_SUBTRACT: {
            name = "OP_SUBTRACT";
            break;
        }
        case OP_MULTIPLY: {
            name = "OP_MULTIPLY";
            break;
        }
        case OP_DIVIDE: {
            name = "OP_DIVIDE";
            break;
        }
        case OP_NOT: {
            name = "OP_NOT";
            break;
        }
        case OP_NEGATE: {
            name = "OP_NEGATE";
            break;
        }
        case OP_PRINT: {
            name = "OP_PRINT";
            break;
        }
        case OP_JUMP: {
            name = "OP_JUMP";
            break;
        }
        case OP_JUMP_IF_FALSE: {
            name = "OP_JUMP_IF_FALSE";
            break;
        }
        case OP_LOOP: {
            name = "OP_LOOP";
            break;
        }
        case OP_CALL: {
            name = "OP_CALL";
            break;
        }
        case OP_CLOSURE: {
            name = "OP_CLOSURE";
            break;
        }
        case OP_CLOSE_UPVALUE: {
            name = "OP_CLOSE_UPVALUE";
            break;
        }
        case OP_RETURN: {
            name = "OP_RETURN";
            break;
        }
        case OP_CLASS: {
            name = "OP_CLASS";
            break;
        }
        case OP_METHOD: {
            name = "OP_METHOD";
            break;
        }
    }

    return name;
}