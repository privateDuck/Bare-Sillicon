
// Generated from bs.g4 by ANTLR 4.13.1


#include "bsListener.h"
#include "bsVisitor.h"

#include "bsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BsParserStaticData final {
  BsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BsParserStaticData(const BsParserStaticData&) = delete;
  BsParserStaticData(BsParserStaticData&&) = delete;
  BsParserStaticData& operator=(const BsParserStaticData&) = delete;
  BsParserStaticData& operator=(BsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag bsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
BsParserStaticData *bsParserStaticData = nullptr;

void bsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (bsParserStaticData != nullptr) {
    return;
  }
#else
  assert(bsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<BsParserStaticData>(
    std::vector<std::string>{
      "program", "declaration", "typedef", "global", "function", "params", 
      "param_decl", "block", "statement", "var_decl", "array_decl", "array_initializer", 
      "init_element", "goto_label", "compound", "if", "ifelse", "while", 
      "for1", "for2", "goto", "goto_if", "return", "break", "continue", 
      "expr", "args", "type", "udef_type", "alignment"
    },
    std::vector<std::string>{
      "", "';'", "'='", "'('", "')'", "','", "'{'", "'}'", "'['", "']'", 
      "':'", "'++'", "'--'", "'<'", "'>'", "'&'", "'~'", "'!'", "'*'", "'/'", 
      "'%'", "'>>'", "'<<'", "'>='", "'<='", "'=='", "'!='", "'^'", "'|'", 
      "'&&'", "'||'", "'+='", "'-='", "'*='", "'/='", "'%='", "'<<='", "'>>='", 
      "'&='", "'^='", "'|='", "'byte'", "'char'", "'int'", "", "'uchar'", 
      "'uint'", "'goto'", "'if'", "'else'", "'while'", "'for'", "'return'", 
      "'break'", "'continue'", "'static'", "'reinterpret_cast'", "'from'", 
      "'to'", "'typedef'", "", "", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "BYTE_t", "CHAR_t", "INT_t", "UBYTE_t", 
      "UCHAR_t", "UINT_t", "GOTO", "IF", "ELSE", "WHILE", "FOR", "RETURN", 
      "BREAK", "CONTINUE", "STATIC", "REINTERPRET_CAST", "FROM", "TO", "TYPEDEF", 
      "FN", "ALIGN", "PLUS", "MINUS", "ID", "CHAR", "STRING_LITERAL", "UNTERMINATED_STRING_LITERAL", 
      "UNSIGNED_INT", "Newline", "Whitespace", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,72,408,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,1,0,1,1,1,1,1,1,3,1,
  	72,8,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,3,
  	4,89,8,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,97,8,5,10,5,12,5,100,9,5,1,6,1,6,
  	1,6,1,7,1,7,5,7,107,8,7,10,7,12,7,110,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,131,8,8,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,146,8,10,1,10,1,
  	10,1,11,1,11,1,11,1,11,5,11,154,8,11,10,11,12,11,157,9,11,1,11,1,11,1,
  	12,1,12,1,12,3,12,164,8,12,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,18,1,18,1,18,3,18,194,8,18,1,18,1,18,3,18,198,8,18,1,18,
  	1,18,3,18,202,8,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,22,
  	1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,3,25,245,8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,269,8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,296,8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,306,8,25,1,
  	25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,316,8,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,3,25,326,8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,
  	25,1,25,3,25,336,8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,346,
  	8,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,5,25,387,
  	8,25,10,25,12,25,390,9,25,1,26,1,26,1,26,5,26,395,8,26,10,26,12,26,398,
  	9,26,1,27,1,27,1,28,1,28,3,28,404,8,28,1,29,1,29,1,29,0,1,50,30,0,2,4,
  	6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,
  	54,56,58,0,12,1,0,11,12,1,0,62,63,1,0,16,17,1,0,31,32,1,0,33,35,1,0,36,
  	37,1,0,38,40,1,0,18,19,1,0,13,14,1,0,23,24,1,0,25,26,1,0,41,46,448,0,
  	63,1,0,0,0,2,71,1,0,0,0,4,73,1,0,0,0,6,78,1,0,0,0,8,84,1,0,0,0,10,93,
  	1,0,0,0,12,101,1,0,0,0,14,104,1,0,0,0,16,130,1,0,0,0,18,132,1,0,0,0,20,
  	138,1,0,0,0,22,149,1,0,0,0,24,163,1,0,0,0,26,165,1,0,0,0,28,168,1,0,0,
  	0,30,170,1,0,0,0,32,176,1,0,0,0,34,184,1,0,0,0,36,190,1,0,0,0,38,206,
  	1,0,0,0,40,216,1,0,0,0,42,220,1,0,0,0,44,226,1,0,0,0,46,230,1,0,0,0,48,
  	233,1,0,0,0,50,345,1,0,0,0,52,391,1,0,0,0,54,399,1,0,0,0,56,403,1,0,0,
  	0,58,405,1,0,0,0,60,62,3,2,1,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,
  	0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,0,0,1,67,1,1,0,
  	0,0,68,72,3,6,3,0,69,72,3,8,4,0,70,72,3,4,2,0,71,68,1,0,0,0,71,69,1,0,
  	0,0,71,70,1,0,0,0,72,3,1,0,0,0,73,74,5,59,0,0,74,75,3,54,27,0,75,76,5,
  	64,0,0,76,77,5,1,0,0,77,5,1,0,0,0,78,79,3,56,28,0,79,80,5,64,0,0,80,81,
  	5,2,0,0,81,82,3,50,25,0,82,83,5,1,0,0,83,7,1,0,0,0,84,85,3,56,28,0,85,
  	86,5,64,0,0,86,88,5,3,0,0,87,89,3,10,5,0,88,87,1,0,0,0,88,89,1,0,0,0,
  	89,90,1,0,0,0,90,91,5,4,0,0,91,92,3,14,7,0,92,9,1,0,0,0,93,98,3,12,6,
  	0,94,95,5,5,0,0,95,97,3,12,6,0,96,94,1,0,0,0,97,100,1,0,0,0,98,96,1,0,
  	0,0,98,99,1,0,0,0,99,11,1,0,0,0,100,98,1,0,0,0,101,102,3,56,28,0,102,
  	103,5,64,0,0,103,13,1,0,0,0,104,108,5,6,0,0,105,107,3,16,8,0,106,105,
  	1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,111,1,0,0,
  	0,110,108,1,0,0,0,111,112,5,7,0,0,112,15,1,0,0,0,113,131,3,18,9,0,114,
  	131,3,20,10,0,115,116,3,50,25,0,116,117,5,1,0,0,117,131,1,0,0,0,118,131,
  	3,26,13,0,119,131,3,28,14,0,120,131,3,30,15,0,121,131,3,32,16,0,122,131,
  	3,34,17,0,123,131,3,36,18,0,124,131,3,38,19,0,125,131,3,40,20,0,126,131,
  	3,42,21,0,127,131,3,44,22,0,128,131,3,46,23,0,129,131,3,48,24,0,130,113,
  	1,0,0,0,130,114,1,0,0,0,130,115,1,0,0,0,130,118,1,0,0,0,130,119,1,0,0,
  	0,130,120,1,0,0,0,130,121,1,0,0,0,130,122,1,0,0,0,130,123,1,0,0,0,130,
  	124,1,0,0,0,130,125,1,0,0,0,130,126,1,0,0,0,130,127,1,0,0,0,130,128,1,
  	0,0,0,130,129,1,0,0,0,131,17,1,0,0,0,132,133,3,56,28,0,133,134,5,64,0,
  	0,134,135,5,2,0,0,135,136,3,50,25,0,136,137,5,1,0,0,137,19,1,0,0,0,138,
  	139,3,56,28,0,139,140,5,64,0,0,140,141,5,8,0,0,141,142,5,68,0,0,142,145,
  	5,9,0,0,143,144,5,2,0,0,144,146,3,22,11,0,145,143,1,0,0,0,145,146,1,0,
  	0,0,146,147,1,0,0,0,147,148,5,1,0,0,148,21,1,0,0,0,149,150,5,6,0,0,150,
  	155,3,24,12,0,151,152,5,5,0,0,152,154,3,24,12,0,153,151,1,0,0,0,154,157,
  	1,0,0,0,155,153,1,0,0,0,155,156,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,
  	0,158,159,5,7,0,0,159,23,1,0,0,0,160,164,5,68,0,0,161,164,5,65,0,0,162,
  	164,5,66,0,0,163,160,1,0,0,0,163,161,1,0,0,0,163,162,1,0,0,0,164,25,1,
  	0,0,0,165,166,5,64,0,0,166,167,5,10,0,0,167,27,1,0,0,0,168,169,3,14,7,
  	0,169,29,1,0,0,0,170,171,5,48,0,0,171,172,5,3,0,0,172,173,3,50,25,0,173,
  	174,5,4,0,0,174,175,3,16,8,0,175,31,1,0,0,0,176,177,5,48,0,0,177,178,
  	5,3,0,0,178,179,3,50,25,0,179,180,5,4,0,0,180,181,3,16,8,0,181,182,5,
  	49,0,0,182,183,3,16,8,0,183,33,1,0,0,0,184,185,5,50,0,0,185,186,5,3,0,
  	0,186,187,3,50,25,0,187,188,5,4,0,0,188,189,3,16,8,0,189,35,1,0,0,0,190,
  	191,5,51,0,0,191,193,5,3,0,0,192,194,3,18,9,0,193,192,1,0,0,0,193,194,
  	1,0,0,0,194,195,1,0,0,0,195,197,5,1,0,0,196,198,3,50,25,0,197,196,1,0,
  	0,0,197,198,1,0,0,0,198,199,1,0,0,0,199,201,5,1,0,0,200,202,3,50,25,0,
  	201,200,1,0,0,0,201,202,1,0,0,0,202,203,1,0,0,0,203,204,5,4,0,0,204,205,
  	3,16,8,0,205,37,1,0,0,0,206,207,5,51,0,0,207,208,5,3,0,0,208,209,5,64,
  	0,0,209,210,5,57,0,0,210,211,3,50,25,0,211,212,5,58,0,0,212,213,3,50,
  	25,0,213,214,5,4,0,0,214,215,3,16,8,0,215,39,1,0,0,0,216,217,5,47,0,0,
  	217,218,5,64,0,0,218,219,5,1,0,0,219,41,1,0,0,0,220,221,5,47,0,0,221,
  	222,5,64,0,0,222,223,5,48,0,0,223,224,3,50,25,0,224,225,5,1,0,0,225,43,
  	1,0,0,0,226,227,5,52,0,0,227,228,3,50,25,0,228,229,5,1,0,0,229,45,1,0,
  	0,0,230,231,5,53,0,0,231,232,5,1,0,0,232,47,1,0,0,0,233,234,5,54,0,0,
  	234,235,5,1,0,0,235,49,1,0,0,0,236,237,6,25,-1,0,237,238,5,3,0,0,238,
  	239,3,50,25,0,239,240,5,4,0,0,240,346,1,0,0,0,241,242,5,64,0,0,242,244,
  	5,3,0,0,243,245,3,52,26,0,244,243,1,0,0,0,244,245,1,0,0,0,245,246,1,0,
  	0,0,246,346,5,4,0,0,247,248,7,0,0,0,248,346,5,64,0,0,249,250,7,1,0,0,
  	250,346,3,50,25,33,251,252,5,3,0,0,252,253,3,56,28,0,253,254,5,4,0,0,
  	254,255,3,50,25,32,255,346,1,0,0,0,256,257,5,56,0,0,257,258,5,13,0,0,
  	258,259,3,56,28,0,259,260,5,14,0,0,260,261,5,3,0,0,261,262,3,50,25,0,
  	262,263,5,4,0,0,263,346,1,0,0,0,264,265,5,8,0,0,265,268,3,50,25,0,266,
  	267,5,10,0,0,267,269,3,58,29,0,268,266,1,0,0,0,268,269,1,0,0,0,269,270,
  	1,0,0,0,270,271,5,9,0,0,271,346,1,0,0,0,272,273,5,15,0,0,273,346,5,64,
  	0,0,274,275,7,2,0,0,275,346,3,50,25,28,276,277,5,64,0,0,277,278,5,2,0,
  	0,278,346,3,50,25,14,279,280,5,64,0,0,280,281,7,3,0,0,281,346,3,50,25,
  	13,282,283,5,64,0,0,283,284,7,4,0,0,284,346,3,50,25,12,285,286,5,64,0,
  	0,286,287,7,5,0,0,287,346,3,50,25,11,288,289,5,64,0,0,289,290,7,6,0,0,
  	290,346,3,50,25,10,291,292,5,8,0,0,292,295,3,50,25,0,293,294,5,10,0,0,
  	294,296,3,58,29,0,295,293,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,
  	298,5,9,0,0,298,299,5,2,0,0,299,300,3,50,25,9,300,346,1,0,0,0,301,302,
  	5,8,0,0,302,305,3,50,25,0,303,304,5,10,0,0,304,306,3,58,29,0,305,303,
  	1,0,0,0,305,306,1,0,0,0,306,307,1,0,0,0,307,308,5,9,0,0,308,309,7,3,0,
  	0,309,310,3,50,25,8,310,346,1,0,0,0,311,312,5,8,0,0,312,315,3,50,25,0,
  	313,314,5,10,0,0,314,316,3,58,29,0,315,313,1,0,0,0,315,316,1,0,0,0,316,
  	317,1,0,0,0,317,318,5,9,0,0,318,319,7,4,0,0,319,320,3,50,25,7,320,346,
  	1,0,0,0,321,322,5,8,0,0,322,325,3,50,25,0,323,324,5,10,0,0,324,326,3,
  	58,29,0,325,323,1,0,0,0,325,326,1,0,0,0,326,327,1,0,0,0,327,328,5,9,0,
  	0,328,329,7,5,0,0,329,330,3,50,25,6,330,346,1,0,0,0,331,332,5,8,0,0,332,
  	335,3,50,25,0,333,334,5,10,0,0,334,336,3,58,29,0,335,333,1,0,0,0,335,
  	336,1,0,0,0,336,337,1,0,0,0,337,338,5,9,0,0,338,339,7,6,0,0,339,340,3,
  	50,25,5,340,346,1,0,0,0,341,346,5,64,0,0,342,346,5,68,0,0,343,346,5,66,
  	0,0,344,346,5,65,0,0,345,236,1,0,0,0,345,241,1,0,0,0,345,247,1,0,0,0,
  	345,249,1,0,0,0,345,251,1,0,0,0,345,256,1,0,0,0,345,264,1,0,0,0,345,272,
  	1,0,0,0,345,274,1,0,0,0,345,276,1,0,0,0,345,279,1,0,0,0,345,282,1,0,0,
  	0,345,285,1,0,0,0,345,288,1,0,0,0,345,291,1,0,0,0,345,301,1,0,0,0,345,
  	311,1,0,0,0,345,321,1,0,0,0,345,331,1,0,0,0,345,341,1,0,0,0,345,342,1,
  	0,0,0,345,343,1,0,0,0,345,344,1,0,0,0,346,388,1,0,0,0,347,348,10,27,0,
  	0,348,349,7,7,0,0,349,387,3,50,25,28,350,351,10,26,0,0,351,352,5,20,0,
  	0,352,387,3,50,25,27,353,354,10,25,0,0,354,355,7,1,0,0,355,387,3,50,25,
  	26,356,357,10,24,0,0,357,358,5,21,0,0,358,387,3,50,25,25,359,360,10,23,
  	0,0,360,361,5,22,0,0,361,387,3,50,25,24,362,363,10,22,0,0,363,364,7,8,
  	0,0,364,387,3,50,25,23,365,366,10,21,0,0,366,367,7,9,0,0,367,387,3,50,
  	25,22,368,369,10,20,0,0,369,370,7,10,0,0,370,387,3,50,25,21,371,372,10,
  	19,0,0,372,373,5,15,0,0,373,387,3,50,25,20,374,375,10,18,0,0,375,376,
  	5,27,0,0,376,387,3,50,25,19,377,378,10,17,0,0,378,379,5,28,0,0,379,387,
  	3,50,25,18,380,381,10,16,0,0,381,382,5,29,0,0,382,387,3,50,25,17,383,
  	384,10,15,0,0,384,385,5,30,0,0,385,387,3,50,25,16,386,347,1,0,0,0,386,
  	350,1,0,0,0,386,353,1,0,0,0,386,356,1,0,0,0,386,359,1,0,0,0,386,362,1,
  	0,0,0,386,365,1,0,0,0,386,368,1,0,0,0,386,371,1,0,0,0,386,374,1,0,0,0,
  	386,377,1,0,0,0,386,380,1,0,0,0,386,383,1,0,0,0,387,390,1,0,0,0,388,386,
  	1,0,0,0,388,389,1,0,0,0,389,51,1,0,0,0,390,388,1,0,0,0,391,396,3,50,25,
  	0,392,393,5,5,0,0,393,395,3,50,25,0,394,392,1,0,0,0,395,398,1,0,0,0,396,
  	394,1,0,0,0,396,397,1,0,0,0,397,53,1,0,0,0,398,396,1,0,0,0,399,400,7,
  	11,0,0,400,55,1,0,0,0,401,404,3,54,27,0,402,404,5,64,0,0,403,401,1,0,
  	0,0,403,402,1,0,0,0,404,57,1,0,0,0,405,406,5,61,0,0,406,59,1,0,0,0,24,
  	63,71,88,98,108,130,145,155,163,193,197,201,244,268,295,305,315,325,335,
  	345,386,388,396,403
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  bsParserStaticData = staticData.release();
}

}

bsParser::bsParser(TokenStream *input) : bsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

bsParser::bsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  bsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *bsParserStaticData->atn, bsParserStaticData->decisionToDFA, bsParserStaticData->sharedContextCache, options);
}

