
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  bsParser : public antlr4::Parser {
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

  enum {
    RuleProgram = 0, RuleDeclaration = 1, RuleTypedef = 2, RuleGlobal = 3, 
    RuleFunction = 4, RuleParams = 5, RuleParam_decl = 6, RuleBlock = 7, 
    RuleStatement = 8, RuleVar_decl = 9, RuleArray_decl = 10, RuleArray_initializer = 11, 
    RuleInit_element = 12, RuleGoto_label = 13, RuleCompound = 14, RuleIf = 15, 
    RuleIfelse = 16, RuleWhile = 17, RuleFor1 = 18, RuleFor2 = 19, RuleGoto = 20, 
    RuleGoto_if = 21, RuleReturn = 22, RuleBreak = 23, RuleContinue = 24, 
    RuleExpr = 25, RuleArgs = 26, RuleType = 27, RuleUdef_type = 28, RuleAlignment = 29
  };

  explicit bsParser(antlr4::TokenStream *input);

  bsParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~bsParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class DeclarationContext;
  class TypedefContext;
  class GlobalContext;
  class FunctionContext;
  class ParamsContext;
  class Param_declContext;
  class BlockContext;
  class StatementContext;
  class Var_declContext;
  class Array_declContext;
  class Array_initializerContext;
  class Init_elementContext;
  class Goto_labelContext;
  class CompoundContext;
  class IfContext;
  class IfelseContext;
  class WhileContext;
  class For1Context;
  class For2Context;
  class GotoContext;
  class Goto_ifContext;
  class ReturnContext;
  class BreakContext;
  class ContinueContext;
  class ExprContext;
  class ArgsContext;
  class TypeContext;
  class Udef_typeContext;
  class AlignmentContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GlobalContext *global();
    FunctionContext *function();
    TypedefContext *typedef_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  TypedefContext : public antlr4::ParserRuleContext {
  public:
    TypedefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPEDEF();
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedefContext* typedef_();

  class  GlobalContext : public antlr4::ParserRuleContext {
  public:
    GlobalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udef_typeContext *udef_type();
    antlr4::tree::TerminalNode *ID();
    Init_elementContext *init_element();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalContext* global();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udef_typeContext *udef_type();
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    ParamsContext *params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Param_declContext *> param_decl();
    Param_declContext* param_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  Param_declContext : public antlr4::ParserRuleContext {
  public:
    Param_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udef_typeContext *udef_type();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_declContext* param_decl();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    bool isDead = false;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declContext *var_decl();
    Array_declContext *array_decl();
    ExprContext *expr();
    Goto_labelContext *goto_label();
    CompoundContext *compound();
    IfContext *if_();
    IfelseContext *ifelse();
    WhileContext *while_();
    For1Context *for1();
    For2Context *for2();
    GotoContext *goto_();
    Goto_ifContext *goto_if();
    ReturnContext *return_();
    BreakContext *break_();
    ContinueContext *continue_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    bool isDead = false;
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udef_typeContext *udef_type();
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Array_declContext : public antlr4::ParserRuleContext {
  public:
    Array_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udef_typeContext *udef_type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SIGNED_INT();
    Array_initializerContext *array_initializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_declContext* array_decl();

  class  Array_initializerContext : public antlr4::ParserRuleContext {
  public:
    Array_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Init_elementContext *> init_element();
    Init_elementContext* init_element(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_initializerContext* array_initializer();

  class  Init_elementContext : public antlr4::ParserRuleContext {
  public:
    Init_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Init_elementContext() = default;
    void copyFrom(Init_elementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  InitCharLiteralContext : public Init_elementContext {
  public:
    InitCharLiteralContext(Init_elementContext *ctx);

    antlr4::tree::TerminalNode *CHAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InitIntLiteralContext : public Init_elementContext {
  public:
    InitIntLiteralContext(Init_elementContext *ctx);

    antlr4::Token *atom = nullptr;
    antlr4::tree::TerminalNode *SIGNED_INT();
    antlr4::tree::TerminalNode *UNSIGNED_INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InitStringLiteralContext : public Init_elementContext {
  public:
    InitStringLiteralContext(Init_elementContext *ctx);

    antlr4::tree::TerminalNode *STRING_LITERAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Init_elementContext* init_element();

  class  Goto_labelContext : public antlr4::ParserRuleContext {
  public:
    Goto_labelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Goto_labelContext* goto_label();

  class  CompoundContext : public antlr4::ParserRuleContext {
  public:
    CompoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundContext* compound();

  class  IfContext : public antlr4::ParserRuleContext {
  public:
    IfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfContext* if_();

  class  IfelseContext : public antlr4::ParserRuleContext {
  public:
    bsParser::StatementContext *pos = nullptr;
    bsParser::StatementContext *neg = nullptr;
    IfelseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    antlr4::tree::TerminalNode *ELSE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfelseContext* ifelse();

  class  WhileContext : public antlr4::ParserRuleContext {
  public:
    bool noCond = false;
    WhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExprContext *expr();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileContext* while_();

  class  For1Context : public antlr4::ParserRuleContext {
  public:
    bsParser::ExprContext *cond = nullptr;
    bsParser::ExprContext *end_oper = nullptr;
    For1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    StatementContext *statement();
    Var_declContext *var_decl();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For1Context* for1();

  class  For2Context : public antlr4::ParserRuleContext {
  public:
    bsParser::ExprContext *start_val = nullptr;
    bsParser::ExprContext *end_val = nullptr;
    For2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *TO();
    StatementContext *statement();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For2Context* for2();

  class  GotoContext : public antlr4::ParserRuleContext {
  public:
    GotoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GotoContext* goto_();

  class  Goto_ifContext : public antlr4::ParserRuleContext {
  public:
    int state = 0;
    bsParser::ExprContext *cond = nullptr;
    Goto_ifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Goto_ifContext* goto_if();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  BreakContext : public antlr4::ParserRuleContext {
  public:
    BreakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreakContext* break_();

  class  ContinueContext : public antlr4::ParserRuleContext {
  public:
    ContinueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContinueContext* continue_();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    bool isConst = false;
    long long eValue = 0;
    bool isDc = false;
    bool isDead = false;
    int eType = 0;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PreIDContext : public ExprContext {
  public:
    PreIDContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::Token *operand = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivContext : public ExprContext {
  public:
    MulDivContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IAndXorOrCompAssignContext : public ExprContext {
  public:
    IAndXorOrCompAssignContext(ExprContext *ctx);

    bsParser::ExprContext *deref = nullptr;
    antlr4::Token *cop = nullptr;
    bsParser::ExprContext *e = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DSimpleAssignContext : public ExprContext {
  public:
    DSimpleAssignContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DLSRSCompAssignContext : public ExprContext {
  public:
    DLSRSCompAssignContext(ExprContext *ctx);

    antlr4::Token *cop = nullptr;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddressOfContext : public ExprContext {
  public:
    AddressOfContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StaticCastContext : public ExprContext {
  public:
    StaticCastContext(ExprContext *ctx);

    Udef_typeContext *udef_type();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IDContext : public ExprContext {
  public:
    IDContext(ExprContext *ctx);

    antlr4::Token *atom = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicAndContext : public ExprContext {
  public:
    LogicAndContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DereferenceContext : public ExprContext {
  public:
    DereferenceContext(ExprContext *ctx);

    ExprContext *expr();
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerLiteralContext : public ExprContext {
  public:
    IntegerLiteralContext(ExprContext *ctx);

    antlr4::Token *atom = nullptr;
    antlr4::tree::TerminalNode *UNSIGNED_INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallContext : public ExprContext {
  public:
    CallContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ArgsContext *args();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicOrContext : public ExprContext {
  public:
    LogicOrContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModContext : public ExprContext {
  public:
    ModContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitOrContext : public ExprContext {
  public:
    BitOrContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharLiteralContext : public ExprContext {
  public:
    CharLiteralContext(ExprContext *ctx);

    antlr4::Token *atom = nullptr;
    antlr4::tree::TerminalNode *CHAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LShiftContext : public ExprContext {
  public:
    LShiftContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubContext : public ExprContext {
  public:
    AddSubContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GLContext : public ExprContext {
  public:
    GLContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IMulDivModCompAssignContext : public ExprContext {
  public:
    IMulDivModCompAssignContext(ExprContext *ctx);

    bsParser::ExprContext *deref = nullptr;
    antlr4::Token *cop = nullptr;
    bsParser::ExprContext *e = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ISimpleAssignContext : public ExprContext {
  public:
    ISimpleAssignContext(ExprContext *ctx);

    bsParser::ExprContext *deref = nullptr;
    bsParser::ExprContext *e = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ILSRSCompAssignContext : public ExprContext {
  public:
    ILSRSCompAssignContext(ExprContext *ctx);

    bsParser::ExprContext *deref = nullptr;
    antlr4::Token *cop = nullptr;
    bsParser::ExprContext *e = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DMulDivModCompAssignContext : public ExprContext {
  public:
    DMulDivModCompAssignContext(ExprContext *ctx);

    antlr4::Token *cop = nullptr;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReinterpretCastContext : public ExprContext {
  public:
    ReinterpretCastContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *REINTERPRET_CAST();
    Udef_typeContext *udef_type();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DAddSubCompAssignContext : public ExprContext {
  public:
    DAddSubCompAssignContext(ExprContext *ctx);

    antlr4::Token *cop = nullptr;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqNeqContext : public ExprContext {
  public:
    EqNeqContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BNeg_LNotContext : public ExprContext {
  public:
    BNeg_LNotContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    bsParser::ExprContext *operand = nullptr;
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitXorContext : public ExprContext {
  public:
    BitXorContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLiteralContext : public ExprContext {
  public:
    StringLiteralContext(ExprContext *ctx);

    antlr4::Token *atom = nullptr;
    antlr4::tree::TerminalNode *STRING_LITERAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GeLeContext : public ExprContext {
  public:
    GeLeContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    antlr4::Token *op = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitAndContext : public ExprContext {
  public:
    BitAndContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IAddSubCompAssignContext : public ExprContext {
  public:
    IAddSubCompAssignContext(ExprContext *ctx);

    bsParser::ExprContext *deref = nullptr;
    antlr4::Token *cop = nullptr;
    bsParser::ExprContext *e = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    AlignmentContext *alignment();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParanContext : public ExprContext {
  public:
    ParanContext(ExprContext *ctx);

    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DAndXorOrCompAssignContext : public ExprContext {
  public:
    DAndXorOrCompAssignContext(ExprContext *ctx);

    antlr4::Token *cop = nullptr;
    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryPNContext : public ExprContext {
  public:
    UnaryPNContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    bsParser::ExprContext *operand = nullptr;
    ExprContext *expr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RShiftContext : public ExprContext {
  public:
    RShiftContext(ExprContext *ctx);

    bsParser::ExprContext *left = nullptr;
    bsParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ArgsContext : public antlr4::ParserRuleContext {
  public:
    ArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsContext* args();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BYTE_t();
    antlr4::tree::TerminalNode *CHAR_t();
    antlr4::tree::TerminalNode *UBYTE_t();
    antlr4::tree::TerminalNode *UCHAR_t();
    antlr4::tree::TerminalNode *INT_t();
    antlr4::tree::TerminalNode *UINT_t();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  Udef_typeContext : public antlr4::ParserRuleContext {
  public:
    Udef_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udef_typeContext* udef_type();

  class  AlignmentContext : public antlr4::ParserRuleContext {
  public:
    AlignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AlignmentContext* alignment();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

