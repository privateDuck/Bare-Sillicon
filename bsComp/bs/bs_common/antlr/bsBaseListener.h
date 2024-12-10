
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bsListener.h"


/**
 * This class provides an empty implementation of bsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  bsBaseListener : public bsListener {
public:

  virtual void enterProgram(bsParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(bsParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDeclaration(bsParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(bsParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterTypedef(bsParser::TypedefContext * /*ctx*/) override { }
  virtual void exitTypedef(bsParser::TypedefContext * /*ctx*/) override { }

  virtual void enterGlobal(bsParser::GlobalContext * /*ctx*/) override { }
  virtual void exitGlobal(bsParser::GlobalContext * /*ctx*/) override { }

  virtual void enterFunction(bsParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(bsParser::FunctionContext * /*ctx*/) override { }

  virtual void enterParams(bsParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(bsParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParam_decl(bsParser::Param_declContext * /*ctx*/) override { }
  virtual void exitParam_decl(bsParser::Param_declContext * /*ctx*/) override { }

  virtual void enterBlock(bsParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(bsParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(bsParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(bsParser::StatementContext * /*ctx*/) override { }

  virtual void enterVar_decl(bsParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(bsParser::Var_declContext * /*ctx*/) override { }

  virtual void enterArray_decl(bsParser::Array_declContext * /*ctx*/) override { }
  virtual void exitArray_decl(bsParser::Array_declContext * /*ctx*/) override { }

  virtual void enterArray_initializer(bsParser::Array_initializerContext * /*ctx*/) override { }
  virtual void exitArray_initializer(bsParser::Array_initializerContext * /*ctx*/) override { }

  virtual void enterInitIntLiteral(bsParser::InitIntLiteralContext * /*ctx*/) override { }
  virtual void exitInitIntLiteral(bsParser::InitIntLiteralContext * /*ctx*/) override { }

  virtual void enterInitCharLiteral(bsParser::InitCharLiteralContext * /*ctx*/) override { }
  virtual void exitInitCharLiteral(bsParser::InitCharLiteralContext * /*ctx*/) override { }

  virtual void enterInitStringLiteral(bsParser::InitStringLiteralContext * /*ctx*/) override { }
  virtual void exitInitStringLiteral(bsParser::InitStringLiteralContext * /*ctx*/) override { }

  virtual void enterGoto_label(bsParser::Goto_labelContext * /*ctx*/) override { }
  virtual void exitGoto_label(bsParser::Goto_labelContext * /*ctx*/) override { }

  virtual void enterCompound(bsParser::CompoundContext * /*ctx*/) override { }
  virtual void exitCompound(bsParser::CompoundContext * /*ctx*/) override { }

  virtual void enterIf(bsParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(bsParser::IfContext * /*ctx*/) override { }

  virtual void enterIfelse(bsParser::IfelseContext * /*ctx*/) override { }
  virtual void exitIfelse(bsParser::IfelseContext * /*ctx*/) override { }

  virtual void enterWhile(bsParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(bsParser::WhileContext * /*ctx*/) override { }

  virtual void enterFor1(bsParser::For1Context * /*ctx*/) override { }
  virtual void exitFor1(bsParser::For1Context * /*ctx*/) override { }

  virtual void enterFor2(bsParser::For2Context * /*ctx*/) override { }
  virtual void exitFor2(bsParser::For2Context * /*ctx*/) override { }

  virtual void enterGoto(bsParser::GotoContext * /*ctx*/) override { }
  virtual void exitGoto(bsParser::GotoContext * /*ctx*/) override { }

  virtual void enterGoto_if(bsParser::Goto_ifContext * /*ctx*/) override { }
  virtual void exitGoto_if(bsParser::Goto_ifContext * /*ctx*/) override { }

  virtual void enterReturn(bsParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(bsParser::ReturnContext * /*ctx*/) override { }

  virtual void enterBreak(bsParser::BreakContext * /*ctx*/) override { }
  virtual void exitBreak(bsParser::BreakContext * /*ctx*/) override { }

  virtual void enterContinue(bsParser::ContinueContext * /*ctx*/) override { }
  virtual void exitContinue(bsParser::ContinueContext * /*ctx*/) override { }

  virtual void enterPreID(bsParser::PreIDContext * /*ctx*/) override { }
  virtual void exitPreID(bsParser::PreIDContext * /*ctx*/) override { }

  virtual void enterMulDiv(bsParser::MulDivContext * /*ctx*/) override { }
  virtual void exitMulDiv(bsParser::MulDivContext * /*ctx*/) override { }

  virtual void enterIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext * /*ctx*/) override { }
  virtual void exitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext * /*ctx*/) override { }

  virtual void enterDSimpleAssign(bsParser::DSimpleAssignContext * /*ctx*/) override { }
  virtual void exitDSimpleAssign(bsParser::DSimpleAssignContext * /*ctx*/) override { }

  virtual void enterDLSRSCompAssign(bsParser::DLSRSCompAssignContext * /*ctx*/) override { }
  virtual void exitDLSRSCompAssign(bsParser::DLSRSCompAssignContext * /*ctx*/) override { }

  virtual void enterAddressOf(bsParser::AddressOfContext * /*ctx*/) override { }
  virtual void exitAddressOf(bsParser::AddressOfContext * /*ctx*/) override { }

  virtual void enterStaticCast(bsParser::StaticCastContext * /*ctx*/) override { }
  virtual void exitStaticCast(bsParser::StaticCastContext * /*ctx*/) override { }

  virtual void enterID(bsParser::IDContext * /*ctx*/) override { }
  virtual void exitID(bsParser::IDContext * /*ctx*/) override { }

  virtual void enterLogicAnd(bsParser::LogicAndContext * /*ctx*/) override { }
  virtual void exitLogicAnd(bsParser::LogicAndContext * /*ctx*/) override { }

  virtual void enterDereference(bsParser::DereferenceContext * /*ctx*/) override { }
  virtual void exitDereference(bsParser::DereferenceContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(bsParser::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(bsParser::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterCall(bsParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(bsParser::CallContext * /*ctx*/) override { }

  virtual void enterLogicOr(bsParser::LogicOrContext * /*ctx*/) override { }
  virtual void exitLogicOr(bsParser::LogicOrContext * /*ctx*/) override { }

  virtual void enterMod(bsParser::ModContext * /*ctx*/) override { }
  virtual void exitMod(bsParser::ModContext * /*ctx*/) override { }

  virtual void enterBitOr(bsParser::BitOrContext * /*ctx*/) override { }
  virtual void exitBitOr(bsParser::BitOrContext * /*ctx*/) override { }

  virtual void enterCharLiteral(bsParser::CharLiteralContext * /*ctx*/) override { }
  virtual void exitCharLiteral(bsParser::CharLiteralContext * /*ctx*/) override { }

  virtual void enterLShift(bsParser::LShiftContext * /*ctx*/) override { }
  virtual void exitLShift(bsParser::LShiftContext * /*ctx*/) override { }

  virtual void enterAddSub(bsParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(bsParser::AddSubContext * /*ctx*/) override { }

  virtual void enterGL(bsParser::GLContext * /*ctx*/) override { }
  virtual void exitGL(bsParser::GLContext * /*ctx*/) override { }

  virtual void enterIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext * /*ctx*/) override { }
  virtual void exitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext * /*ctx*/) override { }

  virtual void enterISimpleAssign(bsParser::ISimpleAssignContext * /*ctx*/) override { }
  virtual void exitISimpleAssign(bsParser::ISimpleAssignContext * /*ctx*/) override { }

  virtual void enterILSRSCompAssign(bsParser::ILSRSCompAssignContext * /*ctx*/) override { }
  virtual void exitILSRSCompAssign(bsParser::ILSRSCompAssignContext * /*ctx*/) override { }

  virtual void enterDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext * /*ctx*/) override { }
  virtual void exitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext * /*ctx*/) override { }

  virtual void enterReinterpretCast(bsParser::ReinterpretCastContext * /*ctx*/) override { }
  virtual void exitReinterpretCast(bsParser::ReinterpretCastContext * /*ctx*/) override { }

  virtual void enterDAddSubCompAssign(bsParser::DAddSubCompAssignContext * /*ctx*/) override { }
  virtual void exitDAddSubCompAssign(bsParser::DAddSubCompAssignContext * /*ctx*/) override { }

  virtual void enterEqNeq(bsParser::EqNeqContext * /*ctx*/) override { }
  virtual void exitEqNeq(bsParser::EqNeqContext * /*ctx*/) override { }

  virtual void enterBNeg_LNot(bsParser::BNeg_LNotContext * /*ctx*/) override { }
  virtual void exitBNeg_LNot(bsParser::BNeg_LNotContext * /*ctx*/) override { }

  virtual void enterBitXor(bsParser::BitXorContext * /*ctx*/) override { }
  virtual void exitBitXor(bsParser::BitXorContext * /*ctx*/) override { }

  virtual void enterStringLiteral(bsParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(bsParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterGeLe(bsParser::GeLeContext * /*ctx*/) override { }
  virtual void exitGeLe(bsParser::GeLeContext * /*ctx*/) override { }

  virtual void enterBitAnd(bsParser::BitAndContext * /*ctx*/) override { }
  virtual void exitBitAnd(bsParser::BitAndContext * /*ctx*/) override { }

  virtual void enterIAddSubCompAssign(bsParser::IAddSubCompAssignContext * /*ctx*/) override { }
  virtual void exitIAddSubCompAssign(bsParser::IAddSubCompAssignContext * /*ctx*/) override { }

  virtual void enterParan(bsParser::ParanContext * /*ctx*/) override { }
  virtual void exitParan(bsParser::ParanContext * /*ctx*/) override { }

  virtual void enterDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext * /*ctx*/) override { }
  virtual void exitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext * /*ctx*/) override { }

  virtual void enterUnaryPN(bsParser::UnaryPNContext * /*ctx*/) override { }
  virtual void exitUnaryPN(bsParser::UnaryPNContext * /*ctx*/) override { }

  virtual void enterRShift(bsParser::RShiftContext * /*ctx*/) override { }
  virtual void exitRShift(bsParser::RShiftContext * /*ctx*/) override { }

  virtual void enterArgs(bsParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(bsParser::ArgsContext * /*ctx*/) override { }

  virtual void enterType(bsParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(bsParser::TypeContext * /*ctx*/) override { }

  virtual void enterUdef_type(bsParser::Udef_typeContext * /*ctx*/) override { }
  virtual void exitUdef_type(bsParser::Udef_typeContext * /*ctx*/) override { }

  virtual void enterAlignment(bsParser::AlignmentContext * /*ctx*/) override { }
  virtual void exitAlignment(bsParser::AlignmentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

