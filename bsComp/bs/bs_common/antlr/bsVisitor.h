
// Generated from bs.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "bsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by bsParser.
 */
class  bsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by bsParser.
   */
    virtual std::any visitProgram(bsParser::ProgramContext *context) = 0;

    virtual std::any visitDeclaration(bsParser::DeclarationContext *context) = 0;

    virtual std::any visitTypedef(bsParser::TypedefContext *context) = 0;

    virtual std::any visitGlobal(bsParser::GlobalContext *context) = 0;

    virtual std::any visitFunction(bsParser::FunctionContext *context) = 0;

    virtual std::any visitParams(bsParser::ParamsContext *context) = 0;

    virtual std::any visitParam_decl(bsParser::Param_declContext *context) = 0;

    virtual std::any visitBlock(bsParser::BlockContext *context) = 0;

    virtual std::any visitStatement(bsParser::StatementContext *context) = 0;

    virtual std::any visitVar_decl(bsParser::Var_declContext *context) = 0;

    virtual std::any visitArray_decl(bsParser::Array_declContext *context) = 0;

    virtual std::any visitArray_initializer(bsParser::Array_initializerContext *context) = 0;

    virtual std::any visitInitIntLiteral(bsParser::InitIntLiteralContext *context) = 0;

    virtual std::any visitInitCharLiteral(bsParser::InitCharLiteralContext *context) = 0;

    virtual std::any visitInitStringLiteral(bsParser::InitStringLiteralContext *context) = 0;

    virtual std::any visitGoto_label(bsParser::Goto_labelContext *context) = 0;

    virtual std::any visitCompound(bsParser::CompoundContext *context) = 0;

    virtual std::any visitIf(bsParser::IfContext *context) = 0;

    virtual std::any visitIfelse(bsParser::IfelseContext *context) = 0;

    virtual std::any visitWhile(bsParser::WhileContext *context) = 0;

    virtual std::any visitFor1(bsParser::For1Context *context) = 0;

    virtual std::any visitFor2(bsParser::For2Context *context) = 0;

    virtual std::any visitGoto(bsParser::GotoContext *context) = 0;

    virtual std::any visitGoto_if(bsParser::Goto_ifContext *context) = 0;

    virtual std::any visitReturn(bsParser::ReturnContext *context) = 0;

    virtual std::any visitBreak(bsParser::BreakContext *context) = 0;

    virtual std::any visitContinue(bsParser::ContinueContext *context) = 0;

    virtual std::any visitPreID(bsParser::PreIDContext *context) = 0;

    virtual std::any visitMulDiv(bsParser::MulDivContext *context) = 0;

    virtual std::any visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext *context) = 0;

    virtual std::any visitDSimpleAssign(bsParser::DSimpleAssignContext *context) = 0;

    virtual std::any visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext *context) = 0;

    virtual std::any visitAddressOf(bsParser::AddressOfContext *context) = 0;

    virtual std::any visitStaticCast(bsParser::StaticCastContext *context) = 0;

    virtual std::any visitID(bsParser::IDContext *context) = 0;

    virtual std::any visitLogicAnd(bsParser::LogicAndContext *context) = 0;

    virtual std::any visitDereference(bsParser::DereferenceContext *context) = 0;

    virtual std::any visitIntegerLiteral(bsParser::IntegerLiteralContext *context) = 0;

    virtual std::any visitCall(bsParser::CallContext *context) = 0;

    virtual std::any visitLogicOr(bsParser::LogicOrContext *context) = 0;

    virtual std::any visitMod(bsParser::ModContext *context) = 0;

    virtual std::any visitBitOr(bsParser::BitOrContext *context) = 0;

    virtual std::any visitCharLiteral(bsParser::CharLiteralContext *context) = 0;

    virtual std::any visitLShift(bsParser::LShiftContext *context) = 0;

    virtual std::any visitAddSub(bsParser::AddSubContext *context) = 0;

    virtual std::any visitGL(bsParser::GLContext *context) = 0;

    virtual std::any visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext *context) = 0;

    virtual std::any visitISimpleAssign(bsParser::ISimpleAssignContext *context) = 0;

    virtual std::any visitILSRSCompAssign(bsParser::ILSRSCompAssignContext *context) = 0;

    virtual std::any visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext *context) = 0;

    virtual std::any visitReinterpretCast(bsParser::ReinterpretCastContext *context) = 0;

    virtual std::any visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext *context) = 0;

    virtual std::any visitEqNeq(bsParser::EqNeqContext *context) = 0;

    virtual std::any visitBNeg_LNot(bsParser::BNeg_LNotContext *context) = 0;

    virtual std::any visitBitXor(bsParser::BitXorContext *context) = 0;

    virtual std::any visitStringLiteral(bsParser::StringLiteralContext *context) = 0;

    virtual std::any visitGeLe(bsParser::GeLeContext *context) = 0;

    virtual std::any visitBitAnd(bsParser::BitAndContext *context) = 0;

    virtual std::any visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext *context) = 0;

    virtual std::any visitParan(bsParser::ParanContext *context) = 0;

    virtual std::any visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext *context) = 0;

    virtual std::any visitUnaryPN(bsParser::UnaryPNContext *context) = 0;

    virtual std::any visitRShift(bsParser::RShiftContext *context) = 0;

    virtual std::any visitArgs(bsParser::ArgsContext *context) = 0;

    virtual std::any visitType(bsParser::TypeContext *context) = 0;

    virtual std::any visitUdef_type(bsParser::Udef_typeContext *context) = 0;

    virtual std::any visitAlignment(bsParser::AlignmentContext *context) = 0;


};

