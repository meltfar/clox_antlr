//
// Created by zhouplus on 16/03/2024.
//
#include "loxLexer.h"
#include "loxParser.h"
#include "antlr4-runtime.h"
#include <iostream>
#include <sstream>
#include <format>

#include "compiler.h"

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
    ss << "\"";
    ss << "sdfedfsdf";
    ss << "\" == 3.3;\n";
    ss << "\"wode\" == false;\n";
    ss << "\"wer\" != (2 + 3.2);\n";
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
    compiler.compile(ctx);

    return 0;
}
