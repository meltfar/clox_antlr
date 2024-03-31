//
// Created by zhouplus on 22/03/2024.
//

#include "object.h"
#include <fmt/core.h>
#include <iostream>

LoxValue::LoxValue(std::string &&str) {
    this->type = VAL_OBJ;
    // auto obj = ObjString(std::move(str));
    this->data = std::make_shared<ObjString>(std::move(str));
}

std::string LoxValue::as_string() const {
    if (!this->is_obj()) {
        throw std::runtime_error(fmt::format("expected an object, but found: {}", *this));
    }
    auto &name_obj = this->as_object();
    if (!name_obj->is_type<ObjString>()) {
        throw std::runtime_error(fmt::format("The name of an ident should be string, but found: {}", *this));
    }
    const auto osp = dynamic_cast<ObjString *>(name_obj.get());
    return osp->get_string();
}

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

// write string to value array, then add a OPCODE CONSTANT
uint16_t ObjFunction::write_string(std::string &&s) {
    std::shared_ptr<Object> os = std::make_shared<ObjString>(std::move(s));
    this->value_array_.emplace_back(std::move(os));

    return this->add_constant_opcode();
}

// only write to value array, don't add CONSTANT
uint16_t ObjFunction::write_string_only(std::string &&s) {
    std::shared_ptr<Object> os = std::make_shared<ObjString>(std::move(s));
    this->value_array_.emplace_back(std::move(os));

    return this->value_array_.size() - 1;
}

void ObjFunction::debug_print_chunk() const {
    std::cout << "======= chunk ================" << std::endl;
    size_t index = 0;
    while (index < this->chunk_.size()) {
        const auto op = static_cast<OpCode>(this->chunk_[index]);
        std::cout << fmt::format("{:04d} ", index);
        switch (op) {
            case OP_CONSTANT_16: {
                std::cout << "OP_CONSTANT" << "  ";
                this->debug_print_value(index);
                index += 3;
                break;
            }
            case OP_GET_LOCAL: {
                std::cout << "OP_GET_LOCAL" << "  ";
                auto idx = this->debug_get_word(index);
                std::cout << "(" << idx << ")" << std::endl;
                index += 3;
                break;
            }
            case OP_SET_LOCAL: {
                std::cout << "OP_SET_LOCAL" << std::endl;
                auto idx = this->debug_get_word(index);
                std::cout << "(" << idx << ")" << std::endl;
                index += 3;
                break;
            }
            case OP_GET_GLOBAL: {
                std::cout << "OP_GET_GLOBAL" << "  ";
                this->debug_print_value(index);
                index += 3;
                break;
            }
            case OP_DEFINE_GLOBAL: {
                std::cout << "OP_DEFINE_GLOBAL" << "  ";
                this->debug_print_value(index);
                index += 3;
                break;
            }
            case OP_SET_GLOBAL: {
                std::cout << "OP_SET_GLOBAL" << "  ";
                this->debug_print_value(index);
                index += 3;
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
            case OP_NIL:
            case OP_TRUE:
            case OP_FALSE:
            case OP_POP:
            case OP_EQUAL:
            case OP_GREATER:
            case OP_LESS:
            case OP_ADD:
            case OP_SUBTRACT:
            case OP_MULTIPLY:
            case OP_DIVIDE:
            case OP_NOT:
            case OP_NEGATE:
            case OP_PRINT: {
                fmt::print("{}\n", op);
                index += 1;
                break;
            }
            case OP_JUMP: {
                std::cout << "OP_JUMP" << "  ";
                auto idx = this->debug_get_word(index);
                std::cout << "(jump +" << idx << ")" << std::endl;
                index += 3;
                break;
            }
            case OP_JUMP_IF_FALSE: {
                std::cout << "OP_JUMP_IF_FALSE" << "  ";
                auto idx = this->debug_get_word(index);
                std::cout << "(jump +" << idx << ")" << std::endl;
                index += 3;
                break;
            }
            case OP_LOOP: {
                std::cout << "OP_LOOP" << "  ";
                auto idx = this->debug_get_word(index);
                std::cout << "(jump -" << idx << ")" << std::endl;
                index += 3;
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

            default:;
        }
    }

    std::cout << "======= chunk over ===========" << std::endl;
}

// regard the next two bytes as index
// then print the value in the value array with this index.
void ObjFunction::debug_print_value(const size_t index) const {
    const uint8_t b1 = this->chunk_[index + 1];
    const uint8_t b2 = this->chunk_[index + 2];

    const uint16_t b = (b1 << 8) | b2;
    auto &cont = this->value_array_[b];
    std::cout << cont << " (" << b << ")" << std::endl;
}

uint16_t ObjFunction::debug_get_word(const size_t index) const {
    const uint8_t b1 = this->chunk_[index + 1];
    const uint8_t b2 = this->chunk_[index + 2];

    const uint16_t b = (b1 << 8) | b2;

    return b;
}

const std::vector<uint8_t> &ObjFunction::get_chunk() const {
    return this->chunk_;
}

const std::vector<LoxValue> &ObjFunction::get_values() const {
    return this->value_array_;
}

std::string ObjFunction::print() {
    return fmt::format("<func {} with {} params>", this->function_name_, this->get_arity());
}

// write an opcode, then two bytes for index
void ObjFunction::add_constant_opcode_with_index(const OpCode op, const uint16_t index) {
    this->chunk_.push_back(op);
    this->chunk_.push_back(index >> 8);
    this->chunk_.push_back(index & 0x00FF);
}

uint16_t ObjFunction::add_constant_opcode() {
    // Format: OP_CON Index_of_value(2 bytes)
    this->chunk_.push_back(OP_CONSTANT_16);
    const uint16_t index = this->value_array_.size() - 1;
    this->chunk_.push_back(index >> 8);
    this->chunk_.push_back(index & 0x00FF);
    return index;
}

int ObjFunction::emit_jump(OpCode opCode) {
    this->add_constant_opcode_with_index(opCode, 0xFFFF);
    return this->chunk_.size() - 2;
}

void ObjFunction::patch_jump(int offset) {
    int jump = this->chunk_.size() - offset - 2;

    if (jump > UINT16_MAX) {
        throw std::runtime_error("too much code to jump over");
    }

    this->chunk_[offset] = (jump >> 8) & 0xFF;
    this->chunk_[offset + 1] = jump & 0xFF;
}

void ObjFunction::emit_loop(uint16_t index) {
    this->write_opcode(OP_LOOP);

    int offset = this->chunk_.size() - index + 2;
    if (offset > UINT16_MAX) {
        throw std::runtime_error("loop body is too large");
    }

    this->chunk_.push_back((offset >> 8) & 0xFF);
    this->chunk_.push_back(offset & 0xFF);
}

std::string ObjString::print() {
    return fmt::format("{}", this->string_);
}
