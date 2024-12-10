
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bsVisitor.h"


/**
 * This class provides an empty implementation of bsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  bsBaseVisitor : public bsVisitor {
public:

  virtual std::any visitProgram(bsParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(bsParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypedef(bsParser::TypedefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal(bsParser::GlobalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(bsParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(bsParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam_decl(bsParser::Param_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(bsParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(bsParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_decl(bsParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_decl(bsParser::Array_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_initializer(bsParser::Array_initializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitIntLiteral(bsParser::InitIntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitCharLiteral(bsParser::InitCharLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitStringLiteral(bsParser::InitStringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoto_label(bsParser::Goto_labelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound(bsParser::CompoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(bsParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfelse(bsParser::IfelseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(bsParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor1(bsParser::For1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor2(bsParser::For2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoto(bsParser::GotoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoto_if(bsParser::Goto_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(bsParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak(bsParser::BreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinue(bsParser::ContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreID(bsParser::PreIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDiv(bsParser::MulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDSimpleAssign(bsParser::DSimpleAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddressOf(bsParser::AddressOfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStaticCast(bsParser::StaticCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitID(bsParser::IDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicAnd(bsParser::LogicAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDereference(bsParser::DereferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteral(bsParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(bsParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicOr(bsParser::LogicOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMod(bsParser::ModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitOr(bsParser::BitOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharLiteral(bsParser::CharLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLShift(bsParser::LShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSub(bsParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGL(bsParser::GLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitISimpleAssign(bsParser::ISimpleAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitILSRSCompAssign(bsParser::ILSRSCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReinterpretCast(bsParser::ReinterpretCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqNeq(bsParser::EqNeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBNeg_LNot(bsParser::BNeg_LNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitXor(bsParser::BitXorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(bsParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeLe(bsParser::GeLeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitAnd(bsParser::BitAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParan(bsParser::ParanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryPN(bsParser::UnaryPNContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRShift(bsParser::RShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(bsParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(bsParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUdef_type(bsParser::Udef_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlignment(bsParser::AlignmentContext *ctx) override {
    return visitChildren(ctx);
  }


};

