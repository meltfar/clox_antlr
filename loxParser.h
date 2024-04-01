
// Generated from ./lox.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  loxParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, WHITESPACE = 38, 
    NEWLINE = 39, NUMBER = 40, STRING_LITERAL = 41, IDENTIFIER = 42, ALPHA = 43, 
    DIGIT = 44
  };

  enum {
    RuleProgram = 0, RuleDeclaration = 1, RuleClassDec = 2, RuleFunDec = 3, 
    RuleVarDec = 4, RuleStatement = 5, RuleExprStmt = 6, RuleForStmt = 7, 
    RuleIfStmt = 8, RulePrintStmt = 9, RuleReturnStmt = 10, RuleWhileStmt = 11, 
    RuleBreakStmt = 12, RuleContinueStmt = 13, RuleBlock = 14, RuleExpression = 15, 
    RuleAssignment = 16, RuleLogic_or = 17, RuleLogic_and = 18, RuleEquality = 19, 
    RuleComparison = 20, RuleTerm = 21, RuleFactor = 22, RuleUnary = 23, 
    RuleCall = 24, RulePrimay = 25, RuleFunction = 26, RuleParameters = 27, 
    RuleArguments = 28
  };

  explicit loxParser(antlr4::TokenStream *input);

  loxParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~loxParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class DeclarationContext;
  class ClassDecContext;
  class FunDecContext;
  class VarDecContext;
  class StatementContext;
  class ExprStmtContext;
  class ForStmtContext;
  class IfStmtContext;
  class PrintStmtContext;
  class ReturnStmtContext;
  class WhileStmtContext;
  class BreakStmtContext;
  class ContinueStmtContext;
  class BlockContext;
  class ExpressionContext;
  class AssignmentContext;
  class Logic_orContext;
  class Logic_andContext;
  class EqualityContext;
  class ComparisonContext;
  class TermContext;
  class FactorContext;
  class UnaryContext;
  class CallContext;
  class PrimayContext;
  class FunctionContext;
  class ParametersContext;
  class ArgumentsContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

   
  };

  ProgramContext* program();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassDecContext *classDec();
    FunDecContext *funDec();
    VarDecContext *varDec();
    StatementContext *statement();

   
  };

  DeclarationContext* declaration();

  class  ClassDecContext : public antlr4::ParserRuleContext {
  public:
    ClassDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);

   
  };

  ClassDecContext* classDec();

  class  FunDecContext : public antlr4::ParserRuleContext {
  public:
    FunDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();

   
  };

  FunDecContext* funDec();

  class  VarDecContext : public antlr4::ParserRuleContext {
  public:
    VarDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

   
  };

  VarDecContext* varDec();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprStmtContext *exprStmt();
    ForStmtContext *forStmt();
    IfStmtContext *ifStmt();
    PrintStmtContext *printStmt();
    ReturnStmtContext *returnStmt();
    WhileStmtContext *whileStmt();
    BreakStmtContext *breakStmt();
    ContinueStmtContext *continueStmt();
    BlockContext *block();

   
  };

  StatementContext* statement();

  class  ExprStmtContext : public antlr4::ParserRuleContext {
  public:
    ExprStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

   
  };

  ExprStmtContext* exprStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    VarDecContext *varDec();
    ExprStmtContext *exprStmt();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  ForStmtContext* forStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

   
  };

  IfStmtContext* ifStmt();

  class  PrintStmtContext : public antlr4::ParserRuleContext {
  public:
    PrintStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

   
  };

  PrintStmtContext* printStmt();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

   
  };

  ReturnStmtContext* returnStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    BlockContext *block();

   
  };

  WhileStmtContext* whileStmt();

  class  BreakStmtContext : public antlr4::ParserRuleContext {
  public:
    BreakStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  BreakStmtContext* breakStmt();

  class  ContinueStmtContext : public antlr4::ParserRuleContext {
  public:
    ContinueStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  ContinueStmtContext* continueStmt();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

   
  };

  BlockContext* block();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();

   
  };

  ExpressionContext* expression();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    AssignmentContext *assignment();
    CallContext *call();
    Logic_orContext *logic_or();

   
  };

  AssignmentContext* assignment();

  class  Logic_orContext : public antlr4::ParserRuleContext {
  public:
    Logic_orContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Logic_andContext *> logic_and();
    Logic_andContext* logic_and(size_t i);

   
  };

  Logic_orContext* logic_or();

  class  Logic_andContext : public antlr4::ParserRuleContext {
  public:
    Logic_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EqualityContext *> equality();
    EqualityContext* equality(size_t i);

   
  };

  Logic_andContext* logic_and();

  class  EqualityContext : public antlr4::ParserRuleContext {
  public:
    EqualityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComparisonContext *> comparison();
    ComparisonContext* comparison(size_t i);

   
  };

  EqualityContext* equality();

  class  ComparisonContext : public antlr4::ParserRuleContext {
  public:
    ComparisonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);

   
  };

  ComparisonContext* comparison();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);

   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryContext *> unary();
    UnaryContext* unary(size_t i);

   
  };

  FactorContext* factor();

  class  UnaryContext : public antlr4::ParserRuleContext {
  public:
    UnaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryContext *unary();
    CallContext *call();

   
  };

  UnaryContext* unary();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimayContext *primay();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<ArgumentsContext *> arguments();
    ArgumentsContext* arguments(size_t i);

   
  };

  CallContext* call();

  class  PrimayContext : public antlr4::ParserRuleContext {
  public:
    PrimayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

   
  };

  PrimayContext* primay();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    BlockContext *block();
    ParametersContext *parameters();

   
  };

  FunctionContext* function();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

   
  };

  ParametersContext* parameters();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  ArgumentsContext* arguments();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

