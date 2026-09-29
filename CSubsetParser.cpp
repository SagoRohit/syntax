
// Generated from CSubset.g4 by ANTLR 4.13.2


#include "CSubsetVisitor.h"

#include "CSubsetParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubsetParserStaticData final {
  CSubsetParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetParserStaticData(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData(CSubsetParserStaticData&&) = delete;
  CSubsetParserStaticData& operator=(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData& operator=(CSubsetParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetParserStaticData> csubsetParserStaticData = nullptr;

void csubsetParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "'++'", "'--'", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,301,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,
  	1,2,1,2,1,2,3,2,62,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,77,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	3,4,92,8,4,1,5,1,5,1,5,1,5,1,5,3,5,99,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,5,5,109,8,5,10,5,12,5,112,9,5,1,6,1,6,1,6,1,6,1,6,1,6,3,6,120,8,6,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,134,8,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,145,8,9,10,9,12,9,148,9,9,1,10,1,10,1,10,
  	1,10,1,10,5,10,155,8,10,10,10,12,10,158,9,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,200,8,11,1,12,1,12,1,12,1,12,
  	3,12,206,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,214,8,13,1,14,1,14,1,
  	14,1,14,1,14,3,14,221,8,14,1,15,1,15,1,15,1,15,1,15,3,15,228,8,15,1,16,
  	1,16,1,16,1,16,1,16,3,16,235,8,16,1,17,1,17,1,17,1,17,1,17,1,17,5,17,
  	243,8,17,10,17,12,17,246,9,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,254,
  	8,18,10,18,12,18,257,9,18,1,19,1,19,1,19,1,19,1,19,3,19,264,8,19,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,3,20,284,8,20,1,21,1,21,3,21,288,8,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,5,22,296,8,22,10,22,12,22,299,9,22,1,22,0,7,2,10,18,20,34,
  	36,44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,
  	44,0,1,1,0,11,13,315,0,46,1,0,0,0,2,48,1,0,0,0,4,61,1,0,0,0,6,76,1,0,
  	0,0,8,91,1,0,0,0,10,98,1,0,0,0,12,119,1,0,0,0,14,121,1,0,0,0,16,125,1,
  	0,0,0,18,133,1,0,0,0,20,149,1,0,0,0,22,199,1,0,0,0,24,205,1,0,0,0,26,
  	213,1,0,0,0,28,220,1,0,0,0,30,227,1,0,0,0,32,234,1,0,0,0,34,236,1,0,0,
  	0,36,247,1,0,0,0,38,263,1,0,0,0,40,283,1,0,0,0,42,287,1,0,0,0,44,289,
  	1,0,0,0,46,47,3,2,1,0,47,1,1,0,0,0,48,49,6,1,-1,0,49,50,3,4,2,0,50,55,
  	1,0,0,0,51,52,10,2,0,0,52,54,3,4,2,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,
  	1,0,0,0,55,56,1,0,0,0,56,3,1,0,0,0,57,55,1,0,0,0,58,62,3,14,7,0,59,62,
  	3,6,3,0,60,62,3,8,4,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,5,
  	1,0,0,0,63,64,3,16,8,0,64,65,5,30,0,0,65,66,5,14,0,0,66,67,3,10,5,0,67,
  	68,5,15,0,0,68,69,5,20,0,0,69,77,1,0,0,0,70,71,3,16,8,0,71,72,5,30,0,
  	0,72,73,5,14,0,0,73,74,5,15,0,0,74,75,5,20,0,0,75,77,1,0,0,0,76,63,1,
  	0,0,0,76,70,1,0,0,0,77,7,1,0,0,0,78,79,3,16,8,0,79,80,5,30,0,0,80,81,
  	5,14,0,0,81,82,3,10,5,0,82,83,5,15,0,0,83,84,3,12,6,0,84,92,1,0,0,0,85,
  	86,3,16,8,0,86,87,5,30,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,3,12,6,
  	0,90,92,1,0,0,0,91,78,1,0,0,0,91,85,1,0,0,0,92,9,1,0,0,0,93,94,6,5,-1,
  	0,94,95,3,16,8,0,95,96,5,30,0,0,96,99,1,0,0,0,97,99,3,16,8,0,98,93,1,
  	0,0,0,98,97,1,0,0,0,99,110,1,0,0,0,100,101,10,4,0,0,101,102,5,21,0,0,
  	102,103,3,16,8,0,103,104,5,30,0,0,104,109,1,0,0,0,105,106,10,3,0,0,106,
  	107,5,21,0,0,107,109,3,16,8,0,108,100,1,0,0,0,108,105,1,0,0,0,109,112,
  	1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,11,1,0,0,0,112,110,1,0,0,
  	0,113,114,5,16,0,0,114,115,3,20,10,0,115,116,5,17,0,0,116,120,1,0,0,0,
  	117,118,5,16,0,0,118,120,5,17,0,0,119,113,1,0,0,0,119,117,1,0,0,0,120,
  	13,1,0,0,0,121,122,3,16,8,0,122,123,3,18,9,0,123,124,5,20,0,0,124,15,
  	1,0,0,0,125,126,7,0,0,0,126,17,1,0,0,0,127,128,6,9,-1,0,128,134,5,30,
  	0,0,129,130,5,30,0,0,130,131,5,18,0,0,131,132,5,31,0,0,132,134,5,19,0,
  	0,133,127,1,0,0,0,133,129,1,0,0,0,134,146,1,0,0,0,135,136,10,4,0,0,136,
  	137,5,21,0,0,137,145,5,30,0,0,138,139,10,3,0,0,139,140,5,21,0,0,140,141,
  	5,30,0,0,141,142,5,18,0,0,142,143,5,31,0,0,143,145,5,19,0,0,144,135,1,
  	0,0,0,144,138,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,0,146,147,1,0,0,0,
  	147,19,1,0,0,0,148,146,1,0,0,0,149,150,6,10,-1,0,150,151,3,22,11,0,151,
  	156,1,0,0,0,152,153,10,1,0,0,153,155,3,22,11,0,154,152,1,0,0,0,155,158,
  	1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,21,1,0,0,0,158,156,1,0,0,
  	0,159,200,3,14,7,0,160,200,3,24,12,0,161,200,3,12,6,0,162,163,5,7,0,0,
  	163,164,5,14,0,0,164,165,3,24,12,0,165,166,3,24,12,0,166,167,3,28,14,
  	0,167,168,5,15,0,0,168,169,3,22,11,0,169,200,1,0,0,0,170,171,5,5,0,0,
  	171,172,5,14,0,0,172,173,3,28,14,0,173,174,5,15,0,0,174,175,3,22,11,0,
  	175,176,5,6,0,0,176,177,3,22,11,0,177,200,1,0,0,0,178,179,5,5,0,0,179,
  	180,5,14,0,0,180,181,3,28,14,0,181,182,5,15,0,0,182,183,3,22,11,0,183,
  	200,1,0,0,0,184,185,5,8,0,0,185,186,5,14,0,0,186,187,3,28,14,0,187,188,
  	5,15,0,0,188,189,3,22,11,0,189,200,1,0,0,0,190,191,5,9,0,0,191,192,5,
  	14,0,0,192,193,5,30,0,0,193,194,5,15,0,0,194,200,5,20,0,0,195,196,5,10,
  	0,0,196,197,3,28,14,0,197,198,5,20,0,0,198,200,1,0,0,0,199,159,1,0,0,
  	0,199,160,1,0,0,0,199,161,1,0,0,0,199,162,1,0,0,0,199,170,1,0,0,0,199,
  	178,1,0,0,0,199,184,1,0,0,0,199,190,1,0,0,0,199,195,1,0,0,0,200,23,1,
  	0,0,0,201,206,5,20,0,0,202,203,3,28,14,0,203,204,5,20,0,0,204,206,1,0,
  	0,0,205,201,1,0,0,0,205,202,1,0,0,0,206,25,1,0,0,0,207,214,5,30,0,0,208,
  	209,5,30,0,0,209,210,5,18,0,0,210,211,3,28,14,0,211,212,5,19,0,0,212,
  	214,1,0,0,0,213,207,1,0,0,0,213,208,1,0,0,0,214,27,1,0,0,0,215,221,3,
  	30,15,0,216,217,3,26,13,0,217,218,5,29,0,0,218,219,3,30,15,0,219,221,
  	1,0,0,0,220,215,1,0,0,0,220,216,1,0,0,0,221,29,1,0,0,0,222,228,3,32,16,
  	0,223,224,3,32,16,0,224,225,5,28,0,0,225,226,3,32,16,0,226,228,1,0,0,
  	0,227,222,1,0,0,0,227,223,1,0,0,0,228,31,1,0,0,0,229,235,3,34,17,0,230,
  	231,3,34,17,0,231,232,5,27,0,0,232,233,3,34,17,0,233,235,1,0,0,0,234,
  	229,1,0,0,0,234,230,1,0,0,0,235,33,1,0,0,0,236,237,6,17,-1,0,237,238,
  	3,36,18,0,238,244,1,0,0,0,239,240,10,1,0,0,240,241,5,22,0,0,241,243,3,
  	36,18,0,242,239,1,0,0,0,243,246,1,0,0,0,244,242,1,0,0,0,244,245,1,0,0,
  	0,245,35,1,0,0,0,246,244,1,0,0,0,247,248,6,18,-1,0,248,249,3,38,19,0,
  	249,255,1,0,0,0,250,251,10,1,0,0,251,252,5,23,0,0,252,254,3,38,19,0,253,
  	250,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,0,255,256,1,0,0,0,256,37,1,
  	0,0,0,257,255,1,0,0,0,258,259,5,22,0,0,259,264,3,38,19,0,260,261,5,26,
  	0,0,261,264,3,38,19,0,262,264,3,40,20,0,263,258,1,0,0,0,263,260,1,0,0,
  	0,263,262,1,0,0,0,264,39,1,0,0,0,265,284,3,26,13,0,266,267,5,30,0,0,267,
  	268,5,14,0,0,268,269,3,42,21,0,269,270,5,15,0,0,270,284,1,0,0,0,271,272,
  	5,14,0,0,272,273,3,28,14,0,273,274,5,15,0,0,274,284,1,0,0,0,275,284,5,
  	31,0,0,276,284,5,32,0,0,277,278,3,26,13,0,278,279,5,24,0,0,279,284,1,
  	0,0,0,280,281,3,26,13,0,281,282,5,25,0,0,282,284,1,0,0,0,283,265,1,0,
  	0,0,283,266,1,0,0,0,283,271,1,0,0,0,283,275,1,0,0,0,283,276,1,0,0,0,283,
  	277,1,0,0,0,283,280,1,0,0,0,284,41,1,0,0,0,285,288,3,44,22,0,286,288,
  	1,0,0,0,287,285,1,0,0,0,287,286,1,0,0,0,288,43,1,0,0,0,289,290,6,22,-1,
  	0,290,291,3,30,15,0,291,297,1,0,0,0,292,293,10,2,0,0,293,294,5,21,0,0,
  	294,296,3,30,15,0,295,292,1,0,0,0,296,299,1,0,0,0,297,295,1,0,0,0,297,
  	298,1,0,0,0,298,45,1,0,0,0,299,297,1,0,0,0,24,55,61,76,91,98,108,110,
  	119,133,144,146,156,199,205,213,220,227,234,244,255,263,283,287,297
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetParserStaticData = std::move(staticData);
}

}

CSubsetParser::CSubsetParser(TokenStream *input) : CSubsetParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubsetParser::CSubsetParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubsetParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubsetParserStaticData->atn, csubsetParserStaticData->decisionToDFA, csubsetParserStaticData->sharedContextCache, options);
}

