#include "ir_stage.hpp"

namespace bsc{

std::any IRGen::visitProgram(bsParser::ProgramContext* context)
{
    out.indent();
    visitChildren(context);
    out.unindent();
    return std::any();
}

std::any IRGen::visitDeclaration(bsParser::DeclarationContext* context)
{
    visitChildren(context);
    return std::any();
}

std::any IRGen::visitTypedef(bsParser::TypedefContext* context)
{
    Type tp = std::any_cast<Type>(visit(context->type()));
    std::string id = context->ID()->getText();
    _typeMap[id] = tp;
    return std::any();
}

std::any IRGen::visitGlobal(bsParser::GlobalContext* context)
{
    Type tp = std::any_cast<Type>(visit(context->udef_type()));
    symTable.AddGlobal(context->ID()->getText(), tp, false, context->expr()->eValue, nullptr);
    const auto& sym = symTable.GetVariable(context->ID()->getText());

    out << "globl: " << getTypeName(tp) << ' ' << sym.name << " = ";
    // auto global_expr_result = visitExpr(context->expr()); no need to visit expr, it's already evaluated
    out.endline();

    ir.AddDeclareGlobal(sym.name, sym.eValue, tp); // Add evaluated value
    return std::any();
}

std::any IRGen::visitFunction(bsParser::FunctionContext* context)
{
    symTable.PushNewScope();
    currentFunction = context->ID()->getText();
    currentFunctionReturnType = std::any_cast<Type>(visit(context->udef_type()));
    _fnRetTypes[currentFunction] = currentFunctionReturnType;

    out.empty();
    out.empty();
    int param_count = 0;
    if (context->params())
        param_count = std::any_cast<size_t>(visit(context->params()));

    out.unindent();
    out << "func: " << currentFunction << " returns " << getTypeName(currentFunctionReturnType);
    out.endline();
    out.indent();

    ir.AddDeclareFunction(currentFunction, param_count, currentFunctionReturnType);

    visit(context->block());

    symTable.PopLastScope();
    out.empty();
    out.empty();
    return std::any();
}

std::any IRGen::visitParams(bsParser::ParamsContext* context)
{
    auto params = context->param_decl();
    for (auto p : params) {
        visit(p);
    }
    return params.size();
}

std::any IRGen::visitParam_decl(bsParser::Param_declContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    symTable.AddCurrent(context->ID()->getText(), t, false, 0, nullptr);
    const auto& sym = symTable.GetVariable(context->ID()->getText());

    out << "param: " << getTypeName(t) << " " << sym.name;
    out.endline();

    ir.AddDeclareFunctionParameter(sym.name, t);
    return std::any();
}

std::any IRGen::visitBlock(bsParser::BlockContext* context)
{
    for (auto* stm : context->statement()) {
        visit(stm);
    }
    return std::any();
}

std::any IRGen::visitStatement(bsParser::StatementContext* context)
{
    if (context->var_decl())
    {
        visit(context->var_decl());
    }
    else if (context->array_decl())
    {
        visit(context->array_decl());
    }
    else if (context->expr())
    {
        auto tmp = visitExpr(context->expr());
        FreeIfTemporary(tmp);
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

std::any IRGen::visitVar_decl(bsParser::Var_declContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    std::string id = context->ID()->getText();
    symTable.AddCurrent(id, t, context->expr()->isConst, context->expr()->eValue, context);
    const auto& sym = symTable.GetVariable(id);

    out << "local: " << getTypeName(t) << " " << sym.name;
    out.endline();

    ir.AddDeclareVariable(sym.name, t);

    auto result = visitExpr(context->expr());
    out << sym.name << " = " << result.get();
    out.endline();
    ir.AddVariableDefinition(sym.name, result, t);

    FreeIfTemporary(result);
    return std::any();
}

std::any IRGen::visitArray_decl(bsParser::Array_declContext* context)
{
    return std::any();
}

std::any IRGen::visitArray_initializer(bsParser::Array_initializerContext* context)
{
    return std::any();
}

std::any IRGen::visitInitIntLiteral(bsParser::InitIntLiteralContext* context)
{
    long long i = std::stoll(context->atom->getText());
    out << i;
    return i;
}

std::any IRGen::visitInitCharLiteral(bsParser::InitCharLiteralContext* context)
{
    long long c = parseAsciiSequence(context->CHAR()->getText());
    out << c;
    return c;
}

std::any IRGen::visitInitStringLiteral(bsParser::InitStringLiteralContext* context)
{
    std::string txt = context->STRING_LITERAL()->getText();
    std::string lbl = GetStringLabel();
    stringTable[lbl] = txt;
    out << lbl;
    return std::any();
}

std::any IRGen::visitGoto_label(bsParser::Goto_labelContext* context)
{
    if (currentFunction.empty()) {
        logger.LogError(context, "Goto label outside function");
        return nullptr;
    }
    out.unindent();
    out << context->ID()->getText() << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(context->ID()->getText());
    return std::any();
}

std::any IRGen::visitCompound(bsParser::CompoundContext* context)
{
    symTable.PushNewScope();
    visit(context->block());
    symTable.PopLastScope();
    return std::any();
}

std::any IRGen::visitIf(bsParser::IfContext* context)
{
    std::string endLabel = GetLabel();
    nextLabel = endLabel;

    if (context->statement() == nullptr) {
        logger.LogError(context, "Empty statement detected");
        return nullptr;
    }

    TAC_ARG t = visitExpr(context->expr());
    out << t.get() << " = " << t.get() << " == 0";
    out.endline();
    ir.AddBinaryOp(t, t, TAC_ARG::getAsConstant(0, t.type), IROpertion::EQUAL);

    out << "ifTrue " << t << " goto " << endLabel;
    out.endline();
    ir.AddGotoIfTrue(t, endLabel);

    FreeIfTemporary(t);

    visit(context->statement());

    out.unindent();
    out << endLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(endLabel);

    nextLabel.clear();
    return std::any();
}

std::any IRGen::visitIfelse(bsParser::IfelseContext* context)
{
    std::string elseLabel = GetLabel();
    std::string endLabel = GetLabel();
    nextLabel = endLabel;

    if (context->pos == nullptr || context->neg == nullptr) {
        logger.LogError(context, "Empty statement detected");
        return nullptr;
    }

    TAC_ARG t = visitExpr(context->expr());
    out << t.get() << " = " << t.get() << " == 0";
    out.endline();
    ir.AddBinaryOp(t, t, TAC_ARG::getAsConstant(0, t.type), IROpertion::EQUAL);

    out << "ifTrue " << t.get() << " goto " << elseLabel;
    out.endline();
    ir.AddGotoIfTrue(t, elseLabel);
    FreeIfTemporary(t);

    visit(context->pos);

    out.unindent();
    out << elseLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(elseLabel);

    visit(context->neg);
    
    out.unindent();
    out << endLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(endLabel);

    nextLabel.clear();
    return std::any();
}

std::any IRGen::visitWhile(bsParser::WhileContext* context)
{
    std::string loopLabel = GetLabel();
    std::string endLabel = GetLabel();
    lastLabel = loopLabel;
    nextLabel = endLabel;

    out.unindent();
    out << loopLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(loopLabel);

    TAC_ARG t = visitExpr(context->expr());
    out << t.get() << " = " << t.get() << " == 0";
    out.endline();
    ir.AddBinaryOp(t, t, TAC_ARG::getAsConstant(0, t.type), IROpertion::EQUAL);

    out << "ifTrue " << t.get() << " goto " << endLabel;
    out.endline();
    ir.AddGotoIfTrue(t, endLabel);

    visit(context->statement());

    out << "goto " << loopLabel;
    out.endline();
    ir.AddGotoLabel(loopLabel);

    out.unindent();
    out << endLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(endLabel);

    FreeIfTemporary(t);
    lastLabel.clear();
    nextLabel.clear();
    return std::any();
}

std::any IRGen::visitFor1(bsParser::For1Context* context)
{
    std::string loopLabel = GetLabel();
    std::string endLabel = GetLabel();
    lastLabel = loopLabel;
    nextLabel = endLabel;

    if (context->var_decl()) {
		visit(context->var_decl());
	}

    out.unindent();
    out << loopLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(loopLabel);

    if (context->cond) {
        TAC_ARG t = visitExpr(context->cond);
        out << t.get() << " = " << t.get() << " == 0";
        out.endline();
        ir.AddBinaryOp(t, t, TAC_ARG::getAsConstant(0, t.type), IROpertion::EQUAL);

        out << "ifTrue " << t.get() << " goto " << endLabel;
        out.endline();
        ir.AddGotoIfTrue(t, endLabel);
        FreeIfTemporary(t);
    }

    visit(context->statement());

    if (context->end_oper) {
		visit(context->end_oper);
	}

    out << "goto " << loopLabel;
    out.endline();
    ir.AddGotoLabel(loopLabel);

    out.unindent();
    out << endLabel << ':';
    out.endline();
    out.indent();
    ir.AddDeclareLabel(endLabel);

    lastLabel.clear();
    nextLabel.clear();
    return std::any();
}

std::any IRGen::visitFor2(bsParser::For2Context* context)
{
    std::string loopLabel = GetLabel();
    std::string endLabel = GetLabel();
    lastLabel = loopLabel;
    nextLabel = endLabel;

    std::string sym_name = context->ID()->getText();

    TAC_ARG argS, argE;
    if (!context->start_val->isConst)
        argS = visitExpr(context->start_val);
    else {
        auto cexpr = TAC_ARG::getAsConstant(context->start_val->eValue, Type::INT_t);
        argS = GetTemporaryTAC(Type::INT_t);
        ir.AddBinaryOp(argS, cexpr, TAC_ARG::getAsConstant(0, Type::INT_t), IROpertion::ADD);
    }

    if (!context->end_val->isConst)
        argE = visitExpr(context->end_val);
    else
        argE = TAC_ARG::getAsConstant(context->end_val->eValue, Type::INT_t);

    symTable.AddTemporaryResident(sym_name, Type::INT_t, context->start_val->isConst, context->start_val->eValue, argS.value);
    
    ir.AddDeclareLabel(loopLabel);
    
    TAC_ARG res = GetTemporaryTAC(Type::INT_t);
    ir.AddBinaryOp(res, argS, argE, bsc::IROpertion::EQUAL);
    ir.AddGotoIfTrue(res, endLabel);
    FreeIfTemporary(res);

    
    visit(context->statement());

    ir.AddBinaryOp(argS, argS, TAC_ARG::getAsConstant(1, Type::INT_t), IROpertion::ADD);
    ir.AddDeclareLabel(endLabel);
    FreeIfTemporary(argS);
    FreeIfTemporary(argE);
    return std::any();
}

std::any IRGen::visitGoto(bsParser::GotoContext* context)
{
    out << "goto " << context->ID()->getText();
    out.endline();
    ir.AddGotoLabel(context->ID()->getText());
    return std::any();
}

std::any IRGen::visitGoto_if(bsParser::Goto_ifContext* context)
{
    TAC_ARG t = visitExpr(context->expr());
    out << "if " << t.get() << " goto " << context->ID()->getText();
    out.endline();
    ir.AddGotoIfTrue(t, context->ID()->getText());
    FreeIfTemporary(t);
    return std::any();
}

std::any IRGen::visitReturn(bsParser::ReturnContext* context)
{
    TAC_ARG t = visitExpr(context->expr());
    if (isInt(t.type) && isChar(currentFunctionReturnType) || isChar(t.type) && isInt(currentFunctionReturnType)) {
        logger.LogError(context, "Return type mismatch");
        FreeIfTemporary(t);
        return nullptr;
    }
    out << "return " << t.get();
    out.endline();
    ir.AddReturn(t, currentFunctionReturnType);
    FreeIfTemporary(t);
    return std::any();
}

std::any IRGen::visitBreak(bsParser::BreakContext* context)
{
    if (nextLabel.empty()) {
        logger.LogError(context, "Break outside loop or conditional block");
        return nullptr;
    }
    out << "goto " << nextLabel;
    out.endline();
    ir.AddGotoLabel(nextLabel);
    return std::any();
}

std::any IRGen::visitContinue(bsParser::ContinueContext* context)
{
    if (lastLabel.empty()) {
        logger.LogError(context, "Continue outside loop");
        return nullptr;
    }
    out << "goto " << lastLabel;
    out.endline();
    ir.AddGotoLabel(lastLabel);
    return std::any();
}

std::any IRGen::visitPreID(bsParser::PreIDContext* context)
{
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    out << sym.name << " = " << sym.name << ' ' << context->op->getText()[0] << " 1";
    out.endline();
    TAC_ARG arg;
    arg.setAsVariable(sym.name, sym.type);
    if (context->op->getText() == "++") {
		ir.AddBinaryOp(arg, arg, TAC_ARG::getAsConstant(1, sym.type), IROpertion::ADD);
	}
    else {
        ir.AddBinaryOp(arg, arg, TAC_ARG::getAsConstant(1, sym.type), IROpertion::SUB);
	}
    return arg;
}

std::any IRGen::visitMulDiv(bsParser::MulDivContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type,tr.type));

    if (context->op->getText() == "*") {
        out << tmp << " = " << tl << " * " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::MUL);
    }
    else {
        out << tmp << " = " << tl << " / " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::DIV);
    }

    return tmp;
}
std::any IRGen::visitAddressOf(bsParser::AddressOfContext* context)
{
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    TAC_ARG tmp = GetTemporaryTAC(Type::UINT_t);
    out << tmp << " = loadptr " << sym.name;
    out.endline();
    ir.AddLoadPointer(tmp, sym.name, sym.type);
    return tmp;
}

