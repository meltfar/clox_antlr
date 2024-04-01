
// Generated from ./lox.g4 by ANTLR 4.13.1



#include "loxParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LoxParserStaticData final {
  LoxParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LoxParserStaticData(const LoxParserStaticData&) = delete;
  LoxParserStaticData(LoxParserStaticData&&) = delete;
  LoxParserStaticData& operator=(const LoxParserStaticData&) = delete;
  LoxParserStaticData& operator=(LoxParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag loxParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LoxParserStaticData *loxParserStaticData = nullptr;

void loxParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (loxParserStaticData != nullptr) {
    return;
  }
#else
  assert(loxParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LoxParserStaticData>(
    std::vector<std::string>{
      "program", "declaration", "classDec", "funDec", "varDec", "statement", 
      "exprStmt", "forStmt", "ifStmt", "printStmt", "returnStmt", "whileStmt", 
      "breakStmt", "continueStmt", "block", "expression", "assignment", 
      "logic_or", "logic_and", "equality", "comparison", "term", "factor", 
      "unary", "call", "primay", "function", "parameters", "arguments"
    },
    std::vector<std::string>{
      "", "'class'", "'('", "')'", "'{'", "'}'", "'func'", "'var'", "'='", 
      "';'", "'for'", "'if'", "'else'", "'print'", "'return'", "'while'", 
      "'break'", "'continue'", "'.'", "'or'", "'and'", "'!='", "'=='", "'>'", 
      "'>='", "'<'", "'<='", "'-'", "'+'", "'/'", "'*'", "'!'", "'true'", 
      "'false'", "'nil'", "'this'", "'super'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "WHITESPACE", "NEWLINE", "NUMBER", "STRING_LITERAL", 
      "IDENTIFIER", "ALPHA", "DIGIT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,291,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,1,71,8,1,
  	1,2,1,2,1,2,1,2,1,2,3,2,78,8,2,1,2,1,2,5,2,82,8,2,10,2,12,2,85,9,2,1,
  	2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,4,3,4,96,8,4,1,4,1,4,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,3,5,109,8,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,7,119,
  	8,7,1,7,3,7,122,8,7,1,7,1,7,3,7,126,8,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,3,8,139,8,8,1,9,1,9,1,9,1,9,1,10,1,10,3,10,147,8,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,
  	1,14,5,14,165,8,14,10,14,12,14,168,9,14,1,14,1,14,1,15,1,15,1,16,1,16,
  	1,16,3,16,177,8,16,1,16,1,16,1,16,1,16,3,16,183,8,16,1,17,1,17,1,17,5,
  	17,188,8,17,10,17,12,17,191,9,17,1,18,1,18,1,18,5,18,196,8,18,10,18,12,
  	18,199,9,18,1,19,1,19,1,19,5,19,204,8,19,10,19,12,19,207,9,19,1,20,1,
  	20,1,20,5,20,212,8,20,10,20,12,20,215,9,20,1,21,1,21,1,21,5,21,220,8,
  	21,10,21,12,21,223,9,21,1,22,1,22,1,22,5,22,228,8,22,10,22,12,22,231,
  	9,22,1,23,1,23,1,23,3,23,236,8,23,1,24,1,24,1,24,3,24,241,8,24,1,24,1,
  	24,1,24,5,24,246,8,24,10,24,12,24,249,9,24,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,265,8,25,1,26,1,26,1,
  	26,3,26,270,8,26,1,26,1,26,1,26,1,27,1,27,1,27,5,27,278,8,27,10,27,12,
  	27,281,9,27,1,28,1,28,1,28,5,28,286,8,28,10,28,12,28,289,9,28,1,28,0,
  	0,29,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,0,5,1,0,21,22,1,0,23,26,1,0,27,28,1,0,29,30,2,0,27,
  	27,31,31,306,0,61,1,0,0,0,2,70,1,0,0,0,4,72,1,0,0,0,6,88,1,0,0,0,8,91,
  	1,0,0,0,10,108,1,0,0,0,12,110,1,0,0,0,14,113,1,0,0,0,16,131,1,0,0,0,18,
  	140,1,0,0,0,20,144,1,0,0,0,22,150,1,0,0,0,24,156,1,0,0,0,26,159,1,0,0,
  	0,28,162,1,0,0,0,30,171,1,0,0,0,32,182,1,0,0,0,34,184,1,0,0,0,36,192,
  	1,0,0,0,38,200,1,0,0,0,40,208,1,0,0,0,42,216,1,0,0,0,44,224,1,0,0,0,46,
  	235,1,0,0,0,48,237,1,0,0,0,50,264,1,0,0,0,52,266,1,0,0,0,54,274,1,0,0,
  	0,56,282,1,0,0,0,58,60,3,2,1,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,
  	0,0,61,62,1,0,0,0,62,64,1,0,0,0,63,61,1,0,0,0,64,65,5,0,0,1,65,1,1,0,
  	0,0,66,71,3,4,2,0,67,71,3,6,3,0,68,71,3,8,4,0,69,71,3,10,5,0,70,66,1,
  	0,0,0,70,67,1,0,0,0,70,68,1,0,0,0,70,69,1,0,0,0,71,3,1,0,0,0,72,73,5,
  	1,0,0,73,77,5,42,0,0,74,75,5,2,0,0,75,76,5,42,0,0,76,78,5,3,0,0,77,74,
  	1,0,0,0,77,78,1,0,0,0,78,79,1,0,0,0,79,83,5,4,0,0,80,82,3,52,26,0,81,
  	80,1,0,0,0,82,85,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,86,1,0,0,0,85,
  	83,1,0,0,0,86,87,5,5,0,0,87,5,1,0,0,0,88,89,5,6,0,0,89,90,3,52,26,0,90,
  	7,1,0,0,0,91,92,5,7,0,0,92,95,5,42,0,0,93,94,5,8,0,0,94,96,3,30,15,0,
  	95,93,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,98,5,9,0,0,98,9,1,0,0,0,
  	99,109,3,12,6,0,100,109,3,14,7,0,101,109,3,16,8,0,102,109,3,18,9,0,103,
  	109,3,20,10,0,104,109,3,22,11,0,105,109,3,24,12,0,106,109,3,26,13,0,107,
  	109,3,28,14,0,108,99,1,0,0,0,108,100,1,0,0,0,108,101,1,0,0,0,108,102,
  	1,0,0,0,108,103,1,0,0,0,108,104,1,0,0,0,108,105,1,0,0,0,108,106,1,0,0,
  	0,108,107,1,0,0,0,109,11,1,0,0,0,110,111,3,30,15,0,111,112,5,9,0,0,112,
  	13,1,0,0,0,113,114,5,10,0,0,114,118,5,2,0,0,115,119,3,8,4,0,116,119,3,
  	12,6,0,117,119,5,9,0,0,118,115,1,0,0,0,118,116,1,0,0,0,118,117,1,0,0,
  	0,119,121,1,0,0,0,120,122,3,30,15,0,121,120,1,0,0,0,121,122,1,0,0,0,122,
  	123,1,0,0,0,123,125,5,9,0,0,124,126,3,30,15,0,125,124,1,0,0,0,125,126,
  	1,0,0,0,126,127,1,0,0,0,127,128,5,9,0,0,128,129,5,3,0,0,129,130,3,28,
  	14,0,130,15,1,0,0,0,131,132,5,11,0,0,132,133,5,2,0,0,133,134,3,30,15,
  	0,134,135,5,3,0,0,135,138,3,28,14,0,136,137,5,12,0,0,137,139,3,28,14,
  	0,138,136,1,0,0,0,138,139,1,0,0,0,139,17,1,0,0,0,140,141,5,13,0,0,141,
  	142,3,30,15,0,142,143,5,9,0,0,143,19,1,0,0,0,144,146,5,14,0,0,145,147,
  	3,30,15,0,146,145,1,0,0,0,146,147,1,0,0,0,147,148,1,0,0,0,148,149,5,9,
  	0,0,149,21,1,0,0,0,150,151,5,15,0,0,151,152,5,2,0,0,152,153,3,30,15,0,
  	153,154,5,3,0,0,154,155,3,28,14,0,155,23,1,0,0,0,156,157,5,16,0,0,157,
  	158,5,9,0,0,158,25,1,0,0,0,159,160,5,17,0,0,160,161,5,9,0,0,161,27,1,
  	0,0,0,162,166,5,4,0,0,163,165,3,2,1,0,164,163,1,0,0,0,165,168,1,0,0,0,
  	166,164,1,0,0,0,166,167,1,0,0,0,167,169,1,0,0,0,168,166,1,0,0,0,169,170,
  	5,5,0,0,170,29,1,0,0,0,171,172,3,32,16,0,172,31,1,0,0,0,173,174,3,48,
  	24,0,174,175,5,18,0,0,175,177,1,0,0,0,176,173,1,0,0,0,176,177,1,0,0,0,
  	177,178,1,0,0,0,178,179,5,42,0,0,179,180,5,8,0,0,180,183,3,32,16,0,181,
  	183,3,34,17,0,182,176,1,0,0,0,182,181,1,0,0,0,183,33,1,0,0,0,184,189,
  	3,36,18,0,185,186,5,19,0,0,186,188,3,36,18,0,187,185,1,0,0,0,188,191,
  	1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,35,1,0,0,0,191,189,1,0,0,
  	0,192,197,3,38,19,0,193,194,5,20,0,0,194,196,3,38,19,0,195,193,1,0,0,
  	0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,37,1,0,0,0,199,
  	197,1,0,0,0,200,205,3,40,20,0,201,202,7,0,0,0,202,204,3,40,20,0,203,201,
  	1,0,0,0,204,207,1,0,0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,39,1,0,0,
  	0,207,205,1,0,0,0,208,213,3,42,21,0,209,210,7,1,0,0,210,212,3,42,21,0,
  	211,209,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,41,
  	1,0,0,0,215,213,1,0,0,0,216,221,3,44,22,0,217,218,7,2,0,0,218,220,3,44,
  	22,0,219,217,1,0,0,0,220,223,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,
  	222,43,1,0,0,0,223,221,1,0,0,0,224,229,3,46,23,0,225,226,7,3,0,0,226,
  	228,3,46,23,0,227,225,1,0,0,0,228,231,1,0,0,0,229,227,1,0,0,0,229,230,
  	1,0,0,0,230,45,1,0,0,0,231,229,1,0,0,0,232,233,7,4,0,0,233,236,3,46,23,
  	0,234,236,3,48,24,0,235,232,1,0,0,0,235,234,1,0,0,0,236,47,1,0,0,0,237,
  	247,3,50,25,0,238,240,5,2,0,0,239,241,3,56,28,0,240,239,1,0,0,0,240,241,
  	1,0,0,0,241,242,1,0,0,0,242,246,5,3,0,0,243,244,5,18,0,0,244,246,5,42,
  	0,0,245,238,1,0,0,0,245,243,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,247,
  	248,1,0,0,0,248,49,1,0,0,0,249,247,1,0,0,0,250,265,5,32,0,0,251,265,5,
  	33,0,0,252,265,5,34,0,0,253,265,5,35,0,0,254,265,5,40,0,0,255,265,5,41,
  	0,0,256,265,5,42,0,0,257,258,5,2,0,0,258,259,3,30,15,0,259,260,5,3,0,
  	0,260,265,1,0,0,0,261,262,5,36,0,0,262,263,5,18,0,0,263,265,5,42,0,0,
  	264,250,1,0,0,0,264,251,1,0,0,0,264,252,1,0,0,0,264,253,1,0,0,0,264,254,
  	1,0,0,0,264,255,1,0,0,0,264,256,1,0,0,0,264,257,1,0,0,0,264,261,1,0,0,
  	0,265,51,1,0,0,0,266,267,5,42,0,0,267,269,5,2,0,0,268,270,3,54,27,0,269,
  	268,1,0,0,0,269,270,1,0,0,0,270,271,1,0,0,0,271,272,5,3,0,0,272,273,3,
  	28,14,0,273,53,1,0,0,0,274,279,5,42,0,0,275,276,5,37,0,0,276,278,5,42,
  	0,0,277,275,1,0,0,0,278,281,1,0,0,0,279,277,1,0,0,0,279,280,1,0,0,0,280,
  	55,1,0,0,0,281,279,1,0,0,0,282,287,3,30,15,0,283,284,5,37,0,0,284,286,
  	3,30,15,0,285,283,1,0,0,0,286,289,1,0,0,0,287,285,1,0,0,0,287,288,1,0,
  	0,0,288,57,1,0,0,0,289,287,1,0,0,0,28,61,70,77,83,95,108,118,121,125,
  	138,146,166,176,182,189,197,205,213,221,229,235,240,245,247,264,269,279,
  	287
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  loxParserStaticData = staticData.release();
}

}

loxParser::loxParser(TokenStream *input) : loxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

loxParser::loxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  loxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *loxParserStaticData->atn, loxParserStaticData->decisionToDFA, loxParserStaticData->sharedContextCache, options);
}