CSubsetParser::~CSubsetParser() {
  delete _interpreter;
}

const atn::ATN& CSubsetParser::getATN() const {
  return *csubsetParserStaticData->atn;
}

std::string CSubsetParser::getGrammarFileName() const {
  return "CSubset.g4";
}

const std::vector<std::string>& CSubsetParser::getRuleNames() const {
  return csubsetParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubsetParser::getVocabulary() const {
  return csubsetParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetParser::getSerializedATN() const {
  return csubsetParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubsetParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::ProgramContext* CSubsetParser::StartContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}


size_t CSubsetParser::StartContext::getRuleIndex() const {
  return CSubsetParser::RuleStart;
}


std::any CSubsetParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StartContext* CSubsetParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubsetParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::UnitContext* CSubsetParser::ProgramContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramContext* CSubsetParser::ProgramContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}


std::any CSubsetParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::ProgramContext* CSubsetParser::program() {
   return program(0);
}

CSubsetParser::ProgramContext* CSubsetParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubsetParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubsetParser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(51);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(52);
        unit(); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Var_declarationContext* CSubsetParser::UnitContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::Func_declarationContext* CSubsetParser::UnitContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::Func_definitionContext* CSubsetParser::UnitContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}


