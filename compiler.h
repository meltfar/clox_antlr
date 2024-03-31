//
// Created by zhouplus on 19/03/2024.
//

#ifndef COMPILER_H
#define COMPILER_H
#include <memory>
#include <spdlog/spdlog.h>

#include "object.h"
#include "loxParser.h"


enum FunctionType {
    TYPE_FUNCTION,
    TYPE_METHOD,
    TYPE_SCRIPT
};

struct CompiledResult {
    std::shared_ptr<ObjFunction> script;
    std::unordered_map<std::string, LoxValue> string_table;
};

struct Local {
    std::string name;
    int scope_depth;
    bool is_captured;
};

class Compiler : std::enable_shared_from_this<Compiler> {
    Compiler* parent_compiler_;
    int scope_depth_;
    std::shared_ptr<ObjFunction> function_;
    std::unordered_map<std::string, LoxValue> string_table_;
    std::vector<Local> locals_;
    FunctionType type_;

public:
    explicit Compiler(): scope_depth_(0), type_(TYPE_SCRIPT) {
        parent_compiler_ = nullptr;
        function_ = std::make_shared<ObjFunction>();
        this->locals_ = std::vector<Local>();
    }

    Compiler(const Compiler&) = delete;

    Compiler(Compiler &parent_, FunctionType type): Compiler() {
        this->parent_compiler_ = &parent_;
        this->scope_depth_ = parent_.scope_depth_ + 1;
    }

    // get into block (for, while, bare block...)
    explicit Compiler(Compiler* parent_)  {
        this->parent_compiler_ = parent_; // TODO: Do I really need this?
        this->scope_depth_ = parent_->scope_depth_ + 1;
        this->function_ = parent_->function_;
    }

    // exiting blocks
    ~Compiler() {
        SPDLOG_DEBUG("======== ~ compiler ========");
        SPDLOG_DEBUG("destructing compiler at scope depth: {}", this->scope_depth_);
        if (!this->locals_.empty()) {
            for (auto& s: this->locals_) {
                // if it was captured, then push (OP_CLOSE_UPVALUE)
                if (s.is_captured) {
                    SPDLOG_DEBUG("add a CLOSE UpValue for captured local: {} [depth: {}]", s.name, s.scope_depth);
                    this->function_->write_opcode(OP_CLOSE_UPVALUE);
                } else {
                    SPDLOG_DEBUG("add a pop opcode for local: {} [depth: {}]", s.name, s.scope_depth);
                    this->function_->write_opcode(OP_POP);
                }
            }
        }
        SPDLOG_DEBUG("======== ~ compiler over ========");
    }

    static void debug_print(const std::shared_ptr<ObjFunction> &func);

    CompiledResult compile(loxParser::ProgramContext *program);

    void declaration(loxParser::DeclarationContext *ctx);

    void statement(const loxParser::StatementContext *ctx);

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

    void block_dec(loxParser::BlockContext* ctx);

    void if_dec(loxParser::IfStmtContext* ctx);

    void return_stmt(loxParser::ReturnStmtContext* ctx);

    void while_stmt(loxParser::WhileStmtContext* ctx);

    void enter_scope();

    void exit_scope();

    void handle_variable(std::string ident_name, bool is_set);

    template<typename T>
    int find_variable(const std::vector<T>& container, std::function<bool(const T&)> dest) {
        for (auto i = 0; i < container.size(); i ++) {
            if (auto& v = container[i]; dest(v)) {
                return i;
            }
        }

        return -1;
    }
};

#endif //COMPILER_H
