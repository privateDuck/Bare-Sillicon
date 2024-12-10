#include "source_gen.hpp"

std::any SourceGen::visitGlobal(bsParser::GlobalContext* context)
{
	out << context->ID()->getText() << " = ";
	visit(context->init_element());
	out << ';';
	out.endline();
    return std::any();
}

std::any SourceGen::visitTypedef(bsParser::TypedefContext* context)
{
	out << "typedef " << context->type()->getText() << " " << context->ID()->getText() << ';';
	out.endline();
	out.empty();
	return std::any();
}

std::any SourceGen::visitFunction(bsParser::FunctionContext* context)
{
	out.empty();
	visit(context->udef_type());
    out << " " << context->ID()->getText() << '(';
    if(context->params())
		visit(context->params());

    out << ")";
	//out.endline();

    visit(context->block());
	out.empty();
    return std::any();
}

std::any SourceGen::visitParams(bsParser::ParamsContext* context)
{
	auto params = context->param_decl();
	for (size_t i = 0; i < params.size(); i++)
	{
		visit(params[i]->udef_type());
		out << " " << params[i]->ID()->getText();
		if (i < params.size() - 1)
			out << ", ";
	}
    return std::any();
}

std::any SourceGen::visitBlock(bsParser::BlockContext* context)
{
	out << '{';
	out.endline();
	out.empty();
	out.indent();
    for (auto statement : context->statement())
    {
		if (statement->isDead && eurce) continue;
        visit(statement);
    }
	out.unindent();
	out.empty();
	out << '}';
	out.endline();
    return std::any();
}

std::any SourceGen::visitStatement(bsParser::StatementContext* context)
{
    if (context->var_decl())
    {
		if (context->var_decl()->isDead && edce) return nullptr;
		visit(context->var_decl());
		out.endline();
	}
    else if (context->array_decl())
	{
        visit(context->array_decl());
    }
	else if (context->expr()) 
	{
		visit(context->expr());
		out << ';';
		out.endline();
	}
	else if (context->goto_label()) {
		visit(context->goto_label());
	}
    else if (context->compound())
    {
        visit(context->compound());
	}
	else if (context->if_()) {
		visit(context->if_());
	}
	else if (context->ifelse())
	{
		visit(context->ifelse());
	}
	else if (context->while_())
	{
		visit(context->while_());
	}
	else if (context->for1())
	{
		visit(context->for1());
	}
	else if (context->for2())
	{
		visit(context->for2());
	}
	else if (context->goto_()) {
		visit(context->goto_());
	}
	else if (context->goto_if()) {
		visit(context->goto_if());
	}
	else if (context->return_())
	{
		visit(context->return_());
	}
	else if (context->break_())
	{
		visit(context->break_());
	}
	else if (context->continue_())
	{
		visit(context->continue_());
	}
    return std::any();
}

std::any SourceGen::visitVar_decl(bsParser::Var_declContext* context)
{
	visit(context->udef_type());
	out <<  " " << context->ID()->getText() << " = ";
	optExprVisit(context->expr());
	out << ';';

	return std::any();
}

std::any SourceGen::visitArray_decl(bsParser::Array_declContext* context)
{
	visit(context->udef_type());
	out << context->ID()->getText() << '[' << context->SIGNED_INT()->getText() << ']';
	if (context->array_initializer())
	{
		visit(context->array_initializer());
	}
	out << ';';
	out.endline();

	return std::any();
}

std::any SourceGen::visitArray_initializer(bsParser::Array_initializerContext* context)
{
	auto arrElements = context->init_element();
	out << " = { ";
	for (size_t i = 0; i < arrElements.size(); i++)
	{
		visit(arrElements[i]);
		if (i < arrElements.size() - 1)
			out << ", ";
	}
	out << " }";
	return std::any();
}

std::any SourceGen::visitInitIntLiteral(bsParser::InitIntLiteralContext* context)
{
	out << context->atom->getText();
	return std::any();
}

std::any SourceGen::visitInitCharLiteral(bsParser::InitCharLiteralContext* context)
{
	out << context->CHAR()->getText();
	return std::any();
}

std::any SourceGen::visitInitStringLiteral(bsParser::InitStringLiteralContext* context)
{
	out << context->STRING_LITERAL()->getText();
	return std::any();
}

std::any SourceGen::visitGoto_label(bsParser::Goto_labelContext* context)
{
	out.unindent();
	out << context->ID()->getText() << ':';
	out.endline();
	out.indent();
	return std::any();
}

