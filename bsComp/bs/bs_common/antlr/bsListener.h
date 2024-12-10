
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by bsParser.
 */
class  bsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(bsParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(bsParser::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(bsParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(bsParser::DeclarationContext *ctx) = 0;

  virtual void enterTypedef(bsParser::TypedefContext *ctx) = 0;
  virtual void exitTypedef(bsParser::TypedefContext *ctx) = 0;

  virtual void enterGlobal(bsParser::GlobalContext *ctx) = 0;
  virtual void exitGlobal(bsParser::GlobalContext *ctx) = 0;

  virtual void enterFunction(bsParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(bsParser::FunctionContext *ctx) = 0;

  virtual void enterParams(bsParser::ParamsContext *ctx) = 0;
  virtual void exitParams(bsParser::ParamsContext *ctx) = 0;

  virtual void enterParam_decl(bsParser::Param_declContext *ctx) = 0;
  virtual void exitParam_decl(bsParser::Param_declContext *ctx) = 0;

  virtual void enterBlock(bsParser::BlockContext *ctx) = 0;
  virtual void exitBlock(bsParser::BlockContext *ctx) = 0;

  virtual void enterStatement(bsParser::StatementContext *ctx) = 0;
  virtual void exitStatement(bsParser::StatementContext *ctx) = 0;

  virtual void enterVar_decl(bsParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(bsParser::Var_declContext *ctx) = 0;

  virtual void enterArray_decl(bsParser::Array_declContext *ctx) = 0;
  virtual void exitArray_decl(bsParser::Array_declContext *ctx) = 0;

  virtual void enterArray_initializer(bsParser::Array_initializerContext *ctx) = 0;
  virtual void exitArray_initializer(bsParser::Array_initializerContext *ctx) = 0;

  virtual void enterInitIntLiteral(bsParser::InitIntLiteralContext *ctx) = 0;
  virtual void exitInitIntLiteral(bsParser::InitIntLiteralContext *ctx) = 0;

  virtual void enterInitCharLiteral(bsParser::InitCharLiteralContext *ctx) = 0;
  virtual void exitInitCharLiteral(bsParser::InitCharLiteralContext *ctx) = 0;

  virtual void enterInitStringLiteral(bsParser::InitStringLiteralContext *ctx) = 0;
  virtual void exitInitStringLiteral(bsParser::InitStringLiteralContext *ctx) = 0;

  virtual void enterGoto_label(bsParser::Goto_labelContext *ctx) = 0;
  virtual void exitGoto_label(bsParser::Goto_labelContext *ctx) = 0;

  virtual void enterCompound(bsParser::CompoundContext *ctx) = 0;
  virtual void exitCompound(bsParser::CompoundContext *ctx) = 0;

  virtual void enterIf(bsParser::IfContext *ctx) = 0;
  virtual void exitIf(bsParser::IfContext *ctx) = 0;

  virtual void enterIfelse(bsParser::IfelseContext *ctx) = 0;
  virtual void exitIfelse(bsParser::IfelseContext *ctx) = 0;

  virtual void enterWhile(bsParser::WhileContext *ctx) = 0;
  virtual void exitWhile(bsParser::WhileContext *ctx) = 0;

  virtual void enterFor1(bsParser::For1Context *ctx) = 0;
  virtual void exitFor1(bsParser::For1Context *ctx) = 0;

  virtual void enterFor2(bsParser::For2Context *ctx) = 0;
  virtual void exitFor2(bsParser::For2Context *ctx) = 0;

  virtual void enterGoto(bsParser::GotoContext *ctx) = 0;
  virtual void exitGoto(bsParser::GotoContext *ctx) = 0;

  virtual void enterGoto_if(bsParser::Goto_ifContext *ctx) = 0;
  virtual void exitGoto_if(bsParser::Goto_ifContext *ctx) = 0;

  virtual void enterReturn(bsParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(bsParser::ReturnContext *ctx) = 0;

  virtual void enterBreak(bsParser::BreakContext *ctx) = 0;
  virtual void exitBreak(bsParser::BreakContext *ctx) = 0;

  virtual void enterContinue(bsParser::ContinueContext *ctx) = 0;
  virtual void exitContinue(bsParser::ContinueContext *ctx) = 0;

  virtual void enterPreID(bsParser::PreIDContext *ctx) = 0;
  virtual void exitPreID(bsParser::PreIDContext *ctx) = 0;

  virtual void enterMulDiv(bsParser::MulDivContext *ctx) = 0;
  virtual void exitMulDiv(bsParser::MulDivContext *ctx) = 0;

  virtual void enterIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext *ctx) = 0;
  virtual void exitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext *ctx) = 0;

  virtual void enterDSimpleAssign(bsParser::DSimpleAssignContext *ctx) = 0;
  virtual void exitDSimpleAssign(bsParser::DSimpleAssignContext *ctx) = 0;

  virtual void enterDLSRSCompAssign(bsParser::DLSRSCompAssignContext *ctx) = 0;
  virtual void exitDLSRSCompAssign(bsParser::DLSRSCompAssignContext *ctx) = 0;

  virtual void enterAddressOf(bsParser::AddressOfContext *ctx) = 0;
  virtual void exitAddressOf(bsParser::AddressOfContext *ctx) = 0;

  virtual void enterStaticCast(bsParser::StaticCastContext *ctx) = 0;
  virtual void exitStaticCast(bsParser::StaticCastContext *ctx) = 0;

  virtual void enterID(bsParser::IDContext *ctx) = 0;
  virtual void exitID(bsParser::IDContext *ctx) = 0;

  virtual void enterLogicAnd(bsParser::LogicAndContext *ctx) = 0;
  virtual void exitLogicAnd(bsParser::LogicAndContext *ctx) = 0;

  virtual void enterDereference(bsParser::DereferenceContext *ctx) = 0;
  virtual void exitDereference(bsParser::DereferenceContext *ctx) = 0;

  virtual void enterIntegerLiteral(bsParser::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(bsParser::IntegerLiteralContext *ctx) = 0;

  virtual void enterCall(bsParser::CallContext *ctx) = 0;
  virtual void exitCall(bsParser::CallContext *ctx) = 0;

  virtual void enterLogicOr(bsParser::LogicOrContext *ctx) = 0;
  virtual void exitLogicOr(bsParser::LogicOrContext *ctx) = 0;

  virtual void enterMod(bsParser::ModContext *ctx) = 0;
  virtual void exitMod(bsParser::ModContext *ctx) = 0;

  virtual void enterBitOr(bsParser::BitOrContext *ctx) = 0;
  virtual void exitBitOr(bsParser::BitOrContext *ctx) = 0;

  virtual void enterCharLiteral(bsParser::CharLiteralContext *ctx) = 0;
  virtual void exitCharLiteral(bsParser::CharLiteralContext *ctx) = 0;

  virtual void enterLShift(bsParser::LShiftContext *ctx) = 0;
  virtual void exitLShift(bsParser::LShiftContext *ctx) = 0;

  virtual void enterAddSub(bsParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(bsParser::AddSubContext *ctx) = 0;

  virtual void enterGL(bsParser::GLContext *ctx) = 0;
  virtual void exitGL(bsParser::GLContext *ctx) = 0;

  virtual void enterIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext *ctx) = 0;
  virtual void exitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext *ctx) = 0;

  virtual void enterISimpleAssign(bsParser::ISimpleAssignContext *ctx) = 0;
  virtual void exitISimpleAssign(bsParser::ISimpleAssignContext *ctx) = 0;

  virtual void enterILSRSCompAssign(bsParser::ILSRSCompAssignContext *ctx) = 0;
  virtual void exitILSRSCompAssign(bsParser::ILSRSCompAssignContext *ctx) = 0;

  virtual void enterDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext *ctx) = 0;
  virtual void exitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext *ctx) = 0;

  virtual void enterReinterpretCast(bsParser::ReinterpretCastContext *ctx) = 0;
  virtual void exitReinterpretCast(bsParser::ReinterpretCastContext *ctx) = 0;

  virtual void enterDAddSubCompAssign(bsParser::DAddSubCompAssignContext *ctx) = 0;
  virtual void exitDAddSubCompAssign(bsParser::DAddSubCompAssignContext *ctx) = 0;

  virtual void enterEqNeq(bsParser::EqNeqContext *ctx) = 0;
  virtual void exitEqNeq(bsParser::EqNeqContext *ctx) = 0;

  virtual void enterBNeg_LNot(bsParser::BNeg_LNotContext *ctx) = 0;
  virtual void exitBNeg_LNot(bsParser::BNeg_LNotContext *ctx) = 0;

  virtual void enterBitXor(bsParser::BitXorContext *ctx) = 0;
  virtual void exitBitXor(bsParser::BitXorContext *ctx) = 0;

  virtual void enterStringLiteral(bsParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(bsParser::StringLiteralContext *ctx) = 0;

  virtual void enterGeLe(bsParser::GeLeContext *ctx) = 0;
  virtual void exitGeLe(bsParser::GeLeContext *ctx) = 0;

  virtual void enterBitAnd(bsParser::BitAndContext *ctx) = 0;
  virtual void exitBitAnd(bsParser::BitAndContext *ctx) = 0;

  virtual void enterIAddSubCompAssign(bsParser::IAddSubCompAssignContext *ctx) = 0;
  virtual void exitIAddSubCompAssign(bsParser::IAddSubCompAssignContext *ctx) = 0;

  virtual void enterParan(bsParser::ParanContext *ctx) = 0;
  virtual void exitParan(bsParser::ParanContext *ctx) = 0;

  virtual void enterDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext *ctx) = 0;
  virtual void exitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext *ctx) = 0;

  virtual void enterUnaryPN(bsParser::UnaryPNContext *ctx) = 0;
  virtual void exitUnaryPN(bsParser::UnaryPNContext *ctx) = 0;

  virtual void enterRShift(bsParser::RShiftContext *ctx) = 0;
  virtual void exitRShift(bsParser::RShiftContext *ctx) = 0;

  virtual void enterArgs(bsParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(bsParser::ArgsContext *ctx) = 0;

  virtual void enterType(bsParser::TypeContext *ctx) = 0;
  virtual void exitType(bsParser::TypeContext *ctx) = 0;

  virtual void enterUdef_type(bsParser::Udef_typeContext *ctx) = 0;
  virtual void exitUdef_type(bsParser::Udef_typeContext *ctx) = 0;

  virtual void enterAlignment(bsParser::AlignmentContext *ctx) = 0;
  virtual void exitAlignment(bsParser::AlignmentContext *ctx) = 0;


};

