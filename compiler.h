//
// Created by zhouplus on 19/03/2024.
//

#ifndef COMPILER_H
#define COMPILER_H
#include <memory>
#include <string>

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

class Compiler : std::enable_shared_from_this<Compiler> {
    std::shared_ptr<Compiler> parent_compiler_;
    int scope_depth_;

public:
    explicit Compiler(): scope_depth_(0) {
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
};


class Object : std::enable_shared_from_this<Object> {
    bool is_marked_;
    ObjectType type_;
};

class ObjFunction : Object {
    int arity_;
    std::vector<uint8_t> chunk_;
    std::string function_name_;
};

#endif //COMPILER_H