bsParser::~bsParser() {
  delete _interpreter;
}

const atn::ATN& bsParser::getATN() const {
  return *bsParserStaticData->atn;
}

std::string bsParser::getGrammarFileName() const {
  return "bs.g4";
}

const std::vector<std::string>& bsParser::getRuleNames() const {
  return bsParserStaticData->ruleNames;
}

const dfa::Vocabulary& bsParser::getVocabulary() const {
  return bsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView bsParser::getSerializedATN() const {
  return bsParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

bsParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::ProgramContext::EOF() {
  return getToken(bsParser::EOF, 0);
}

std::vector<bsParser::DeclarationContext *> bsParser::ProgramContext::declaration() {
  return getRuleContexts<bsParser::DeclarationContext>();
}

bsParser::DeclarationContext* bsParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<bsParser::DeclarationContext>(i);
}


size_t bsParser::ProgramContext::getRuleIndex() const {
  return bsParser::RuleProgram;
}

void bsParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void bsParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any bsParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ProgramContext* bsParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, bsParser::RuleProgram);
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
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 41) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 41)) & 8650815) != 0)) {
      setState(60);
      declaration();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(bsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

bsParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::GlobalContext* bsParser::DeclarationContext::global() {
  return getRuleContext<bsParser::GlobalContext>(0);
}

bsParser::FunctionContext* bsParser::DeclarationContext::function() {
  return getRuleContext<bsParser::FunctionContext>(0);
}

bsParser::TypedefContext* bsParser::DeclarationContext::typedef_() {
  return getRuleContext<bsParser::TypedefContext>(0);
}


size_t bsParser::DeclarationContext::getRuleIndex() const {
  return bsParser::RuleDeclaration;
}

void bsParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void bsParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any bsParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

bsParser::DeclarationContext* bsParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, bsParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(68);
      global();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(69);
      function();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      typedef_();
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

//----------------- TypedefContext ------------------------------------------------------------------

bsParser::TypedefContext::TypedefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::TypedefContext::TYPEDEF() {
  return getToken(bsParser::TYPEDEF, 0);
}

bsParser::TypeContext* bsParser::TypedefContext::type() {
  return getRuleContext<bsParser::TypeContext>(0);
}

tree::TerminalNode* bsParser::TypedefContext::ID() {
  return getToken(bsParser::ID, 0);
}


size_t bsParser::TypedefContext::getRuleIndex() const {
  return bsParser::RuleTypedef;
}

void bsParser::TypedefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedef(this);
}

void bsParser::TypedefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedef(this);
}