std::any CSubsetParser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::UnitContext* CSubsetParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubsetParser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(58);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(59);
      func_declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(60);
      func_definition();
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

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Func_declarationContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_declarationContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_declarationContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::Func_declarationContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_declarationContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::Func_declarationContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}


size_t CSubsetParser::Func_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_declaration;
}


std::any CSubsetParser::Func_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_declaration(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Func_declarationContext* CSubsetParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_specifier();
      setState(64);
      match(CSubsetParser::ID);
      setState(65);
      match(CSubsetParser::LPAREN);
      setState(66);
      parameter_list(0);
      setState(67);
      match(CSubsetParser::RPAREN);
      setState(68);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(70);
      type_specifier();
      setState(71);
      match(CSubsetParser::ID);
      setState(72);
      match(CSubsetParser::LPAREN);
      setState(73);
      match(CSubsetParser::RPAREN);
      setState(74);
      match(CSubsetParser::SEMICOLON);
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

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Func_definitionContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_definitionContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Func_definitionContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::Func_definitionContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Func_definitionContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::Func_definitionContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}


size_t CSubsetParser::Func_definitionContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_definition;
}


std::any CSubsetParser::Func_definitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunc_definition(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      type_specifier();
      setState(79);
      match(CSubsetParser::ID);
      setState(80);
      match(CSubsetParser::LPAREN);
      setState(81);
      parameter_list(0);
      setState(82);
      match(CSubsetParser::RPAREN);
      setState(83);
      compound_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(85);
      type_specifier();
      setState(86);
      match(CSubsetParser::ID);
      setState(87);
      match(CSubsetParser::LPAREN);
      setState(88);
      match(CSubsetParser::RPAREN);
      setState(89);
      compound_statement();
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

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Parameter_listContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::Parameter_listContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::Parameter_listContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Parameter_listContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}