std::any IRGen::visitID(bsParser::IDContext* context)
{
    std::string id = context->ID()->getText();
    auto &vi = symTable.GetVariable(id);
    TAC_ARG arg;
    if (vi.isTemporaryResident) arg.setAsIRTemporary(TAC_Temp(vi.scopeIndex), vi.type);
	else arg.setAsVariable(vi.name, vi.type);
    return arg;
}

std::any IRGen::visitAddSub(bsParser::AddSubContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));

    if (context->op->getText() == "+") {
        out << tmp << " = " << tl << " + " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::ADD);
    }
    else {
        out << tmp << " = " << tl << " - " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::SUB);
    }

    return tmp;
}

std::any IRGen::visitLogicAnd(bsParser::LogicAndContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " && " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::LOGICAL_AND);

    return tmp;
}

std::any IRGen::visitStaticCast(bsParser::StaticCastContext* context)
{
    // TODO: implement cast
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    auto tmp = visitExpr(context->expr());

    if ((Type)context->expr()->eType == t) {
        return tmp;
    }
    else {
        auto ntmp = GetTemporaryTAC(t);
        switch (t)
        {
        case bsc::Type::CHAR_t:
            out << ntmp.get() << " = cast_to_char(" << tmp.get() << ')';
            break;
        case bsc::Type::UCHAR_t:
            out << ntmp.get() << " = cast_to_uchar(" << tmp.get() << ')';
            break;
        case bsc::Type::INT_t:
            out << ntmp.get() << " = cast_to_int(" << tmp.get() << ')';
            break;
        case bsc::Type::UINT_t:
            out << ntmp.get() << " = cast_to_uint(" << tmp.get() << ')';
            break;
        default:
            break;
        }
        out.endline();
        ir.AddStaticCast(ntmp, tmp, t);
        FreeIfTemporary(tmp);
        return ntmp;
    }
}

