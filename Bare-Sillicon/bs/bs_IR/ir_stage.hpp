#pragma once
#include <unordered_map>
#include <sstream>
#include <format>
#include "../bs_common/symbols.hpp"
#include "../bs_common/indentedstream.hpp"
#include "../bs_common/antlr/bsVisitor.h"
#include "../bs_common/antlr/bsBaseListener.h"
#include "../bs_common/logger.hpp"
#include "../bs_IR/ir.hpp"

namespace bsc {

	// Intermediate representation generator
	class IRGen : public bsVisitor {

	public:

		IRGen() {
			NAMERESOLVER::get().clear();
			for (size_t i = 0; i < 32; i++)
			{
				freeTemporaries.push_back(31-i);
				TAC_ARG tac;
				tac.setAsIRTemporary(TAC_Temp(i), Type::INT_t);
				tacTemporaries.emplace_back(tac);
			}
		}
		
		std::string GetIR2() { return ir.ConvertToString(); }
		std::string GetIR() { return out.str(); }
		std::string GetLogs() { return logger.GetLog(); }

		IR& GetIRObject() { return ir; }

		// Inherited via bsVisitor
		std::any visitProgram(bsParser::ProgramContext* context) override;
		std::any visitDeclaration(bsParser::DeclarationContext* context) override;
		std::any visitTypedef(bsParser::TypedefContext* context) override;
		std::any visitGlobal(bsParser::GlobalContext* context) override;
		std::any visitFunction(bsParser::FunctionContext* context) override;
		std::any visitParams(bsParser::ParamsContext* context) override;
		std::any visitParam_decl(bsParser::Param_declContext* context) override;
		std::any visitBlock(bsParser::BlockContext* context) override;
		std::any visitStatement(bsParser::StatementContext* context) override;
		std::any visitVar_decl(bsParser::Var_declContext* context) override;
		std::any visitArray_decl(bsParser::Array_declContext* context) override;
		std::any visitArray_initializer(bsParser::Array_initializerContext* context) override;
		std::any visitInitIntLiteral(bsParser::InitIntLiteralContext* context) override;
		std::any visitInitCharLiteral(bsParser::InitCharLiteralContext* context) override;
		std::any visitInitStringLiteral(bsParser::InitStringLiteralContext* context) override;
		std::any visitGoto_label(bsParser::Goto_labelContext* context) override;
		std::any visitCompound(bsParser::CompoundContext* context) override;
		std::any visitIf(bsParser::IfContext* context) override;
		std::any visitIfelse(bsParser::IfelseContext* context) override;
		std::any visitWhile(bsParser::WhileContext* context) override;
		std::any visitFor1(bsParser::For1Context* context) override;
		std::any visitFor2(bsParser::For2Context* context) override;
		std::any visitGoto(bsParser::GotoContext* context) override;
		std::any visitGoto_if(bsParser::Goto_ifContext* context) override;
		std::any visitReturn(bsParser::ReturnContext* context) override;
		std::any visitBreak(bsParser::BreakContext* context) override;
		std::any visitContinue(bsParser::ContinueContext* context) override;
		std::any visitPreID(bsParser::PreIDContext* context) override;
		std::any visitMulDiv(bsParser::MulDivContext* context) override;
		std::any visitAddressOf(bsParser::AddressOfContext* context) override;
		std::any visitID(bsParser::IDContext* context) override;
		std::any visitAddSub(bsParser::AddSubContext* context) override;
		std::any visitLogicAnd(bsParser::LogicAndContext* context) override;
		std::any visitStaticCast(bsParser::StaticCastContext* context) override;
		std::any visitReinterpretCast(bsParser::ReinterpretCastContext* context) override;
		std::any visitDereference(bsParser::DereferenceContext* context) override;
		std::any visitIntegerLiteral(bsParser::IntegerLiteralContext* context) override;
		std::any visitCall(bsParser::CallContext* context) override;
		std::any visitLogicOr(bsParser::LogicOrContext* context) override;
		std::any visitMod(bsParser::ModContext* context) override;
		std::any visitBitOr(bsParser::BitOrContext* context) override;
		std::any visitCharLiteral(bsParser::CharLiteralContext* context) override;
		std::any visitLShift(bsParser::LShiftContext* context) override;
		std::any visitGL(bsParser::GLContext* context) override;
		std::any visitEqNeq(bsParser::EqNeqContext* context) override;
		std::any visitISimpleAssign(bsParser::ISimpleAssignContext* context) override;
		std::any visitILSRSCompAssign(bsParser::ILSRSCompAssignContext* context) override;
		std::any visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext* context) override;
		std::any visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext* context) override;
		std::any visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext* context) override;
		std::any visitDSimpleAssign(bsParser::DSimpleAssignContext* context) override;
		std::any visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext* context) override;
		std::any visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext* context) override;
		std::any visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext* context) override;
		std::any visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext* context) override;
		std::any visitBitXor(bsParser::BitXorContext* context) override;
		std::any visitStringLiteral(bsParser::StringLiteralContext* context) override;
		std::any visitGeLe(bsParser::GeLeContext* context) override;
		std::any visitBitAnd(bsParser::BitAndContext* context) override;
		std::any visitParan(bsParser::ParanContext* context) override;
		std::any visitBNeg_LNot(bsParser::BNeg_LNotContext* context) override;
		std::any visitUnaryPN(bsParser::UnaryPNContext* context) override;
		std::any visitRShift(bsParser::RShiftContext* context) override;
		std::any visitArgs(bsParser::ArgsContext* context) override;
		std::any visitType(bsParser::TypeContext* context) override;
		std::any visitUdef_type(bsParser::Udef_typeContext* context) override;
		std::any visitAlignment(bsParser::AlignmentContext* context) override;
		Type visitAlign(bsParser::AlignmentContext* context);
	private:

		void openScope();
		void addSymbolCurrent(const std::string& name, Type type);
		void addGlobalCurrent(const std::string& name, Type type);
		Type getSymbolType(const std::string& name);

		std::unordered_map<std::string, std::string> stringTable;
		std::unordered_map<std::string, Type> _typeMap;
		std::unordered_map<std::string, Type> _fnRetTypes;
		VarTable symTable;
		Logger logger;

		std::string currentFunction;
		Type currentFunctionReturnType;
		std::string lastLabel;
		std::string nextLabel;

		TAC_ARG visitExpr(bsParser::ExprContext* ctx);

		TAC_ARG &GetTemporaryTAC(Type type);
		void FreeTemporaryTAC(TAC_Temp tmp);
		void FreeIfTemporary(TAC_ARG& arg);

		std::string GetLabel();
		std::string GetStringLabel();

		IndentedStream out;
		IR ir;
		std::vector<TAC_ARG> tacTemporaries;
		std::vector<int> freeTemporaries;
		int sCount = -1;
		int lCount = -1;
	};

};