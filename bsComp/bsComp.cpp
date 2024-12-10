// bsComp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "antlr4-runtime.h"
#include "antlr4-common.h"
#include "bs/bs_common/static_analyzer.hpp"
#include "bs/bs_common/source_gen.hpp"
#include "bs/bs_IR/ir_stage.hpp"
#include "bs/bs_common/antlr/bsLexer.h"
#include "bs/bs_common/antlr/bsParser.h"

/*

    typedef int MyInt;
int print(int x) {
    // Print integer
    return -1;
}

MyInt globalVar = 42; // Global variable declaration

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1); // Recursive function call
    }
}

int printArray(uint arr) {
    for (int i = 0;; i < 5; ++i) {
        print([arr + i : 1u]); // Assuming `print` is a built-in
    }
    return 0;
}

int main() {
    // Variable declaration
    int x = ~10;
    char c = 'A';
    uint y = 0x10;
    32;
    32*x;
    // Array and initializer
    //byte nums[5] = {1, 2, 3, 4, 5};

    // Arithmetic operations
    x += 5;
    y = x * 2 - 4 / 2;

    // Logical operations
    if (x > 10 && y < 20) {
        ++x;
    } else {
        --y;
    }

    // Loops
    int i = 0;
    while (i < 5) {
        [i:2u] += 1;
        ++i;
    }

    for (int j = 0;; j < 5; ++j) {
        [j:1u] *= 2;
    }

    // Function calls
    //printArray(nums);
    int fact = factorial(5);

    // Goto
    my_label:
    if (x > 15) goto end;
    ++x;

    end:
    return fact;
}

*/

int main()
{
    std::string input = R"(
    int print(int x) {
		int y = 2*x+1;
        y = 21&2; 
        y += x;
        int z = y + x;
        [y:4u] = x;
		return -1;
	}
)";
	antlr4::ANTLRInputStream istr(input);
	bsLexer lex(&istr);
	antlr4::CommonTokenStream tks(&lex);
	bsParser parser(&tks);

	bsParser::ProgramContext* program = parser.program();

	bsc::StaticVisitor sa(2);
	sa.visitProgram(program);

	bsc::IRGen ir;
	ir.visit(program);

    bsc::IR& irep = ir.GetIRObject();
    irep.OptimizationPass1();
	/*SourceGen sg;
	sg.EnableConstantPropogation();
	sg.EnableConstantFolding();
	sg.EnableUnreachableCodeElimination();
	sg.EnableDeadCodeElimination();
	sg.EnableAlgebraicSimplification();
	sg.EnableStrengthReduction();
	sg.visit(program);

	std::cout << sg.GetOutput() << "\n\n\n";*/

	std::cout << sa.GetLogs() << "\n\n";

	std::cout << ir.GetIR() << "\n\n";
	
	std::cout << ir.GetLogs() << "\n\n";
    std::cout << irep.ConvertToString();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