std::any SourceGen::visitCompound(bsParser::CompoundContext* context)
{
	visitBlock(context->block());
	return std::any();
}

std::any SourceGen::visitIf(bsParser::IfContext* context)
{
	out.empty();
	if ((context->expr()->isDc && ecf) || (context->expr()->isConst && ecp)) {
		int val = context->expr()->eValue;
		if (val != 0) {
			visit(context->statement()); 
			out.endline();
			out.empty();
		}
	} 
	else {
		out << "if (";
		optExprVisit(context->expr());
		out << ')';
		out.endline();

		visit(context->statement());

		out.endline();
		out.empty();
	}
	return std::any();
}

std::any SourceGen::visitIfelse(bsParser::IfelseContext* context)
{
	out.empty();
	if ((context->expr()->isDc && ecf) || (context->expr()->isConst && ecp)) {
		int val = context->expr()->eValue;
		if (val != 0) {
			visit(context->pos);
			out.endline();
			out.empty();
		}
		else {
			visit(context->neg);
			out.endline();
			out.empty();
		}
	}
	else {
		out << "if (";
		optExprVisit(context->expr());
		out << ')';
		out.endline();

		visit(context->pos);

		out << "else";
		out.endline();

		visit(context->neg);

		out.endline();
		out.empty();
	}
	return std::any();
}

std::any SourceGen::visitWhile(bsParser::WhileContext* context)
{
	out.empty();
	if (isConstExprOpt(context->expr())) {
		int val = context->expr()->eValue;
		if (val != 0) {
			context->noCond = true;
			out << "while (1)";
			out.endline();
			visit(context->statement());
			out.endline();
			out.empty();
		}
	}
	else {
		out << "while (";
		optExprVisit(context->expr());
		out << ')';
		out.endline();

		visit(context->statement());

		out.endline();
		out.empty();
	}
	return std::any();
}

std::any SourceGen::visitFor1(bsParser::For1Context* context)
{
	out.empty();
	out << "for (";
	if (context->var_decl())
	{
		visit(context->var_decl());
	}
	if (context->cond)
		optExprVisit(context->cond);
	out << "; ";
	
	if (context->end_oper)
		optExprVisit(context->end_oper);

	out << ')';
	visit(context->statement());

	out.empty();

	return std::any();
}

std::any SourceGen::visitFor2(bsParser::For2Context* context)
{
	out.empty();
	if (isConstExprOpt(context->start_val) && !isConstExprOpt(context->end_val)) {
		int val = context->start_val->eValue;
		out << "for (" << context->ID()->getText() << " from " << val << " to ";
		optExprVisit(context->end_val);
		out << ')';
		visit(context->statement());
		out.endline();
		out.empty();
	}
	else if (isConstExprOpt(context->end_val) && !isConstExprOpt(context->start_val)) {
		int val = context->end_val->eValue;
		out << "for (" << context->ID()->getText() << " from ";
		optExprVisit(context->start_val);
		out << " to " << val << ')';
		visit(context->statement());
		out.endline();
		out.empty();
	}
	else if (isConstExprOpt(context->start_val) && isConstExprOpt(context->end_val)) {
		int start = context->start_val->eValue;
		int end = context->end_val->eValue;
		int length = end - start;
		if (length <= 0) return nullptr;

		out << "for (" << context->ID()->getText() << " from " << start << " to " << end << ')';
		visit(context->statement());
		out.endline();
		out.empty();
	}
	else {
		out << "for (" << context->ID()->getText() << " from ";
		optExprVisit(context->start_val);
		out << " to ";
		optExprVisit(context->end_val);
		out << ')';
		visit(context->statement());
		out.endline();
		out.empty();
	}

	return std::any();
}

std::any SourceGen::visitGoto(bsParser::GotoContext* context)
{
	out.unindent();
	out << "goto " << context->ID()->getText() << ';';
	out.endline();
	out.indent();
	return std::any();
}

std::any SourceGen::visitGoto_if(bsParser::Goto_ifContext* context)
{
	out.unindent();
	switch (context->state)
	{
	case 0:
		out << "goto " << context->ID()->getText() << " if ";
		optExprVisit(context->expr());
		out << ';';
		out.endline();
		break;
	case 1:
		out << "goto " << context->ID()->getText() << ';';
		out.endline();
		break;
	case 2:
	default:
		break;
	}
	out.indent();
	return std::any();
}

std::any SourceGen::visitReturn(bsParser::ReturnContext* context)
{
	out << "return ";
	optExprVisit(context->expr());
	out << ';';
	out.endline();
	return std::any();
}