size_t CSubsetParser::Parameter_listContext::getRuleIndex() const {
  return CSubsetParser::RuleParameter_list;
}


std::any CSubsetParser::Parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameter_list(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list() {
   return parameter_list(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubsetParser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubsetParser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(94);
      type_specifier();
      setState(95);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      setState(97);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(108);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(100);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(101);
          match(CSubsetParser::COMMA);
          setState(102);
          type_specifier();
          setState(103);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(105);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(106);
          match(CSubsetParser::COMMA);
          setState(107);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::Compound_statementContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::Compound_statementContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::Compound_statementContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}


size_t CSubsetParser::Compound_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleCompound_statement;
}


std::any CSubsetParser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Compound_statementContext* CSubsetParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      match(CSubsetParser::LCURL);
      setState(114);
      statements(0);
      setState(115);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(CSubsetParser::LCURL);
      setState(118);
      match(CSubsetParser::RCURL);
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

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Type_specifierContext* CSubsetParser::Var_declarationContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::Var_declarationContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Var_declarationContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}


size_t CSubsetParser::Var_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleVar_declaration;
}


std::any CSubsetParser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Var_declarationContext* CSubsetParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubsetParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    type_specifier();
    setState(122);
    declaration_list(0);
    setState(123);
    match(CSubsetParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::Type_specifierContext::INT() {
  return getToken(CSubsetParser::INT, 0);
}

tree::TerminalNode* CSubsetParser::Type_specifierContext::FLOAT() {
  return getToken(CSubsetParser::FLOAT, 0);
}

tree::TerminalNode* CSubsetParser::Type_specifierContext::VOID() {
  return getToken(CSubsetParser::VOID, 0);
}


size_t CSubsetParser::Type_specifierContext::getRuleIndex() const {
  return CSubsetParser::RuleType_specifier;
}


std::any CSubsetParser::Type_specifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitType_specifier(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Type_specifierContext* CSubsetParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubsetParser::RuleType_specifier);
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
    setState(125);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::Declaration_listContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::Declaration_listContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::Declaration_listContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::Declaration_listContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::Declaration_listContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::Declaration_listContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}