loxParser::~loxParser() {
  delete _interpreter;
}

const atn::ATN& loxParser::getATN() const {
  return *loxParserStaticData->atn;
}

std::string loxParser::getGrammarFileName() const {
  return "lox.g4";
}

const std::vector<std::string>& loxParser::getRuleNames() const {
  return loxParserStaticData->ruleNames;
}

const dfa::Vocabulary& loxParser::getVocabulary() const {
  return loxParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView loxParser::getSerializedATN() const {
  return loxParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

loxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* loxParser::ProgramContext::EOF() {
  return getToken(loxParser::EOF, 0);
}

std::vector<loxParser::DeclarationContext *> loxParser::ProgramContext::declaration() {
  return getRuleContexts<loxParser::DeclarationContext>();
}

loxParser::DeclarationContext* loxParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<loxParser::DeclarationContext>(i);
}


size_t loxParser::ProgramContext::getRuleIndex() const {
  return loxParser::RuleProgram;
}


loxParser::ProgramContext* loxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, loxParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7832007339222) != 0)) {
      setState(58);
      declaration();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(loxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

loxParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ClassDecContext* loxParser::DeclarationContext::classDec() {
  return getRuleContext<loxParser::ClassDecContext>(0);
}

loxParser::FunDecContext* loxParser::DeclarationContext::funDec() {
  return getRuleContext<loxParser::FunDecContext>(0);
}

loxParser::VarDecContext* loxParser::DeclarationContext::varDec() {
  return getRuleContext<loxParser::VarDecContext>(0);
}

loxParser::StatementContext* loxParser::DeclarationContext::statement() {
  return getRuleContext<loxParser::StatementContext>(0);
}


size_t loxParser::DeclarationContext::getRuleIndex() const {
  return loxParser::RuleDeclaration;
}


loxParser::DeclarationContext* loxParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, loxParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        classDec();
        break;
      }

      case loxParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(67);
        funDec();
        break;
      }

      case loxParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(68);
        varDec();
        break;
      }

      case loxParser::T__1:
      case loxParser::T__3:
      case loxParser::T__9:
      case loxParser::T__10:
      case loxParser::T__12:
      case loxParser::T__13:
      case loxParser::T__14:
      case loxParser::T__15:
      case loxParser::T__16:
      case loxParser::T__26:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::T__34:
      case loxParser::T__35:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(69);
        statement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDecContext ------------------------------------------------------------------

