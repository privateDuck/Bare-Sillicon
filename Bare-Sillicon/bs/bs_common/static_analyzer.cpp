#include "static_analyzer.hpp"

namespace bsc{

    static bool isPowerOfTwo(int x) {
        return x && (!(x & (x - 1)));
    }

std::any StaticVisitor::visitProgram(bsParser::ProgramContext* context)
{
    return visitChildren(context);
}

std::any StaticVisitor::visitDeclaration(bsParser::DeclarationContext* context)
{
    return visitChildren(context);
}

std::any StaticVisitor::visitTypedef(bsParser::TypedefContext* context)
{
    Type t = std::any_cast<Type>(visit(context->type()));
    _typeMap[context->ID()->getText()] = t;
    return std::any();
}

std::any StaticVisitor::visitGlobal(bsParser::GlobalContext* context)
{
    if (!scopeTable.HasVariable(context->ID()->getText())) {
        auto global_expr_result = visitExpr(context->expr());
        if (!global_expr_result.isConstExpr) logger.LogError(context, "Global variable must be initialized with a constant expression");

        scopeTable.AddGlobal(context->ID()->getText(), global_expr_result.type, global_expr_result.isConstExpr, global_expr_result.value, nullptr);
	}
    else {
        logger.LogError(context, "Redifinition of global variable: {}", context->ID()->getText());
    }
    return std::any();
}

std::any StaticVisitor::visitFunction(bsParser::FunctionContext* context)
{
    _fnReturned = false;
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    currentFunctionReturnType = t;
    _currentFunction = context->ID()->getText();
    funcInfo fi;
	fi.returnType = t;
    fi.localStackSize = 0;
    fi.name = _currentFunction;
    _functions[_currentFunction] = fi;

    /*VarGraph* newScope = new VarGraph();
    newScope->_parent = _currentScope;
    _currentScope = newScope;
    _scopes.push_back(newScope);*/

    scopeTable.PushNewScope();
    
    if (context->params())
        visit(context->params());

    visit(context->block());

    scopeTable.PopLastScope();
    return std::any();
}

std::any StaticVisitor::visitParams(bsParser::ParamsContext* context)
{
    for (auto p : context->param_decl()) {
		visit(p);
	}
    return std::any();
}

std::any StaticVisitor::visitParam_decl(bsParser::Param_declContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    scopeTable.AddCurrent(context->ID()->getText(), t, false, 0, nullptr);
    _functions[_currentFunction].argTypes.push_back(t);
    _functions[_currentFunction].argNames.push_back(context->ID()->getText());
    return std::any();
}

std::any StaticVisitor::visitCompound(bsParser::CompoundContext* context)
{
    /*VarGraph* newScope = new VarGraph();
    newScope->_parent = _currentScope;
    _currentScope = newScope;
    _scopes.push_back(newScope);*/
    scopeTable.PushNewScope();

    visit(context->block());

    scopeTable.PopLastScope();
    return std::any();
}

std::any StaticVisitor::visitBlock(bsParser::BlockContext* context)
{
    for (auto context : context->statement())
    {
        if (!context->return_())
            context->isDead = _fnReturned || _bcEnc || _definiteGoto;

        if (context->var_decl()) {
            visit(context->var_decl());
        }
        else if (context->array_decl()) {
            visit(context->array_decl());
        }
        else if (context->expr()) {
            visit(context->expr());
        }
        else if (context->goto_label()) {
			visit(context->goto_label());
		}
		else if (context->goto_()) {
			visit(context->goto_());
		}
        else if (context->goto_if()) {
            visit(context->goto_if());
        }
        else if (context->compound()) {
            visit(context->compound());
        }
        else if (context->if_()) {
            visit(context->if_());
        }
        else if (context->ifelse()) {
            visit(context->ifelse());
        }
        else if (context->while_()) {
            visit(context->while_());
        }
        else if (context->for1()) {
            visit(context->for1());
        }
        else if (context->for2()) {
            visit(context->for2());
        }
        else if (context->return_()) {
            visit(context->return_());
        }
        else if (context->break_()) {
            visit(context->break_());
            _bcEnc = true;
        }
        else if (context->continue_()) {
            visit(context->continue_());
            _bcEnc = true;
        }
    }
    _bcEnc = false;

    for (const auto& [id, data] : scopeTable.GetCurrentScopeVariables()) {
        for (bsParser::ExprContext* pn : data.assingment_nodes)
            pn->isDead = true;
        if (!data.isUsed && data.isConstExpr && data.decl_node) data.decl_node->isDead = true; // dead code elimination
    }
    // value is constant and is never referenced
    // value is dynamic
    return nullptr;
}

std::any StaticVisitor::visitStatement(bsParser::StatementContext* context)
{
    return visitChildren(context);
}

std::any StaticVisitor::visitVar_decl(bsParser::Var_declContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    exprResult rr = visitExpr(context->expr());

    if (scopeTable.HasVariable(context->ID()->getText()))
    {
		logger.LogError(context, "Redifinition of variable: {}", context->ID()->getText());
	}

    scopeTable.AddCurrent(context->ID()->getText(), t, rr.isConstExpr, rr.value, context);

    logger.CheckWarning(ShouldCastWarn(rr.type, t), context, "Assignment of an expression with type {} to a variable with type {}", getTypeName(rr.type), getTypeName(t));

    return std::any();
}

std::any StaticVisitor::visitArray_decl(bsParser::Array_declContext* context)
{
    Type t = std::any_cast<Type>(visit(context->udef_type()));
    int size = std::stoll(context->UNSIGNED_INT()->getText());
    logger.CheckError(size <= 0, context, "Array size must be greater than 0");
    
    scopeTable.AddCurrent(context->ID()->getText(), t, false, 0, nullptr);
    if (context->array_initializer()) {
        visit(context->array_initializer());
    }
    return std::any();
}

std::any StaticVisitor::visitArray_initializer(bsParser::Array_initializerContext* context)
{
    for (auto init : context->init_element()) {
		visit(init);
	}
    return std::any();
}

std::any StaticVisitor::visitInitIntLiteral(bsParser::InitIntLiteralContext* context)
{
    int value = std::stoll(context->atom->getText());
    initLiteral il;
    il.type = LITERAL_TYPE::INT;
    il.i = value;
    return il;
}

std::any StaticVisitor::visitInitCharLiteral(bsParser::InitCharLiteralContext* context)
{
    char c = parseAsciiSequence(context->CHAR()->getText());
    initLiteral il;
    il.type = LITERAL_TYPE::CHAR;
    il.c = c;
    return il;
}

std::any StaticVisitor::visitInitStringLiteral(bsParser::InitStringLiteralContext* context)
{
    std::string txt = context->STRING_LITERAL()->getText();
	_stringTable.emplace_back(txt.substr(1, txt.size() - 2));
	initLiteral il;
	il.type = LITERAL_TYPE::STRING;
	il.s = _stringTable.back();
	return il;
}

std::any StaticVisitor::visitGoto_label(bsParser::Goto_labelContext* context)
{
    if (scopeTable.IsGloablScope()) // Global Scope
    {
        logger.LogError(context, "Cannot declare goto labels outside of a function body");
    }
    
    _definiteGoto = false;
    return std::any();
}

std::any StaticVisitor::visitIf(bsParser::IfContext* context)
{
    auto rr = visitExpr(context->expr());
    context->expr()->isDc = rr.isDC;
    if (rr.isConstExpr) {
		context->expr()->isConst = true;
		context->expr()->eValue = rr.value;
	}
    visit(context->statement());
    return std::any();
}

std::any StaticVisitor::visitIfelse(bsParser::IfelseContext* context)
{
    auto rr = visitExpr(context->expr());
    context->expr()->isDc = rr.isDC;
    if (rr.isConstExpr) {
        context->expr()->isConst = true;
        context->expr()->eValue = rr.value;
    }
    visit(context->pos);
	visit(context->neg);
    return std::any();
}

std::any StaticVisitor::visitWhile(bsParser::WhileContext* context)
{
    auto rr = visitExpr(context->expr());
    context->expr()->isDc = rr.isDC;
    if (rr.isConstExpr) {
        if (rr.value == 0 && context->statement()) {
            context->statement()->isDead = true;
        }
    }

    visit(context->statement());

    return std::any();
}

std::any StaticVisitor::visitFor1(bsParser::For1Context* context)
{
    if (context->var_decl()) {
        Type t = std::any_cast<Type>(visit(context->var_decl()->udef_type()));
        exprResult rr = visitExpr(context->var_decl()->expr());
        scopeTable.AddCurrent(context->var_decl()->ID()->getText(), t, rr.isConstExpr, rr.value, context->var_decl());

        logger.CheckWarning(t == rr.type, context, "Assignment of an expression with type {} to a variable with type {}", getTypeName(rr.type), getTypeName(t));
    }

    if (context->end_oper) {
        auto rr = visitExpr(context->end_oper);
        context->end_oper->isDc = rr.isDC;
        if (rr.isConstExpr) {
            context->end_oper->isConst = true;
			context->end_oper->eValue = rr.value;
        }
    }
    
    if (context->cond) {
        auto rr = visitExpr(context->cond);
        context->cond->isDc = rr.isDC;
        if (rr.isConstExpr) {
            context->cond->isConst = true;
            context->cond->eValue = rr.value;
            if (rr.value == 0 && context->statement()) {
                context->statement()->isDead = true;
            }
        }
    }

    visit(context->statement());

    return std::any();
}

std::any StaticVisitor::visitFor2(bsParser::For2Context* context)
{
    // should use forward scope

    std::string id = context->ID()->getText();
    scopeTable.PushToNextScope(id, Type::INT_t, false, std::stoll(context->start_val->getText()), nullptr);
    auto sv = visitExpr(context->start_val);
    auto ev = visitExpr(context->end_val);

    context->start_val->isDc = sv.isDC;
    context->end_val->isDc = ev.isDC;

    if (sv.isConstExpr) {
		context->start_val->isConst = true;
		context->start_val->eValue = sv.value;
	}
    if (ev.isConstExpr) {
        context->end_val->isConst = true;
        context->end_val->eValue = ev.value;
    }

    if (sv.isConstExpr && ev.isConstExpr && sv.value > ev.value) {
        // doesn't execute
        if (context->statement())
            context->statement()->isDead = true;
    }

    logger.CheckError(context->statement() == nullptr, context, "For loop must have a statement");

    visit(context->statement());
    return std::any();
}

std::any StaticVisitor::visitGoto(bsParser::GotoContext* context)
{
    _definiteGoto = true;
    return std::any();
}

std::any StaticVisitor::visitGoto_if(bsParser::Goto_ifContext* context)
{
    auto rr = visitExpr(context->cond);
    if (rr.isConstExpr && rr.value == 0) context->state = 2;
    else if (rr.isConstExpr && rr.value != 0) { context->state = 1; _definiteGoto = true; }
    return std::any();
}

std::any StaticVisitor::visitReturn(bsParser::ReturnContext* context)
{
    auto rr = visitExpr(context->expr());
    if (ShouldCastWarn(rr.type, currentFunctionReturnType))
    {
		logger.LogWarning(context, "Return type mismatch");
	}

    if (rr.isConstExpr) {
		context->expr()->isConst = true;
		context->expr()->eValue = rr.value;
	}
    _fnReturned = true;
    return std::any();
}

std::any StaticVisitor::visitBreak(bsParser::BreakContext* context)
{
    _bcEnc = true;
    return std::any();
}

std::any StaticVisitor::visitContinue(bsParser::ContinueContext* context)
{
    _bcEnc = true;
    return std::any();
}

std::any StaticVisitor::visitPreID(bsParser::PreIDContext* context)
{
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    if (context->op->getText() == "++") {
		sym.eValue++;
	}
    else {
		sym.eValue--;
	}
    context->eType = (int)sym.type;
    context->isConst = sym.isConstExpr;
    context->eValue = sym.eValue;
    context->isDc = false;

    return exprResult(sym.type, sym.isConstExpr, false, sym.eValue);
}

std::any StaticVisitor::visitMulDiv(bsParser::MulDivContext* context)
{
    auto left = std::any_cast<exprResult>(visit(context->left));
    auto right = std::any_cast<exprResult>(visit(context->right));

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        if (context->op->getText() == "*") {
            context->eValue = left.value * right.value;
        }
        else {
            context->eValue = left.value / right.value;
        }
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, true, context->eValue);
    }
    else if (left.isConstExpr && left.value == 0 && context->op->getText() == "*") {
        context->isConst = true;
        context->eValue = 0;
        context->isDc = true;
        return exprResult(Type::INT_t, true, true, 0);
    }
    else if (right.isConstExpr && right.value == 0 && context->op->getText() == "*") {
        context->isConst = true;
        context->eValue = 0;
        context->isDc = true;
        return exprResult(Type::INT_t, true, true, 0);
    }
    else if (right.isConstExpr && right.value == 1) {
        context->isConst = left.isConstExpr;
        context->eValue = left.value;
        context->isDc = left.isDC;
        return exprResult(left.type, left.isConstExpr, left.isDC, left.value);
    }
    else if (left.isConstExpr && left.value == 1) {
        context->isConst = right.isConstExpr;
        context->eValue = right.value;
        context->isDc = right.isDC;
        return exprResult(right.type, right.isConstExpr, left.isDC, left.value);
    }
    else if (left.isConstExpr && left.value == 0 && context->op->getText() == "/") {
        context->isConst = true;
        context->eValue = 0;
        context->isDc = true;
        return exprResult(left.type, true, true, 0);
    }
    else if (right.isConstExpr && right.value == 1 && context->op->getText() == "/") {
        context->isConst = left.isConstExpr;
        context->eValue = left.value;
        context->isDc = left.isDC;
        return exprResult(left.type, left.isConstExpr, left.isDC, left.value);
    }
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitAddressOf(bsParser::AddressOfContext* context)
{
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isUsed = true;
    return exprResult(Type::UINT_t, false, false, 0);
}