std::any IRGen::visitReinterpretCast(bsParser::ReinterpretCastContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    auto tmp = visitExpr(context->expr());

    if ((Type)context->expr()->eType == t) {
        return tmp;
    }
    else {
        auto ntmp = GetTemporaryTAC(t);
        switch (t)
        {
        case bsc::Type::CHAR_t:
            out << ntmp.get() << " = reinterpret_as_char(" << tmp.get() << ')';
            break;
        case bsc::Type::UCHAR_t:
            out << ntmp.get() << " = reinterpret_as_uchar(" << tmp.get() << ')';
            break;
        case bsc::Type::INT_t:
            out << ntmp.get() << " = reinterpret_as_int(" << tmp.get() << ')';
            break;
        case bsc::Type::UINT_t:
            out << ntmp.get() << " = reinterpret_as_uint(" << tmp.get() << ')';
            break;
        default:
            break;
        }
        out.endline();
        ir.AddReinterpretCast(ntmp, tmp, t);
        FreeIfTemporary(tmp);
        return ntmp;
    }
}

std::any IRGen::visitDereference(bsParser::DereferenceContext* context)
{
    Type type = visitAlign(context->alignment());
    TAC_ARG te = visitExpr(context->expr());
    TAC_ARG tp = GetTemporaryTAC(type);

    out << tp << " = [" << te << ':' << getTypeName(type) << ']';
    out.endline();
    ir.AddPointerRValue(tp, te, type);
    FreeIfTemporary(te);
    return tp;
}