loxParser::ClassDecContext::ClassDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> loxParser::ClassDecContext::IDENTIFIER() {
  return getTokens(loxParser::IDENTIFIER);
}

tree::TerminalNode* loxParser::ClassDecContext::IDENTIFIER(size_t i) {
  return getToken(loxParser::IDENTIFIER, i);
}

std::vector<loxParser::FunctionContext *> loxParser::ClassDecContext::function() {
  return getRuleContexts<loxParser::FunctionContext>();
}

loxParser::FunctionContext* loxParser::ClassDecContext::function(size_t i) {
  return getRuleContext<loxParser::FunctionContext>(i);
}


size_t loxParser::ClassDecContext::getRuleIndex() const {
  return loxParser::RuleClassDec;
}


loxParser::ClassDecContext* loxParser::classDec() {
  ClassDecContext *_localctx = _tracker.createInstance<ClassDecContext>(_ctx, getState());
  enterRule(_localctx, 4, loxParser::RuleClassDec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(loxParser::T__0);
    setState(73);
    match(loxParser::IDENTIFIER);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__1) {
      setState(74);
      match(loxParser::T__1);
      setState(75);
      match(loxParser::IDENTIFIER);
      setState(76);
      match(loxParser::T__2);
    }
    setState(79);
    match(loxParser::T__3);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::IDENTIFIER) {
      setState(80);
      function();
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    match(loxParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunDecContext ------------------------------------------------------------------

loxParser::FunDecContext::FunDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::FunctionContext* loxParser::FunDecContext::function() {
  return getRuleContext<loxParser::FunctionContext>(0);
}


size_t loxParser::FunDecContext::getRuleIndex() const {
  return loxParser::RuleFunDec;
}


loxParser::FunDecContext* loxParser::funDec() {
  FunDecContext *_localctx = _tracker.createInstance<FunDecContext>(_ctx, getState());
  enterRule(_localctx, 6, loxParser::RuleFunDec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(loxParser::T__5);
    setState(89);
    function();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDecContext ------------------------------------------------------------------

loxParser::VarDecContext::VarDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* loxParser::VarDecContext::IDENTIFIER() {
  return getToken(loxParser::IDENTIFIER, 0);
}

loxParser::ExpressionContext* loxParser::VarDecContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}


size_t loxParser::VarDecContext::getRuleIndex() const {
  return loxParser::RuleVarDec;
}


loxParser::VarDecContext* loxParser::varDec() {
  VarDecContext *_localctx = _tracker.createInstance<VarDecContext>(_ctx, getState());
  enterRule(_localctx, 8, loxParser::RuleVarDec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(loxParser::T__6);
    setState(92);
    match(loxParser::IDENTIFIER);
    setState(95);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__7) {
      setState(93);
      match(loxParser::T__7);
      setState(94);
      expression();
    }
    setState(97);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

loxParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExprStmtContext* loxParser::StatementContext::exprStmt() {
  return getRuleContext<loxParser::ExprStmtContext>(0);
}

loxParser::ForStmtContext* loxParser::StatementContext::forStmt() {
  return getRuleContext<loxParser::ForStmtContext>(0);
}

loxParser::IfStmtContext* loxParser::StatementContext::ifStmt() {
  return getRuleContext<loxParser::IfStmtContext>(0);
}

loxParser::PrintStmtContext* loxParser::StatementContext::printStmt() {
  return getRuleContext<loxParser::PrintStmtContext>(0);
}

loxParser::ReturnStmtContext* loxParser::StatementContext::returnStmt() {
  return getRuleContext<loxParser::ReturnStmtContext>(0);
}

loxParser::WhileStmtContext* loxParser::StatementContext::whileStmt() {
  return getRuleContext<loxParser::WhileStmtContext>(0);
}

loxParser::BreakStmtContext* loxParser::StatementContext::breakStmt() {
  return getRuleContext<loxParser::BreakStmtContext>(0);
}

loxParser::ContinueStmtContext* loxParser::StatementContext::continueStmt() {
  return getRuleContext<loxParser::ContinueStmtContext>(0);
}

loxParser::BlockContext* loxParser::StatementContext::block() {
  return getRuleContext<loxParser::BlockContext>(0);
}


size_t loxParser::StatementContext::getRuleIndex() const {
  return loxParser::RuleStatement;
}


loxParser::StatementContext* loxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, loxParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__1:
      case loxParser::T__26:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::T__34:
      case loxParser::T__35:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        exprStmt();
        break;
      }

      case loxParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        forStmt();
        break;
      }

      case loxParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(101);
        ifStmt();
        break;
      }

      case loxParser::T__12: {
        enterOuterAlt(_localctx, 4);
        setState(102);
        printStmt();
        break;
      }

      case loxParser::T__13: {
        enterOuterAlt(_localctx, 5);
        setState(103);
        returnStmt();
        break;
      }

      case loxParser::T__14: {
        enterOuterAlt(_localctx, 6);
        setState(104);
        whileStmt();
        break;
      }

      case loxParser::T__15: {
        enterOuterAlt(_localctx, 7);
        setState(105);
        breakStmt();
        break;
      }

      case loxParser::T__16: {
        enterOuterAlt(_localctx, 8);
        setState(106);
        continueStmt();
        break;
      }

      case loxParser::T__3: {
        enterOuterAlt(_localctx, 9);
        setState(107);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStmtContext ------------------------------------------------------------------

loxParser::ExprStmtContext::ExprStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExpressionContext* loxParser::ExprStmtContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}


size_t loxParser::ExprStmtContext::getRuleIndex() const {
  return loxParser::RuleExprStmt;
}


loxParser::ExprStmtContext* loxParser::exprStmt() {
  ExprStmtContext *_localctx = _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, loxParser::RuleExprStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    expression();
    setState(111);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

loxParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::BlockContext* loxParser::ForStmtContext::block() {
  return getRuleContext<loxParser::BlockContext>(0);
}

loxParser::VarDecContext* loxParser::ForStmtContext::varDec() {
  return getRuleContext<loxParser::VarDecContext>(0);
}

loxParser::ExprStmtContext* loxParser::ForStmtContext::exprStmt() {
  return getRuleContext<loxParser::ExprStmtContext>(0);
}

std::vector<loxParser::ExpressionContext *> loxParser::ForStmtContext::expression() {
  return getRuleContexts<loxParser::ExpressionContext>();
}

loxParser::ExpressionContext* loxParser::ForStmtContext::expression(size_t i) {
  return getRuleContext<loxParser::ExpressionContext>(i);
}


size_t loxParser::ForStmtContext::getRuleIndex() const {
  return loxParser::RuleForStmt;
}


loxParser::ForStmtContext* loxParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, loxParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(loxParser::T__9);
    setState(114);
    match(loxParser::T__1);
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__6: {
        setState(115);
        varDec();
        break;
      }

      case loxParser::T__1:
      case loxParser::T__26:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::T__34:
      case loxParser::T__35:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        setState(116);
        exprStmt();
        break;
      }

      case loxParser::T__8: {
        setState(117);
        match(loxParser::T__8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7832007081988) != 0)) {
      setState(120);
      expression();
    }
    setState(123);
    match(loxParser::T__8);
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7832007081988) != 0)) {
      setState(124);
      expression();
    }
    setState(127);
    match(loxParser::T__8);
    setState(128);
    match(loxParser::T__2);
    setState(129);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

loxParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExpressionContext* loxParser::IfStmtContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}

std::vector<loxParser::BlockContext *> loxParser::IfStmtContext::block() {
  return getRuleContexts<loxParser::BlockContext>();
}

loxParser::BlockContext* loxParser::IfStmtContext::block(size_t i) {
  return getRuleContext<loxParser::BlockContext>(i);
}


size_t loxParser::IfStmtContext::getRuleIndex() const {
  return loxParser::RuleIfStmt;
}


loxParser::IfStmtContext* loxParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, loxParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(loxParser::T__10);
    setState(132);
    match(loxParser::T__1);
    setState(133);
    expression();
    setState(134);
    match(loxParser::T__2);
    setState(135);
    block();
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__11) {
      setState(136);
      match(loxParser::T__11);
      setState(137);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStmtContext ------------------------------------------------------------------

loxParser::PrintStmtContext::PrintStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExpressionContext* loxParser::PrintStmtContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}


size_t loxParser::PrintStmtContext::getRuleIndex() const {
  return loxParser::RulePrintStmt;
}


loxParser::PrintStmtContext* loxParser::printStmt() {
  PrintStmtContext *_localctx = _tracker.createInstance<PrintStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, loxParser::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(loxParser::T__12);
    setState(141);
    expression();
    setState(142);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

loxParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExpressionContext* loxParser::ReturnStmtContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}