std::any SourceGen::visitBreak(bsParser::BreakContext* context)
{
	out << "break;";
	out.endline();
	return std::any();
}

std::any SourceGen::visitContinue(bsParser::ContinueContext* context)
{
	out << "continue;";
	out.endline();
	return std::any();
}

std::any SourceGen::visitCall(bsParser::CallContext* context)
{
	out << context->ID()->getText() << '(';
	visit(context->args());
	out << ')';
	return std::any();
}

std::any SourceGen::visitLogicOr(bsParser::LogicOrContext* context)
{
	optExprVisit(context->left);
	out << " || ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitPreID(bsParser::PreIDContext* context)
{
	out << context->op->getText() << context->operand->getText();
	return std::any();
}

std::any SourceGen::visitMod(bsParser::ModContext* context)
{
	optExprVisit(context->left);
	out << " % ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitBitOr(bsParser::BitOrContext* context)
{
	optExprVisit(context->left);
	out << " | ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitIntegerLiteral(bsParser::IntegerLiteralContext* context)
{
	out << context->atom->getText();
	return std::any();
}

std::any SourceGen::visitCharLiteral(bsParser::CharLiteralContext* context)
{
	out << context->CHAR()->getText();
	return std::any();
}

std::any SourceGen::visitStringLiteral(bsParser::StringLiteralContext* context)
{
	out << context->STRING_LITERAL()->getText();
	return std::any();
}

std::any SourceGen::visitISimpleAssign(bsParser::ISimpleAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << '[';
	optExprVisit(context->deref);
	if (context->alignment()) {
		out << ':';
		visit(context->alignment());
	}
	out << "] = ";
	optExprVisit(context->e);
	return std::any();
}

std::any SourceGen::visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << '[';
	optExprVisit(context->deref);
	if (context->alignment()) {
		out << ':';
		visit(context->alignment());
	}
	out << ']';
	out << context->cop->getText();
	optExprVisit(context->e);
	return std::any();
}

std::any SourceGen::visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << '[';
	optExprVisit(context->deref);
	if (context->alignment()) {
		out << ':';
		visit(context->alignment());
	}
	out << ']';
	out << context->cop->getText();
	optExprVisit(context->e);
	return std::any();
}

std::any SourceGen::visitILSRSCompAssign(bsParser::ILSRSCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << '[';
	optExprVisit(context->deref);
	if (context->alignment()) {
		out << ':';
		visit(context->alignment());
	}
	out << ']';
	out << context->cop->getText();
	optExprVisit(context->e);
	return std::any();
}

std::any SourceGen::visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << '[';
	optExprVisit(context->deref);
	if (context->alignment()) {
		out << ':';
		visit(context->alignment());
	}
	out << ']';
	out << context->cop->getText();
	optExprVisit(context->e);
	return std::any();
}

