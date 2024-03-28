//
// Created by zhouplus on 16/03/2024.
//
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "loxLexer.h"
#include "loxParser.h"
#include "antlr4-runtime.h"
#include <iostream>
#include <sstream>
#include <format>

#include "compiler.h"
#include "vm.h"

using namespace std;

class LoxErrorListener final : public antlr4::BaseErrorListener {
    std::string err_msg_;

    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {
        this->err_msg_ += std::format("line {}:{} {}", line, charPositionInLine, msg);
    }

public:
    [[nodiscard]] bool has_error() const {
        return !this->err_msg_.empty();
    }

    [[nodiscard]] const std::string &get_error_msg() const {
        return this->err_msg_;
    }
};

int main() {
    std::stringstream ss;
    ss << "var idid = \"abc\";\n";
    ss << "var second = idid + \"efg\";\n";
    ss << "idid = \"newidid\";\n";
    ss << "print idid;\n";
    ss << "print second;\n";
    antlr4::ANTLRInputStream input(ss);
    loxLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    LoxErrorListener listener;
    loxParser parser(&tokens);
    parser.addErrorListener(&listener);

    auto ctx = parser.program();

    if (listener.has_error()) {
        std::cerr << "error occurred: \n" << listener.get_error_msg() << std::endl;
        return 1;
    }

    Compiler compiler;
    auto [script, string_table] = compiler.compile(ctx);

    Compiler::debug_print(script);

    VM vm(std::move(string_table), std::move(script));
    vm.execute();

    return 0;
}
