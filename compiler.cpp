#include "compiler.h"
#include "spdlog/spdlog.h"

void Compiler::debug_print(const std::shared_ptr<ObjFunction> &func) {
    // TODO: temporary approach
    for (auto& v:func->get_values()) {
        if (v.is_obj() && v.as_object()->is_type<ObjFunction>()) {
            v.as_function()->debug_print_chunk();
        }
    }
    func->debug_print_chunk();
}

CompiledResult Compiler::compile(loxParser::ProgramContext *program) {
    for (const auto dec: program->declaration()) {
        this->declaration(dec);
    }

    // final return
    this->function_->write_opcode(OP_NIL);
    this->function_->write_opcode(OP_RETURN);

    auto cr = CompiledResult{};
    cr.script = std::move(this->function_);
    cr.string_table = std::move(this->string_table_);

    return cr;
}

void Compiler::declaration(loxParser::DeclarationContext *ctx) {
    if (ctx->children.size() != 1) {
        throw std::format_error("declaration should have only ONE child");
    }
    const auto cld = ctx->children[0];
    /* class Dec */
    /* func Dec */
    if (const auto func_dec = dynamic_cast<loxParser::FunDecContext *>(cld); func_dec != nullptr) {
        this->func_dec(func_dec->function());
        return;
    }
    /* var Dec */
    if (const auto var_dec = dynamic_cast<loxParser::VarDecContext *>(cld); var_dec != nullptr) {
        this->variable_dec(var_dec);
        return;
    }
    /* statement */
    if (const auto stmt = dynamic_cast<loxParser::StatementContext *>(cld); stmt != nullptr) {
        this->statement(stmt);
        return;
    }
}

void Compiler::statement(const loxParser::StatementContext *ctx) {
    assert(ctx->children.size() == 1);
    const auto cld = ctx->children[0];
    /* exprStmt*/
    if (const auto expr_stmt = dynamic_cast<loxParser::ExprStmtContext *>(cld); expr_stmt != nullptr) {
        this->expression(expr_stmt->expression());
        // IMPORTANT: an individual expression statement should be followed by a pop!
        this->function_->write_opcode(OP_POP);
        return;
    }
    /* forStmt*/
    /* ifStmt*/
    if (const auto if_stmt = dynamic_cast<loxParser::IfStmtContext *>(cld); if_stmt != nullptr) {
        this->if_dec(if_stmt);
        return;
    }
    /* printStmt*/
    if (const auto print_stmt = dynamic_cast<loxParser::PrintStmtContext *>(cld); print_stmt != nullptr) {
        this->expression(print_stmt->expression());
        this->function_->write_opcode(OP_PRINT);
        return;
    }
    /* returnStmt*/
    if (const auto return_stmt = dynamic_cast<loxParser::ReturnStmtContext *>(cld); return_stmt != nullptr) {
        this->return_stmt(return_stmt);
        return;
    }
    /* whileStmt*/
    if (const auto while_stmt = dynamic_cast<loxParser::WhileStmtContext *>(cld); while_stmt != nullptr) {
        this->while_stmt(while_stmt);
        return;
    }
    /* block*/
    if (const auto block = dynamic_cast<loxParser::BlockContext *>(cld); block != nullptr) {
        auto sub_compiler = Compiler(this, true, true);
        sub_compiler.block_dec(block);
        // this->enter_scope();
        // this->block_dec(block);
        // this->exit_scope();
        return;
    }
}

void Compiler::expression(loxParser::ExpressionContext *ctx) {
    auto cld = ctx->assignment();
    this->assignment(cld);
}

// (call '.')? IDENTIFIER '=' assignment | logic_or
void Compiler::assignment(loxParser::AssignmentContext *ctx) {
    auto idx = 0;
    // call
    if (const auto cal = dynamic_cast<loxParser::CallContext *>(ctx->children[idx]); cal != nullptr) {
        // call '.' IDENTIFIER '=' assignment
        this->call_dec(cal);
        // jump over '.'
        idx += 2;
    }

    if (const auto ident = ctx->IDENTIFIER(); ident != nullptr) {
        // IDENTIFIER '=' assignment
        auto ident_name = ident->getText();
        // jump over '='
        idx += 2;
        // assignment
        const auto assig = dynamic_cast<loxParser::AssignmentContext *>(ctx->children[idx]);
        this->assignment(assig);

        // handle ident
        SPDLOG_DEBUG("assignment - identifier: {}", ident_name);
        this->handle_variable(std::move(ident_name), true);
    } else {
        const auto lo = dynamic_cast<loxParser::Logic_orContext *>(ctx->children[idx]);
        // logic_or
        this->logic_or(lo);
    }
}