size_t loxParser::ReturnStmtContext::getRuleIndex() const {
  return loxParser::RuleReturnStmt;
}


loxParser::ReturnStmtContext* loxParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, loxParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(loxParser::T__13);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7832007081988) != 0)) {
      setState(145);
      expression();
    }
    setState(148);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

loxParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::ExpressionContext* loxParser::WhileStmtContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}

loxParser::BlockContext* loxParser::WhileStmtContext::block() {
  return getRuleContext<loxParser::BlockContext>(0);
}


size_t loxParser::WhileStmtContext::getRuleIndex() const {
  return loxParser::RuleWhileStmt;
}


loxParser::WhileStmtContext* loxParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 22, loxParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(loxParser::T__14);
    setState(151);
    match(loxParser::T__1);
    setState(152);
    expression();
    setState(153);
    match(loxParser::T__2);
    setState(154);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStmtContext ------------------------------------------------------------------

loxParser::BreakStmtContext::BreakStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t loxParser::BreakStmtContext::getRuleIndex() const {
  return loxParser::RuleBreakStmt;
}


loxParser::BreakStmtContext* loxParser::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, loxParser::RuleBreakStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(loxParser::T__15);
    setState(157);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

loxParser::ContinueStmtContext::ContinueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t loxParser::ContinueStmtContext::getRuleIndex() const {
  return loxParser::RuleContinueStmt;
}