std::any bsParser::TypedefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitTypedef(this);
  else
    return visitor->visitChildren(this);
}

bsParser::TypedefContext* bsParser::typedef_() {
  TypedefContext *_localctx = _tracker.createInstance<TypedefContext>(_ctx, getState());
  enterRule(_localctx, 4, bsParser::RuleTypedef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(bsParser::TYPEDEF);
    setState(74);
    type();
    setState(75);
    match(bsParser::ID);
    setState(76);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalContext ------------------------------------------------------------------

bsParser::GlobalContext::GlobalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Udef_typeContext* bsParser::GlobalContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

tree::TerminalNode* bsParser::GlobalContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::GlobalContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}


size_t bsParser::GlobalContext::getRuleIndex() const {
  return bsParser::RuleGlobal;
}

void bsParser::GlobalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal(this);
}

void bsParser::GlobalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal(this);
}


std::any bsParser::GlobalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGlobal(this);
  else
    return visitor->visitChildren(this);
}

bsParser::GlobalContext* bsParser::global() {
  GlobalContext *_localctx = _tracker.createInstance<GlobalContext>(_ctx, getState());
  enterRule(_localctx, 6, bsParser::RuleGlobal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    udef_type();
    setState(79);
    match(bsParser::ID);
    setState(80);
    match(bsParser::T__1);
    setState(81);
    expr(0);
    setState(82);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

bsParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Udef_typeContext* bsParser::FunctionContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

tree::TerminalNode* bsParser::FunctionContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::BlockContext* bsParser::FunctionContext::block() {
  return getRuleContext<bsParser::BlockContext>(0);
}

bsParser::ParamsContext* bsParser::FunctionContext::params() {
  return getRuleContext<bsParser::ParamsContext>(0);
}


size_t bsParser::FunctionContext::getRuleIndex() const {
  return bsParser::RuleFunction;
}

void bsParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void bsParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any bsParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

bsParser::FunctionContext* bsParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 8, bsParser::RuleFunction);
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
    setState(84);
    udef_type();
    setState(85);
    match(bsParser::ID);
    setState(86);
    match(bsParser::T__2);
    setState(88);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 41) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 41)) & 8388671) != 0)) {
      setState(87);
      params();
    }
    setState(90);
    match(bsParser::T__3);
    setState(91);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

bsParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bsParser::Param_declContext *> bsParser::ParamsContext::param_decl() {
  return getRuleContexts<bsParser::Param_declContext>();
}

bsParser::Param_declContext* bsParser::ParamsContext::param_decl(size_t i) {
  return getRuleContext<bsParser::Param_declContext>(i);
}


size_t bsParser::ParamsContext::getRuleIndex() const {
  return bsParser::RuleParams;
}

void bsParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void bsParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


std::any bsParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ParamsContext* bsParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 10, bsParser::RuleParams);
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
    setState(93);
    param_decl();
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bsParser::T__4) {
      setState(94);
      match(bsParser::T__4);
      setState(95);
      param_decl();
      setState(100);
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

//----------------- Param_declContext ------------------------------------------------------------------

bsParser::Param_declContext::Param_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Udef_typeContext* bsParser::Param_declContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

tree::TerminalNode* bsParser::Param_declContext::ID() {
  return getToken(bsParser::ID, 0);
}


size_t bsParser::Param_declContext::getRuleIndex() const {
  return bsParser::RuleParam_decl;
}

void bsParser::Param_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam_decl(this);
}

void bsParser::Param_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam_decl(this);
}


std::any bsParser::Param_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitParam_decl(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Param_declContext* bsParser::param_decl() {
  Param_declContext *_localctx = _tracker.createInstance<Param_declContext>(_ctx, getState());
  enterRule(_localctx, 12, bsParser::RuleParam_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    udef_type();
    setState(102);
    match(bsParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

bsParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bsParser::StatementContext *> bsParser::BlockContext::statement() {
  return getRuleContexts<bsParser::StatementContext>();
}

bsParser::StatementContext* bsParser::BlockContext::statement(size_t i) {
  return getRuleContext<bsParser::StatementContext>(i);
}


size_t bsParser::BlockContext::getRuleIndex() const {
  return bsParser::RuleBlock;
}

void bsParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void bsParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any bsParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

bsParser::BlockContext* bsParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, bsParser::RuleBlock);
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
    setState(104);
    match(bsParser::T__5);
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4504164776346937016) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 23) != 0)) {
      setState(105);
      statement();
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(111);
    match(bsParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

bsParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Var_declContext* bsParser::StatementContext::var_decl() {
  return getRuleContext<bsParser::Var_declContext>(0);
}

bsParser::Array_declContext* bsParser::StatementContext::array_decl() {
  return getRuleContext<bsParser::Array_declContext>(0);
}

bsParser::ExprContext* bsParser::StatementContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::Goto_labelContext* bsParser::StatementContext::goto_label() {
  return getRuleContext<bsParser::Goto_labelContext>(0);
}

bsParser::CompoundContext* bsParser::StatementContext::compound() {
  return getRuleContext<bsParser::CompoundContext>(0);
}

bsParser::IfContext* bsParser::StatementContext::if_() {
  return getRuleContext<bsParser::IfContext>(0);
}

bsParser::IfelseContext* bsParser::StatementContext::ifelse() {
  return getRuleContext<bsParser::IfelseContext>(0);
}

bsParser::WhileContext* bsParser::StatementContext::while_() {
  return getRuleContext<bsParser::WhileContext>(0);
}

bsParser::For1Context* bsParser::StatementContext::for1() {
  return getRuleContext<bsParser::For1Context>(0);
}

bsParser::For2Context* bsParser::StatementContext::for2() {
  return getRuleContext<bsParser::For2Context>(0);
}

bsParser::GotoContext* bsParser::StatementContext::goto_() {
  return getRuleContext<bsParser::GotoContext>(0);
}

bsParser::Goto_ifContext* bsParser::StatementContext::goto_if() {
  return getRuleContext<bsParser::Goto_ifContext>(0);
}

bsParser::ReturnContext* bsParser::StatementContext::return_() {
  return getRuleContext<bsParser::ReturnContext>(0);
}

bsParser::BreakContext* bsParser::StatementContext::break_() {
  return getRuleContext<bsParser::BreakContext>(0);
}

bsParser::ContinueContext* bsParser::StatementContext::continue_() {
  return getRuleContext<bsParser::ContinueContext>(0);
}


size_t bsParser::StatementContext::getRuleIndex() const {
  return bsParser::RuleStatement;
}

void bsParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void bsParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any bsParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

bsParser::StatementContext* bsParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, bsParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      var_decl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
      array_decl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(115);
      expr(0);
      setState(116);
      match(bsParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(118);
      goto_label();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(119);
      compound();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(120);
      if_();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(121);
      ifelse();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(122);
      while_();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(123);
      for1();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(124);
      for2();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(125);
      goto_();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(126);
      goto_if();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(127);
      return_();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(128);
      break_();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(129);
      continue_();
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

//----------------- Var_declContext ------------------------------------------------------------------

bsParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Udef_typeContext* bsParser::Var_declContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

tree::TerminalNode* bsParser::Var_declContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::Var_declContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}


size_t bsParser::Var_declContext::getRuleIndex() const {
  return bsParser::RuleVar_decl;
}

void bsParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void bsParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


std::any bsParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Var_declContext* bsParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 18, bsParser::RuleVar_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    udef_type();
    setState(133);
    match(bsParser::ID);
    setState(134);
    match(bsParser::T__1);
    setState(135);
    expr(0);
    setState(136);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_declContext ------------------------------------------------------------------

bsParser::Array_declContext::Array_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::Udef_typeContext* bsParser::Array_declContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

tree::TerminalNode* bsParser::Array_declContext::ID() {
  return getToken(bsParser::ID, 0);
}

tree::TerminalNode* bsParser::Array_declContext::UNSIGNED_INT() {
  return getToken(bsParser::UNSIGNED_INT, 0);
}

bsParser::Array_initializerContext* bsParser::Array_declContext::array_initializer() {
  return getRuleContext<bsParser::Array_initializerContext>(0);
}


size_t bsParser::Array_declContext::getRuleIndex() const {
  return bsParser::RuleArray_decl;
}

void bsParser::Array_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_decl(this);
}

void bsParser::Array_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_decl(this);
}


