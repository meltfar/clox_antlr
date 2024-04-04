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
#include <chrono>

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
    spdlog::set_level(spdlog::level::trace);

    std::stringstream ss;
    ss << R"=(
    func fib(n) {
        if (n < 2) {
            return n;
        }
        return fib(n - 2) + fib(n - 1);
    }
    print fib(30);
)=";
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

    auto compiler = std::make_shared<Compiler>();
    auto [script, string_table] = compiler->compile(ctx);

    Compiler::debug_print(script);

    VM vm(std::move(string_table), std::move(script));

    auto start = std::chrono::system_clock::now();
    vm.execute();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "it takes: " << elapsed_seconds << "s to complete" << std::endl;
    return 0;
}