void Compiler::logic_or(loxParser::Logic_orContext *ctx) {
    assert(ctx->children.size() % 2 == 1);
    const auto leftmost = dynamic_cast<loxParser::Logic_andContext *>(ctx->children[0]);
    if (leftmost == nullptr) {
        throw std::format_error("the leftmost in logic_or should not be null");
    }
    this->logic_and(leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        int else_jump = this->function_->emit_jump(OP_JUMP_IF_FALSE);
        int end_jump = this->function_->emit_jump(OP_JUMP);
        const auto right = dynamic_cast<loxParser::Logic_andContext *>(ctx->children[i * 2 + 2]);

        this->function_->patch_jump(else_jump);
        this->function_->write_opcode(OP_POP);

        this->logic_and(right);
        this->function_->patch_jump(end_jump);
    }
}

void Compiler::logic_and(loxParser::Logic_andContext *ctx) {
    assert(ctx->children.size() % 2 == 1);

    // handle the first eq
    const auto leftmost = dynamic_cast<loxParser::EqualityContext *>(ctx->children[0]);
    if (leftmost == nullptr) {
        throw std::format_error("the leftmost in logic_and should not be null");
    }
    this->equality(leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        int end_jump = this->function_->emit_jump(OP_JUMP_IF_FALSE);
        //const auto op = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[i * 2 + 1]);
        const auto right = dynamic_cast<loxParser::EqualityContext *>(ctx->children[i * 2 + 2]);

        this->function_->write_opcode(OP_POP);

        this->equality(right);

        this->function_->patch_jump(end_jump);
    }
}

void Compiler::equality(loxParser::EqualityContext *ctx) {
    assert(ctx->children.size() % 2 == 1);

    // handle the first term
    const auto comp_leftmost = dynamic_cast<loxParser::ComparisonContext *>(ctx->children[0]);
    if (comp_leftmost == nullptr) {
        throw std::format_error("the leftmost comp in eqaulity should not be null");
    }
    this->comparison(comp_leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        const auto op = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[i * 2 + 1]);
        const auto comp_2 = dynamic_cast<loxParser::ComparisonContext *>(ctx->children[i * 2 + 2]);

        this->comparison(comp_2);

        auto op_str = op->getText();
        std::cout << op_str << std::endl;
        this->function_->write_opcode(OP_EQUAL);
        if (op_str == "!=") {
            this->function_->write_opcode(OP_NOT);
        }
    }
}

void Compiler::comparison(const loxParser::ComparisonContext *ctx) {
    assert(ctx->children.size() % 2 == 1);

    // handle the first term
    const auto term_leftmost = dynamic_cast<loxParser::TermContext *>(ctx->children[0]);
    if (term_leftmost == nullptr) {
        throw std::format_error("the leftmost term in comparison should not be null");
    }
    this->term(term_leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        const auto op = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[i * 2 + 1]);
        const auto term_2 = dynamic_cast<loxParser::TermContext *>(ctx->children[i * 2 + 2]);

        this->term(term_2);

        auto op_str = op->getText();
        std::cout << op_str << std::endl;
        if (op_str == ">") {
            this->function_->write_opcode(OP_GREATER);
        } else if (op_str == "<") {
            this->function_->write_opcode(OP_LESS);
        } else if (op_str == "<=") {
            this->function_->write_opcode(OP_GREATER);
            this->function_->write_opcode(OP_NOT);
        } else {
            this->function_->write_opcode(OP_LESS);
            this->function_->write_opcode(OP_NOT);
        }
    }
}

void Compiler::term(const loxParser::TermContext *ctx) {
    assert(ctx->children.size() % 2 == 1);

    // handle the first unary
    const auto factor_leftmost = dynamic_cast<loxParser::FactorContext *>(ctx->children[0]);
    if (factor_leftmost == nullptr) {
        throw std::format_error("the leftmost unary in factor should not be null");
    }
    this->factor(factor_leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        const auto op = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[i * 2 + 1]);
        const auto factor_2 = dynamic_cast<loxParser::FactorContext *>(ctx->children[i * 2 + 2]);

        this->factor(factor_2);

        auto op_str = op->getText();
        std::cout << op_str << std::endl;
        if (op_str == "+") {
            this->function_->write_opcode(OP_ADD);
        } else {
            this->function_->write_opcode(OP_SUBTRACT);
        }
    }
}