std::any bsParser::Array_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitArray_decl(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Array_declContext* bsParser::array_decl() {
  Array_declContext *_localctx = _tracker.createInstance<Array_declContext>(_ctx, getState());
  enterRule(_localctx, 20, bsParser::RuleArray_decl);
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
    setState(138);
    udef_type();
    setState(139);
    match(bsParser::ID);
    setState(140);
    match(bsParser::T__7);
    setState(141);
    match(bsParser::UNSIGNED_INT);
    setState(142);
    match(bsParser::T__8);
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bsParser::T__1) {
      setState(143);
      match(bsParser::T__1);
      setState(144);
      array_initializer();
    }
    setState(147);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_initializerContext ------------------------------------------------------------------

bsParser::Array_initializerContext::Array_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bsParser::Init_elementContext *> bsParser::Array_initializerContext::init_element() {
  return getRuleContexts<bsParser::Init_elementContext>();
}

bsParser::Init_elementContext* bsParser::Array_initializerContext::init_element(size_t i) {
  return getRuleContext<bsParser::Init_elementContext>(i);
}


size_t bsParser::Array_initializerContext::getRuleIndex() const {
  return bsParser::RuleArray_initializer;
}

void bsParser::Array_initializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_initializer(this);
}

void bsParser::Array_initializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_initializer(this);
}


std::any bsParser::Array_initializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitArray_initializer(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Array_initializerContext* bsParser::array_initializer() {
  Array_initializerContext *_localctx = _tracker.createInstance<Array_initializerContext>(_ctx, getState());
  enterRule(_localctx, 22, bsParser::RuleArray_initializer);
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
    match(bsParser::T__5);
    setState(150);
    init_element();
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bsParser::T__4) {
      setState(151);
      match(bsParser::T__4);
      setState(152);
      init_element();
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(158);
    match(bsParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Init_elementContext ------------------------------------------------------------------

bsParser::Init_elementContext::Init_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bsParser::Init_elementContext::getRuleIndex() const {
  return bsParser::RuleInit_element;
}

void bsParser::Init_elementContext::copyFrom(Init_elementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InitCharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::InitCharLiteralContext::CHAR() {
  return getToken(bsParser::CHAR, 0);
}

bsParser::InitCharLiteralContext::InitCharLiteralContext(Init_elementContext *ctx) { copyFrom(ctx); }

void bsParser::InitCharLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitCharLiteral(this);
}
void bsParser::InitCharLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitCharLiteral(this);
}

std::any bsParser::InitCharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitInitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InitIntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::InitIntLiteralContext::UNSIGNED_INT() {
  return getToken(bsParser::UNSIGNED_INT, 0);
}

bsParser::InitIntLiteralContext::InitIntLiteralContext(Init_elementContext *ctx) { copyFrom(ctx); }

void bsParser::InitIntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitIntLiteral(this);
}
void bsParser::InitIntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitIntLiteral(this);
}

std::any bsParser::InitIntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitInitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InitStringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::InitStringLiteralContext::STRING_LITERAL() {
  return getToken(bsParser::STRING_LITERAL, 0);
}

bsParser::InitStringLiteralContext::InitStringLiteralContext(Init_elementContext *ctx) { copyFrom(ctx); }

void bsParser::InitStringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitStringLiteral(this);
}
void bsParser::InitStringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitStringLiteral(this);
}

std::any bsParser::InitStringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitInitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
bsParser::Init_elementContext* bsParser::init_element() {
  Init_elementContext *_localctx = _tracker.createInstance<Init_elementContext>(_ctx, getState());
  enterRule(_localctx, 24, bsParser::RuleInit_element);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bsParser::UNSIGNED_INT: {
        _localctx = _tracker.createInstance<bsParser::InitIntLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(160);
        antlrcpp::downCast<InitIntLiteralContext *>(_localctx)->atom = match(bsParser::UNSIGNED_INT);
        break;
      }

      case bsParser::CHAR: {
        _localctx = _tracker.createInstance<bsParser::InitCharLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(161);
        match(bsParser::CHAR);
        break;
      }

      case bsParser::STRING_LITERAL: {
        _localctx = _tracker.createInstance<bsParser::InitStringLiteralContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(162);
        match(bsParser::STRING_LITERAL);
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

//----------------- Goto_labelContext ------------------------------------------------------------------

bsParser::Goto_labelContext::Goto_labelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::Goto_labelContext::ID() {
  return getToken(bsParser::ID, 0);
}


size_t bsParser::Goto_labelContext::getRuleIndex() const {
  return bsParser::RuleGoto_label;
}

void bsParser::Goto_labelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto_label(this);
}

void bsParser::Goto_labelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto_label(this);
}


std::any bsParser::Goto_labelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGoto_label(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Goto_labelContext* bsParser::goto_label() {
  Goto_labelContext *_localctx = _tracker.createInstance<Goto_labelContext>(_ctx, getState());
  enterRule(_localctx, 26, bsParser::RuleGoto_label);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(bsParser::ID);
    setState(166);
    match(bsParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundContext ------------------------------------------------------------------

bsParser::CompoundContext::CompoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::BlockContext* bsParser::CompoundContext::block() {
  return getRuleContext<bsParser::BlockContext>(0);
}


size_t bsParser::CompoundContext::getRuleIndex() const {
  return bsParser::RuleCompound;
}

void bsParser::CompoundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound(this);
}

void bsParser::CompoundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound(this);
}


std::any bsParser::CompoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitCompound(this);
  else
    return visitor->visitChildren(this);
}

bsParser::CompoundContext* bsParser::compound() {
  CompoundContext *_localctx = _tracker.createInstance<CompoundContext>(_ctx, getState());
  enterRule(_localctx, 28, bsParser::RuleCompound);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfContext ------------------------------------------------------------------

bsParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::IfContext::IF() {
  return getToken(bsParser::IF, 0);
}

bsParser::ExprContext* bsParser::IfContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::StatementContext* bsParser::IfContext::statement() {
  return getRuleContext<bsParser::StatementContext>(0);
}


size_t bsParser::IfContext::getRuleIndex() const {
  return bsParser::RuleIf;
}

void bsParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}

void bsParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}


std::any bsParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}

bsParser::IfContext* bsParser::if_() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 30, bsParser::RuleIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(bsParser::IF);
    setState(171);
    match(bsParser::T__2);
    setState(172);
    expr(0);
    setState(173);
    match(bsParser::T__3);
    setState(174);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfelseContext ------------------------------------------------------------------

bsParser::IfelseContext::IfelseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::IfelseContext::IF() {
  return getToken(bsParser::IF, 0);
}

bsParser::ExprContext* bsParser::IfelseContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

tree::TerminalNode* bsParser::IfelseContext::ELSE() {
  return getToken(bsParser::ELSE, 0);
}

