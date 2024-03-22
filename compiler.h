//
// Created by zhouplus on 19/03/2024.
//

#ifndef COMPILER_H
#define COMPILER_H
#include <memory>
#include <string>

#include "chunk.h"
#include "loxParser.h"

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

enum FunctionType {
    TYPE_FUNCTION,
    TYPE_METHOD,
    TYPE_SCRIPT
};

class Object : std::enable_shared_from_this<Object> {
    bool is_marked_;
    ObjectType type_;
};

class ObjFunction : Object {
    int arity_;
    std::vector<uint8_t> chunk_;
    std::vector<LoxValue> value_array_;
    std::string function_name_;

public:
    ObjFunction(): arity_(0) {
        chunk_ = std::vector<uint8_t>();
        value_array_ = std::vector<LoxValue>();
    }

    void write_opcode(OpCode code);

    void write_constant(double value);

    void write_constant(bool value);

    int get_arity() const {
        return this->arity_;
    }
};

class Compiler : std::enable_shared_from_this<Compiler> {
    std::shared_ptr<Compiler> parent_compiler_;
    int scope_depth_;
    std::shared_ptr<ObjFunction> function_;

public:
    explicit Compiler(): scope_depth_(0) {
        parent_compiler_ = nullptr;
        function_ = std::make_shared<ObjFunction>();
    }

    Compiler(Compiler &parent_, FunctionType type): Compiler() {
        this->parent_compiler_ = parent_.shared_from_this();
        this->scope_depth_ = parent_.scope_depth_ + 1;
    }

    void compile(loxParser::ProgramContext *program);

    void declaration(loxParser::DeclarationContext *ctx);

    void statement(loxParser::StatementContext *stmt);

    void expression(loxParser::ExpressionContext *ctx);

    void assignment(loxParser::AssignmentContext *ctx);

    void logic_or(loxParser::Logic_orContext *ctx);

    void logic_and(loxParser::Logic_andContext *ctx);

    void equality(loxParser::EqualityContext *ctx);

    void comparison(loxParser::ComparisonContext *ctx);

    void term(loxParser::TermContext *ctx);

    void factor(loxParser::FactorContext *ctx);

    void unary(loxParser::UnaryContext *ctx);

    void call_dec(loxParser::CallContext *ctx);

    void primary(loxParser::PrimayContext *ctx);

    void argument_dec(loxParser::ArgumentsContext *ctx);
};

#endif //COMPILER_H