void Compiler::factor(const loxParser::FactorContext *ctx) {
    assert(ctx->children.size() % 2 == 1);

    // handle the first unary
    const auto unary_leftmost = dynamic_cast<loxParser::UnaryContext *>(ctx->children[0]);
    if (unary_leftmost == nullptr) {
        throw std::format_error("the leftmost unary in factor should not be null");
    }
    this->unary(unary_leftmost);

    // then comes with a sequence of pairs
    for (int i = 0; i < (ctx->children.size() - 1) / 2; ++i) {
        const auto op = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[i * 2 + 1]);
        const auto unary_2 = dynamic_cast<loxParser::UnaryContext *>(ctx->children[i * 2 + 2]);

        this->unary(unary_2);

        auto op_str = op->getText();
        std::cout << op_str << std::endl;
        if (op_str == "*") {
            this->function_->write_opcode(OP_MULTIPLY);
        } else {
            this->function_->write_opcode(OP_DIVIDE);
        }
    }
}

void Compiler::unary(const loxParser::UnaryContext *ctx) {
    assert(ctx->children.size() <= 2);
    auto index = 0;
    // ! -
    std::string unary_op;
    if (ctx->children.size() > 1) {
        const auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(ctx->children[index++]);
        if (ter == nullptr) {
            throw std::format_error("ter should not be nullptr");
        }
        unary_op = ter->getText();
        std::cout << unary_op << std::endl;
    }

    // unary
    if (const auto unary = dynamic_cast<loxParser::UnaryContext *>(ctx->children[index]); unary != nullptr) {
        this->unary(unary);
    } else if (const auto cal = dynamic_cast<loxParser::CallContext *>(ctx->children[index]); cal != nullptr) {
        // call
        this->call_dec(cal);
    }

    if (!unary_op.empty()) {
        if (unary_op == "!") {
            this->function_->write_opcode(OP_NOT);
        } else {
            this->function_->write_opcode(OP_NEGATE);
        }
    }
}

void Compiler::call_dec(loxParser::CallContext *ctx) {
    // primary
    this->primary(ctx->primay());
    if (ctx->children.size() == 1) {
        return;
    }
    int arg_count = 0;
    // arguments
    auto args = ctx->arguments(0);
    if (args != nullptr) {
        arg_count = args->expression().size();
        this->arguments_dec(args);
    } else {
        // identifier

    }

    // finally, a call opcode
    this->function_->add_constant_opcode_with_index(OP_CALL, arg_count);
}

void Compiler::primary(loxParser::PrimayContext *ctx) {
    // NUMBER
    if (const auto number = ctx->NUMBER(); number != nullptr) {
        const auto n1 = std::stod(number->getText());
        std::cout << "primay - number: " << n1 << std::endl;

        this->function_->write_constant(n1);
        return;
    }
    // STRING_LITERAL
    if (const auto str = ctx->STRING_LITERAL(); str != nullptr) {
        auto s1 = str->getText();
        s1 = s1.substr(1, s1.length() - 2);
        std::cout << "primay - string: " << s1 << std::endl;

        this->function_->write_string(std::move(s1));
        return;
    }

    const auto f1 = ctx->children[0]->getText();
    // literal
    if (f1 == "true" || f1 == "false") {
        std::cout << "primay - literal: " << f1 << std::endl;
        this->function_->write_opcode(f1 == "true" ? OP_TRUE : OP_FALSE);
        return;
    }

    if (f1 == "nil") {
        std::cout << "primary - literal: nil" << std::endl;
        this->function_->write_opcode(OP_NIL);
        return;
    }

    if (f1 == "this") {
        std::cout << "primary - literal: this" << std::endl;
        return;
    }

    // (expression)
    if (f1 == "(") {
        this->expression(ctx->expression());
        return;
    }

    // super . IDENTIFIER
    if (f1 == "super") {
        auto v1 = ctx->IDENTIFIER();
        auto v1_name = v1->getText();

        return;
    }

    // IDENTIFIER
    if (const auto ident = ctx->IDENTIFIER(); ident != nullptr) {
        auto i1 = ident->getText();
        std::cout << "primay - identifier name: " << i1 << std::endl;
        this->handle_variable(std::move(i1), false);
    }
}

