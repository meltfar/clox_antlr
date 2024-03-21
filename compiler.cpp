//
// Created by zhouplus on 19/03/2024.
//

#include "compiler.h"


void Compiler::compile(loxParser::ProgramContext *program) {
    for (auto dec: program->declaration()) {
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
    for (auto cld: ctx->children) {
        // call
        if (auto cal = dynamic_cast<loxParser::CallContext *>(cld); cal != nullptr) {
            continue;
        }
        // IDENTIFIER '=' assignment | logic_or;
        auto identifier = ctx->IDENTIFIER();
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
        auto ter = dynamic_cast<antlr4::tree::TerminalNodeImpl *>(cld);
        if (ter != nullptr) {
            std::cout << ter->getText() << std::endl;
        }
    }
}

void Compiler::comparison(loxParser::ComparisonContext *ctx) {
}