std::any IRGen::visitIntegerLiteral(bsParser::IntegerLiteralContext* context)
{
    long long integer = std::stoll(context->atom->getText());
    TAC_ARG arg;
    arg.argType = IRARG::VALUE;
    arg.value = integer;
    arg.type = integer < 0 ? Type::INT_t : Type::UINT_t;
    return arg;
}

std::any IRGen::visitCall(bsParser::CallContext* context)
{
    auto paramTemps = std::any_cast<std::vector<TAC_ARG>>(visit(context->args()));
    TAC_ARG t = GetTemporaryTAC(_fnRetTypes[currentFunction]); // Find type of function
    out << t.get() << " = call " << context->ID()->getText() << ", " << paramTemps.size();
    out.endline();
    ir.AddFunctionCall(t, context->ID()->getText(), paramTemps.size(), _fnRetTypes[currentFunction]);
    for (auto& tmp : paramTemps) FreeIfTemporary(tmp);
    return t;
}

std::any IRGen::visitLogicOr(bsParser::LogicOrContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " || " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::LOGICAL_OR);

    return tmp;
}

std::any IRGen::visitMod(bsParser::ModContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " % " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::MOD);

    return tmp;
}

std::any IRGen::visitBitOr(bsParser::BitOrContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " | " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::BITWISE_OR);

    return tmp;
}

