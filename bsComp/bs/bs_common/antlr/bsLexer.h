
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  bsLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, BYTE_t = 41, CHAR_t = 42, INT_t = 43, UBYTE_t = 44, 
    UCHAR_t = 45, UINT_t = 46, GOTO = 47, IF = 48, ELSE = 49, WHILE = 50, 
    FOR = 51, RETURN = 52, BREAK = 53, CONTINUE = 54, STATIC = 55, REINTERPRET_CAST = 56, 
    FROM = 57, TO = 58, TYPEDEF = 59, FN = 60, ALIGN = 61, PLUS = 62, MINUS = 63, 
    ID = 64, CHAR = 65, STRING_LITERAL = 66, UNTERMINATED_STRING_LITERAL = 67, 
    UNSIGNED_INT = 68, SIGNED_INT = 69, Newline = 70, Whitespace = 71, BlockComment = 72, 
    LineComment = 73
  };

  explicit bsLexer(antlr4::CharStream *input);

  ~bsLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

