#pragma once

#include <string>
#include <vector>
#include <format>
#include "symbols.hpp"
#include "antlr4-common.h"

namespace bsc {


	enum class LogType {
		INFO,
		WARNING,
		CRITICAL,
		ERROR
	};

	struct LogEntry {
		int line;
		int column;
		LogType type;
		std::string message;

		LogEntry() : line(-1), column(-1), type(LogType::INFO), message("") {}
		LogEntry(int line, int column, LogType type, const std::string& message) : line(line), column(column), type(type), message(message) {}

		std::string ToString() const {
			return std::format("({}:{}) [{}:] {}", line, column, GetTypeString(type), message);
		}

	private:
		static constexpr std::string GetTypeString(LogType type) {
			switch (type) {
			case LogType::INFO:
				return "INFO";
			case LogType::WARNING:
				return "WARNING";
			case LogType::CRITICAL:
				return "CRITICAL";
			case LogType::ERROR:
				return "ERROR";
			default:
				return "UNKNOWN";
			}
		}
	};

	class Logger {
	public:
		std::string owner;
		std::vector<LogEntry> entries;

		Logger() : owner("") {}
		Logger(const std::string& owner) : owner(owner) {}

		template<typename... Args>
		void LogWarning(antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::WARNING, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
		}

		template<typename... Args>
		void LogError(antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::ERROR, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
		}

		template<typename... Args>
		void LogInfo(antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::INFO, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
		}

		template<typename... Args>
		void LogCritical(antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::CRITICAL, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
		}

		void Log(int line, int column, LogType type, const std::string& message) {
			entries.emplace_back(line, column, type, message);
		}

		// Common checks
		template<typename... Args>
		void CheckError(bool condition, antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			if (condition) {
				entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::ERROR, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
			}
		}

		template<typename... Args>
		void CheckWarning(bool condition, antlr4::ParserRuleContext* ctx, const std::format_string<Args...> fmt_msg, Args&&... args) {
			if (condition) {
				entries.emplace_back(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), LogType::WARNING, std::vformat(fmt_msg.get(), std::make_format_args(args...)));
			}
		}

		void TypeCheckWarning(Type t1, Type t2, antlr4::ParserRuleContext* ctx) {
			if (t1 != t2) {
				LogWarning(ctx, "Type mismatch");
			}
		}

		void GenerateMisalignedDereferenceWarning(antlr4::ParserRuleContext* ctx) {
			LogWarning(ctx, "Misaligned dereference");
		}

		std::string GetLog() const {
			std::string log = "";
			for (auto& entry : entries) {
				log += entry.ToString() + "\n";
			}
			return log;
		}
	};

};