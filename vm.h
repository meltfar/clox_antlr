//
// Created by zhouplus on 23/03/2024.
//

#ifndef VM_H
#define VM_H

#include <deque>
#include <unordered_map>
#include <iostream>

#include "object.h"


#define STACK_MAXIMUM 65535

class VM {
    std::deque<LoxValue> stack_;
    std::unordered_map<std::string, LoxValue> globals_;
    std::unordered_map<std::string, LoxValue> strings_;

    std::shared_ptr<ObjFunction> script_;

    uint64_t ip_ = 0;

public:
    VM(std::unordered_map<std::string, LoxValue> &&strings, std::shared_ptr<ObjFunction> &&script)
            : strings_(std::move(strings)),
              script_(std::move(script)) {
    }

    void execute();

    LoxValue pop();

    void push(LoxValue &&value);

    [[nodiscard]] const LoxValue &peek(uint32_t offset) const;

    uint16_t read_word();

    uint8_t read_byte();

    [[nodiscard]] static bool is_falsey(const LoxValue &lv);

    static void ensure_number(const LoxValue &lox_value);

    static void ensure_all_type(std::vector<const LoxValue *> &&list, ValueType vt);

    static bool is_equal(const LoxValue &v1, const LoxValue &v2);
};


#endif //VM_H
