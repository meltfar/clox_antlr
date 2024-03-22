//
// Created by zhouplus on 19/03/2024.
//

#include "compiler.h"


void ObjFunction::write_opcode(const OpCode code) {
    this->chunk_.push_back(code);
}

void ObjFunction::write_constant(const double value) {
    // constant value
    this->value_array_.emplace_back(value);

    // Format: OP_CON 01
    this->chunk_.push_back(OP_CONSTANT);
    this->chunk_.push_back(this->value_array_.size() - 1);
}

void ObjFunction::write_constant(bool value) {
    // constant value
    this->value_array_.emplace_back(value);

    // Format: OP_CON Index_of_value
    this->chunk_.push_back(OP_CONSTANT);
    this->chunk_.push_back(this->value_array_.size() - 1);
}

void Compiler::compile(loxParser::ProgramContext *program) {
    for (const auto dec: program->declaration()) {
        this->declaration(dec);
    }
}

void Compiler::declaration(loxParser::DeclarationContext *ctx) {
    if (ctx->children.size() != 1) {
        throw std::exception("declaration should have only ONE child");
    }
    auto cld = ctx->children[0];
    /* class Dec */
    /* func Dec */
    /* var Dec */
    /* statement */
    if (auto stmt = dynamic_cast<loxParser::StatementContext *>(cld); stmt != nullptr) {
        this->statement(stmt);
    }
}

void Compiler::statement(loxParser::StatementContext *ctx) {
    assert(ctx->children.size() == 1);
    auto cld = ctx->children[0];
    /* exprStmt*/
    if (auto expr_stmt = dynamic_cast<loxParser::ExprStmtContext *>(cld); expr_stmt != nullptr) {
        this->expression(expr_stmt->expression());
        return;
    }
    /* forStmt*/
    /* ifStmt*/
    /* printStmt*/
    /* returnStmt*/
    /* whileStmt*/
    /* block*/
}

void Compiler::expression(loxParser::ExpressionContext *ctx) {
    auto cld = ctx->assignment();
    this->assignment(cld);
}

void Compiler::assignment(loxParser::AssignmentContext *ctx) {
    auto ident = ctx->IDENTIFIER();
    for (auto cld: ctx->children) {
        // call
        if (auto cal = dynamic_cast<loxParser::CallContext *>(cld); cal != nullptr) {
            continue;
        }
        // IDENTIFIER '=' assignment | logic_or;
        // auto identifier = ctx->IDENTIFIER();
        if (auto assig = dynamic_cast<loxParser::AssignmentContext *>(cld); assig != nullptr) {
            this->assignment(assig);
        } else if (auto lo = dynamic_cast<loxParser::Logic_orContext *>(cld); lo != nullptr) {
            this->logic_or(lo);
        }
    }
}

void Compiler::logic_or(loxParser::Logic_orContext *ctx) {
    for (auto cld: ctx->children) {
        auto la = dynamic_cast<loxParser::Logic_andContext *>(cld);
        this->logic_and(la);
    }
}

void Compiler::logic_and(loxParser::Logic_andContext *ctx) {
    for (auto cld: ctx->children) {
        auto eq = dynamic_cast<loxParser::EqualityContext *>(cld);
        this->equality(eq);
    }
}

// TODO: 测试一下，是不是 等于号或者不等于号被丢掉了，得处理一下
void Compiler::equality(loxParser::EqualityContext *ctx) {
    for (auto cld: ctx->children) {
        // comparison
        if (auto comp = dynamic_cast<loxParser::ComparisonContext *>(cld); comp != nullptr) {
            this->comparison(comp);
            continue;
        }
        // == !=
        if (auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld); ter != nullptr) {
            std::cout << ter->getText() << std::endl;
        }
    }
}

void Compiler::comparison(loxParser::ComparisonContext *ctx) {
    for (auto cld: ctx->children) {
        // term
        if (auto term = dynamic_cast<loxParser::TermContext *>(cld); term != nullptr) {
            this->term(term);
            continue;
        }
        // < > <= >=
        if (auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld); ter != nullptr) {
            std::cout << ter->getText() << std::endl;
        }
    }
}

void Compiler::term(loxParser::TermContext *ctx) {
    for (auto cld: ctx->children) {
        // factor
        if (auto factor = dynamic_cast<loxParser::FactorContext *>(cld); factor != nullptr) {
            this->factor(factor);
            continue;
        }
        // + -
        if (auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld); ter != nullptr) {
            std::cout << ter->getText() << std::endl;
        }
    }
}

void Compiler::factor(loxParser::FactorContext *ctx) {
    for (auto cld: ctx->children) {
        // unary
        if (auto unary = dynamic_cast<loxParser::UnaryContext *>(cld); unary != nullptr) {
            this->unary(unary);
            continue;
        }
        // * /
        if (auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld); ter != nullptr) {
            std::cout << ter->getText() << std::endl;
        }
    }
}

void Compiler::unary(loxParser::UnaryContext *ctx) {
    for (auto cld: ctx->children) {
        // ! -
        if (auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld); ter != nullptr) {
            std::cout << ter->getText() << std::endl;
            continue;
        }
        // unary
        if (auto unary = dynamic_cast<loxParser::UnaryContext *>(cld); unary != nullptr) {
            this->unary(unary);
        }
        // call
        if (auto cal = dynamic_cast<loxParser::CallContext *>(cld); cal != nullptr) {
            this->call_dec(cal);
        }
    }
}

void Compiler::call_dec(loxParser::CallContext *ctx) {
    for (auto cld: ctx->children) {
        // primary
        if (auto pri = dynamic_cast<loxParser::PrimayContext *>(cld); pri != nullptr) {
            this->primary(pri);
            continue;
        }

        // arguments
        // identifier
    }
}

void Compiler::primary(loxParser::PrimayContext *ctx) {
    // NUMBER
    if (auto number = ctx->NUMBER(); number != nullptr) {
        auto n1 = std::stod(number->getText());
        std::cout << "primay - number: " << n1 << std::endl;

        this->function_->write_constant(n1);
        return;
    }
    // STRING_LITERAL
    if (auto str = ctx->STRING_LITERAL(); str != nullptr) {
        auto s1 = str->getText();
        s1 = s1.substr(1, s1.length() - 2);
        std::cout << "primay - string: " << s1 << std::endl;
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
        auto exp = ctx->expression();
        this->expression(exp);

        return;
    }

    // super . IDENTIFIER
    if (f1 == "super") {
        auto v1 = ctx->IDENTIFIER();
        auto v1_name = v1->getText();

        return;
    }

    // IDENTIFIER
    if (auto ident = ctx->IDENTIFIER(); ident != nullptr) {
        auto i1 = ident->getText();
        std::cout << "primay - identifier name: " << i1 << std::endl;
    }
}