std::any IRGen::visitCharLiteral(bsParser::CharLiteralContext* context)
{
    TAC_ARG arg;
    arg.argType = IRARG::VALUE;
    arg.value = parseAsciiSequence(context->CHAR()->getText());
    arg.type = Type::CHAR_t;
    return arg;
}

std::any IRGen::visitLShift(bsParser::LShiftContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " << " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::SHIFT_LEFT);

    return tmp;
}

std::any IRGen::visitGL(bsParser::GLContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));

    if (context->op->getText() == ">") {
        out << tmp << " = " << tl << " > " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::GREATER);
    }
    else {
        out << tmp << " = " << tl << " < " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::LESS);
    }

    return tmp;
}

std::any IRGen::visitEqNeq(bsParser::EqNeqContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));

    if (context->op->getText() == "==") {
        out << tmp << " = " << tl << " == " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::EQUAL);
    }
    else {
        out << tmp << " = " << tl << " != " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::NOT_EQUAL);
    }

    return tmp;
}

std::any IRGen::visitBitXor(bsParser::BitXorContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " ^ " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::BITWISE_XOR);

    return tmp;
}

std::any IRGen::visitISimpleAssign(bsParser::ISimpleAssignContext* context)
{
    TAC_ARG te = visitExpr(context->e);
    TAC_ARG tp = visitExpr(context->deref);

    Type type = visitAlign(context->alignment());
    out << '[' << tp << ':' << getTypeName(type) << "] = " << te;
    out.endline();
    ir.AddPointerLValue(tp, te, type);
    FreeIfTemporary(tp);
    return te;
}

