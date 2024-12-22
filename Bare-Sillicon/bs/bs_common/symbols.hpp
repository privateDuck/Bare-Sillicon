#pragma once


#include <string>
#include <format>
#include <vector>
#include <unordered_map>
#include "antlr/bsParser.h"
#include "types.hpp"

namespace bsc {

	static int parseAsciiSequence(const std::string& sequence) {
		// Mapping of escaped characters to their ASCII values
		static std::unordered_map<std::string, int> escapeCharacters = {
			{"'\\n'", 10},  // Newline
			{"'\\t'", 9},   // Horizontal tab
			{"'\\r'", 13},  // Carriage return
			{"'\\b'", 8},   // Backspace
			{"'\\f'", 12},  // Form feed
			{"'\\a'", 7},   // Bell
			{"'\\v'", 11},  // Vertical tab
			{"'\\\\'", 92}, // Backslash
			{"'\\\''", 39},  // Single quote
			{"'\\\"'", 34}  // Double quote
		};

		// Check if the sequence is an escaped character
		if (sequence.size() > 3 && sequence[1] == '\\') {
			// If it's in the escape character map, return the corresponding ASCII value
			if (escapeCharacters.find(sequence) != escapeCharacters.end()) {
				return escapeCharacters[sequence];
			}
			// Handle octal or hexadecimal sequences here if needed (optional)
		}

		// Otherwise, assume it's a single character and return its ASCII value
		if (sequence.size() == 3) {
			return static_cast<int>(sequence[1]);
		}

		// If input is invalid, return -1 (error code)
		return -1;
	}

	enum class StorageLocation {
		LOCAL_STACK,
		LOCAL_REGISTER,
		GLOBAL
	};

	enum class LVAL_TYPE {
		IDENTIFIER,
		DEREFERENCE
	};

	enum class LITERAL_TYPE {
		INT,
		CHAR,
		STRING
	};

	struct VarInfo {
		std::string	name;
		Type type = Type::UINT_t;
		int eValue = 0;
		bool isUsed = false;
		bool isModified = false;
		bool isConstExpr = true;
		bool isTemporaryResident = false;
		int scopeIndex = 0;

		bsParser::Var_declContext* decl_node = nullptr;
		std::vector<bsParser::ExprContext*> assingment_nodes;

		VarInfo() = default;

		VarInfo(const std::string& name, Type t, int init_value, bool isConstExpr, bsParser::Var_declContext* decl, int idx) : 
			name(std::format("{}_{}", name, idx)), type(t), eValue(init_value), isConstExpr(isConstExpr), decl_node(decl), scopeIndex(idx) {}
		
		VarInfo(const std::string& name, Type t, int init_value, bool isUsed, bool isMod, bool isConstExpr, bool isTempRes, bsParser::Var_declContext* decl, int idx) :
			name(std::format("{}_{}", name, idx)),type(t), eValue(init_value), isUsed(isUsed), isModified(isMod), isConstExpr(isConstExpr), isTemporaryResident(isTempRes), decl_node(decl), scopeIndex(idx) {}

	};

	struct funcInfo {
		Type returnType;
		std::vector<Type> argTypes;
		std::vector<std::string> argNames;
		std::string name;
		int localStackSize;
	};

	struct exprResult {
		Type type;
		bool isConstExpr;
		bool isDC;
		long long value;
		explicit exprResult(Type type) : type(type), isConstExpr(false), isDC(false), value(0) {}
		exprResult(Type type, bool isConstExpr, bool isdc, long long value) : type(type), isConstExpr(isConstExpr), isDC(isdc), value(value) {}
	};

	struct arrElement {
		Type type;
		int index;
		int eValue; // if any
	};

	struct lvalInfo {
		Type type;
		LVAL_TYPE lvalType;
		std::string name;
	};

	struct initLiteral {
		LITERAL_TYPE type;
		int i;
		char c;
		std::string s;
	};

	struct VarGraph {
		std::unordered_map<std::string, VarInfo> _vars;
		VarGraph* _parent;