size_t CSubsetParser::Declaration_listContext::getRuleIndex() const {
  return CSubsetParser::RuleDeclaration_list;
}


std::any CSubsetParser::Declaration_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclaration_list(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubsetParser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(128);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      setState(129);
      match(CSubsetParser::ID);
      setState(130);
      match(CSubsetParser::LTHIRD);
      setState(131);
      match(CSubsetParser::CONST_INT);
      setState(132);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(144);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(135);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(136);
          match(CSubsetParser::COMMA);
          setState(137);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(138);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(139);
          match(CSubsetParser::COMMA);
          setState(140);
          match(CSubsetParser::ID);
          setState(141);
          match(CSubsetParser::LTHIRD);
          setState(142);
          match(CSubsetParser::CONST_INT);
          setState(143);
          match(CSubsetParser::RTHIRD);
          break;
        }

        default:
          break;
        } 
      }
      setState(148);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubsetParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::StatementContext* CSubsetParser::StatementsContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsContext* CSubsetParser::StatementsContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}


size_t CSubsetParser::StatementsContext::getRuleIndex() const {
  return CSubsetParser::RuleStatements;
}


std::any CSubsetParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::StatementsContext* CSubsetParser::statements() {
   return statements(0);
}

CSubsetParser::StatementsContext* CSubsetParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubsetParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubsetParser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(150);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(152);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(153);
        statement(); 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubsetParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Var_declarationContext* CSubsetParser::StatementContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

std::vector<CSubsetParser::Expression_statementContext *> CSubsetParser::StatementContext::expression_statement() {
  return getRuleContexts<CSubsetParser::Expression_statementContext>();
}

CSubsetParser::Expression_statementContext* CSubsetParser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<CSubsetParser::Expression_statementContext>(i);
}

CSubsetParser::Compound_statementContext* CSubsetParser::StatementContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