std::any IRGen::visitILSRSCompAssign(bsParser::ILSRSCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->e);
    TAC_ARG tp = visitExpr(context->deref);

    Type type = visitAlign(context->alignment());
    TAC_ARG tmp = GetTemporaryTAC(type);
    
    out << tmp << " = [" << tp << ':' << getTypeName(type) << ']';
    out.endline();
    ir.AddPointerRValue(tmp, tp, type);

    if (context->cop->getText() == ">>=") {
		out << tmp << " = " << tmp << " >> " << te;
        ir.AddBinaryOp(tmp, tmp, te, IROpertion::SHIFT_RIGHT);
	}
	else {
        out << tmp << " = " << tmp << " << " << te;
        ir.AddBinaryOp(tmp, tmp, te, IROpertion::SHIFT_LEFT);
	}
    out.endline();

    out << '[' << tp << ':' << getTypeName(type) << "] = " << tmp;
    out.endline();
    ir.AddPointerLValue(tp, tmp, type);

    FreeIfTemporary(tp);
    FreeIfTemporary(te);

    return tmp;
}

std::any IRGen::visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->e);
    TAC_ARG tp = visitExpr(context->deref);

    Type type = visitAlign(context->alignment());
    TAC_ARG tmp = GetTemporaryTAC(type);

    out << tmp << " = [" << tp << ':' << getTypeName(type) << ']';
    out.endline();
    ir.AddPointerRValue(tmp, tp, type);

    out << tmp << " = " << tmp << ' ' << context->cop->getText()[0] << ' ' << te;
    out.endline();
    if (context->cop->getText() == "+=") {
		ir.AddBinaryOp(tmp, tmp, te, IROpertion::ADD);
	}
    else {
		ir.AddBinaryOp(tmp, tmp, te, IROpertion::SUB);
	}

    out << '[' << tp << ':' << getTypeName(type) << "] = " << tmp;
    out.endline();
    ir.AddPointerLValue(tp, tmp, type);

    FreeIfTemporary(tp);
    FreeIfTemporary(te);
    return tmp;
}

std::any IRGen::visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->e);
    TAC_ARG tp = visitExpr(context->deref);

    Type type = visitAlign(context->alignment());
    TAC_ARG tmp = GetTemporaryTAC(type);

    out << tmp << " = [" << tp << ':' << getTypeName(type) << ']';
    out.endline();
    ir.AddPointerRValue(tmp, tp, type);

    out << tmp << " = " << tmp << ' ' << context->cop->getText()[0] << ' ' << te;
    out.endline();
    if (context->cop->getText() == "*=") {
		ir.AddBinaryOp(tmp, tmp, te, IROpertion::MUL);
	}
    else if (context->cop->getText() == "/=") {
		ir.AddBinaryOp(tmp, tmp, te, IROpertion::DIV);
	}
    else {
		ir.AddBinaryOp(tmp, tmp, te, IROpertion::MOD);
	}

    out << '[' << tp << ':' << getTypeName(type) << "] = " << tmp;
    out.endline();
    ir.AddPointerLValue(tp, tmp, type);

    FreeIfTemporary(tp);
    FreeIfTemporary(te);
    return tmp;
}

std::any IRGen::visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->e);
    TAC_ARG tp = visitExpr(context->deref);

    Type type = visitAlign(context->alignment());
    TAC_ARG tmp = GetTemporaryTAC(type);
    
    out << tmp << " = [" << tp << ':' << getTypeName(type) << ']';
    out.endline();
    ir.AddPointerRValue(tmp, tp, type);

    out << tmp << " = " << tmp << ' ' << context->cop->getText()[0] << ' ' << te;
    out.endline();
    if (context->cop->getText() == "&=") {
        ir.AddBinaryOp(tmp, tmp, te, IROpertion::BITWISE_AND);
    }
    else if (context->cop->getText() == "^=") {
        ir.AddBinaryOp(tmp, tmp, te, IROpertion::BITWISE_XOR);
    }
    else {
        ir.AddBinaryOp(tmp, tmp, te, IROpertion::BITWISE_OR);
    }

    out << '[' << tp << ':' << getTypeName(type) << "] = " << tmp;
    out.endline();
    ir.AddPointerLValue(tp, tmp, type);

    FreeIfTemporary(tp);
    FreeIfTemporary(te);
    return tmp;
}

