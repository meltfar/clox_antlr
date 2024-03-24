//
// Created by zhouplus on 23/03/2024.
//

#include "vm.h"
#include <fmt/core.h>

void VM::execute() {
    const auto top_script = this->script_;
    auto &chunk = top_script->get_chunk();
    auto values = top_script->get_values();

    while (true) {
        switch (auto op = chunk[this->ip_++]) {
            case OP_RETURN: {
                // if there is still a call frame, we return to it.
                return;
            }
            case OP_CONSTANT_16: {
                const auto cont_idx = this->read_word();
                this->push(std::move(values[cont_idx]));
                break;
            }
            case OP_ADD: {
                const auto op1 = this->pop();
                const auto op2 = this->pop();
                // TODO: string concat
                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 + v2));
                break;
            }
            case OP_SUBTRACT: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                ensure_all_type({&op1, &op2}, VAL_NUMBER);

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 - v2));
                break;
            }
            case OP_MULTIPLY: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                ensure_all_type({&op1, &op2}, VAL_NUMBER);

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 * v2));
                break;
            }
            case OP_DIVIDE: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                ensure_all_type({&op1, &op2}, VAL_NUMBER);

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 / v2));
                break;
            }
            case OP_TRUE: {
                this->push(LoxValue(true));
                break;
            }
            case OP_FALSE: {
                this->push(LoxValue(false));
                break;
            }
            case OP_NIL: {
                this->push(LoxValue());
                break;
            }
            case OP_PRINT: {
                auto value = this->pop();
                std::cout << value << std::endl;
                break;
            }
            case OP_NEGATE: {
                auto value = this->pop();
                ensure_number(value);
                this->push(LoxValue(-std::get<double>(value.data)));
                break;
            }
            case OP_EQUAL: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                this->push(LoxValue(is_equal(op1, op2)));

                break;
            }
            case OP_GREATER: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                ensure_all_type({&op1, &op2}, VAL_NUMBER);

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 > v2));
                break;
            }
            case OP_LESS: {

            }

            default:
                throw std::runtime_error(std::format("unexpected op code: {}", op));
        }
    }
}

LoxValue VM::pop() {
    auto back = std::move(this->stack_.back());
    this->stack_.pop_back();
    return back;
}

void VM::push(LoxValue &&value) {
    this->stack_.push_back(std::move(value));
}

const LoxValue &VM::peek(const uint32_t offset) const {
    return this->stack_[this->stack_.size() - 1 - offset];
}

uint16_t VM::read_word() {
    const auto b1 = this->read_byte();
    const auto b2 = this->read_byte();
    return (b1 << 8) | b2;
}

uint8_t VM::read_byte() {
    auto &chunk = this->script_->get_chunk();
    const auto ret = chunk[this->ip_++];
    if (this->ip_ >= chunk.size()) {
        throw std::runtime_error("ip out of the size of chunk");
    }

    return ret;
}

bool VM::is_falsey(const LoxValue &lv) {
    // if (std::holds_alternative<double>(lox_value.data)) {
    //     return std::get<double>(lox_value.data) == 0;
    // }
    // if (std::holds_alternative<bool>(lox_value.data)) {
    //     return std::get<bool>(lox_value.data) == false;
    // }
    if (lv.type == VAL_NIL) {
        return true;
    }
    if (lv.type == VAL_BOOL) {
        return !std::get<bool>(lv.data);
    }
    if (lv.type == VAL_NUMBER) {
        return std::get<double>(lv.data) == 0;
    }
    // empty string is already regarded as false
    if (const auto &obj = std::get<std::unique_ptr<Object> >(lv.data); obj->get_type() == OBJ_STRING) {
        const auto *obs = dynamic_cast<ObjString *>(obj.get());
        return obs->get_string_view().empty();
    }

    return false;
}

void VM::ensure_number(const LoxValue &lox_value) {
    if (lox_value.type != VAL_NUMBER) {
        throw std::runtime_error(std::format("expecting a number, but found: {}",
                                             static_cast<uint8_t>(lox_value.type)));
    }
}

bool VM::is_equal(const LoxValue &v1, const LoxValue &v2) {
    if (v1.type != v2.type) {
        return false;
    }

    switch (v1.type) {
        case VAL_NIL:
            return true;
        case VAL_NUMBER:
            return std::get<double>(v1.data) == std::get<double>(v2.data);
        case VAL_BOOL:
            return std::get<bool>(v1.data) == std::get<bool>(v2.data);
        case VAL_OBJ:
            return v1.data == v2.data;
    }
    return false;
}

void VM::ensure_all_type(std::vector<const LoxValue *> &&list, ValueType vt) {
    for (const LoxValue *vl: list) {
        if (vl->type != vt) {
            throw std::runtime_error(fmt::format("expecting all be type: {}, but found: {}", vt, vl->type));
//                auto err = std::format("expecting all be type: {}, but found: {}", vt, vl->type);
//            throw std::runtime_error(
//                    std::format("expecting all be type: {}, but found: {}",
//                                value_type_to_string(vt),
//                                value_type_to_string(vl->type)));
        }
    }
}