tree::TerminalNode* CSubsetParser::StatementContext::FOR() {
  return getToken(CSubsetParser::FOR, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::StatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::StatementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

std::vector<CSubsetParser::StatementContext *> CSubsetParser::StatementContext::statement() {
  return getRuleContexts<CSubsetParser::StatementContext>();
}

CSubsetParser::StatementContext* CSubsetParser::StatementContext::statement(size_t i) {
  return getRuleContext<CSubsetParser::StatementContext>(i);
}

tree::TerminalNode* CSubsetParser::StatementContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::ELSE() {
  return getToken(CSubsetParser::ELSE, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::WHILE() {
  return getToken(CSubsetParser::WHILE, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::PRINTLN() {
  return getToken(CSubsetParser::PRINTLN, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

tree::TerminalNode* CSubsetParser::StatementContext::RETURN() {
  return getToken(CSubsetParser::RETURN, 0);
}


size_t CSubsetParser::StatementContext::getRuleIndex() const {
  return CSubsetParser::RuleStatement;
}


std::any CSubsetParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(159);
      var_declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(160);
      expression_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(161);
      compound_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(162);
      match(CSubsetParser::FOR);
      setState(163);
      match(CSubsetParser::LPAREN);
      setState(164);
      expression_statement();
      setState(165);
      expression_statement();
      setState(166);
      expression();
      setState(167);
      match(CSubsetParser::RPAREN);
      setState(168);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(170);
      match(CSubsetParser::IF);
      setState(171);
      match(CSubsetParser::LPAREN);
      setState(172);
      expression();
      setState(173);
      match(CSubsetParser::RPAREN);
      setState(174);
      statement();
      setState(175);
      match(CSubsetParser::ELSE);
      setState(176);
      statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(178);
      match(CSubsetParser::IF);
      setState(179);
      match(CSubsetParser::LPAREN);
      setState(180);
      expression();
      setState(181);
      match(CSubsetParser::RPAREN);
      setState(182);
      statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(184);
      match(CSubsetParser::WHILE);
      setState(185);
      match(CSubsetParser::LPAREN);
      setState(186);
      expression();
      setState(187);
      match(CSubsetParser::RPAREN);
      setState(188);
      statement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(190);
      match(CSubsetParser::PRINTLN);
      setState(191);
      match(CSubsetParser::LPAREN);
      setState(192);
      match(CSubsetParser::ID);
      setState(193);
      match(CSubsetParser::RPAREN);
      setState(194);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(195);
      match(CSubsetParser::RETURN);
      setState(196);
      expression();
      setState(197);
      match(CSubsetParser::SEMICOLON);
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

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::Expression_statementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::Expression_statementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}


size_t CSubsetParser::Expression_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression_statement;
}


std::any CSubsetParser::Expression_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression_statement(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Expression_statementContext* CSubsetParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(201);
        match(CSubsetParser::SEMICOLON);
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(202);
        expression();
        setState(203);
        match(CSubsetParser::SEMICOLON);
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

//----------------- VariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::VariableContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::VariableContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::VariableContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::VariableContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}


size_t CSubsetParser::VariableContext::getRuleIndex() const {
  return CSubsetParser::RuleVariable;
}


std::any CSubsetParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::VariableContext* CSubsetParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(207);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(208);
      match(CSubsetParser::ID);
      setState(209);
      match(CSubsetParser::LTHIRD);
      setState(210);
      expression();
      setState(211);
      match(CSubsetParser::RTHIRD);
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

//----------------- ExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ExpressionContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::VariableContext* CSubsetParser::ExpressionContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::ExpressionContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}


size_t CSubsetParser::ExpressionContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression;
}


std::any CSubsetParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ExpressionContext* CSubsetParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      logic_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      variable();
      setState(217);
      match(CSubsetParser::ASSIGNOP);
      setState(218);
      logic_expression();
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

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CSubsetParser::Rel_expressionContext *> CSubsetParser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<CSubsetParser::Rel_expressionContext>();
}

CSubsetParser::Rel_expressionContext* CSubsetParser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::Logic_expressionContext::LOGICOP() {
  return getToken(CSubsetParser::LOGICOP, 0);
}


size_t CSubsetParser::Logic_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleLogic_expression;
}


std::any CSubsetParser::Logic_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogic_expression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(222);
      rel_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(223);
      rel_expression();
      setState(224);
      match(CSubsetParser::LOGICOP);
      setState(225);
      rel_expression();
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

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CSubsetParser::Simple_expressionContext *> CSubsetParser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<CSubsetParser::Simple_expressionContext>();
}

CSubsetParser::Simple_expressionContext* CSubsetParser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::Rel_expressionContext::RELOP() {
  return getToken(CSubsetParser::RELOP, 0);
}


size_t CSubsetParser::Rel_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleRel_expression;
}


std::any CSubsetParser::Rel_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRel_expression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Rel_expressionContext* CSubsetParser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(234);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(229);
      simple_expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(230);
      simple_expression(0);
      setState(231);
      match(CSubsetParser::RELOP);
      setState(232);
      simple_expression(0);
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

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::TermContext* CSubsetParser::Simple_expressionContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::Simple_expressionContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Simple_expressionContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}


size_t CSubsetParser::Simple_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleSimple_expression;
}