loxParser::ContinueStmtContext* loxParser::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, loxParser::RuleContinueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(loxParser::T__16);
    setState(160);
    match(loxParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

loxParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::DeclarationContext *> loxParser::BlockContext::declaration() {
  return getRuleContexts<loxParser::DeclarationContext>();
}

loxParser::DeclarationContext* loxParser::BlockContext::declaration(size_t i) {
  return getRuleContext<loxParser::DeclarationContext>(i);
}


size_t loxParser::BlockContext::getRuleIndex() const {
  return loxParser::RuleBlock;
}


loxParser::BlockContext* loxParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 28, loxParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(loxParser::T__3);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7832007339222) != 0)) {
      setState(163);
      declaration();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(loxParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

loxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::AssignmentContext* loxParser::ExpressionContext::assignment() {
  return getRuleContext<loxParser::AssignmentContext>(0);
}


size_t loxParser::ExpressionContext::getRuleIndex() const {
  return loxParser::RuleExpression;
}


loxParser::ExpressionContext* loxParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, loxParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    assignment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

loxParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* loxParser::AssignmentContext::IDENTIFIER() {
  return getToken(loxParser::IDENTIFIER, 0);
}

loxParser::AssignmentContext* loxParser::AssignmentContext::assignment() {
  return getRuleContext<loxParser::AssignmentContext>(0);
}

loxParser::CallContext* loxParser::AssignmentContext::call() {
  return getRuleContext<loxParser::CallContext>(0);
}

loxParser::Logic_orContext* loxParser::AssignmentContext::logic_or() {
  return getRuleContext<loxParser::Logic_orContext>(0);
}


size_t loxParser::AssignmentContext::getRuleIndex() const {
  return loxParser::RuleAssignment;
}


loxParser::AssignmentContext* loxParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 32, loxParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(173);
        call();
        setState(174);
        match(loxParser::T__17);
        break;
      }

      default:
        break;
      }
      setState(178);
      match(loxParser::IDENTIFIER);
      setState(179);
      match(loxParser::T__7);
      setState(180);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(181);
      logic_or();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_orContext ------------------------------------------------------------------

loxParser::Logic_orContext::Logic_orContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::Logic_andContext *> loxParser::Logic_orContext::logic_and() {
  return getRuleContexts<loxParser::Logic_andContext>();
}

loxParser::Logic_andContext* loxParser::Logic_orContext::logic_and(size_t i) {
  return getRuleContext<loxParser::Logic_andContext>(i);
}


size_t loxParser::Logic_orContext::getRuleIndex() const {
  return loxParser::RuleLogic_or;
}