// actually, it just inserts the variable name into value array for global
// or push a new local for depth > 0
int Compiler::parse_variable(std::string ident_name) {
    auto index = -1;
    if (this->scope_depth_ == 0) {
        // global
        index = this->function_->write_string_only(std::move(ident_name));
    } else {
        // inside scope
        if (std::ranges::count_if(this->locals_, [&](const Local &l) { return l.name == ident_name; }) > 0) {
            throw std::runtime_error(fmt::format("duplicated variable declaration for: {}", ident_name));
        }
        // all locals need to be popped from stack,
        // so I put this to the destructor of the Compiler
        // we give the scope_depth as -1 to tag it as "uninitialized"
        this->locals_.push_back(Local{std::move(ident_name), -1, false});
    }

    return index;
}

void Compiler::mark_last_local_variable_as_initialized() {
    if (this->scope_depth_ == 0) {
        return;
    }
    // mark the local var as "initialized"
    this->locals_[this->locals_.size() - 1].scope_depth = this->scope_depth_;
}

// add a DEFINE_GLOBAL opcode for global
// or just mark as initialed for local
void Compiler::define_variable(int index) {
    if (this->scope_depth_ == 0) {
        // define global variable
        this->function_->add_constant_opcode_with_index(OP_DEFINE_GLOBAL, index);
    } else {
        this->mark_last_local_variable_as_initialized();
    }
}

void Compiler::variable_dec(loxParser::VarDecContext *ctx) {
    assert(ctx->children.size() >= 3);
    ctx->removeLastChild(); // omit ';'
    // 'var' IDENTIFIER ('=' expression)?
    const auto ident = ctx->IDENTIFIER();
    auto ident_name = ident->getText();

    /**
     * static uint8_t parseVariable(const char *errorMessage) {
            consume(TOKEN_IDENTIFIER, errorMessage);
            declareVariable {
                if (current->scopeDepth == 0) return;
                Token *name = &parser.previous;
                for (int i = current->localCount - 1; i >= 0; i--) {
                    Local *local = &current->locals[i];
                    if (local->depth != -1 && local->depth < current->scopeDepth) {
                        break;
                    }
                    if (identifiersEqual(name, &local->name)) {
                        error("Already a variable with this name in this scope.");
                    }
                }
                addLocal(Token name) {
                    Local* local = &current->locals[current->localCount++];
                    local->name = name;
                    local->depth = current->scopeDepth;
                }
            }
            if (current->scopeDepth > 0) return 0;
            return identifierConstant(&parser.previous);
        }
     **/
    auto index = this->parse_variable(std::move(ident_name));

    if (ctx->children.size() > 2) {
        // initializer
        this->expression(ctx->expression());
    } else {
        this->function_->write_opcode(OP_NIL);
    }

    /**
    *   static void defineVariable(uint8_t global) {
            if (current->scopeDepth > 0) {
                markInitialized();
                return;
            }
            emitBytes(OP_DEFINE_GLOBAL, global);
        }
     */
    // only need to use string to define var for global.
    this->define_variable(index);
}

void Compiler::block_dec(loxParser::BlockContext *ctx) {
    assert(ctx->children.size() >= 2);
    // skip '}'
    ctx->removeLastChild();
    // skip '{'
    for (auto i = 1; i < ctx->children.size(); i++) {
        if (const auto cld = dynamic_cast<loxParser::DeclarationContext *>(ctx->children[i]); cld != nullptr) {
            this->declaration(cld);
        }
    }
}

void Compiler::handle_variable(std::string ident_name, const bool is_set) {
    OpCode opcode;
    auto comp_func = [&](const LoxValue &lv) {
        if (lv.is_obj() && lv.as_object()->is_type<ObjString>() &&
            lv.as_string() == ident_name) { return true; }
        else { return false; }
    };

    // the already existed variable string, -1 for not exist, so we need to create a new one.
    auto index = -1;
    // if on global, then just flatly handle it
    if (this->scope_depth_ == 0) {
        index = find_variable<LoxValue>(this->function_->get_values(), comp_func);
        // if not exist, create a new one
        if (index < 0) {
            index = this->function_->write_string_only(std::move(ident_name));
        }

        // global
        opcode = is_set ? OP_SET_GLOBAL : OP_GET_GLOBAL;
    } else {
        // from local -> upvalue -> global to find corresponding var
        if (index = find_variable<Local>(this->locals_, [&](const Local &l) { return l.name == ident_name; });
                index >= 0) {
            // the var exist in local
            // we need to check if we are trying to refer to a local var during its initialization.
            if (this->locals_[index].scope_depth < 0) {
                throw std::format_error(
                        fmt::format("cannot refer to a local variable while itself was initializing: {}", ident_name));
            }
            // local
            opcode = is_set ? OP_SET_LOCAL : OP_GET_LOCAL;
        } else if (false) {
            // the var exist in upValue

            // upValue
            opcode = is_set ? OP_SET_UPVALUE : OP_GET_UPVALUE;
        } else {
            // check if exist in global
            // TODO: maybe we need to move all strings into the hashtable
            index = this->function_->write_string_only(std::move(ident_name));
            opcode = is_set ? OP_SET_GLOBAL : OP_GET_GLOBAL;
        }
    }

    this->function_->add_constant_opcode_with_index(opcode, index);
}