std::any SourceGen::visitDSimpleAssign(bsParser::DSimpleAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << context->ID()->getText() << " = ";
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << context->ID()->getText() << context->cop->getText();
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << context->ID()->getText() << context->cop->getText();
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << context->ID()->getText() << context->cop->getText();
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext* context)
{
	if (context->isDead && edce) return nullptr;
	out << context->ID()->getText() << context->cop->getText();
	optExprVisit(context->expr());
	return std::any();
}
std::any SourceGen::visitLShift(bsParser::LShiftContext* context)
{
	optExprVisit(context->left);
	out << " << ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitMulDiv(bsParser::MulDivContext* context)
{
	if (context->op->getText() == "*") {
		if (context->left->eValue == 1 && context->left->isConst && eas) {
			optExprVisit(context->right);
			return std::any();
		}
		else if (context->right->eValue == 1 && context->right->isConst && eas) {
			optExprVisit(context->left);
			return std::any();
		}
		else if ((context->left->eValue == 0 && context->left->isConst || context->right->eValue == 0 && context->right->isConst) && eas) {
			out << "0";
			return std::any();
		}
		else if (isPowerOfTwo(context->left->eValue) && esr) {
			optExprVisit(context->right);
			out << " << " << getPowerOfTwo(context->left->eValue);
			return std::any();
		}
		else if (isPowerOfTwo(context->right->eValue) && esr) {
			optExprVisit(context->left);
			out << " << " << getPowerOfTwo(context->right->eValue);
			return std::any();
		}
		optExprVisit(context->left);
		out << " * ";
		optExprVisit(context->right);
	}
	else {
		if (context->right->eValue == 1 && context->right->isConst && eas) {
			optExprVisit(context->left);
			return std::any();
		}
		else if (context->left->eValue == 0 && context->left->isConst && eas) {
			out << "0";
			return std::any();
		}
		else if (context->right->eValue == 0 && context->right->isConst&& eas) {
			out << "0";
			return std::any();
		}
		else if (isPowerOfTwo(context->right->eValue) && esr) {
			optExprVisit(context->left);
			out << " >> " << getPowerOfTwo(context->right->eValue);
			return std::any();
		}
		optExprVisit(context->left);
		out << " / ";
		optExprVisit(context->right);
	}
	return std::any();
}

std::any SourceGen::visitGL(bsParser::GLContext* context)
{
	optExprVisit(context->left);
	out << context->op->getText();
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitEqNeq(bsParser::EqNeqContext* context)
{
	optExprVisit(context->left);
	out << context->op->getText();
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitBitXor(bsParser::BitXorContext* context)
{
	optExprVisit(context->left);
	out << " ^ ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitGeLe(bsParser::GeLeContext* context)
{
	optExprVisit(context->left);
	out << context->op->getText();
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitBitAnd(bsParser::BitAndContext* context)
{
	optExprVisit(context->left);
	out << " & ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitAddressOf(bsParser::AddressOfContext* context)
{
	out << "&";
	out << context->ID()->getText();
	return std::any();
}

std::any SourceGen::visitParan(bsParser::ParanContext* context)
{
	out << '(';
	optExprVisit(context->expr());
	out << ')';
	return std::any();
}

std::any SourceGen::visitBNeg_LNot(bsParser::BNeg_LNotContext* context)
{
	out << context->op->getText();
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitID(bsParser::IDContext* context)
{
	if (context->isConst && ecp) {
		out << context->eValue;
	}
	else {
		out << context->ID()->getText();
	}
	return std::any();
}

std::any SourceGen::visitAddSub(bsParser::AddSubContext* context)
{
	
	if (context->right->eValue == 0 && context->right->isConst && eas) {
		optExprVisit(context->left);
		return std::any();
	}
	else if (context->left->eValue == 0 && context->left->isConst && eas) {
		optExprVisit(context->right);
		return std::any();
	}
	optExprVisit(context->left);
	out << context->op->getText();
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitLogicAnd(bsParser::LogicAndContext* context)
{
	optExprVisit(context->left);
	out << " && ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitUnaryPN(bsParser::UnaryPNContext* context)
{
	out << context->op->getText();
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitStaticCast(bsParser::StaticCastContext* context)
{
	out << '(';
	visit(context->udef_type());
	out << ')';
	optExprVisit(context->expr());
	return std::any();
}

std::any SourceGen::visitReinterpretCast(bsParser::ReinterpretCastContext* context)
{
	out << "reinterpret_cast<";
	visit(context->udef_type());
	out << ">(";
	optExprVisit(context->expr());
	out << ')';
	return std::any();
}

std::any SourceGen::visitDereference(bsParser::DereferenceContext* context)
{
	out << '[';
	optExprVisit(context->expr());
	if (context->alignment()) {
		out << ':' << context->alignment()->getText();
	}
	out << ']';
	return std::any();
}

std::any SourceGen::visitRShift(bsParser::RShiftContext* context)
{
	optExprVisit(context->left);
	out << " >> ";
	optExprVisit(context->right);
	return std::any();
}

std::any SourceGen::visitArgs(bsParser::ArgsContext* context)
{
	auto args = context->expr();
	for (size_t i = 0; i < args.size(); i++)
	{
		optExprVisit(args[i]);
		if (i < args.size() - 1)
			out << ", ";
	}
	return std::any();
}

std::any SourceGen::visitUdef_type(bsParser::Udef_typeContext* context)
{
	if (context->type())
		out << context->type()->getText();
	else
		out << context->ID()->getText();
	return std::any();
}

std::any SourceGen::visitAlignment(bsParser::AlignmentContext* context)
{
	out << context->ALIGN()->getText();
	
	return std::any();
}

std::any SourceGen::optExprVisit(bsParser::ExprContext* context)
{
	if ((context->isDc && ecf) || (context->isConst && ecp)) {
		out << context->eValue;
	}
	else {
		return visit(context);
	}
	return std::any();
}

bool SourceGen::isConstExprOpt(bsParser::ExprContext* context)
{
	if ((context->isDc && ecf) || (context->isConst && ecp)) {
		return true;
	}
	return false;
}

bool SourceGen::isPowerOfTwo(int x)
{
	return x && (!(x & (x - 1)));
}

int SourceGen::getPowerOfTwo(int x)
{
	return (int)log2(x);
}