std::any StaticVisitor::visitAddSub(bsParser::AddSubContext* context)
{
    auto lr = visitExpr(context->left);
    auto rr = visitExpr(context->right);

    Type tp = SelectCommonType(lr.type, rr.type);
    context->eType = (int)tp;

    if (lr.isConstExpr && rr.isConstExpr) {
        context->isConst = true;
        if (context->op->getText() == "+") {
			context->eValue = lr.value + rr.value;
		}
        else {
            context->eValue = lr.value - rr.value;
		}
        context->isDc = lr.isDC && rr.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
	}
    else if (rr.isConstExpr && rr.value == 0){
        context->isConst = lr.isConstExpr;
        context->eValue = lr.value;
        context->isDc = lr.isDC;
        return exprResult(lr.type, lr.isConstExpr, lr.isDC, lr.value);
	}
    else if (lr.isConstExpr && lr.value == 0) {
		context->isConst = rr.isConstExpr;
		context->eValue = rr.value;
		context->isDc = rr.isDC;
		return exprResult(rr.type, rr.isConstExpr, rr.isDC, rr.value);
    }
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitLogicAnd(bsParser::LogicAndContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
		context->isConst = true;
		context->eValue = left.value && right.value;
		context->isDc = left.isDC && right.isDC;
		return exprResult(tp, true, context->isDc, context->eValue);
	}
    else if (right.isConstExpr && left.value == 1) {
    	context->isConst = right.isConstExpr;
        context->eValue = right.value;
        context->isDc = right.isDC;
        return exprResult(right.type, right.isConstExpr, right.isDC, right.value);
    }
    else if (left.isConstExpr && right.value == 1) {
		context->isConst = left.isConstExpr;
		context->eValue = left.value;
		context->isDc = left.isDC;
		return exprResult(left.type, left.isConstExpr, left.isDC, left.value);
	}

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitStaticCast(bsParser::StaticCastContext* context)
{
    Type castTo = std::any_cast<Type>(visit(context->udef_type()));
    auto expr = visitExpr(context->expr());
    Type castFrom = expr.type;

    if (castTo == castFrom) logger.LogInfo(context, "Unnecessary cast from {} to {}", getTypeName(castFrom), getTypeName(castTo));
    else if (isChar(castTo) && isInt(castFrom)) logger.LogWarning(context, "Possible loss of data from {} to {}", getTypeName(castFrom), getTypeName(castTo));
    
    long long castedValue = staticCast(expr.value, castFrom, castTo, MACHINE_WORD_SIZE);
    
    context->eType = (int)castTo;
    context->isConst = expr.isConstExpr;
    context->eValue = castedValue;
    context->isDc = expr.isDC;

    return exprResult(castTo, expr.isConstExpr, expr.isDC, castedValue);
}

std::any StaticVisitor::visitReinterpretCast(bsParser::ReinterpretCastContext* context)
{
    Type castTo = std::any_cast<Type>(visit(context->udef_type()));
    auto expr = visitExpr(context->expr());
    Type castFrom = expr.type;

    if (castTo == castFrom) logger.LogInfo(context, "Unnecessary cast from {} to {}", getTypeName(castFrom), getTypeName(castTo));
    else if (isChar(castTo) && isInt(castFrom)) logger.LogWarning(context, "Possible loss of data from casting {} to {}", getTypeName(castFrom), getTypeName(castTo));

    long long castedValue = reinterpretCast(expr.value, castFrom, castTo, MACHINE_WORD_SIZE);

    context->eType = (int)castTo;
    context->isConst = expr.isConstExpr;
    context->eValue = castedValue;
    context->isDc = expr.isDC;

    return exprResult(castTo, expr.isConstExpr, expr.isDC, castedValue);
}

std::any StaticVisitor::visitDereference(bsParser::DereferenceContext* context)
{
    auto r = visitExpr(context->expr());

    if (r.isConstExpr) {
        if (r.value < 0)
            logger.LogError(context, "A pointer must be a non-negative integer");
        r.type = Type::UINT_t;
        context->expr()->eType = (int)Type::UINT_t;
    }
    else {
        logger.CheckWarning(isChar(r.type), context, "CAUTION: Usage of single byte address");
        logger.CheckWarning(r.type == Type::INT_t, context, "CAUTION: Address could be negative");
    }

    Type alignType = visitAlign(context->alignment());
    return exprResult(alignType, false, false, 0);
}

std::any StaticVisitor::visitCall(bsParser::CallContext* context)
{
    visit(context->args());
    funcInfo& fi = _functions[context->ID()->getText()];
    return exprResult(fi.returnType, false, false, 0);
}

std::any StaticVisitor::visitLogicOr(bsParser::LogicOrContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        context->eValue = left.value || right.value;
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }
    else if (right.isConstExpr && left.value == 0) {
        context->isConst = right.isConstExpr;
        context->eValue = right.value;
        context->isDc = right.isDC;
        return exprResult(right.type, right.isConstExpr, right.isDC, right.value);
    }
    else if (left.isConstExpr && right.value == 0) {
        context->isConst = left.isConstExpr;
        context->eValue = left.value;
        context->isDc = left.isDC;
        return exprResult(left.type, left.isConstExpr, left.isDC, left.value);
    }

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitMod(bsParser::ModContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
		context->isConst = true;
		context->eValue = left.value % right.value;
		context->isDc = left.isDC && right.isDC;
		return exprResult(tp, true, context->isDc, context->eValue);
	}
    else if (right.isConstExpr && right.value == 1) {
		context->isConst = left.isConstExpr;
		context->eValue = 0;
		context->isDc = left.isDC;
		return exprResult(left.type, left.isConstExpr, left.isDC, 0);
	}
    else if (left.isConstExpr && left.value == 0) {
		context->isConst = true;
		context->eValue = 0;
		context->isDc = true;
		return exprResult(left.type, true, true, 0);
	}
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitBitXor(bsParser::BitXorContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        context->eValue = left.value ^ right.value;
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitBitOr(bsParser::BitOrContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        context->eValue = left.value | right.value;
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitID(bsParser::IDContext* context)
{
    bool exist = scopeTable.HasVariable(context->getText());

    if (!exist) {
        logger.LogError(context, "Use of undefined symbol: {}", context->getText());
        return exprResult(Type::INT_t, false, false, 0);
	}

    VarInfo& vi = scopeTable.GetVariable(context->getText());

    context->isConst = vi.isConstExpr;
    context->eValue = vi.eValue;
    context->eType = (int)vi.type;
    context->isDc = false;
    return exprResult(vi.type, vi.isConstExpr, false, vi.eValue);
}

std::any StaticVisitor::visitIntegerLiteral(bsParser::IntegerLiteralContext* context)
{
    int value = std::stoll(context->atom->getText());
    Type t = value < 0 ? Type::INT_t : Type::UINT_t;
    context->isConst = true;
    context->eValue = value;
    context->isDc = true;
    context->eType = (int)(value < 0 ? Type::INT_t : Type::UINT_t);
    return exprResult(t, true, true, value);
}

std::any StaticVisitor::visitCharLiteral(bsParser::CharLiteralContext* context)
{
    std::string txt = context->CHAR()->getText();
    int value = parseAsciiSequence(txt);

    if (value < 0 || value > 127) logger.LogError(context, "Invalid character literal: {}", txt);

    context->isConst = true;
    context->eValue = value;
    context->isDc = true;
    context->eType = (int)Type::CHAR_t;
    return exprResult(Type::CHAR_t, true, true, value);
}

std::any StaticVisitor::visitStringLiteral(bsParser::StringLiteralContext* context)
{
    std::string txt = context->STRING_LITERAL()->getText();
	_stringTable.emplace_back(txt.substr(1, txt.size() - 2));
	context->isConst = false;
	context->eValue = _stringTable.size() - 1;
	context->isDc = false;
    context->eType = (int)Type::UINT_t;
	return exprResult(Type::UINT_t, false, false, _stringTable.size() - 1);
}

std::any StaticVisitor::visitLShift(bsParser::LShiftContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);
    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        context->eValue = left.value << right.value;
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitGL(bsParser::GLContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);
    Type tp = SelectCommonType(left.type, right.type);

    if (left.isConstExpr && right.isConstExpr) {
		context->isConst = true;
        if (context->op->getText() == ">") {
			context->eValue = left.value > right.value;
		}
        else {
			context->eValue = left.value < right.value;
		}
		context->isDc = left.isDC && right.isDC;
		return exprResult(tp, true, context->isDc, context->eValue);
	}
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitEqNeq(bsParser::EqNeqContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        if (context->op->getText() == "==") {
            context->eValue = left.value == right.value;
        }
        else {
            context->eValue = left.value != right.value;
        }
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitDSimpleAssign(bsParser::DSimpleAssignContext* context)
{
    auto r = visitExpr(context->expr());
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isConstExpr = sym.isConstExpr && r.isConstExpr;
    sym.eValue = r.value;
    sym.isModified = true;
    sym.assingment_nodes.push_back(context);

    logger.CheckWarning(ShouldCastWarn(r.type, sym.type), context, "Assignment of expression with type {} to a variable with type {}", getTypeName(r.type), getTypeName(sym.type));

    context->eValue = r.value;
    context->isConst = sym.isConstExpr;
    context->isDc = r.isDC;
    context->eType = (int)sym.type;

    return exprResult(SelectCommonType(sym.type, r.type), sym.isConstExpr, r.isDC, r.value);
}

std::any StaticVisitor::visitDAddSubCompAssign(bsParser::DAddSubCompAssignContext* context)
{
    auto r = visitExpr(context->expr());
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isConstExpr = sym.isConstExpr && r.isConstExpr;
    if (context->cop->getText() == "+=")
		sym.eValue += r.value;
	else
		sym.eValue -= r.value;

    sym.isModified = true;
    sym.assingment_nodes.push_back(context);

    logger.CheckWarning(ShouldCastWarn(r.type, sym.type), context, "Compound assignment of expression with type {} to a variable with type {}", getTypeName(r.type), getTypeName(sym.type));

    context->eValue = sym.eValue;
    context->isConst = sym.isConstExpr;
    context->isDc = false;
    context->eType = (int)sym.type;

    return exprResult(SelectCommonType(sym.type, r.type), sym.isConstExpr, false, sym.eValue);
}

std::any StaticVisitor::visitDMulDivModCompAssign(bsParser::DMulDivModCompAssignContext* context)
{
    auto r = visitExpr(context->expr());
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isConstExpr = sym.isConstExpr && r.isConstExpr;
    if (context->cop->getText() == "*=")
        sym.eValue *= r.value;
    else if (context->cop->getText() == "/=")
        sym.eValue /= r.value;
	else
		sym.eValue %= r.value;

    sym.isModified = true;
    sym.assingment_nodes.push_back(context);

    logger.CheckWarning(ShouldCastWarn(r.type, sym.type), context, "Assignment of expression with type {} to a variable with type {}", getTypeName(r.type), getTypeName(sym.type));

    context->eValue = sym.eValue;
    context->isConst = sym.isConstExpr;
    context->isDc = false;
    context->eType = (int)sym.type;

    return exprResult(SelectCommonType(sym.type, r.type), sym.isConstExpr, false, sym.eValue);
}

std::any StaticVisitor::visitDLSRSCompAssign(bsParser::DLSRSCompAssignContext* context)
{
    auto r = visitExpr(context->expr());
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isConstExpr = sym.isConstExpr && r.isConstExpr;
    if (context->cop->getText() == "<<=")
		sym.eValue <<= r.value;
	else
		sym.eValue >>= r.value;

    sym.isModified = true;
    sym.assingment_nodes.push_back(context);

    logger.CheckWarning(ShouldCastWarn(r.type, sym.type), context, "Assignment of expression with type {} to a variable with type {}", getTypeName(r.type), getTypeName(sym.type));
    
    context->eValue = sym.eValue;
    context->isConst = sym.isConstExpr;
    context->isDc = false;
    context->eType = (int)sym.type;

    return exprResult(SelectCommonType(sym.type, r.type), sym.isConstExpr, false, sym.eValue);
}

std::any StaticVisitor::visitDAndXorOrCompAssign(bsParser::DAndXorOrCompAssignContext* context)
{
    auto r = visitExpr(context->expr());
    auto& sym = scopeTable.GetVariable(context->ID()->getText());
    sym.isConstExpr = sym.isConstExpr && r.isConstExpr;
    if (context->cop->getText() == "&=")
		sym.eValue &= r.value;
	else if (context->cop->getText() == "^=")
		sym.eValue ^= r.value;
    else
        sym.eValue |= r.value;

    sym.isModified = true;
    sym.assingment_nodes.push_back(context);

    logger.CheckWarning(ShouldCastWarn(r.type, sym.type), context, "Assignment of expression with type {} to a variable with type {}", getTypeName(r.type), getTypeName(sym.type));

    context->eValue = sym.eValue;
    context->isConst = sym.isConstExpr;
    context->isDc = false;
    context->eType = (int)sym.type;

    return exprResult(SelectCommonType(sym.type, r.type), sym.isConstExpr, false, sym.eValue);
}

std::any StaticVisitor::visitISimpleAssign(bsParser::ISimpleAssignContext* context)
{
    auto re = visitExpr(context->e);
    auto rp = visitExpr(context->deref);

    if (rp.type != Type::UINT_t) { logger.LogWarning(context, "A pointer should have the type 'uint'"); }

    if (rp.isConstExpr && rp.value < 0) {
        logger.LogError(context, "A pointer must be a non-negative integer");
    }

    Type alignType = visitAlign(context->alignment());

    logger.CheckError(getTypeSize(alignType) < getTypeSize(re.type), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), getTypeSize(alignType));
    logger.CheckWarning(ShouldCastWarn(re.type, alignType), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), getTypeSize(alignType));
    context->eValue = re.value;
    context->isConst = false;
    context->isDc = false;
    context->eType = (int)alignType;

    return exprResult(alignType, re.isConstExpr, re.isDC, re.value);
}

std::any StaticVisitor::visitIAddSubCompAssign(bsParser::IAddSubCompAssignContext* context)
{
    auto re = visitExpr(context->e);
    auto rp = visitExpr(context->deref);

    if (rp.type != Type::UINT_t) { logger.LogWarning(context, "A pointer should really have the type 'uint'"); }

    if (re.isConstExpr && re.value < 0) {
        logger.LogError(context, "A pointer must be a non-negative integer");
    }

    Type alignType = visitAlign(context->alignment());
    int align_ = getTypeSize(alignType);

    logger.CheckError(align_ < getTypeSize(re.type), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    logger.CheckWarning(ShouldCastWarn(re.type, alignType), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    context->eValue = 0;
    context->isConst = false;
    context->isDc = false;
    context->eType = (int)alignType;

    return exprResult(alignType, false, false, 0);
}

std::any StaticVisitor::visitIMulDivModCompAssign(bsParser::IMulDivModCompAssignContext* context)
{
    auto re = visitExpr(context->e);
    auto rp = visitExpr(context->deref);

    if (rp.type != Type::UINT_t) { logger.LogWarning(context, "A pointer should really have the type 'uint'"); }

    if (re.isConstExpr && re.value < 0) {
        logger.LogError(context, "A pointer must be a non-negative integer");
    }

    Type alignType = visitAlign(context->alignment());
    int align_ = getTypeSize(alignType);

    logger.CheckError(align_ < getTypeSize(re.type), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    logger.CheckWarning(ShouldCastWarn(re.type, alignType), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    context->eValue = 0;
    context->isConst = false;
    context->isDc = false;
    context->eType = (int)alignType;

    return exprResult(alignType, false, false, 0);
}

std::any StaticVisitor::visitILSRSCompAssign(bsParser::ILSRSCompAssignContext* context)
{
    auto re = visitExpr(context->e);
    auto rp = visitExpr(context->deref);

    if (rp.type != Type::UINT_t) { logger.LogWarning(context, "A pointer should really have the type 'uint'"); }

    if (re.isConstExpr && re.value < 0) {
        logger.LogError(context, "A pointer must be a non-negative integer");
    }

    Type alignType = visitAlign(context->alignment());
    int align_ = getTypeSize(alignType);

    logger.CheckError(align_ < getTypeSize(re.type), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    logger.CheckWarning(ShouldCastWarn(re.type, alignType), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    context->eValue = 0;
    context->isConst = false;
    context->isDc = false;
    context->eType = (int)alignType;

    return exprResult(alignType, false, false, 0);
}

std::any StaticVisitor::visitIAndXorOrCompAssign(bsParser::IAndXorOrCompAssignContext* context)
{
    auto re = visitExpr(context->e);
    auto rp = visitExpr(context->deref);

    if (rp.type != Type::UINT_t) { logger.LogWarning(context, "A pointer should really have the type 'uint'"); }

    if (re.isConstExpr && re.value < 0) {
        logger.LogError(context, "A pointer must be a non-negative integer");
    }

    Type alignType = visitAlign(context->alignment());
    int align_ = getTypeSize(alignType);

    logger.CheckError(align_ < getTypeSize(re.type), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    logger.CheckWarning(ShouldCastWarn(re.type, alignType), context, "Assignment of expression with size {}bytes to a memory location with size {}bytes", getTypeSize(re.type), align_);
    context->eValue = 0;
    context->isConst = false;
    context->isDc = false;
    context->eType = (int)alignType;

    return exprResult(alignType, false, false, 0);
}

std::any StaticVisitor::visitGeLe(bsParser::GeLeContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        if (context->op->getText() == ">=") {
            context->eValue = left.value >= right.value;
        }
        else {
            context->eValue = left.value <= right.value;
        }

        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }
    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitBitAnd(bsParser::BitAndContext* context)
{
    auto left = visitExpr(context->left);
    auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
        context->isConst = true;
        context->eValue = left.value & right.value;
        context->isDc = left.isDC && right.isDC;
        return exprResult(tp, true, context->isDc, context->eValue);
    }

    return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitParan(bsParser::ParanContext* context)
{
    auto res = visitExpr(context->expr());
    context->isConst = res.isConstExpr;
    context->eValue = res.value;
    context->isDc = res.isDC;
    context->eType = (int)res.type;
    return res;
}

std::any StaticVisitor::visitBNeg_LNot(bsParser::BNeg_LNotContext* context)
{
    auto r = visitExpr(context->operand);
    context->eType = (int)r.type;

    if (r.isConstExpr) {
		context->isConst = true;
        if (context->op->getText() == "~") {
			context->eValue = ~r.value;
		}
        else {
			context->eValue = !r.value;
		}
		context->isDc = r.isDC;
		return exprResult(r.type, true, context->isDc, context->eValue);
	}
    return exprResult(r.type, false, false, 0);
}

std::any StaticVisitor::visitUnaryPN(bsParser::UnaryPNContext* context)
{
    auto r = visitExpr(context->operand);
    context->eType = (int)r.type;

    if (r.isConstExpr) {
		context->isConst = true;
        if (context->op->getText() == "+") {
			context->eValue = r.value;
		}
        else {
			context->eValue = -r.value;
		}
		context->isDc = r.isDC;
		return exprResult(r.type, true, context->isDc, context->eValue);
	}
    return exprResult(r.type, false, false, 0);
}

std::any StaticVisitor::visitRShift(bsParser::RShiftContext* context)
{
    auto left = visitExpr(context->left);
	auto right = visitExpr(context->right);

    Type tp = SelectCommonType(left.type, right.type);
    context->eType = (int)tp;

    if (left.isConstExpr && right.isConstExpr) {
		context->isConst = true;
		context->eValue = left.value >> right.value;
		context->isDc = left.isDC && right.isDC;
		return exprResult(tp, true, context->isDc, context->eValue);
	}

	return exprResult(tp, false, false, 0);
}

std::any StaticVisitor::visitArgs(bsParser::ArgsContext* context)
{
    for (auto arg : context->expr()) {
		visitExpr(arg);
	}
    return std::any();
}

std::any StaticVisitor::visitType(bsParser::TypeContext* context)
{
    Type tp = ptypeMap[context->getText()];
    return tp;
}

std::any StaticVisitor::visitUdef_type(bsParser::Udef_typeContext* context)
{
    Type tp;
    if (context->type())
        tp = std::any_cast<Type>(visit(context->type()));
    else
        tp = _typeMap[context->ID()->getText()];
	return tp;
}

std::any StaticVisitor::visitAlignment(bsParser::AlignmentContext* context)
{
    std::string txt = context->ALIGN()->getText();
    return ptypeMap[txt];
}

exprResult StaticVisitor::visitExpr(bsParser::ExprContext* context)
{
    auto vr = std::any_cast<exprResult>(visit(context));
    return vr;
}

Type StaticVisitor::visitAlign(bsParser::AlignmentContext* context)
{
    if (context) {
		std::string txt = context->ALIGN()->getText();
		return ptypeMap[txt];
	}
    return Type::INT_t;
}

}; // namespace bsc