void Compiler::if_dec(loxParser::IfStmtContext *ctx) {
    // 'if' '(' expression ')' block ( 'else' block)?
    assert(ctx->children.size() >= 5);
    // expression
    this->expression(ctx->expression());
    // add jump tag
    auto jump_patch_pos = this->function_->emit_jump(OP_JUMP_IF_FALSE);
    this->function_->write_opcode(OP_POP);
    // block
    auto sub_compiler = Compiler(this, true, true);
    sub_compiler.block_dec(ctx->block(0));
    // jumping tag for jump over "else" branch
    auto jump_over_else = this->function_->emit_jump(OP_JUMP);
    // patch jump
    this->function_->patch_jump(jump_patch_pos);
    this->function_->write_opcode(OP_POP);
    // else
    if (ctx->children.size() > 5) {
        // has an else branch
        auto sub_else_compiler = Compiler(this, true, true);
        sub_else_compiler.block_dec(ctx->block(1));
    }
    this->function_->patch_jump(jump_over_else);
}

void Compiler::return_stmt(loxParser::ReturnStmtContext *ctx) {
    if (this->type_ == TYPE_SCRIPT) {
        throw std::format_error("cannot return from global context");
    }

    if (ctx->children.size() > 2) {
        this->expression(ctx->expression());
    } else {
        this->function_->write_opcode(OP_NIL);
    }
    this->function_->write_opcode(OP_RETURN);
}

void Compiler::while_stmt(loxParser::WhileStmtContext *ctx) {
    auto loop_start = this->function_->get_chunk().size();
    // loop condition
    this->expression(ctx->expression());

    auto exit_jump = this->function_->emit_jump(OP_JUMP_IF_FALSE);
    this->function_->write_opcode(OP_POP);
    auto sub_compiler = Compiler(this, true, true);
    sub_compiler.block_dec(ctx->block());

    this->function_->emit_loop(loop_start);

    this->function_->patch_jump(exit_jump);
    this->function_->write_opcode(OP_POP);
}

void Compiler::handle_function(FunctionType func_type, loxParser::ParametersContext *param_ctx,
                               loxParser::BlockContext *blk_ctx, std::string func_name) {
    auto func_compiler = Compiler(this, func_type, true);
    func_compiler.function_->set_function_name(std::move(func_name));

    // parameters
    if (param_ctx != nullptr) {
        const auto all_idents = param_ctx->IDENTIFIER();
        for (auto &ident: all_idents) {
            auto ident_name = ident->getText();
            func_compiler.function_->inc_arity();
            if (func_compiler.function_->get_arity() > 255) {
                throw std::format_error("can't have more than 255 parameters for a function");
            }
            auto idx = func_compiler.parse_variable(std::move(ident_name));
            func_compiler.define_variable(idx);
        }
    }
    // body
    func_compiler.block_dec(blk_ctx);

    this->function_->write_function(func_compiler.function_);
}

void Compiler::func_dec(loxParser::FunctionContext *ctx) {
    // IDENTIFIER '(' parameters? ')' block;
    auto ident = ctx->IDENTIFIER();
    auto ident_name = ident->getText();

    auto index = this->parse_variable(ident_name);
    this->mark_last_local_variable_as_initialized();

    // handle function body
    this->handle_function(TYPE_FUNCTION, ctx->parameters(), ctx->block(), std::move(ident_name));

    this->define_variable(index);
}

void Compiler::arguments_dec(loxParser::ArgumentsContext *ctx) {
    auto exps = ctx->expression();
    if (!exps.empty()) {
        for (auto exp: exps) {
            this->expression(exp);
        }
    }
}
// TODO: support debug print sub function.