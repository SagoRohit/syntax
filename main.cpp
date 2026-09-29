#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "MyVisitor.h"

using namespace antlr4;
using namespace std;

ofstream lexLogFile; // used by Lexer.g4

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    // Count total lines
    int totalLines = 0;
    {
        ifstream countFile(argv[1]);
        string line;
        while (getline(countFile, line)) totalLines++;
        countFile.close();
    }

    ANTLRInputStream input(inputFile);
    CSubsetLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CSubsetParser parser(&tokens);

    parser.removeErrorListeners();

    CSubsetParser::StartContext* tree = parser.start();

    MyVisitor visitor;
    visitor.totalLines = totalLines;
    visitor.visit(tree);

    inputFile.close();
    if (lexLogFile.is_open()) lexLogFile.close();
    return 0;
}