std::vector<bsParser::StatementContext *> bsParser::IfelseContext::statement() {
  return getRuleContexts<bsParser::StatementContext>();
}

bsParser::StatementContext* bsParser::IfelseContext::statement(size_t i) {
  return getRuleContext<bsParser::StatementContext>(i);
}


size_t bsParser::IfelseContext::getRuleIndex() const {
  return bsParser::RuleIfelse;
}

void bsParser::IfelseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfelse(this);
}

void bsParser::IfelseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfelse(this);
}


std::any bsParser::IfelseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIfelse(this);
  else
    return visitor->visitChildren(this);
}

bsParser::IfelseContext* bsParser::ifelse() {
  IfelseContext *_localctx = _tracker.createInstance<IfelseContext>(_ctx, getState());
  enterRule(_localctx, 32, bsParser::RuleIfelse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(bsParser::IF);
    setState(177);
    match(bsParser::T__2);
    setState(178);
    expr(0);
    setState(179);
    match(bsParser::T__3);
    setState(180);
    antlrcpp::downCast<IfelseContext *>(_localctx)->pos = statement();
    setState(181);
    match(bsParser::ELSE);
    setState(182);
    antlrcpp::downCast<IfelseContext *>(_localctx)->neg = statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileContext ------------------------------------------------------------------

bsParser::WhileContext::WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::WhileContext::WHILE() {
  return getToken(bsParser::WHILE, 0);
}

bsParser::ExprContext* bsParser::WhileContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::StatementContext* bsParser::WhileContext::statement() {
  return getRuleContext<bsParser::StatementContext>(0);
}


size_t bsParser::WhileContext::getRuleIndex() const {
  return bsParser::RuleWhile;
}

void bsParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}

void bsParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}


std::any bsParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}

bsParser::WhileContext* bsParser::while_() {
  WhileContext *_localctx = _tracker.createInstance<WhileContext>(_ctx, getState());
  enterRule(_localctx, 34, bsParser::RuleWhile);

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
    match(bsParser::WHILE);
    setState(185);
    match(bsParser::T__2);
    setState(186);
    expr(0);
    setState(187);
    match(bsParser::T__3);
    setState(188);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For1Context ------------------------------------------------------------------

bsParser::For1Context::For1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::For1Context::FOR() {
  return getToken(bsParser::FOR, 0);
}

bsParser::StatementContext* bsParser::For1Context::statement() {
  return getRuleContext<bsParser::StatementContext>(0);
}

bsParser::Var_declContext* bsParser::For1Context::var_decl() {
  return getRuleContext<bsParser::Var_declContext>(0);
}

std::vector<bsParser::ExprContext *> bsParser::For1Context::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::For1Context::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}


size_t bsParser::For1Context::getRuleIndex() const {
  return bsParser::RuleFor1;
}

void bsParser::For1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor1(this);
}

void bsParser::For1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor1(this);
}


std::any bsParser::For1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitFor1(this);
  else
    return visitor->visitChildren(this);
}

bsParser::For1Context* bsParser::for1() {
  For1Context *_localctx = _tracker.createInstance<For1Context>(_ctx, getState());
  enterRule(_localctx, 36, bsParser::RuleFor1);
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
    setState(190);
    match(bsParser::FOR);
    setState(191);
    match(bsParser::T__2);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 41) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 41)) & 8388671) != 0)) {
      setState(192);
      var_decl();
    }
    setState(195);
    match(bsParser::T__0);
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4539628424389224184) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 23) != 0)) {
      setState(196);
      antlrcpp::downCast<For1Context *>(_localctx)->cond = expr(0);
    }
    setState(199);
    match(bsParser::T__0);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4539628424389224184) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 23) != 0)) {
      setState(200);
      antlrcpp::downCast<For1Context *>(_localctx)->end_oper = expr(0);
    }
    setState(203);
    match(bsParser::T__3);
    setState(204);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For2Context ------------------------------------------------------------------

bsParser::For2Context::For2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::For2Context::FOR() {
  return getToken(bsParser::FOR, 0);
}

tree::TerminalNode* bsParser::For2Context::ID() {
  return getToken(bsParser::ID, 0);
}

tree::TerminalNode* bsParser::For2Context::FROM() {
  return getToken(bsParser::FROM, 0);
}

tree::TerminalNode* bsParser::For2Context::TO() {
  return getToken(bsParser::TO, 0);
}

bsParser::StatementContext* bsParser::For2Context::statement() {
  return getRuleContext<bsParser::StatementContext>(0);
}

std::vector<bsParser::ExprContext *> bsParser::For2Context::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::For2Context::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}


size_t bsParser::For2Context::getRuleIndex() const {
  return bsParser::RuleFor2;
}

void bsParser::For2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor2(this);
}

void bsParser::For2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor2(this);
}


std::any bsParser::For2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitFor2(this);
  else
    return visitor->visitChildren(this);
}

bsParser::For2Context* bsParser::for2() {
  For2Context *_localctx = _tracker.createInstance<For2Context>(_ctx, getState());
  enterRule(_localctx, 38, bsParser::RuleFor2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(bsParser::FOR);
    setState(207);
    match(bsParser::T__2);
    setState(208);
    match(bsParser::ID);
    setState(209);
    match(bsParser::FROM);
    setState(210);
    antlrcpp::downCast<For2Context *>(_localctx)->start_val = expr(0);
    setState(211);
    match(bsParser::TO);
    setState(212);
    antlrcpp::downCast<For2Context *>(_localctx)->end_val = expr(0);
    setState(213);
    match(bsParser::T__3);
    setState(214);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoContext ------------------------------------------------------------------

bsParser::GotoContext::GotoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::GotoContext::GOTO() {
  return getToken(bsParser::GOTO, 0);
}

tree::TerminalNode* bsParser::GotoContext::ID() {
  return getToken(bsParser::ID, 0);
}


size_t bsParser::GotoContext::getRuleIndex() const {
  return bsParser::RuleGoto;
}

void bsParser::GotoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto(this);
}

void bsParser::GotoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto(this);
}


std::any bsParser::GotoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGoto(this);
  else
    return visitor->visitChildren(this);
}

bsParser::GotoContext* bsParser::goto_() {
  GotoContext *_localctx = _tracker.createInstance<GotoContext>(_ctx, getState());
  enterRule(_localctx, 40, bsParser::RuleGoto);

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
    match(bsParser::GOTO);
    setState(217);
    match(bsParser::ID);
    setState(218);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Goto_ifContext ------------------------------------------------------------------

bsParser::Goto_ifContext::Goto_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::Goto_ifContext::GOTO() {
  return getToken(bsParser::GOTO, 0);
}

tree::TerminalNode* bsParser::Goto_ifContext::ID() {
  return getToken(bsParser::ID, 0);
}

tree::TerminalNode* bsParser::Goto_ifContext::IF() {
  return getToken(bsParser::IF, 0);
}

bsParser::ExprContext* bsParser::Goto_ifContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}


size_t bsParser::Goto_ifContext::getRuleIndex() const {
  return bsParser::RuleGoto_if;
}

void bsParser::Goto_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto_if(this);
}

void bsParser::Goto_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto_if(this);
}


std::any bsParser::Goto_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGoto_if(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Goto_ifContext* bsParser::goto_if() {
  Goto_ifContext *_localctx = _tracker.createInstance<Goto_ifContext>(_ctx, getState());
  enterRule(_localctx, 42, bsParser::RuleGoto_if);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(bsParser::GOTO);
    setState(221);
    match(bsParser::ID);
    setState(222);
    match(bsParser::IF);
    setState(223);
    antlrcpp::downCast<Goto_ifContext *>(_localctx)->cond = expr(0);
    setState(224);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

bsParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::ReturnContext::RETURN() {
  return getToken(bsParser::RETURN, 0);
}

bsParser::ExprContext* bsParser::ReturnContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}


size_t bsParser::ReturnContext::getRuleIndex() const {
  return bsParser::RuleReturn;
}

void bsParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void bsParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any bsParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ReturnContext* bsParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 44, bsParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(bsParser::RETURN);
    setState(227);
    expr(0);
    setState(228);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakContext ------------------------------------------------------------------

bsParser::BreakContext::BreakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::BreakContext::BREAK() {
  return getToken(bsParser::BREAK, 0);
}


size_t bsParser::BreakContext::getRuleIndex() const {
  return bsParser::RuleBreak;
}

void bsParser::BreakContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreak(this);
}

void bsParser::BreakContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreak(this);
}


std::any bsParser::BreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBreak(this);
  else
    return visitor->visitChildren(this);
}

bsParser::BreakContext* bsParser::break_() {
  BreakContext *_localctx = _tracker.createInstance<BreakContext>(_ctx, getState());
  enterRule(_localctx, 46, bsParser::RuleBreak);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(bsParser::BREAK);
    setState(231);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueContext ------------------------------------------------------------------

bsParser::ContinueContext::ContinueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::ContinueContext::CONTINUE() {
  return getToken(bsParser::CONTINUE, 0);
}


size_t bsParser::ContinueContext::getRuleIndex() const {
  return bsParser::RuleContinue;
}

void bsParser::ContinueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinue(this);
}

