//
// Created by zhouplus on 19/03/2024.
//

#ifndef COMPILER_H
#define COMPILER_H
#include <memory>
#include "object.h"
#include "loxParser.h"


enum FunctionType {
    TYPE_FUNCTION,
    TYPE_METHOD,
    TYPE_SCRIPT
};

struct CompiledResult {
    std::shared_ptr<ObjFunction> script;
    std::unordered_map<std::string, std::shared_ptr<LoxValue> > string_table;
};


class Compiler : std::enable_shared_from_this<Compiler> {
    std::shared_ptr<Compiler> parent_compiler_;
    int scope_depth_;
    std::shared_ptr<ObjFunction> function_;
    std::unordered_map<std::string, std::shared_ptr<LoxValue> > string_table_;

public:
    explicit Compiler(): scope_depth_(0) {
        parent_compiler_ = nullptr;
        function_ = std::make_shared<ObjFunction>();
    }

    Compiler(Compiler &parent_, FunctionType type): Compiler() {
        this->parent_compiler_ = parent_.shared_from_this();
        this->scope_depth_ = parent_.scope_depth_ + 1;
    }

    static void debug_print(const std::shared_ptr<ObjFunction> &func);

    CompiledResult compile(loxParser::ProgramContext *program);

    void declaration(loxParser::DeclarationContext *ctx);

    void statement(loxParser::StatementContext *stmt);

    void expression(loxParser::ExpressionContext *ctx);

    void assignment(loxParser::AssignmentContext *ctx);

    void logic_or(loxParser::Logic_orContext *ctx);

    void logic_and(loxParser::Logic_andContext *ctx);

    void equality(loxParser::EqualityContext *ctx);

    void comparison(const loxParser::ComparisonContext *ctx);

    void term(const loxParser::TermContext *ctx);

    void factor(const loxParser::FactorContext *ctx);

    void unary(const loxParser::UnaryContext *ctx);

    void call_dec(loxParser::CallContext *ctx);

    void primary(loxParser::PrimayContext *ctx);

    void argument_dec(loxParser::ArgumentsContext *ctx);

    void variable_dec(loxParser::VarDecContext *ctx);
};

#endif //COMPILER_H
