#pragma once
#include <sstream>
#include <string>

class IndentedStream {
public:
    IndentedStream() = default;

    template <typename T>
    IndentedStream& operator<<(const T& t) {
        currentLine << t;
        return *this;
    }

    void indent() {
        ++indentLevel;
    }

    void unindent() {
        --indentLevel;
    }

    void newline() {
        applyIndent();
        out << currentLine.str() << '\n';
        currentLine.clear();
    }

    void empty() {
        out << '\n';
    }

    void endline() {
        applyIndent();
        out << currentLine.str() << '\n';
        currentLine.str("");
    }

    std::string str() {
        return out.str();
    }
private:
    std::ostringstream out;
    std::ostringstream currentLine;
    int indentLevel = 0;

    void applyIndent() {
        for (int i = 0; i < indentLevel; i++) {
            out << "    ";
        }
    }
};