void bsParser::ContinueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinue(this);
}


std::any bsParser::ContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitContinue(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ContinueContext* bsParser::continue_() {
  ContinueContext *_localctx = _tracker.createInstance<ContinueContext>(_ctx, getState());
  enterRule(_localctx, 48, bsParser::RuleContinue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(bsParser::CONTINUE);
    setState(234);
    match(bsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

bsParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bsParser::ExprContext::getRuleIndex() const {
  return bsParser::RuleExpr;
}

void bsParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isConst = ctx->isConst;
  this->eValue = ctx->eValue;
  this->isDc = ctx->isDc;
  this->isDead = ctx->isDead;
  this->eType = ctx->eType;
}

//----------------- PreIDContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::PreIDContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::PreIDContext::PreIDContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::PreIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreID(this);
}
void bsParser::PreIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreID(this);
}

std::any bsParser::PreIDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitPreID(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::MulDivContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::MulDivContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::MulDivContext::MulDivContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::MulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDiv(this);
}
void bsParser::MulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDiv(this);
}

std::any bsParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IAndXorOrCompAssignContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::IAndXorOrCompAssignContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::IAndXorOrCompAssignContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::AlignmentContext* bsParser::IAndXorOrCompAssignContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::IAndXorOrCompAssignContext::IAndXorOrCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::IAndXorOrCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIAndXorOrCompAssign(this);
}
void bsParser::IAndXorOrCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIAndXorOrCompAssign(this);
}

std::any bsParser::IAndXorOrCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIAndXorOrCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DSimpleAssignContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::DSimpleAssignContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::DSimpleAssignContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::DSimpleAssignContext::DSimpleAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DSimpleAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDSimpleAssign(this);
}
void bsParser::DSimpleAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDSimpleAssign(this);
}

std::any bsParser::DSimpleAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDSimpleAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DLSRSCompAssignContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::DLSRSCompAssignContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::DLSRSCompAssignContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::DLSRSCompAssignContext::DLSRSCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DLSRSCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDLSRSCompAssign(this);
}
void bsParser::DLSRSCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDLSRSCompAssign(this);
}

std::any bsParser::DLSRSCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDLSRSCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddressOfContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::AddressOfContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::AddressOfContext::AddressOfContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::AddressOfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddressOf(this);
}
void bsParser::AddressOfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddressOf(this);
}

std::any bsParser::AddressOfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitAddressOf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StaticCastContext ------------------------------------------------------------------

bsParser::Udef_typeContext* bsParser::StaticCastContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

bsParser::ExprContext* bsParser::StaticCastContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::StaticCastContext::StaticCastContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::StaticCastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticCast(this);
}
void bsParser::StaticCastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticCast(this);
}

std::any bsParser::StaticCastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitStaticCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::IDContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::IDContext::IDContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::IDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterID(this);
}
void bsParser::IDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitID(this);
}

std::any bsParser::IDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitID(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicAndContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::LogicAndContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::LogicAndContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::LogicAndContext::LogicAndContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::LogicAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAnd(this);
}
void bsParser::LogicAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAnd(this);
}

std::any bsParser::LogicAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitLogicAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DereferenceContext ------------------------------------------------------------------

bsParser::ExprContext* bsParser::DereferenceContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::AlignmentContext* bsParser::DereferenceContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::DereferenceContext::DereferenceContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DereferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDereference(this);
}
void bsParser::DereferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDereference(this);
}

std::any bsParser::DereferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDereference(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::IntegerLiteralContext::UNSIGNED_INT() {
  return getToken(bsParser::UNSIGNED_INT, 0);
}

bsParser::IntegerLiteralContext::IntegerLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}
void bsParser::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}

std::any bsParser::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::CallContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ArgsContext* bsParser::CallContext::args() {
  return getRuleContext<bsParser::ArgsContext>(0);
}

bsParser::CallContext::CallContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void bsParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

std::any bsParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicOrContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::LogicOrContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::LogicOrContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::LogicOrContext::LogicOrContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::LogicOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicOr(this);
}
void bsParser::LogicOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicOr(this);
}

std::any bsParser::LogicOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitLogicOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::ModContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::ModContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::ModContext::ModContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::ModContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMod(this);
}
void bsParser::ModContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMod(this);
}

std::any bsParser::ModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOrContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::BitOrContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::BitOrContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::BitOrContext::BitOrContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::BitOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOr(this);
}
void bsParser::BitOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOr(this);
}

std::any bsParser::BitOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBitOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::CharLiteralContext::CHAR() {
  return getToken(bsParser::CHAR, 0);
}

bsParser::CharLiteralContext::CharLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::CharLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharLiteral(this);
}
void bsParser::CharLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharLiteral(this);
}

std::any bsParser::CharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LShiftContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::LShiftContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::LShiftContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::LShiftContext::LShiftContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::LShiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLShift(this);
}
void bsParser::LShiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLShift(this);
}

std::any bsParser::LShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitLShift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::AddSubContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::AddSubContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

tree::TerminalNode* bsParser::AddSubContext::PLUS() {
  return getToken(bsParser::PLUS, 0);
}

tree::TerminalNode* bsParser::AddSubContext::MINUS() {
  return getToken(bsParser::MINUS, 0);
}

bsParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void bsParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}

std::any bsParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GLContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::GLContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::GLContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::GLContext::GLContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::GLContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGL(this);
}
void bsParser::GLContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGL(this);
}

std::any bsParser::GLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGL(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IMulDivModCompAssignContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::IMulDivModCompAssignContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::IMulDivModCompAssignContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::AlignmentContext* bsParser::IMulDivModCompAssignContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::IMulDivModCompAssignContext::IMulDivModCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::IMulDivModCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIMulDivModCompAssign(this);
}
void bsParser::IMulDivModCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIMulDivModCompAssign(this);
}

std::any bsParser::IMulDivModCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIMulDivModCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ISimpleAssignContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::ISimpleAssignContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::ISimpleAssignContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::AlignmentContext* bsParser::ISimpleAssignContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::ISimpleAssignContext::ISimpleAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::ISimpleAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterISimpleAssign(this);
}
void bsParser::ISimpleAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitISimpleAssign(this);
}

std::any bsParser::ISimpleAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitISimpleAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ILSRSCompAssignContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::ILSRSCompAssignContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::ILSRSCompAssignContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::AlignmentContext* bsParser::ILSRSCompAssignContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::ILSRSCompAssignContext::ILSRSCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::ILSRSCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterILSRSCompAssign(this);
}
void bsParser::ILSRSCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitILSRSCompAssign(this);
}

std::any bsParser::ILSRSCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitILSRSCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DMulDivModCompAssignContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::DMulDivModCompAssignContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::DMulDivModCompAssignContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::DMulDivModCompAssignContext::DMulDivModCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DMulDivModCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDMulDivModCompAssign(this);
}
void bsParser::DMulDivModCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDMulDivModCompAssign(this);
}

std::any bsParser::DMulDivModCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDMulDivModCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReinterpretCastContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::ReinterpretCastContext::REINTERPRET_CAST() {
  return getToken(bsParser::REINTERPRET_CAST, 0);
}

bsParser::Udef_typeContext* bsParser::ReinterpretCastContext::udef_type() {
  return getRuleContext<bsParser::Udef_typeContext>(0);
}

bsParser::ExprContext* bsParser::ReinterpretCastContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::ReinterpretCastContext::ReinterpretCastContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::ReinterpretCastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReinterpretCast(this);
}
void bsParser::ReinterpretCastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReinterpretCast(this);
}

std::any bsParser::ReinterpretCastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitReinterpretCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DAddSubCompAssignContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::DAddSubCompAssignContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::DAddSubCompAssignContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::DAddSubCompAssignContext::DAddSubCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DAddSubCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDAddSubCompAssign(this);
}
void bsParser::DAddSubCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDAddSubCompAssign(this);
}

std::any bsParser::DAddSubCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDAddSubCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqNeqContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::EqNeqContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::EqNeqContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::EqNeqContext::EqNeqContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::EqNeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqNeq(this);
}
void bsParser::EqNeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqNeq(this);
}

std::any bsParser::EqNeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitEqNeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BNeg_LNotContext ------------------------------------------------------------------

bsParser::ExprContext* bsParser::BNeg_LNotContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::BNeg_LNotContext::BNeg_LNotContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::BNeg_LNotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBNeg_LNot(this);
}
void bsParser::BNeg_LNotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBNeg_LNot(this);
}

