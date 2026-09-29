
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubsetParser.
 */
class  CSubsetVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubsetParser.
   */
    virtual std::any visitStart(CSubsetParser::StartContext *context) = 0;

    virtual std::any visitProgram(CSubsetParser::ProgramContext *context) = 0;

    virtual std::any visitUnit(CSubsetParser::UnitContext *context) = 0;

    virtual std::any visitFunc_declaration(CSubsetParser::Func_declarationContext *context) = 0;

    virtual std::any visitFunc_definition(CSubsetParser::Func_definitionContext *context) = 0;

    virtual std::any visitParameter_list(CSubsetParser::Parameter_listContext *context) = 0;

    virtual std::any visitCompound_statement(CSubsetParser::Compound_statementContext *context) = 0;

    virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *context) = 0;

    virtual std::any visitType_specifier(CSubsetParser::Type_specifierContext *context) = 0;

    virtual std::any visitDeclaration_list(CSubsetParser::Declaration_listContext *context) = 0;

    virtual std::any visitStatements(CSubsetParser::StatementsContext *context) = 0;

    virtual std::any visitStatement(CSubsetParser::StatementContext *context) = 0;

    virtual std::any visitExpression_statement(CSubsetParser::Expression_statementContext *context) = 0;

    virtual std::any visitVariable(CSubsetParser::VariableContext *context) = 0;

    virtual std::any visitExpression(CSubsetParser::ExpressionContext *context) = 0;

    virtual std::any visitLogic_expression(CSubsetParser::Logic_expressionContext *context) = 0;

    virtual std::any visitRel_expression(CSubsetParser::Rel_expressionContext *context) = 0;

    virtual std::any visitSimple_expression(CSubsetParser::Simple_expressionContext *context) = 0;

    virtual std::any visitTerm(CSubsetParser::TermContext *context) = 0;

    virtual std::any visitUnary_expression(CSubsetParser::Unary_expressionContext *context) = 0;

    virtual std::any visitFactor(CSubsetParser::FactorContext *context) = 0;

    virtual std::any visitArgument_list(CSubsetParser::Argument_listContext *context) = 0;

    virtual std::any visitArguments(CSubsetParser::ArgumentsContext *context) = 0;


};

