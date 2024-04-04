//
// Created by zhouplus on 23/03/2024.
//

#ifndef VM_H
#define VM_H

#define FRAMES_MAX 64
#define UINT8_COUNT (UINT8_MAX + 1)
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

#include <deque>
#include <unordered_map>
#include <iostream>
#include <utility>
#include <span>
#include <array>

#include "object.h"

struct CallFrame {
    std::shared_ptr<ObjFunction> function;
    uint16_t ip;
    LoxValue* slots;
};

class VM {
    std::array<LoxValue, STACK_MAX> stack_;
    std::unordered_map<std::string, LoxValue> globals_;
    std::unordered_map<std::string, LoxValue> strings_;
    std::vector<CallFrame> call_frames_;
    LoxValue* stack_top_;

public:
    VM(std::unordered_map<std::string, LoxValue> strings, std::shared_ptr<ObjFunction> function)
            : strings_(std::move(strings)), stack_top_(this->stack_.data()) {
        this->push(LoxValue(function));
        // call frame for the script function
        CallFrame cf = CallFrame{std::move(function), 0, this->stack_.data()};
        this->call_frames_.push_back(std::move(cf));
    }

    void execute();

    LoxValue pop();

    void push(LoxValue value);

    // TODO: change LoxValue to use shared_ptr underneath (obj)
    [[nodiscard]] const LoxValue &peek(uint32_t offset) const;

    uint16_t read_word();

    uint8_t read_byte();

    [[nodiscard]] static bool is_falsey(const LoxValue &lv);

    static void ensure_number(const LoxValue &lox_value);

    static void ensure_all_type(std::vector<const LoxValue *> &&list, ValueType vt);

    static bool is_equal(const LoxValue &v1, const LoxValue &v2);

    bool call_on_value(int arg_count);

    void call(const std::shared_ptr<ObjFunction>& function, int arg_count);
};


#endif //VM_H