loxParser::Logic_orContext* loxParser::logic_or() {
  Logic_orContext *_localctx = _tracker.createInstance<Logic_orContext>(_ctx, getState());
  enterRule(_localctx, 34, loxParser::RuleLogic_or);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    logic_and();
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__18) {
      setState(185);
      match(loxParser::T__18);
      setState(186);
      logic_and();
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_andContext ------------------------------------------------------------------

loxParser::Logic_andContext::Logic_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::EqualityContext *> loxParser::Logic_andContext::equality() {
  return getRuleContexts<loxParser::EqualityContext>();
}

loxParser::EqualityContext* loxParser::Logic_andContext::equality(size_t i) {
  return getRuleContext<loxParser::EqualityContext>(i);
}


size_t loxParser::Logic_andContext::getRuleIndex() const {
  return loxParser::RuleLogic_and;
}


loxParser::Logic_andContext* loxParser::logic_and() {
  Logic_andContext *_localctx = _tracker.createInstance<Logic_andContext>(_ctx, getState());
  enterRule(_localctx, 36, loxParser::RuleLogic_and);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    equality();
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__19) {
      setState(193);
      match(loxParser::T__19);
      setState(194);
      equality();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityContext ------------------------------------------------------------------

loxParser::EqualityContext::EqualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::ComparisonContext *> loxParser::EqualityContext::comparison() {
  return getRuleContexts<loxParser::ComparisonContext>();
}

loxParser::ComparisonContext* loxParser::EqualityContext::comparison(size_t i) {
  return getRuleContext<loxParser::ComparisonContext>(i);
}


size_t loxParser::EqualityContext::getRuleIndex() const {
  return loxParser::RuleEquality;
}


loxParser::EqualityContext* loxParser::equality() {
  EqualityContext *_localctx = _tracker.createInstance<EqualityContext>(_ctx, getState());
  enterRule(_localctx, 38, loxParser::RuleEquality);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    comparison();
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__20

    || _la == loxParser::T__21) {
      setState(201);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__20

      || _la == loxParser::T__21)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(202);
      comparison();
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

loxParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::TermContext *> loxParser::ComparisonContext::term() {
  return getRuleContexts<loxParser::TermContext>();
}

loxParser::TermContext* loxParser::ComparisonContext::term(size_t i) {
  return getRuleContext<loxParser::TermContext>(i);
}


size_t loxParser::ComparisonContext::getRuleIndex() const {
  return loxParser::RuleComparison;
}


loxParser::ComparisonContext* loxParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 40, loxParser::RuleComparison);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    term();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 125829120) != 0)) {
      setState(209);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 125829120) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(210);
      term();
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

loxParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::FactorContext *> loxParser::TermContext::factor() {
  return getRuleContexts<loxParser::FactorContext>();
}

loxParser::FactorContext* loxParser::TermContext::factor(size_t i) {
  return getRuleContext<loxParser::FactorContext>(i);
}


size_t loxParser::TermContext::getRuleIndex() const {
  return loxParser::RuleTerm;
}


loxParser::TermContext* loxParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 42, loxParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    factor();
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__26

    || _la == loxParser::T__27) {
      setState(217);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__26

      || _la == loxParser::T__27)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(218);
      factor();
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

loxParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::UnaryContext *> loxParser::FactorContext::unary() {
  return getRuleContexts<loxParser::UnaryContext>();
}

loxParser::UnaryContext* loxParser::FactorContext::unary(size_t i) {
  return getRuleContext<loxParser::UnaryContext>(i);
}


size_t loxParser::FactorContext::getRuleIndex() const {
  return loxParser::RuleFactor;
}


loxParser::FactorContext* loxParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 44, loxParser::RuleFactor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    unary();
    setState(229);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__28

    || _la == loxParser::T__29) {
      setState(225);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__28

      || _la == loxParser::T__29)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(226);
      unary();
      setState(231);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

loxParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::UnaryContext* loxParser::UnaryContext::unary() {
  return getRuleContext<loxParser::UnaryContext>(0);
}

loxParser::CallContext* loxParser::UnaryContext::call() {
  return getRuleContext<loxParser::CallContext>(0);
}


size_t loxParser::UnaryContext::getRuleIndex() const {
  return loxParser::RuleUnary;
}


