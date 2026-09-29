#pragma once

#include "CSubsetBaseVisitor.h"
#include "SymbolTable.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

struct VisitResult {
    std::string text;
    std::string type; // "int", "float", "void", "error"
    bool isArray = false;
    std::string name; // for variables - the variable name
    // For arguments: stores comma-separated "type:isArray:name" entries
    std::string argInfo;
};

class MyVisitor : public CSubsetBaseVisitor {
public:
    SymbolTable symTable;
    std::ofstream logFile;
    std::ofstream errorFile;
    int errorCount = 0;
    int totalLines = 0;

    // Current function context
    std::string currentFuncName;
    std::string currentFuncReturnType;

    // Pending function params
    std::vector<ParamInfo> pendingParams;
    bool hasPendingParams = false;

    // Current declaration type (for declaration_list)
    std::string currentDeclType;

    MyVisitor() {
        logFile.open("log.txt");
        errorFile.open("error.txt");
    }

    ~MyVisitor() {
        if (logFile.is_open()) logFile.close();
        if (errorFile.is_open()) errorFile.close();
    }

    void logRule(int line, const std::string& rule, const std::string& text);
    void logError(int line, const std::string& msg);
    std::string formatFloat(const std::string& text);

    std::any visitStart(CSubsetParser::StartContext* ctx) override;
    std::any visitProgram(CSubsetParser::ProgramContext* ctx) override;
    std::any visitUnit(CSubsetParser::UnitContext* ctx) override;
    std::any visitFunc_declaration(CSubsetParser::Func_declarationContext* ctx) override;
    std::any visitFunc_definition(CSubsetParser::Func_definitionContext* ctx) override;
    std::any visitParameter_list(CSubsetParser::Parameter_listContext* ctx) override;
    std::any visitCompound_statement(CSubsetParser::Compound_statementContext* ctx) override;
    std::any visitVar_declaration(CSubsetParser::Var_declarationContext* ctx) override;
    std::any visitType_specifier(CSubsetParser::Type_specifierContext* ctx) override;
    std::any visitDeclaration_list(CSubsetParser::Declaration_listContext* ctx) override;
    std::any visitStatements(CSubsetParser::StatementsContext* ctx) override;
    std::any visitStatement(CSubsetParser::StatementContext* ctx) override;
    std::any visitExpression_statement(CSubsetParser::Expression_statementContext* ctx) override;
    std::any visitVariable(CSubsetParser::VariableContext* ctx) override;
    std::any visitExpression(CSubsetParser::ExpressionContext* ctx) override;
    std::any visitLogic_expression(CSubsetParser::Logic_expressionContext* ctx) override;
    std::any visitRel_expression(CSubsetParser::Rel_expressionContext* ctx) override;
    std::any visitSimple_expression(CSubsetParser::Simple_expressionContext* ctx) override;
    std::any visitTerm(CSubsetParser::TermContext* ctx) override;
    std::any visitUnary_expression(CSubsetParser::Unary_expressionContext* ctx) override;
    std::any visitFactor(CSubsetParser::FactorContext* ctx) override;
    std::any visitArgument_list(CSubsetParser::Argument_listContext* ctx) override;
    std::any visitArguments(CSubsetParser::ArgumentsContext* ctx) override;
};
