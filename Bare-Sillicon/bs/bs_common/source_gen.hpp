#pragma once

#include "indentedstream.hpp"
#include "antlr/bsBaseVisitor.h"
#include "logger.hpp"


class SourceGen : public bsBaseVisitor {
public:
	SourceGen() = default;
    void EnableConstantPropogation() { ecp = true; ecf = true; }
    void EnableConstantFolding() {ecf = true;}
    void EnableDeadCodeElimination() {edce = true;}
    void EnableUnreachableCodeElimination() {eurce = true;}
    void EnableStrengthReduction() { esr = true; }
    void EnableAlgebraicSimplification() { eas = true; }

    void DisableConstantPropogation() { ecp = false;}
    void DisableConstantFolding() { ecf = false; ecp = false; }
    void DisableDeadCodeElimination() { edce = false; }
    void DisableUnreachableCodeElimination() { eurce = false; }

    std::string GetOutput() { 
        out.endline();
        return out.str(); 
    }
	// Inherited via progBaseVisitor
    virtual std::any visitTypedef(bsParser::TypedefContext* context) override;

    virtual std::any visitGlobal(bsParser::GlobalContext* context) override;

    virtual std::any visitFunction(bsParser::FunctionContext* context) override;

    virtual std::any visitParams(bsParser::ParamsContext* context) override;

    virtual std::any visitBlock(bsParser::BlockContext* context) override;

    virtual std::any visitStatement(bsParser::StatementContext* context) override;

    virtual std::any visitVar_decl(bsParser::Var_declContext* context) override;

    virtual std::any visitArray_decl(bsParser::Array_declContext* context) override;

    virtual std::any visitArray_initializer(bsParser::Array_initializerContext* context) override;
    virtual std::any visitInitIntLiteral(bsParser::InitIntLiteralContext* context) override;
    virtual std::any visitInitCharLiteral(bsParser::InitCharLiteralContext* context) override;
    virtual std::any visitInitStringLiteral(bsParser::InitStringLiteralContext* context) override;

    virtual std::any visitGoto_label(bsParser::Goto_labelContext* context) override;

    virtual std::any visitCompound(bsParser::CompoundContext* context) override;

    virtual std::any visitIf(bsParser::IfContext* context) override;

    virtual std::any visitIfelse(bsParser::IfelseContext* context) override;

    virtual std::any visitWhile(bsParser::WhileContext* context) override;

    virtual std::any visitFor1(bsParser::For1Context* context) override;

    virtual std::any visitFor2(bsParser::For2Context* context) override;

    virtual std::any visitGoto(bsParser::GotoContext* context) override;

    virtual std::any visitGoto_if(bsParser::Goto_ifContext* context) override;

    virtual std::any visitReturn(bsParser::ReturnContext* context) override;

    virtual std::any visitBreak(bsParser::BreakContext* context) override;

    virtual std::any visitContinue(bsParser::ContinueContext* context) override;

    virtual std::any visitCall(bsParser::CallContext* context) override;

    virtual std::any visitLogicOr(bsParser::LogicOrContext* context) override;

    virtual std::any visitPreID(bsParser::PreIDContext* context) override;

    virtual std::any visitMod(bsParser::ModContext* context) override;

    virtual std::any visitBitOr(bsParser::BitOrContext* context) override;

    virtual std::any visitIntegerLiteral(bsParser::IntegerLiteralContext* context) override;

    virtual std::any visitCharLiteral(bsParser::CharLiteralContext* context) override;

    virtual std::any visitStringLiteral(bsParser::StringLiteralContext* context) override;

    virtual std::any visitISimpleAssign(bsParser::ISimpleAssignContext* context) override;
    virtual std::any visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext* context) override;
    virtual std::any visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext* context) override;
    virtual std::any visitILSRSCompAssign(bsParser::ILSRSCompAssignContext* context) override;
    virtual std::any visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext* context) override;

    virtual std::any visitDSimpleAssign(bsParser::DSimpleAssignContext* context) override;
    virtual std::any visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext* context) override;
    virtual std::any visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext* context) override;
    virtual std::any visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext* context) override;
    virtual std::any visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext* context) override;
    
    virtual std::any visitStaticCast(bsParser::StaticCastContext* context) override;
    virtual std::any visitReinterpretCast(bsParser::ReinterpretCastContext* context) override;
    virtual std::any visitDereference(bsParser::DereferenceContext* context) override;

    virtual std::any visitLShift(bsParser::LShiftContext* context) override;

    virtual std::any visitMulDiv(bsParser::MulDivContext* context) override;

    virtual std::any visitGL(bsParser::GLContext* context) override;

    virtual std::any visitEqNeq(bsParser::EqNeqContext* context) override;

    virtual std::any visitBitXor(bsParser::BitXorContext* context) override;

    virtual std::any visitGeLe(bsParser::GeLeContext* context) override;

    virtual std::any visitBitAnd(bsParser::BitAndContext* context) override;

    virtual std::any visitAddressOf(bsParser::AddressOfContext* context) override;

    virtual std::any visitParan(bsParser::ParanContext* context) override;

    virtual std::any visitBNeg_LNot(bsParser::BNeg_LNotContext* context) override;

    virtual std::any visitID(bsParser::IDContext* context) override;

    virtual std::any visitAddSub(bsParser::AddSubContext* context) override;

    virtual std::any visitLogicAnd(bsParser::LogicAndContext* context) override;

    virtual std::any visitUnaryPN(bsParser::UnaryPNContext* context) override;

    virtual std::any visitRShift(bsParser::RShiftContext* context) override;

    virtual std::any visitArgs(bsParser::ArgsContext* context) override;
    virtual std::any visitUdef_type(bsParser::Udef_typeContext* context) override;
    virtual std::any visitAlignment(bsParser::AlignmentContext* context) override;
private:
    std::any optExprVisit(bsParser::ExprContext* context); // optimized expression visit
    bool isConstExprOpt(bsParser::ExprContext* context); // check if expression is constant
    bool isPowerOfTwo(int x); // check if number is power of 2
    int getPowerOfTwo(int x); // find number such that 2^n = x

    IndentedStream out;
    bool ecp = false; // enable constant propogation
    bool ecf = false; // enable constant folding
    bool edce = false; // enable dead code elimination
    bool eurce = false; // enable unreachable code elimination
    bool esr = false; // enable strength reduction
    bool eas = false; // enable algebraic simplification
    int lul = 10; // loop unrolling level
};