loxParser::UnaryContext* loxParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 46, loxParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__26:
      case loxParser::T__30: {
        enterOuterAlt(_localctx, 1);
        setState(232);
        _la = _input->LA(1);
        if (!(_la == loxParser::T__26

        || _la == loxParser::T__30)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(233);
        unary();
        break;
      }

      case loxParser::T__1:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::T__34:
      case loxParser::T__35:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(234);
        call();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

loxParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

loxParser::PrimayContext* loxParser::CallContext::primay() {
  return getRuleContext<loxParser::PrimayContext>(0);
}

std::vector<tree::TerminalNode *> loxParser::CallContext::IDENTIFIER() {
  return getTokens(loxParser::IDENTIFIER);
}

tree::TerminalNode* loxParser::CallContext::IDENTIFIER(size_t i) {
  return getToken(loxParser::IDENTIFIER, i);
}

std::vector<loxParser::ArgumentsContext *> loxParser::CallContext::arguments() {
  return getRuleContexts<loxParser::ArgumentsContext>();
}

loxParser::ArgumentsContext* loxParser::CallContext::arguments(size_t i) {
  return getRuleContext<loxParser::ArgumentsContext>(i);
}


size_t loxParser::CallContext::getRuleIndex() const {
  return loxParser::RuleCall;
}


loxParser::CallContext* loxParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 48, loxParser::RuleCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(237);
    primay();
    setState(247);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(245);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case loxParser::T__1: {
            setState(238);
            match(loxParser::T__1);
            setState(240);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~ 0x3fULL) == 0) &&
              ((1ULL << _la) & 7832007081988) != 0)) {
              setState(239);
              arguments();
            }
            setState(242);
            match(loxParser::T__2);
            break;
          }

          case loxParser::T__17: {
            setState(243);
            match(loxParser::T__17);
            setState(244);
            match(loxParser::IDENTIFIER);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(249);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimayContext ------------------------------------------------------------------

loxParser::PrimayContext::PrimayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* loxParser::PrimayContext::NUMBER() {
  return getToken(loxParser::NUMBER, 0);
}

tree::TerminalNode* loxParser::PrimayContext::STRING_LITERAL() {
  return getToken(loxParser::STRING_LITERAL, 0);
}

tree::TerminalNode* loxParser::PrimayContext::IDENTIFIER() {
  return getToken(loxParser::IDENTIFIER, 0);
}

loxParser::ExpressionContext* loxParser::PrimayContext::expression() {
  return getRuleContext<loxParser::ExpressionContext>(0);
}


size_t loxParser::PrimayContext::getRuleIndex() const {
  return loxParser::RulePrimay;
}


loxParser::PrimayContext* loxParser::primay() {
  PrimayContext *_localctx = _tracker.createInstance<PrimayContext>(_ctx, getState());
  enterRule(_localctx, 50, loxParser::RulePrimay);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__31: {
        enterOuterAlt(_localctx, 1);
        setState(250);
        match(loxParser::T__31);
        break;
      }

      case loxParser::T__32: {
        enterOuterAlt(_localctx, 2);
        setState(251);
        match(loxParser::T__32);
        break;
      }

      case loxParser::T__33: {
        enterOuterAlt(_localctx, 3);
        setState(252);
        match(loxParser::T__33);
        break;
      }

      case loxParser::T__34: {
        enterOuterAlt(_localctx, 4);
        setState(253);
        match(loxParser::T__34);
        break;
      }

      case loxParser::NUMBER: {
        enterOuterAlt(_localctx, 5);
        setState(254);
        match(loxParser::NUMBER);
        break;
      }

      case loxParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 6);
        setState(255);
        match(loxParser::STRING_LITERAL);
        break;
      }

      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 7);
        setState(256);
        match(loxParser::IDENTIFIER);
        break;
      }

      case loxParser::T__1: {
        enterOuterAlt(_localctx, 8);
        setState(257);
        match(loxParser::T__1);
        setState(258);
        expression();
        setState(259);
        match(loxParser::T__2);
        break;
      }

      case loxParser::T__35: {
        enterOuterAlt(_localctx, 9);
        setState(261);
        match(loxParser::T__35);
        setState(262);
        match(loxParser::T__17);
        setState(263);
        match(loxParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

loxParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* loxParser::FunctionContext::IDENTIFIER() {
  return getToken(loxParser::IDENTIFIER, 0);
}

loxParser::BlockContext* loxParser::FunctionContext::block() {
  return getRuleContext<loxParser::BlockContext>(0);
}

loxParser::ParametersContext* loxParser::FunctionContext::parameters() {
  return getRuleContext<loxParser::ParametersContext>(0);
}


size_t loxParser::FunctionContext::getRuleIndex() const {
  return loxParser::RuleFunction;
}


loxParser::FunctionContext* loxParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 52, loxParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(loxParser::IDENTIFIER);
    setState(267);
    match(loxParser::T__1);
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::IDENTIFIER) {
      setState(268);
      parameters();
    }
    setState(271);
    match(loxParser::T__2);
    setState(272);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

loxParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> loxParser::ParametersContext::IDENTIFIER() {
  return getTokens(loxParser::IDENTIFIER);
}

tree::TerminalNode* loxParser::ParametersContext::IDENTIFIER(size_t i) {
  return getToken(loxParser::IDENTIFIER, i);
}


size_t loxParser::ParametersContext::getRuleIndex() const {
  return loxParser::RuleParameters;
}


loxParser::ParametersContext* loxParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 54, loxParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(loxParser::IDENTIFIER);
    setState(279);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__36) {
      setState(275);
      match(loxParser::T__36);
      setState(276);
      match(loxParser::IDENTIFIER);
      setState(281);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

loxParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<loxParser::ExpressionContext *> loxParser::ArgumentsContext::expression() {
  return getRuleContexts<loxParser::ExpressionContext>();
}

loxParser::ExpressionContext* loxParser::ArgumentsContext::expression(size_t i) {
  return getRuleContext<loxParser::ExpressionContext>(i);
}


size_t loxParser::ArgumentsContext::getRuleIndex() const {
  return loxParser::RuleArguments;
}


loxParser::ArgumentsContext* loxParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 56, loxParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    expression();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__36) {
      setState(283);
      match(loxParser::T__36);
      setState(284);
      expression();
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void loxParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  loxParserInitialize();
#else
  ::antlr4::internal::call_once(loxParserOnceFlag, loxParserInitialize);
#endif
}
