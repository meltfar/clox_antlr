
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
      "block", "expression", "assignment", "logic_or", "logic_and", "equality", 
      "comparison", "term", "factor", "unary", "call", "primay", "function", 
      "parameters", "arguments"
    },
    std::vector<std::string>{
      "", "'class'", "'('", "')'", "'{'", "'}'", "'func'", "'var'", "'='", 
      "';'", "'for'", "'if'", "'else'", "'print'", "'return'", "'while'", 
      "'.'", "'or'", "'and'", "'!='", "'=='", "'>'", "'>='", "'<'", "'<='", 
      "'-'", "'+'", "'/'", "'*'", "'!'", "'true'", "'false'", "'nil'", "'this'", 
      "'super'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "WHITESPACE", "NEWLINE", "NUMBER", "STRING_LITERAL", "IDENTIFIER", 
      "ALPHA", "DIGIT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,278,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,5,0,56,8,0,10,
  	0,12,0,59,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,1,67,8,1,1,2,1,2,1,2,1,2,1,2,
  	3,2,74,8,2,1,2,1,2,5,2,78,8,2,10,2,12,2,81,9,2,1,2,1,2,1,3,1,3,1,3,1,
  	4,1,4,1,4,1,4,3,4,92,8,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,103,
  	8,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,7,113,8,7,1,7,3,7,116,8,7,1,7,1,
  	7,3,7,120,8,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,132,8,8,1,9,
  	1,9,1,9,1,9,1,10,1,10,3,10,140,8,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,12,1,12,5,12,152,8,12,10,12,12,12,155,9,12,1,12,1,12,1,13,1,13,
  	1,14,1,14,1,14,3,14,164,8,14,1,14,1,14,1,14,1,14,3,14,170,8,14,1,15,1,
  	15,1,15,5,15,175,8,15,10,15,12,15,178,9,15,1,16,1,16,1,16,5,16,183,8,
  	16,10,16,12,16,186,9,16,1,17,1,17,1,17,5,17,191,8,17,10,17,12,17,194,
  	9,17,1,18,1,18,1,18,5,18,199,8,18,10,18,12,18,202,9,18,1,19,1,19,1,19,
  	5,19,207,8,19,10,19,12,19,210,9,19,1,20,1,20,1,20,5,20,215,8,20,10,20,
  	12,20,218,9,20,1,21,1,21,1,21,3,21,223,8,21,1,22,1,22,1,22,3,22,228,8,
  	22,1,22,1,22,1,22,5,22,233,8,22,10,22,12,22,236,9,22,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,252,8,23,1,
  	24,1,24,1,24,3,24,257,8,24,1,24,1,24,1,24,1,25,1,25,1,25,5,25,265,8,25,
  	10,25,12,25,268,9,25,1,26,1,26,1,26,5,26,273,8,26,10,26,12,26,276,9,26,
  	1,26,0,0,27,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
  	42,44,46,48,50,52,0,5,1,0,19,20,1,0,21,24,1,0,25,26,1,0,27,28,2,0,25,
  	25,29,29,293,0,57,1,0,0,0,2,66,1,0,0,0,4,68,1,0,0,0,6,84,1,0,0,0,8,87,
  	1,0,0,0,10,102,1,0,0,0,12,104,1,0,0,0,14,107,1,0,0,0,16,124,1,0,0,0,18,
  	133,1,0,0,0,20,137,1,0,0,0,22,143,1,0,0,0,24,149,1,0,0,0,26,158,1,0,0,
  	0,28,169,1,0,0,0,30,171,1,0,0,0,32,179,1,0,0,0,34,187,1,0,0,0,36,195,
  	1,0,0,0,38,203,1,0,0,0,40,211,1,0,0,0,42,222,1,0,0,0,44,224,1,0,0,0,46,
  	251,1,0,0,0,48,253,1,0,0,0,50,261,1,0,0,0,52,269,1,0,0,0,54,56,3,2,1,
  	0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,60,1,0,0,
  	0,59,57,1,0,0,0,60,61,5,0,0,1,61,1,1,0,0,0,62,67,3,4,2,0,63,67,3,6,3,
  	0,64,67,3,8,4,0,65,67,3,10,5,0,66,62,1,0,0,0,66,63,1,0,0,0,66,64,1,0,
  	0,0,66,65,1,0,0,0,67,3,1,0,0,0,68,69,5,1,0,0,69,73,5,40,0,0,70,71,5,2,
  	0,0,71,72,5,40,0,0,72,74,5,3,0,0,73,70,1,0,0,0,73,74,1,0,0,0,74,75,1,
  	0,0,0,75,79,5,4,0,0,76,78,3,48,24,0,77,76,1,0,0,0,78,81,1,0,0,0,79,77,
  	1,0,0,0,79,80,1,0,0,0,80,82,1,0,0,0,81,79,1,0,0,0,82,83,5,5,0,0,83,5,
  	1,0,0,0,84,85,5,6,0,0,85,86,3,48,24,0,86,7,1,0,0,0,87,88,5,7,0,0,88,91,
  	5,40,0,0,89,90,5,8,0,0,90,92,3,26,13,0,91,89,1,0,0,0,91,92,1,0,0,0,92,
  	93,1,0,0,0,93,94,5,9,0,0,94,9,1,0,0,0,95,103,3,12,6,0,96,103,3,14,7,0,
  	97,103,3,16,8,0,98,103,3,18,9,0,99,103,3,20,10,0,100,103,3,22,11,0,101,
  	103,3,24,12,0,102,95,1,0,0,0,102,96,1,0,0,0,102,97,1,0,0,0,102,98,1,0,
  	0,0,102,99,1,0,0,0,102,100,1,0,0,0,102,101,1,0,0,0,103,11,1,0,0,0,104,
  	105,3,26,13,0,105,106,5,9,0,0,106,13,1,0,0,0,107,108,5,10,0,0,108,112,
  	5,2,0,0,109,113,3,8,4,0,110,113,3,12,6,0,111,113,5,9,0,0,112,109,1,0,
  	0,0,112,110,1,0,0,0,112,111,1,0,0,0,113,115,1,0,0,0,114,116,3,26,13,0,
  	115,114,1,0,0,0,115,116,1,0,0,0,116,117,1,0,0,0,117,119,5,9,0,0,118,120,
  	3,26,13,0,119,118,1,0,0,0,119,120,1,0,0,0,120,121,1,0,0,0,121,122,5,9,
  	0,0,122,123,3,24,12,0,123,15,1,0,0,0,124,125,5,11,0,0,125,126,5,2,0,0,
  	126,127,3,26,13,0,127,128,5,3,0,0,128,131,3,24,12,0,129,130,5,12,0,0,
  	130,132,3,24,12,0,131,129,1,0,0,0,131,132,1,0,0,0,132,17,1,0,0,0,133,
  	134,5,13,0,0,134,135,3,26,13,0,135,136,5,9,0,0,136,19,1,0,0,0,137,139,
  	5,14,0,0,138,140,3,26,13,0,139,138,1,0,0,0,139,140,1,0,0,0,140,141,1,
  	0,0,0,141,142,5,9,0,0,142,21,1,0,0,0,143,144,5,15,0,0,144,145,5,2,0,0,
  	145,146,3,26,13,0,146,147,5,3,0,0,147,148,3,24,12,0,148,23,1,0,0,0,149,
  	153,5,4,0,0,150,152,3,2,1,0,151,150,1,0,0,0,152,155,1,0,0,0,153,151,1,
  	0,0,0,153,154,1,0,0,0,154,156,1,0,0,0,155,153,1,0,0,0,156,157,5,5,0,0,
  	157,25,1,0,0,0,158,159,3,28,14,0,159,27,1,0,0,0,160,161,3,44,22,0,161,
  	162,5,16,0,0,162,164,1,0,0,0,163,160,1,0,0,0,163,164,1,0,0,0,164,165,
  	1,0,0,0,165,166,5,40,0,0,166,167,5,8,0,0,167,170,3,28,14,0,168,170,3,
  	30,15,0,169,163,1,0,0,0,169,168,1,0,0,0,170,29,1,0,0,0,171,176,3,32,16,
  	0,172,173,5,17,0,0,173,175,3,32,16,0,174,172,1,0,0,0,175,178,1,0,0,0,
  	176,174,1,0,0,0,176,177,1,0,0,0,177,31,1,0,0,0,178,176,1,0,0,0,179,184,
  	3,34,17,0,180,181,5,18,0,0,181,183,3,34,17,0,182,180,1,0,0,0,183,186,
  	1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,33,1,0,0,0,186,184,1,0,0,
  	0,187,192,3,36,18,0,188,189,7,0,0,0,189,191,3,36,18,0,190,188,1,0,0,0,
  	191,194,1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,35,1,0,0,0,194,192,
  	1,0,0,0,195,200,3,38,19,0,196,197,7,1,0,0,197,199,3,38,19,0,198,196,1,
  	0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,37,1,0,0,0,
  	202,200,1,0,0,0,203,208,3,40,20,0,204,205,7,2,0,0,205,207,3,40,20,0,206,
  	204,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,209,1,0,0,0,209,39,1,
  	0,0,0,210,208,1,0,0,0,211,216,3,42,21,0,212,213,7,3,0,0,213,215,3,42,
  	21,0,214,212,1,0,0,0,215,218,1,0,0,0,216,214,1,0,0,0,216,217,1,0,0,0,
  	217,41,1,0,0,0,218,216,1,0,0,0,219,220,7,4,0,0,220,223,3,42,21,0,221,
  	223,3,44,22,0,222,219,1,0,0,0,222,221,1,0,0,0,223,43,1,0,0,0,224,234,
  	3,46,23,0,225,227,5,2,0,0,226,228,3,52,26,0,227,226,1,0,0,0,227,228,1,
  	0,0,0,228,229,1,0,0,0,229,233,5,3,0,0,230,231,5,16,0,0,231,233,5,40,0,
  	0,232,225,1,0,0,0,232,230,1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,234,
  	235,1,0,0,0,235,45,1,0,0,0,236,234,1,0,0,0,237,252,5,30,0,0,238,252,5,
  	31,0,0,239,252,5,32,0,0,240,252,5,33,0,0,241,252,5,38,0,0,242,252,5,39,
  	0,0,243,252,5,40,0,0,244,245,5,2,0,0,245,246,3,26,13,0,246,247,5,3,0,
  	0,247,252,1,0,0,0,248,249,5,34,0,0,249,250,5,16,0,0,250,252,5,40,0,0,
  	251,237,1,0,0,0,251,238,1,0,0,0,251,239,1,0,0,0,251,240,1,0,0,0,251,241,
  	1,0,0,0,251,242,1,0,0,0,251,243,1,0,0,0,251,244,1,0,0,0,251,248,1,0,0,
  	0,252,47,1,0,0,0,253,254,5,40,0,0,254,256,5,2,0,0,255,257,3,50,25,0,256,
  	255,1,0,0,0,256,257,1,0,0,0,257,258,1,0,0,0,258,259,5,3,0,0,259,260,3,
  	24,12,0,260,49,1,0,0,0,261,266,5,40,0,0,262,263,5,35,0,0,263,265,5,40,
  	0,0,264,262,1,0,0,0,265,268,1,0,0,0,266,264,1,0,0,0,266,267,1,0,0,0,267,
  	51,1,0,0,0,268,266,1,0,0,0,269,274,3,26,13,0,270,271,5,35,0,0,271,273,
  	3,26,13,0,272,270,1,0,0,0,273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,
  	0,0,275,53,1,0,0,0,276,274,1,0,0,0,28,57,66,73,79,91,102,112,115,119,
  	131,139,153,163,169,176,184,192,200,208,216,222,227,232,234,251,256,266,
  	274
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
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1958001831126) != 0)) {
      setState(54);
      declaration();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(60);
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
    setState(66);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(62);
        classDec();
        break;
      }

      case loxParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(63);
        funDec();
        break;
      }

      case loxParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(64);
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
      case loxParser::T__24:
      case loxParser::T__28:
      case loxParser::T__29:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(65);
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
    setState(68);
    match(loxParser::T__0);
    setState(69);
    match(loxParser::IDENTIFIER);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__1) {
      setState(70);
      match(loxParser::T__1);
      setState(71);
      match(loxParser::IDENTIFIER);
      setState(72);
      match(loxParser::T__2);
    }
    setState(75);
    match(loxParser::T__3);
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::IDENTIFIER) {
      setState(76);
      function();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
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
    setState(84);
    match(loxParser::T__5);
    setState(85);
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
    setState(87);
    match(loxParser::T__6);
    setState(88);
    match(loxParser::IDENTIFIER);
    setState(91);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__7) {
      setState(89);
      match(loxParser::T__7);
      setState(90);
      expression();
    }
    setState(93);
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
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__1:
      case loxParser::T__24:
      case loxParser::T__28:
      case loxParser::T__29:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        exprStmt();
        break;
      }

      case loxParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        forStmt();
        break;
      }

      case loxParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(97);
        ifStmt();
        break;
      }

      case loxParser::T__12: {
        enterOuterAlt(_localctx, 4);
        setState(98);
        printStmt();
        break;
      }

      case loxParser::T__13: {
        enterOuterAlt(_localctx, 5);
        setState(99);
        returnStmt();
        break;
      }

      case loxParser::T__14: {
        enterOuterAlt(_localctx, 6);
        setState(100);
        whileStmt();
        break;
      }

      case loxParser::T__3: {
        enterOuterAlt(_localctx, 7);
        setState(101);
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
    setState(104);
    expression();
    setState(105);
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
    setState(107);
    match(loxParser::T__9);
    setState(108);
    match(loxParser::T__1);
    setState(112);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__6: {
        setState(109);
        varDec();
        break;
      }

      case loxParser::T__1:
      case loxParser::T__24:
      case loxParser::T__28:
      case loxParser::T__29:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        setState(110);
        exprStmt();
        break;
      }

      case loxParser::T__8: {
        setState(111);
        match(loxParser::T__8);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1958001770500) != 0)) {
      setState(114);
      expression();
    }
    setState(117);
    match(loxParser::T__8);
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1958001770500) != 0)) {
      setState(118);
      expression();
    }
    setState(121);
    match(loxParser::T__8);
    setState(122);
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
    setState(124);
    match(loxParser::T__10);
    setState(125);
    match(loxParser::T__1);
    setState(126);
    expression();
    setState(127);
    match(loxParser::T__2);
    setState(128);
    block();
    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::T__11) {
      setState(129);
      match(loxParser::T__11);
      setState(130);
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
    setState(133);
    match(loxParser::T__12);
    setState(134);
    expression();
    setState(135);
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
    setState(137);
    match(loxParser::T__13);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1958001770500) != 0)) {
      setState(138);
      expression();
    }
    setState(141);
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
    setState(143);
    match(loxParser::T__14);
    setState(144);
    match(loxParser::T__1);
    setState(145);
    expression();
    setState(146);
    match(loxParser::T__2);
    setState(147);
    block();
   
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
  enterRule(_localctx, 24, loxParser::RuleBlock);
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
    setState(149);
    match(loxParser::T__3);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1958001831126) != 0)) {
      setState(150);
      declaration();
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(156);
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
  enterRule(_localctx, 26, loxParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
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
  enterRule(_localctx, 28, loxParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(163);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(160);
        call();
        setState(161);
        match(loxParser::T__15);
        break;
      }

      default:
        break;
      }
      setState(165);
      match(loxParser::IDENTIFIER);
      setState(166);
      match(loxParser::T__7);
      setState(167);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
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
  enterRule(_localctx, 30, loxParser::RuleLogic_or);
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
    setState(171);
    logic_and();
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__16) {
      setState(172);
      match(loxParser::T__16);
      setState(173);
      logic_and();
      setState(178);
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
  enterRule(_localctx, 32, loxParser::RuleLogic_and);
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
    setState(179);
    equality();
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__17) {
      setState(180);
      match(loxParser::T__17);
      setState(181);
      equality();
      setState(186);
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
  enterRule(_localctx, 34, loxParser::RuleEquality);
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
    setState(187);
    comparison();
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__18

    || _la == loxParser::T__19) {
      setState(188);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__18

      || _la == loxParser::T__19)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(189);
      comparison();
      setState(194);
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
  enterRule(_localctx, 36, loxParser::RuleComparison);
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
    setState(195);
    term();
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 31457280) != 0)) {
      setState(196);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 31457280) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(197);
      term();
      setState(202);
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
  enterRule(_localctx, 38, loxParser::RuleTerm);
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
    setState(203);
    factor();
    setState(208);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__24

    || _la == loxParser::T__25) {
      setState(204);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__24

      || _la == loxParser::T__25)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(205);
      factor();
      setState(210);
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
  enterRule(_localctx, 40, loxParser::RuleFactor);
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
    setState(211);
    unary();
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__26

    || _la == loxParser::T__27) {
      setState(212);
      _la = _input->LA(1);
      if (!(_la == loxParser::T__26

      || _la == loxParser::T__27)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(213);
      unary();
      setState(218);
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
  enterRule(_localctx, 42, loxParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__24:
      case loxParser::T__28: {
        enterOuterAlt(_localctx, 1);
        setState(219);
        _la = _input->LA(1);
        if (!(_la == loxParser::T__24

        || _la == loxParser::T__28)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(220);
        unary();
        break;
      }

      case loxParser::T__1:
      case loxParser::T__29:
      case loxParser::T__30:
      case loxParser::T__31:
      case loxParser::T__32:
      case loxParser::T__33:
      case loxParser::NUMBER:
      case loxParser::STRING_LITERAL:
      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(221);
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
  enterRule(_localctx, 44, loxParser::RuleCall);
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
    setState(224);
    primay();
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(232);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case loxParser::T__1: {
            setState(225);
            match(loxParser::T__1);
            setState(227);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~ 0x3fULL) == 0) &&
              ((1ULL << _la) & 1958001770500) != 0)) {
              setState(226);
              arguments();
            }
            setState(229);
            match(loxParser::T__2);
            break;
          }

          case loxParser::T__15: {
            setState(230);
            match(loxParser::T__15);
            setState(231);
            match(loxParser::IDENTIFIER);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(236);
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
  enterRule(_localctx, 46, loxParser::RulePrimay);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case loxParser::T__29: {
        enterOuterAlt(_localctx, 1);
        setState(237);
        match(loxParser::T__29);
        break;
      }

      case loxParser::T__30: {
        enterOuterAlt(_localctx, 2);
        setState(238);
        match(loxParser::T__30);
        break;
      }

      case loxParser::T__31: {
        enterOuterAlt(_localctx, 3);
        setState(239);
        match(loxParser::T__31);
        break;
      }

      case loxParser::T__32: {
        enterOuterAlt(_localctx, 4);
        setState(240);
        match(loxParser::T__32);
        break;
      }

      case loxParser::NUMBER: {
        enterOuterAlt(_localctx, 5);
        setState(241);
        match(loxParser::NUMBER);
        break;
      }

      case loxParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 6);
        setState(242);
        match(loxParser::STRING_LITERAL);
        break;
      }

      case loxParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 7);
        setState(243);
        match(loxParser::IDENTIFIER);
        break;
      }

      case loxParser::T__1: {
        enterOuterAlt(_localctx, 8);
        setState(244);
        match(loxParser::T__1);
        setState(245);
        expression();
        setState(246);
        match(loxParser::T__2);
        break;
      }

      case loxParser::T__33: {
        enterOuterAlt(_localctx, 9);
        setState(248);
        match(loxParser::T__33);
        setState(249);
        match(loxParser::T__15);
        setState(250);
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
  enterRule(_localctx, 48, loxParser::RuleFunction);
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
    setState(253);
    match(loxParser::IDENTIFIER);
    setState(254);
    match(loxParser::T__1);
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == loxParser::IDENTIFIER) {
      setState(255);
      parameters();
    }
    setState(258);
    match(loxParser::T__2);
    setState(259);
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
  enterRule(_localctx, 50, loxParser::RuleParameters);
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
    setState(261);
    match(loxParser::IDENTIFIER);
    setState(266);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__34) {
      setState(262);
      match(loxParser::T__34);
      setState(263);
      match(loxParser::IDENTIFIER);
      setState(268);
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
  enterRule(_localctx, 52, loxParser::RuleArguments);
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
    setState(269);
    expression();
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == loxParser::T__34) {
      setState(270);
      match(loxParser::T__34);
      setState(271);
      expression();
      setState(276);
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
