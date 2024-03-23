//
// Created by zhouplus on 23/03/2024.
//

#include "vm.h"

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
                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 + v2));
                break;
            }
            case OP_SUBTRACT: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 - v2));
                break;
            }
            case OP_MULTIPLY: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

                const auto v1 = std::get<double>(op1.data);
                const auto v2 = std::get<double>(op2.data);

                this->push(LoxValue(v1 * v2));
                break;
            }
            case OP_DIVIDE: {
                const auto op2 = this->pop();
                const auto op1 = this->pop();

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

            default: throw std::runtime_error(std::format("unexpected op code: {}", op));
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
        throw std::exception("ip out of the size of chunk");
    }

    return ret;
}

bool VM::is_falsey(const LoxValue &lox_value) {
    if (std::holds_alternative<double>(lox_value.data)) {
        return std::get<double>(lox_value.data) == 0;
    }
    if (std::holds_alternative<bool>(lox_value.data)) {
        return std::get<bool>(lox_value.data) == false;
    }
    return false;
}

void VM::ensure_number(const LoxValue &lox_value) {
    if (lox_value.type != VAL_NUMBER) {
        throw std::runtime_error(std::format("expecting a number, but found: {}", static_cast<uint8_t>(lox_value.type)));
    }
}
