//
// Created by zhouplus on 22/03/2024.
//

#include "object.h"
#include <iostream>

void ObjFunction::write_opcode(const OpCode code) {
    this->chunk_.push_back(code);
}

void ObjFunction::write_constant(const double value) {
    // constant value
    this->value_array_.emplace_back(value);

    this->add_constant_opcode();
}

void ObjFunction::write_constant(bool value) {
    // constant value
    this->value_array_.emplace_back(value);

    this->add_constant_opcode();
}

// void ObjFunction::write_object(Object&& obj) {
//     this->value_array_.emplace_back(obj);
//
//     this->chunk_.push_back(OP_CONSTANT);
//     this->chunk_.push_back(this->value_array_.size() - 1);
// }

void ObjFunction::write_string(std::string &&s) {
    std::unique_ptr<Object> os = std::make_unique<ObjString>(std::move(s));
    this->value_array_.emplace_back(std::move(os));

    this->add_constant_opcode();
}

void ObjFunction::debug_print_chunk() const {
    std::cout << "======= chunk ================" << std::endl;
    size_t index = 0;
    while (index < this->chunk_.size()) {
        switch (this->chunk_[index]) {
            case OP_CONSTANT_16: {
                std::cout << "OP_CONSTANT" << "  ";
                const uint8_t b1 = this->chunk_[index + 1];
                const uint8_t b2 = this->chunk_[index + 2];

                const uint16_t b = (b1 << 8) | b2;
                auto &cont = this->value_array_[b];
                std::cout << cont << " (" << b << ")" << std::endl;
                index += 3;
                break;
            }
            case OP_NIL: {
                std::cout << "OP_NIL" << std::endl;
                index += 1;
                break;
            }
            case OP_TRUE: {
                std::cout << "OP_TRUE" << std::endl;
                index += 1;
                break;
            }
            case OP_FALSE: {
                std::cout << "OP_FALSE" << std::endl;
                index += 1;
                break;
            }
            case OP_POP: {
                std::cout << "OP_POP" << std::endl;
                index += 1;
                break;
            }
            case OP_GET_LOCAL: {
                std::cout << "OP_GET_LOCAL" << std::endl;
                break;
            }
            case OP_SET_LOCAL: {
                std::cout << "OP_SET_LOCAL" << std::endl;
                break;
            }
            case OP_GET_GLOBAL: {
                std::cout << "OP_GET_GLOBAL" << std::endl;
                break;
            }
            case OP_DEFINE_GLOBAL: {
                std::cout << "OP_DEFINE_GLOBAL" << std::endl;
                break;
            }
            case OP_SET_GLOBAL: {
                std::cout << "OP_SET_GLOBAL" << std::endl;
                break;
            }
            case OP_GET_UPVALUE: {
                std::cout << "OP_GET_UPVALUE" << std::endl;
                break;
            }
            case OP_SET_UPVALUE: {
                std::cout << "OP_SET_UPVALUE" << std::endl;
                break;
            }
            case OP_GET_PROPERTY: {
                std::cout << "OP_GET_PROPERTY" << std::endl;
                break;
            }
            case OP_SET_PROPERTY: {
                std::cout << "OP_SET_PROPERTY" << std::endl;
                break;
            }
            case OP_EQUAL: {
                std::cout << "OP_EQUAL" << std::endl;
                index += 1;
                break;
            }
            case OP_GREATER: {
                std::cout << "OP_GREATER" << std::endl;
                index += 1;
                break;
            }
            case OP_LESS: {
                std::cout << "OP_LESS" << std::endl;
                index += 1;
                break;
            }
            case OP_ADD: {
                std::cout << "OP_ADD" << std::endl;
                index += 1;
                break;
            }
            case OP_SUBTRACT: {
                std::cout << "OP_SUBTRACT" << std::endl;
                index += 1;
                break;
            }
            case OP_MULTIPLY: {
                std::cout << "OP_MULTIPLY" << std::endl;
                index += 1;
                break;
            }
            case OP_DIVIDE: {
                std::cout << "OP_DIVIDE" << std::endl;
                index += 1;
                break;
            }
            case OP_NOT: {
                std::cout << "OP_NOT" << std::endl;
                index += 1;
                break;
            }
            case OP_NEGATE: {
                std::cout << "OP_NEGATE" << std::endl;
                index += 1;
                break;
            }
            case OP_PRINT: {
                std::cout << "OP_PRINT" << std::endl;
                index += 1;
                break;
            }
            case OP_JUMP: {
                std::cout << "OP_JUMP" << std::endl;
                break;
            }
            case OP_JUMP_IF_FALSE: {
                std::cout << "OP_JUMP_IF_FALSE" << std::endl;
                break;
            }
            case OP_LOOP: {
                std::cout << "OP_LOOP" << std::endl;
                break;
            }
            case OP_CALL: {
                std::cout << "OP_CALL" << std::endl;
                break;
            }
            case OP_CLOSURE: {
                std::cout << "OP_CLOSURE" << std::endl;
                break;
            }
            case OP_CLOSE_UPVALUE: {
                std::cout << "OP_CLOSE_UPVALUE" << std::endl;
                break;
            }
            case OP_RETURN: {
                std::cout << "OP_RETURN" << std::endl;
                index += 1;
                break;
            }
            case OP_CLASS: {
                std::cout << "OP_CLASS" << std::endl;
                break;
            }
            case OP_METHOD: {
                std::cout << "OP_METHOD" << std::endl;
                break;
            }

            default: ;
        }
    }
}

const std::vector<uint8_t>& ObjFunction::get_chunk() const {
    return this->chunk_;
}

std::vector<LoxValue> ObjFunction::get_values() {
    return std::move(this->value_array_);
}

void ObjFunction::add_constant_opcode() {
    // Format: OP_CON Index_of_value(2 bytes)
    this->chunk_.push_back(OP_CONSTANT_16);
    const uint16_t index = this->value_array_.size() - 1;
    this->chunk_.push_back(index >> 8);
    this->chunk_.push_back(index & 0x00FF);
}