std::any bsParser::BNeg_LNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBNeg_LNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitXorContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::BitXorContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::BitXorContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::BitXorContext::BitXorContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::BitXorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitXor(this);
}
void bsParser::BitXorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitXor(this);
}

std::any bsParser::BitXorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBitXor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::StringLiteralContext::STRING_LITERAL() {
  return getToken(bsParser::STRING_LITERAL, 0);
}

bsParser::StringLiteralContext::StringLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void bsParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}

std::any bsParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeLeContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::GeLeContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::GeLeContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::GeLeContext::GeLeContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::GeLeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeLe(this);
}
void bsParser::GeLeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeLe(this);
}

std::any bsParser::GeLeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitGeLe(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitAndContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::BitAndContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::BitAndContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::BitAndContext::BitAndContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::BitAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAnd(this);
}
void bsParser::BitAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAnd(this);
}

std::any bsParser::BitAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitBitAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IAddSubCompAssignContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::IAddSubCompAssignContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::IAddSubCompAssignContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::AlignmentContext* bsParser::IAddSubCompAssignContext::alignment() {
  return getRuleContext<bsParser::AlignmentContext>(0);
}

bsParser::IAddSubCompAssignContext::IAddSubCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::IAddSubCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIAddSubCompAssign(this);
}
void bsParser::IAddSubCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIAddSubCompAssign(this);
}

std::any bsParser::IAddSubCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitIAddSubCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParanContext ------------------------------------------------------------------

bsParser::ExprContext* bsParser::ParanContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::ParanContext::ParanContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::ParanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParan(this);
}
void bsParser::ParanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParan(this);
}

std::any bsParser::ParanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitParan(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DAndXorOrCompAssignContext ------------------------------------------------------------------

tree::TerminalNode* bsParser::DAndXorOrCompAssignContext::ID() {
  return getToken(bsParser::ID, 0);
}

bsParser::ExprContext* bsParser::DAndXorOrCompAssignContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

bsParser::DAndXorOrCompAssignContext::DAndXorOrCompAssignContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::DAndXorOrCompAssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDAndXorOrCompAssign(this);
}
void bsParser::DAndXorOrCompAssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDAndXorOrCompAssign(this);
}

std::any bsParser::DAndXorOrCompAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitDAndXorOrCompAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPNContext ------------------------------------------------------------------

bsParser::ExprContext* bsParser::UnaryPNContext::expr() {
  return getRuleContext<bsParser::ExprContext>(0);
}

tree::TerminalNode* bsParser::UnaryPNContext::PLUS() {
  return getToken(bsParser::PLUS, 0);
}

tree::TerminalNode* bsParser::UnaryPNContext::MINUS() {
  return getToken(bsParser::MINUS, 0);
}

bsParser::UnaryPNContext::UnaryPNContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::UnaryPNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPN(this);
}
void bsParser::UnaryPNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPN(this);
}

std::any bsParser::UnaryPNContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitUnaryPN(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RShiftContext ------------------------------------------------------------------

std::vector<bsParser::ExprContext *> bsParser::RShiftContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::RShiftContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}

bsParser::RShiftContext::RShiftContext(ExprContext *ctx) { copyFrom(ctx); }

void bsParser::RShiftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRShift(this);
}
void bsParser::RShiftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRShift(this);
}

std::any bsParser::RShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitRShift(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ExprContext* bsParser::expr() {
   return expr(0);
}

bsParser::ExprContext* bsParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  bsParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  bsParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, bsParser::RuleExpr, precedence);

    size_t _la = 0;

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
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(237);
      match(bsParser::T__2);
      setState(238);
      expr(0);
      setState(239);
      match(bsParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(241);
      match(bsParser::ID);
      setState(242);
      match(bsParser::T__2);
      setState(244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -4539628424389224184) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & 23) != 0)) {
        setState(243);
        args();
      }
      setState(246);
      match(bsParser::T__3);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PreIDContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(247);
      antlrcpp::downCast<PreIDContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__10

      || _la == bsParser::T__11)) {
        antlrcpp::downCast<PreIDContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(248);
      antlrcpp::downCast<PreIDContext *>(_localctx)->operand = match(bsParser::ID);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<UnaryPNContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(249);
      antlrcpp::downCast<UnaryPNContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::PLUS

      || _la == bsParser::MINUS)) {
        antlrcpp::downCast<UnaryPNContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(250);
      antlrcpp::downCast<UnaryPNContext *>(_localctx)->operand = expr(33);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<StaticCastContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(251);
      match(bsParser::T__2);
      setState(252);
      udef_type();
      setState(253);
      match(bsParser::T__3);
      setState(254);
      expr(32);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ReinterpretCastContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(256);
      match(bsParser::REINTERPRET_CAST);
      setState(257);
      match(bsParser::T__12);
      setState(258);
      udef_type();
      setState(259);
      match(bsParser::T__13);
      setState(260);
      match(bsParser::T__2);
      setState(261);
      expr(0);
      setState(262);
      match(bsParser::T__3);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DereferenceContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(264);
      match(bsParser::T__7);
      setState(265);
      expr(0);
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(266);
        match(bsParser::T__9);
        setState(267);
        alignment();
      }
      setState(270);
      match(bsParser::T__8);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<AddressOfContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(272);
      match(bsParser::T__14);
      setState(273);
      match(bsParser::ID);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BNeg_LNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(274);
      antlrcpp::downCast<BNeg_LNotContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__15

      || _la == bsParser::T__16)) {
        antlrcpp::downCast<BNeg_LNotContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(275);
      antlrcpp::downCast<BNeg_LNotContext *>(_localctx)->operand = expr(28);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<DSimpleAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(276);
      match(bsParser::ID);
      setState(277);
      match(bsParser::T__1);
      setState(278);
      expr(14);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<DAddSubCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(279);
      match(bsParser::ID);
      setState(280);
      antlrcpp::downCast<DAddSubCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__30

      || _la == bsParser::T__31)) {
        antlrcpp::downCast<DAddSubCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(281);
      expr(13);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<DMulDivModCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(282);
      match(bsParser::ID);
      setState(283);
      antlrcpp::downCast<DMulDivModCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 60129542144) != 0))) {
        antlrcpp::downCast<DMulDivModCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(284);
      expr(12);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<DLSRSCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(285);
      match(bsParser::ID);
      setState(286);
      antlrcpp::downCast<DLSRSCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__35

      || _la == bsParser::T__36)) {
        antlrcpp::downCast<DLSRSCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(287);
      expr(11);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<DAndXorOrCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(288);
      match(bsParser::ID);
      setState(289);
      antlrcpp::downCast<DAndXorOrCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1924145348608) != 0))) {
        antlrcpp::downCast<DAndXorOrCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(290);
      expr(10);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<ISimpleAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(291);
      match(bsParser::T__7);
      setState(292);
      antlrcpp::downCast<ISimpleAssignContext *>(_localctx)->deref = expr(0);
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(293);
        match(bsParser::T__9);
        setState(294);
        alignment();
      }
      setState(297);
      match(bsParser::T__8);
      setState(298);
      match(bsParser::T__1);
      setState(299);
      antlrcpp::downCast<ISimpleAssignContext *>(_localctx)->e = expr(9);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<IAddSubCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(301);
      match(bsParser::T__7);
      setState(302);
      antlrcpp::downCast<IAddSubCompAssignContext *>(_localctx)->deref = expr(0);
      setState(305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(303);
        match(bsParser::T__9);
        setState(304);
        alignment();
      }
      setState(307);
      match(bsParser::T__8);
      setState(308);
      antlrcpp::downCast<IAddSubCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__30

      || _la == bsParser::T__31)) {
        antlrcpp::downCast<IAddSubCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(309);
      antlrcpp::downCast<IAddSubCompAssignContext *>(_localctx)->e = expr(8);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<IMulDivModCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(311);
      match(bsParser::T__7);
      setState(312);
      antlrcpp::downCast<IMulDivModCompAssignContext *>(_localctx)->deref = expr(0);
      setState(315);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(313);
        match(bsParser::T__9);
        setState(314);
        alignment();
      }
      setState(317);
      match(bsParser::T__8);
      setState(318);
      antlrcpp::downCast<IMulDivModCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 60129542144) != 0))) {
        antlrcpp::downCast<IMulDivModCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(319);
      antlrcpp::downCast<IMulDivModCompAssignContext *>(_localctx)->e = expr(7);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<ILSRSCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(321);
      match(bsParser::T__7);
      setState(322);
      antlrcpp::downCast<ILSRSCompAssignContext *>(_localctx)->deref = expr(0);
      setState(325);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(323);
        match(bsParser::T__9);
        setState(324);
        alignment();
      }
      setState(327);
      match(bsParser::T__8);
      setState(328);
      antlrcpp::downCast<ILSRSCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == bsParser::T__35

      || _la == bsParser::T__36)) {
        antlrcpp::downCast<ILSRSCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(329);
      antlrcpp::downCast<ILSRSCompAssignContext *>(_localctx)->e = expr(6);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<IAndXorOrCompAssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(331);
      match(bsParser::T__7);
      setState(332);
      antlrcpp::downCast<IAndXorOrCompAssignContext *>(_localctx)->deref = expr(0);
      setState(335);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bsParser::T__9) {
        setState(333);
        match(bsParser::T__9);
        setState(334);
        alignment();
      }
      setState(337);
      match(bsParser::T__8);
      setState(338);
      antlrcpp::downCast<IAndXorOrCompAssignContext *>(_localctx)->cop = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1924145348608) != 0))) {
        antlrcpp::downCast<IAndXorOrCompAssignContext *>(_localctx)->cop = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(339);
      antlrcpp::downCast<IAndXorOrCompAssignContext *>(_localctx)->e = expr(5);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<IDContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(341);
      antlrcpp::downCast<IDContext *>(_localctx)->atom = match(bsParser::ID);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<IntegerLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(342);
      antlrcpp::downCast<IntegerLiteralContext *>(_localctx)->atom = match(bsParser::UNSIGNED_INT);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<StringLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(343);
      antlrcpp::downCast<StringLiteralContext *>(_localctx)->atom = match(bsParser::STRING_LITERAL);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<CharLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(344);
      antlrcpp::downCast<CharLiteralContext *>(_localctx)->atom = match(bsParser::CHAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(386);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(347);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(348);
          antlrcpp::downCast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bsParser::T__17

          || _la == bsParser::T__18)) {
            antlrcpp::downCast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(349);
          antlrcpp::downCast<MulDivContext *>(_localctx)->right = expr(28);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(350);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(351);
          match(bsParser::T__19);
          setState(352);
          antlrcpp::downCast<ModContext *>(_localctx)->right = expr(27);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(353);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(354);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bsParser::PLUS

          || _la == bsParser::MINUS)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(355);
          antlrcpp::downCast<AddSubContext *>(_localctx)->right = expr(26);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(356);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(357);
          match(bsParser::T__20);
          setState(358);
          antlrcpp::downCast<RShiftContext *>(_localctx)->right = expr(25);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(359);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(360);
          match(bsParser::T__21);
          setState(361);
          antlrcpp::downCast<LShiftContext *>(_localctx)->right = expr(24);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<GLContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(362);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(363);
          antlrcpp::downCast<GLContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bsParser::T__12

          || _la == bsParser::T__13)) {
            antlrcpp::downCast<GLContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(364);
          antlrcpp::downCast<GLContext *>(_localctx)->right = expr(23);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<GeLeContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(365);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(366);
          antlrcpp::downCast<GeLeContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bsParser::T__22

          || _la == bsParser::T__23)) {
            antlrcpp::downCast<GeLeContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(367);
          antlrcpp::downCast<GeLeContext *>(_localctx)->right = expr(22);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<EqNeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(368);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(369);
          antlrcpp::downCast<EqNeqContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == bsParser::T__24

          || _la == bsParser::T__25)) {
            antlrcpp::downCast<EqNeqContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(370);
          antlrcpp::downCast<EqNeqContext *>(_localctx)->right = expr(21);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BitAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(371);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(372);
          match(bsParser::T__14);
          setState(373);
          antlrcpp::downCast<BitAndContext *>(_localctx)->right = expr(20);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BitXorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(374);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(375);
          match(bsParser::T__26);
          setState(376);
          antlrcpp::downCast<BitXorContext *>(_localctx)->right = expr(19);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<BitOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(377);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(378);
          match(bsParser::T__27);
          setState(379);
          antlrcpp::downCast<BitOrContext *>(_localctx)->right = expr(18);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LogicAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(380);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(381);
          match(bsParser::T__28);
          setState(382);
          antlrcpp::downCast<LogicAndContext *>(_localctx)->right = expr(17);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<LogicOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(383);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(384);
          match(bsParser::T__29);
          setState(385);
          antlrcpp::downCast<LogicOrContext *>(_localctx)->right = expr(16);
          break;
        }

        default:
          break;
        } 
      }
      setState(390);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

bsParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bsParser::ExprContext *> bsParser::ArgsContext::expr() {
  return getRuleContexts<bsParser::ExprContext>();
}

bsParser::ExprContext* bsParser::ArgsContext::expr(size_t i) {
  return getRuleContext<bsParser::ExprContext>(i);
}


size_t bsParser::ArgsContext::getRuleIndex() const {
  return bsParser::RuleArgs;
}

void bsParser::ArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs(this);
}

void bsParser::ArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs(this);
}


std::any bsParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

bsParser::ArgsContext* bsParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 52, bsParser::RuleArgs);
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
    setState(391);
    expr(0);
    setState(396);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bsParser::T__4) {
      setState(392);
      match(bsParser::T__4);
      setState(393);
      expr(0);
      setState(398);
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

//----------------- TypeContext ------------------------------------------------------------------

bsParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::TypeContext::BYTE_t() {
  return getToken(bsParser::BYTE_t, 0);
}

tree::TerminalNode* bsParser::TypeContext::CHAR_t() {
  return getToken(bsParser::CHAR_t, 0);
}

tree::TerminalNode* bsParser::TypeContext::UBYTE_t() {
  return getToken(bsParser::UBYTE_t, 0);
}

tree::TerminalNode* bsParser::TypeContext::UCHAR_t() {
  return getToken(bsParser::UCHAR_t, 0);
}

tree::TerminalNode* bsParser::TypeContext::INT_t() {
  return getToken(bsParser::INT_t, 0);
}

tree::TerminalNode* bsParser::TypeContext::UINT_t() {
  return getToken(bsParser::UINT_t, 0);
}


size_t bsParser::TypeContext::getRuleIndex() const {
  return bsParser::RuleType;
}

void bsParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void bsParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any bsParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

bsParser::TypeContext* bsParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 54, bsParser::RuleType);
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
    setState(399);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 138538465099776) != 0))) {
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

//----------------- Udef_typeContext ------------------------------------------------------------------

bsParser::Udef_typeContext::Udef_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bsParser::TypeContext* bsParser::Udef_typeContext::type() {
  return getRuleContext<bsParser::TypeContext>(0);
}

tree::TerminalNode* bsParser::Udef_typeContext::ID() {
  return getToken(bsParser::ID, 0);
}


size_t bsParser::Udef_typeContext::getRuleIndex() const {
  return bsParser::RuleUdef_type;
}

void bsParser::Udef_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUdef_type(this);
}

void bsParser::Udef_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUdef_type(this);
}


std::any bsParser::Udef_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitUdef_type(this);
  else
    return visitor->visitChildren(this);
}

bsParser::Udef_typeContext* bsParser::udef_type() {
  Udef_typeContext *_localctx = _tracker.createInstance<Udef_typeContext>(_ctx, getState());
  enterRule(_localctx, 56, bsParser::RuleUdef_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bsParser::BYTE_t:
      case bsParser::CHAR_t:
      case bsParser::INT_t:
      case bsParser::UBYTE_t:
      case bsParser::UCHAR_t:
      case bsParser::UINT_t: {
        enterOuterAlt(_localctx, 1);
        setState(401);
        type();
        break;
      }

      case bsParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(402);
        match(bsParser::ID);
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

//----------------- AlignmentContext ------------------------------------------------------------------

bsParser::AlignmentContext::AlignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bsParser::AlignmentContext::ALIGN() {
  return getToken(bsParser::ALIGN, 0);
}


size_t bsParser::AlignmentContext::getRuleIndex() const {
  return bsParser::RuleAlignment;
}

void bsParser::AlignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlignment(this);
}

void bsParser::AlignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlignment(this);
}


std::any bsParser::AlignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bsVisitor*>(visitor))
    return parserVisitor->visitAlignment(this);
  else
    return visitor->visitChildren(this);
}

bsParser::AlignmentContext* bsParser::alignment() {
  AlignmentContext *_localctx = _tracker.createInstance<AlignmentContext>(_ctx, getState());
  enterRule(_localctx, 58, bsParser::RuleAlignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(bsParser::ALIGN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool bsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 25: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool bsParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 27);
    case 1: return precpred(_ctx, 26);
    case 2: return precpred(_ctx, 25);
    case 3: return precpred(_ctx, 24);
    case 4: return precpred(_ctx, 23);
    case 5: return precpred(_ctx, 22);
    case 6: return precpred(_ctx, 21);
    case 7: return precpred(_ctx, 20);
    case 8: return precpred(_ctx, 19);
    case 9: return precpred(_ctx, 18);
    case 10: return precpred(_ctx, 17);
    case 11: return precpred(_ctx, 16);
    case 12: return precpred(_ctx, 15);

  default:
    break;
  }
  return true;
}

void bsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  bsParserInitialize();
#else
  ::antlr4::internal::call_once(bsParserOnceFlag, bsParserInitialize);
#endif
}
