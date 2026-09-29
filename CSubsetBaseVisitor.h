
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetVisitor.h"


/**
 * This class provides an empty implementation of CSubsetVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubsetBaseVisitor : public CSubsetVisitor {
public:

  virtual std::any visitStart(CSubsetParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgram(CSubsetParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnit(CSubsetParser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_declaration(CSubsetParser::Func_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_definition(CSubsetParser::Func_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(CSubsetParser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_statement(CSubsetParser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_specifier(CSubsetParser::Type_specifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration_list(CSubsetParser::Declaration_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatements(CSubsetParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(CSubsetParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_statement(CSubsetParser::Expression_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(CSubsetParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(CSubsetParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogic_expression(CSubsetParser::Logic_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRel_expression(CSubsetParser::Rel_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_expression(CSubsetParser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(CSubsetParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(CSubsetParser::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(CSubsetParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument_list(CSubsetParser::Argument_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(CSubsetParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }


};