std::any IRGen::visitDSimpleAssign(bsParser::DSimpleAssignContext* context)
{
    TAC_ARG te = visitExpr(context->expr());
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    out << sym.name << " = " << te << " + 0";
    out.endline();
    FreeIfTemporary(te);
    TAC_ARG arg;
    arg.setAsVariable(sym.name, sym.type);
    ir.AddBinaryOp(arg, te, TAC_ARG::getAsConstant(0, sym.type), IROpertion::ADD);
    return arg;
}

std::any IRGen::visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->expr());
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    if (context->cop->getText() == ">>=") {
		out << sym.name << " = " << sym.name << " >> " << te;
        ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::SHIFT_RIGHT);
	}
	else {
		out << sym.name << " = " << sym.name << " << " << te;
        ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::SHIFT_LEFT);
	}
    out.endline();
    return te;
}

std::any IRGen::visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->expr());
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    out << sym.name << " = " << sym.name << ' ' << context->cop->getText()[0] << ' ' << te;
    if (context->cop->getText() == "+=") {
		ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::ADD);
	}
    else {
		ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::SUB);
	}
    out.endline();
    return te;
}

std::any IRGen::visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->expr());
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    out << sym.name << " = " << sym.name << ' ' << context->cop->getText()[0] << ' ' << te;
    if (context->cop->getText() == "*=") {
        ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::MUL);
    }
    else if (context->cop->getText() == "/=") {
		ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::DIV);
	}
    else {
		ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::MOD);
	}
    out.endline();
    return te;
}

std::any IRGen::visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext* context)
{
    TAC_ARG te = visitExpr(context->expr());
    const auto& sym = symTable.GetVariable(context->ID()->getText());
    out << sym.name << " = " << sym.name << ' ' << context->cop->getText()[0] << ' ' << te;
    if (context->cop->getText() == "&=") {
        ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::BITWISE_AND);
    }
    else if (context->cop->getText() == "^=") {
		ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::BITWISE_XOR);
    }
    else {
        ir.AddBinaryOp(TAC_ARG::getAsVariable(sym.name, sym.type), TAC_ARG::getAsVariable(sym.name, sym.type), te, IROpertion::BITWISE_OR);
    }
    out.endline();
    return te;
}

std::any IRGen::visitStringLiteral(bsParser::StringLiteralContext* context)
{
    std::string lbl = GetStringLabel();
    stringTable[lbl] = context->STRING_LITERAL()->getText();
    TAC_ARG t = GetTemporaryTAC(Type::UINT_t);
    out << t << " = loadptr " << lbl;
    out.endline();
    ir.AddLoadPointer(t, lbl, Type::UINT_t);
    return std::any();
}

std::any IRGen::visitGeLe(bsParser::GeLeContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));

    if (context->op->getText() == ">=") {
        out << tmp << " = " << tl << " >= " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::GREATER_EQUAL);
    }
    else {
        out << tmp << " = " << tl << " <= " << tr;
        out.endline();
        ir.AddBinaryOp(tmp, tl, tr, IROpertion::LESS_EQUAL);
    }

    return tmp;
}

std::any IRGen::visitBitAnd(bsParser::BitAndContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " & " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::BITWISE_AND);

    return tmp;
}

std::any IRGen::visitParan(bsParser::ParanContext* context)
{
    return visit(context->expr());
}

std::any IRGen::visitBNeg_LNot(bsParser::BNeg_LNotContext* context)
{
    TAC_ARG t = visitExpr(context->expr());
    TAC_ARG arg = GetTemporaryTAC(t.type);

    if (context->op->getText() == "!") {// logical not
        out << arg << " = " << t << " == 0";
        ir.AddBinaryOp(arg, t, TAC_ARG::getAsConstant(0, t.type), IROpertion::EQUAL);
    }
    else {
        out << arg << " = " << t << " ^ -1";
        ir.AddBinaryOp(arg, t, TAC_ARG::getAsConstant(-1, t.type), IROpertion::BITWISE_XOR);
    }
    out.endline();
    FreeIfTemporary(t);
    return arg;
}

