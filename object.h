//
// Created by zhouplus on 22/03/2024.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <format>
#include <memory>
#include <string>
#include <variant>
#include <iostream>
#include <fmt/core.h>

#include "chunk.h"
#include <vector>

class ObjString;

enum ObjectType {
    OBJ_BOUND_METHOD,
    OBJ_CLASS,
    OBJ_CLOSURE,
    OBJ_FUNCTION,
    OBJ_NATIVE,
    OBJ_STRING,
    OBJ_UPVALUE,
    OBJ_INSTANCE,
};

class Object : public std::enable_shared_from_this<Object> {
protected:
    bool is_marked_;
    ObjectType type_;

public:
    virtual ~Object() = default;

    virtual std::string print() = 0;

    Object(): is_marked_(false), type_(OBJ_CLASS) {
    }

    ObjectType get_type() const {
        return type_;
    }

    template<class T>
    bool is_type() {
        auto ret = dynamic_cast<T *>(this);
        return ret != nullptr;
    }
};

struct LoxValue {
    ValueType type;
    std::variant<bool, double, std::shared_ptr<Object> > data;

    explicit LoxValue(double n) {
        this->type = VAL_NUMBER;
        this->data = n;
    }

    explicit LoxValue(bool b) {
        this->type = VAL_BOOL;
        this->data = b;
    }

    explicit LoxValue(std::shared_ptr<Object> obj) {
        this->type = VAL_OBJ;
        this->data = std::move(obj);
    }

    explicit LoxValue(std::string&& str);

    explicit LoxValue() {
        std::cout << "nil constructor called" << std::endl;
        this->type = VAL_NIL;
        this->data = nullptr;
    }

    LoxValue(const LoxValue &other) = default;

    LoxValue(LoxValue &&other) noexcept
        : type(other.type), data(std::move(other.data)) {
    }

    LoxValue &operator=(const LoxValue &other) = default;

    LoxValue &operator=(LoxValue &&other) noexcept {
        if (this == &other)
            return *this;
        data = std::move(other.data);
        other.data = nullptr;
        this->type = other.type;
        return *this;
    }

    [[nodiscard]] bool is_obj() const {
        return this->type == VAL_OBJ;
    }

    [[nodiscard]] bool is_number() const {
        return this->type == VAL_NUMBER;
    }

    [[nodiscard]] bool is_nil() const {
        return this->type == VAL_NIL;
    }

    [[nodiscard]] bool is_bool() const {
        return this->type == VAL_BOOL;
    }

    [[nodiscard]] const std::shared_ptr<Object> &as_object() const {
        return std::get<std::shared_ptr<Object> >(this->data);
    }

    [[nodiscard]] std::string as_string() const;
};

template<>
struct fmt::formatter<LoxValue> : fmt::formatter<string_view> {
    auto format(const LoxValue &lv, fmt::format_context &ctx) const {
        std::string name;
        switch (lv.type) {
            case VAL_NIL: {
                name = "<nil: nil>";
                break;
            }
            case VAL_NUMBER: {
                name = fmt::format("<number: {}>", std::get<double>(lv.data));
                break;
            }
            case VAL_BOOL: {
                name = fmt::format("<bool: {}>", std::get<bool>(lv.data) ? "true" : "false");
                break;
            }
            case VAL_OBJ: {
                name = fmt::format("<obj: {}>", std::get<std::shared_ptr<Object>>(lv.data)->print());
                break;
            }
        }
        return fmt::formatter<string_view>::format(name, ctx);
    }
};

inline std::ostream &operator <<(std::ostream &os, const LoxValue &lv) {
    if (std::holds_alternative<double>(lv.data)) {
        os << std::format("{}", std::get<double>(lv.data));
    } else if (std::holds_alternative<bool>(lv.data)) {
        os << std::format("{}", std::get<bool>(lv.data));
    } else {
        // os << std::format("{}", std::get<std::unique_ptr<Object> >(lv.data)->get_type());
        os << std::get<std::shared_ptr<Object> >(lv.data)->print();
    }
    return os;
}

class ObjFunction : public Object {
    int arity_;
    std::vector<uint8_t> chunk_;
    std::vector<LoxValue> value_array_;
    std::string function_name_;

public:
    ObjFunction(): Object(), arity_(0) {
        this->type_ = OBJ_FUNCTION;

        chunk_ = std::vector<uint8_t>();
        value_array_ = std::vector<LoxValue>();
    }

    void write_opcode(OpCode code);

    void write_constant(double value);

    void write_constant(bool value);

    // void write_object(std::unique_ptr<Object> obj);

    uint16_t write_string(std::string &&s);

    uint16_t write_string_only(std::string &&s);

    int get_arity() const {
        return this->arity_;
    }

    void debug_print_chunk() const;

    void debug_print_value(size_t index) const;

    const std::vector<uint8_t> &get_chunk() const;

    const std::vector<LoxValue>& get_values() const;

    std::string print() override;

    const std::string &get_function_name() const {
        return this->function_name_;
    }

    void add_constant_opcode_with_index(OpCode op, uint16_t index);

private:
    uint16_t add_constant_opcode();
};

template<>
struct fmt::formatter<ObjFunction> : fmt::formatter<string_view> {
    auto format(const ObjFunction &vt, fmt::format_context &ctx) const {
        const auto name = fmt::format("<func {} with {} arity>", vt.get_function_name(), vt.get_arity());
        return fmt::formatter<string_view>::format(name, ctx);
    }
};

class ObjString : public Object {
    std::string string_;

public:
    ~ObjString() override {
        std::cout << "destructing objString: " << this->string_ << std::endl;
    }

    ObjString(): Object() {
        this->type_ = OBJ_STRING;
    }

    explicit ObjString(std::string &&str): ObjString() {
        this->string_ = str;
    }

    std::string_view get_string_view() const {
        return this->string_;
    }

    std::string &get_string() {
        return this->string_;
    }

    std::string print() override;
};

template<>
struct fmt::formatter<ObjString> : fmt::formatter<string_view> {
    auto format(const ObjString &vt, fmt::format_context &ctx) const {
        const auto name = fmt::format("<str {}>", vt.get_string_view());
        return fmt::formatter<string_view>::format(name, ctx);
    }
};

#endif //OBJECT_H