		bool AddVariable(const std::string& name, Type type, bool isConstExpr, bool isTempRes, int initVal, bsParser::Var_declContext* ctx, int idx) {
			if (!HasVariable(name)) {
				_vars[name] = VarInfo(name, type, initVal, false, false, isConstExpr, isTempRes, ctx, idx);
				return true;
			}
			else {
				return false;
			}
		}
		bool HasVariable(const std::string& name) {
			if (_vars.find(name) != _vars.end()) {
				return true;
			}
			for (VarGraph* v = _parent; v != nullptr; v = v->_parent) {
				if (v->_vars.find(name) != v->_vars.end()) {
					return true;
				}
			}
			return false;
		}
		VarGraph* FindScope(const std::string& name) {
			if (_vars.find(name) != _vars.end()) {
				return this;
			}
			for (VarGraph* v = _parent; v != nullptr; v = v->_parent) {
				if (v->_vars.find(name) != v->_vars.end()) {
					return v;
				}
			}
			return nullptr;
		}
		void ModifyVariable(const std::string& name) {
			VarGraph* v = FindScope(name);
			if (v != nullptr) {
				v->_vars[name].isModified = true;
			}
		}
		void UseVariable(const std::string& name) {
			VarGraph* v = FindScope(name);
			if (v != nullptr) {
				v->_vars[name].isUsed = true;
			}
		}
		void SetValue(const std::string& name, int value) {
			VarGraph* v = FindScope(name);
			if (v != nullptr) {
				v->_vars[name].eValue = value;
			}
		}
		VarInfo& GetVariable(const std::string& name) {
			VarGraph* v = FindScope(name);
			if (v != nullptr) {
				return v->_vars[name];
			}
			std::cout << std::format("Could not find variable {}", name) << std::endl;
			throw std::runtime_error("Variable not found");
		}
	};

	class VarTable {
	public:
		VarTable() : _globl(new VarGraph()), _curr(_globl) {
			_globl->_parent = nullptr;
			_scopes.push_back(_globl);
		}
		~VarTable() {
			for (auto ptr : _scopes) {
				delete ptr;
			}
		}

		bool AddGlobal(const std::string& name, Type type, bool isConstExpr, int initVal, bsParser::Var_declContext* ctx) {
			return _globl->AddVariable(name, type, isConstExpr, false, initVal, ctx, 0);
		}

		bool AddCurrent(const std::string& name, Type type, bool isConstExpr, int initVal, bsParser::Var_declContext* ctx) {
			return _curr->AddVariable(name, type, isConstExpr, false, initVal, ctx, _currentScopeIndex);
		}

		bool AddTemporaryResident(const std::string& name, Type type, bool isConstExpr, long long initVal, long long tempIdx) {
			return _curr->AddVariable(name, type, isConstExpr, true, initVal, nullptr, tempIdx);
		}

		bool HasVariable(const std::string& name) {
			return _curr->HasVariable(name);
		}

		bool IsVariableGlobal(const std::string& name) {
			return _globl->HasVariable(name);
		}

		VarInfo& GetVariable(const std::string& name) {
			return _curr->GetVariable(name);
			throw std::runtime_error("Variable not found");
		}

		VarGraph* FindScopeOf(const std::string& name) {
			return _curr->FindScope(name);
		}

		void PushNewScope() {
			VarGraph* gp = new VarGraph();
			_currentScopeIndex++;
			gp->_parent = _curr;
			_curr = gp;
			_scopes.push_back(gp);
			if (_pshtr) {
				_curr->AddVariable(_nxt.name, _nxt.type, _nxt.isConstExpr, false, _nxt.eValue, _nxt.decl_node, _currentScopeIndex);
				_pshtr = false;
			}
		}

		bool IsGlobalScope() {
			return _curr == _globl;
		}

		void PopLastScope() {
			if (IsGlobalScope()) {
				return;
			}
			_curr = _curr->_parent;
		}

		const std::unordered_map<std::string, VarInfo>& GetCurrentScopeVariables() const {
			return _curr->_vars;
		}

		void PushToNextScope(const std::string& name, Type type, bool isConstExpr, int initVal, bsParser::Var_declContext* ctx) {
			_nxt = VarInfo(name, type, initVal, isConstExpr, ctx, _currentScopeIndex);
			_pshtr = true;
		}
		
	private:
		VarGraph* _globl;
		VarGraph* _curr;
		int _currentScopeIndex = 0;
		VarInfo _nxt;
		bool _pshtr = false;
		std::vector<VarGraph*> _scopes;
	};

	class Symbol
	{
	public:
		Symbol(std::string name, Type type) : name(name), type(type) {}
		
		std::string getName() const { return name; }
		Type getType() const { return type; }



		// Optimization
		void optSetEValue(int value) { eValue = value; }
		int optGetEValue() const { return eValue; }

		void optSetUsed(bool used) { isUsed = used; }
		bool optIsUsed() const { return isUsed; }

		void optSetConst(bool isConst) { this->isConst = isConst; }
		bool optIsConst() const { return isConst; }
	private:
		std::string name;
		Type type;
		int locationBase; // Base register (SP, BP, GP, etc..)
		int locationIdentifier; // Is an offset from a pointer (SP - 4, BP + 8, GP - 12, etc..)
		StorageLocation currLocation; // Where the symbol is currently stored
		StorageLocation genLocation; // Where the symbol is generally stored

		// Used for optimization
		int eValue = 0;
		bool isUsed = false, isConst = true;
	};

	class SymbolLink
	{
		SymbolLink* parent;
		std::vector<SymbolLink*> children;
		std::unordered_map<std::string, Symbol> symbols;

		bool AddLocalVariable(const std::string& name);
	};

	class SymbolTable
	{

	};
};