std::any IRGen::visitUnaryPN(bsParser::UnaryPNContext* context)
{
    TAC_ARG t = visitExpr(context->expr());
    if (context->op->getText() == "+") {
        return t;
    }
    else {
        TAC_ARG arg = GetTemporaryTAC(t.type);
        out << arg << " = 0 - " << t;
        out.endline();
        ir.AddBinaryOp(arg, TAC_ARG::getAsConstant(0, t.type), t, IROpertion::SUB);
        FreeIfTemporary(t);
        return arg;
    }
}

std::any IRGen::visitRShift(bsParser::RShiftContext* context)
{
    TAC_ARG tl = visitExpr(context->left);
    TAC_ARG tr = visitExpr(context->right);
    FreeIfTemporary(tr);
    FreeIfTemporary(tl);

    TAC_ARG tmp = GetTemporaryTAC(SelectCommonType(tl.type, tr.type));
    out << tmp << " = " << tl << " >> " << tr;
    out.endline();
    ir.AddBinaryOp(tmp, tl, tr, IROpertion::SHIFT_RIGHT);

    return tmp;
}

std::any IRGen::visitArgs(bsParser::ArgsContext* context)
{
    std::vector<TAC_ARG> temps;
    for (auto e : context->expr()) {
        TAC_ARG t = visitExpr(e);
        temps.push_back(t);
    }
    for (auto e : temps) {
        out << "arg: " << e.get();
        out.endline();
        ir.AddDeclareFunctionArgument(e.get(), e.type);
    }
    return temps;
}

std::any IRGen::visitType(bsParser::TypeContext* context)
{
    return ptypeMap[context->getText()];
}

std::any IRGen::visitUdef_type(bsParser::Udef_typeContext* context)
{
    Type tp;
    if (context->type())
        tp = std::any_cast<Type>(visit(context->type()));
    else
        tp = _typeMap[context->ID()->getText()];
    return tp;
}

std::any IRGen::visitAlignment(bsParser::AlignmentContext* context)
{
    if (context) {
        return ptypeMap[context->getText()];
    }
    return Type::INT_t;
}

Type IRGen::visitAlign(bsParser::AlignmentContext* context)
{
    if (context) {
        return ptypeMap[context->getText()];
    }
    return Type::INT_t;
}

void IRGen::openScope()
{
    symTable.PushNewScope();
}

void IRGen::addSymbolCurrent(const std::string& name, Type type)
{
    symTable.AddCurrent(name, type, false, 0, nullptr);
}

void IRGen::addGlobalCurrent(const std::string& name, Type type)
{
    symTable.AddGlobal(name, type, false, 0, nullptr);
}

Type IRGen::getSymbolType(const std::string& name)
{
    return symTable.GetVariable(name).type; 
}

TAC_ARG IRGen::visitExpr(bsParser::ExprContext* ctx)
{
    if (ctx->isConst) {
        TAC_ARG arg = GetTemporaryTAC((Type)ctx->eType);
        arg.setAsConstant(ctx->eValue, (Type)ctx->eType);
        return arg;
    }
    return std::any_cast<TAC_ARG>(visit(ctx));
}

TAC_ARG &IRGen::GetTemporaryTAC(Type type)
{
    int idx = freeTemporaries.back();
    freeTemporaries.pop_back();
    TAC_ARG& r = tacTemporaries[idx];
    r.type = type;
	return r;
}

void IRGen::FreeTemporaryTAC(TAC_Temp tmp)
{
	freeTemporaries.push_back(tmp.index);
}

void IRGen::FreeIfTemporary(TAC_ARG& arg)
{
    if (arg.argType == IRARG::TEMP) {
		FreeTemporaryTAC(TAC_Temp(arg.value));
	}
}

std::string IRGen::GetLabel()
{
    lCount++;
    return std::format("L{}", lCount);
}

std::string IRGen::GetStringLabel()
{
    sCount++;
    return std::format("Str{}", sCount);
    return std::string();
}

};