std::any CSubsetParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression() {
   return simple_expression(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubsetParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubsetParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(237);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(244);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(239);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(240);
        match(CSubsetParser::ADDOP);
        setState(241);
        term(0); 
      }
      setState(246);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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

CSubsetParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Unary_expressionContext* CSubsetParser::TermContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::TermContext* CSubsetParser::TermContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

tree::TerminalNode* CSubsetParser::TermContext::MULOP() {
  return getToken(CSubsetParser::MULOP, 0);
}


size_t CSubsetParser::TermContext::getRuleIndex() const {
  return CSubsetParser::RuleTerm;
}


std::any CSubsetParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::TermContext* CSubsetParser::term() {
   return term(0);
}

CSubsetParser::TermContext* CSubsetParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubsetParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubsetParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(248);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(250);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(251);
        match(CSubsetParser::MULOP);
        setState(252);
        unary_expression(); 
      }
      setState(257);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CSubsetParser::Unary_expressionContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::Unary_expressionContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::Unary_expressionContext::NOT() {
  return getToken(CSubsetParser::NOT, 0);
}

CSubsetParser::FactorContext* CSubsetParser::Unary_expressionContext::factor() {
  return getRuleContext<CSubsetParser::FactorContext>(0);
}


size_t CSubsetParser::Unary_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleUnary_expression;
}


std::any CSubsetParser::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        match(CSubsetParser::ADDOP);
        setState(259);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(260);
        match(CSubsetParser::NOT);
        setState(261);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(262);
        factor();
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

//----------------- FactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::VariableContext* CSubsetParser::FactorContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FactorContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Argument_listContext* CSubsetParser::FactorContext::argument_list() {
  return getRuleContext<CSubsetParser::Argument_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::FactorContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::FactorContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::FactorContext::CONST_FLOAT() {
  return getToken(CSubsetParser::CONST_FLOAT, 0);
}

tree::TerminalNode* CSubsetParser::FactorContext::INCOP() {
  return getToken(CSubsetParser::INCOP, 0);
}

tree::TerminalNode* CSubsetParser::FactorContext::DECOP() {
  return getToken(CSubsetParser::DECOP, 0);
}


size_t CSubsetParser::FactorContext::getRuleIndex() const {
  return CSubsetParser::RuleFactor;
}


std::any CSubsetParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::FactorContext* CSubsetParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(265);
      variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(266);
      match(CSubsetParser::ID);
      setState(267);
      match(CSubsetParser::LPAREN);
      setState(268);
      argument_list();
      setState(269);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(271);
      match(CSubsetParser::LPAREN);
      setState(272);
      expression();
      setState(273);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(275);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(276);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(277);
      variable();
      setState(278);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(280);
      variable();
      setState(281);
      match(CSubsetParser::DECOP);
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

//----------------- Argument_listContext ------------------------------------------------------------------

CSubsetParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::ArgumentsContext* CSubsetParser::Argument_listContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}


size_t CSubsetParser::Argument_listContext::getRuleIndex() const {
  return CSubsetParser::RuleArgument_list;
}


std::any CSubsetParser::Argument_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgument_list(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Argument_listContext* CSubsetParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubsetParser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(285);
        arguments(0);
        break;
      }

      case CSubsetParser::RPAREN: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentsContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::ArgumentsContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubsetParser::ArgumentsContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}


size_t CSubsetParser::ArgumentsContext::getRuleIndex() const {
  return CSubsetParser::RuleArguments;
}


std::any CSubsetParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}


CSubsetParser::ArgumentsContext* CSubsetParser::arguments() {
   return arguments(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubsetParser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubsetParser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(290);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(292);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(293);
        match(CSubsetParser::COMMA);
        setState(294);
        logic_expression(); 
      }
      setState(299);
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

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubsetParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetParserInitialize();
#else
  ::antlr4::internal::call_once(csubsetParserOnceFlag, csubsetParserInitialize);
#endif
}
