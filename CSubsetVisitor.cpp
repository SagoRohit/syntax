#include "CSubsetVisitor.h"
#include <iostream>
#include <algorithm>

std::string MyVisitor::formatFloat(const std::string& text) {
    double val = std::stod(text);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << val;
    return oss.str();
}

void MyVisitor::logRule(int line, const std::string& rule, const std::string& text) {
    logFile << "Line " << line << ": " << rule << "\n\n" << text << "\n\n";
}

void MyVisitor::logError(int line, const std::string& msg) {
    errorCount++;
    std::string fullMsg = "Error at line " + std::to_string(line) + ": " + msg;
    logFile << fullMsg << "\n\n";
    errorFile << fullMsg << "\n\n";
}

// ==================== start ====================
std::any MyVisitor::visitStart(CSubsetParser::StartContext* ctx) {
    auto res = std::any_cast<VisitResult>(visit(ctx->program()));
    logRule(1, "start : program", "");
    logFile << "\n" << symTable.printCurrent() << "\n";
    logFile << "\nTotal lines: " << totalLines << "\n";
    logFile << "Total errors: " << errorCount << "\n\n";
    return VisitResult{res.text, "void"};
}

// ==================== program ====================
std::any MyVisitor::visitProgram(CSubsetParser::ProgramContext* ctx) {
    if (ctx->program()) {
        auto progRes = std::any_cast<VisitResult>(visit(ctx->program()));
        auto unitRes = std::any_cast<VisitResult>(visit(ctx->unit()));
        std::string text = progRes.text + unitRes.text;
        int line = ctx->unit()->getStart()->getLine();
        logRule(line, "program : program unit", text);
        return VisitResult{text, "void"};
    } else {
        auto unitRes = std::any_cast<VisitResult>(visit(ctx->unit()));
        int line = ctx->unit()->getStart()->getLine();
        logRule(line, "program : unit", unitRes.text);
        return VisitResult{unitRes.text, "void"};
    }
}

// ==================== unit ====================
std::any MyVisitor::visitUnit(CSubsetParser::UnitContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->var_declaration()) {
        auto res = std::any_cast<VisitResult>(visit(ctx->var_declaration()));
        logRule(line, "unit : var_declaration", res.text);
        return VisitResult{res.text, "void"};
    } else if (ctx->func_declaration()) {
        auto res = std::any_cast<VisitResult>(visit(ctx->func_declaration()));
        logRule(line, "unit : func_declaration", res.text);
        return VisitResult{res.text, "void"};
    } else {
        auto res = std::any_cast<VisitResult>(visit(ctx->func_definition()));
        // Log without extra newline, but return with extra newline for program text
        logRule(line, "unit : func_definition", res.text);
        return VisitResult{res.text + "\n", "void"};
    }
}

// ==================== type_specifier ====================
std::any MyVisitor::visitType_specifier(CSubsetParser::Type_specifierContext* ctx) {
    std::string text, tok;
    if (ctx->INT()) { text = "int"; tok = "INT"; }
    else if (ctx->FLOAT()) { text = "float"; tok = "FLOAT"; }
    else { text = "void"; tok = "VOID"; }
    logRule(ctx->getStart()->getLine(), "type_specifier : " + tok, text);
    return VisitResult{text, text};
}

// ==================== func_declaration ====================
std::any MyVisitor::visitFunc_declaration(CSubsetParser::Func_declarationContext* ctx) {
    auto typeRes = std::any_cast<VisitResult>(visit(ctx->type_specifier()));
    std::string funcName = ctx->ID()->getText();
    int line = ctx->getStart()->getLine();
    std::string text, ruleName;
    std::vector<ParamInfo> paramList;

    if (ctx->parameter_list()) {
        pendingParams.clear();
        auto paramRes = std::any_cast<VisitResult>(visit(ctx->parameter_list()));
        paramList = pendingParams;
        pendingParams.clear();
        hasPendingParams = false;
        text = typeRes.text + " " + funcName + "(" + paramRes.text + ");\n";
        ruleName = "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON";
    } else {
        text = typeRes.text + " " + funcName + "();\n";
        ruleName = "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
    }

    SymbolInfo* existing = symTable.lookupCurrent(funcName);
    if (!existing) {
        SymbolInfo* sym = new SymbolInfo(funcName, "ID");
        sym->isFunction = true;
        sym->returnType = typeRes.type;
        sym->dataType = typeRes.type;
        sym->params = paramList;
        sym->isDeclared = true;
        symTable.insert(sym);
    }

    logRule(line, ruleName, text);
    return VisitResult{text, "void"};
}

// ==================== func_definition ====================
std::any MyVisitor::visitFunc_definition(CSubsetParser::Func_definitionContext* ctx) {
    auto typeRes = std::any_cast<VisitResult>(visit(ctx->type_specifier()));
    std::string funcName = ctx->ID()->getText();
    int line = ctx->getStart()->getLine();
    std::string text, ruleName;
    std::vector<ParamInfo> paramList;

    currentFuncName = funcName;
    currentFuncReturnType = typeRes.type;

    if (ctx->parameter_list()) {
        pendingParams.clear();
        auto paramRes = std::any_cast<VisitResult>(visit(ctx->parameter_list()));
        paramList = pendingParams;

        // Check duplicate param names
        for (int i = 0; i < (int)paramList.size(); i++) {
            if (paramList[i].name.empty()) continue;
            for (int j = i + 1; j < (int)paramList.size(); j++) {
                if (paramList[i].name == paramList[j].name) {
                    logError(line, "Multiple declaration of " + paramList[i].name + " in parameter");
                }
            }
        }

        // Check declaration vs definition consistency
        SymbolInfo* existing = symTable.lookupCurrent(funcName);
        if (existing && existing->isFunction && existing->isDeclared && !existing->isDefined) {
            if (existing->returnType != typeRes.type) {
                logError(line, "Return type mismatch with function declaration in function " + funcName);
            } else if (existing->params.size() != paramList.size()) {
                logError(line, "Total number of arguments mismatch with declaration in function " + funcName);
            } else {
                for (int i = 0; i < (int)paramList.size(); i++) {
                    if (existing->params[i].type != paramList[i].type) {
                        logError(line, std::to_string(i+1) + "th argument mismatch in function " + funcName);
                        break;
                    }
                }
            }
            existing->isDefined = true;
            existing->params = paramList;
        } else if (existing) {
            logError(line, "Multiple declaration of " + funcName);
        } else {
            SymbolInfo* sym = new SymbolInfo(funcName, "ID");
            sym->isFunction = true;
            sym->returnType = typeRes.type;
            sym->dataType = typeRes.type;
            sym->params = paramList;
            sym->isDefined = true;
            symTable.insert(sym);
        }

        // Check unnamed params in definition
        for (int i = 0; i < (int)paramList.size(); i++) {
            if (paramList[i].name.empty()) {
                logError(line, std::to_string(i+1) + "th parameter's name not given in function definition of " + funcName);
            }
        }

        hasPendingParams = true;
        text = typeRes.text + " " + funcName + "(" + paramRes.text + ")";
        ruleName = "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
    } else {
        SymbolInfo* existing = symTable.lookupCurrent(funcName);
        if (existing && existing->isFunction && existing->isDeclared && !existing->isDefined) {
            if (existing->returnType != typeRes.type) {
                logError(line, "Return type mismatch with function declaration in function " + funcName);
            } else if (!existing->params.empty()) {
                logError(line, "Total number of arguments mismatch with declaration in function " + funcName);
            }
            existing->isDefined = true;
        } else if (existing) {
            logError(line, "Multiple declaration of " + funcName);
        } else {
            SymbolInfo* sym = new SymbolInfo(funcName, "ID");
            sym->isFunction = true;
            sym->returnType = typeRes.type;
            sym->dataType = typeRes.type;
            sym->isDefined = true;
            symTable.insert(sym);
        }

        hasPendingParams = false;
        pendingParams.clear();
        text = typeRes.text + " " + funcName + "()";
        ruleName = "func_definition : type_specifier ID LPAREN RPAREN compound_statement";
    }

    auto compRes = std::any_cast<VisitResult>(visit(ctx->compound_statement()));
    text += compRes.text;

    logRule(line, ruleName, text);
    currentFuncName = "";
    currentFuncReturnType = "";
    return VisitResult{text, "void"};
}

// ==================== parameter_list ====================
std::any MyVisitor::visitParameter_list(CSubsetParser::Parameter_listContext* ctx) {
    if (ctx->parameter_list()) {
        auto listRes = std::any_cast<VisitResult>(visit(ctx->parameter_list()));
        auto typeRes = std::any_cast<VisitResult>(visit(ctx->type_specifier()));
        ParamInfo p;
        p.type = typeRes.type;
        std::string text, ruleName;
        if (ctx->ID()) {
            p.name = ctx->ID()->getText();
            text = listRes.text + "," + typeRes.text + " " + p.name;
            ruleName = "parameter_list : parameter_list COMMA type_specifier ID";
        } else {
            text = listRes.text + "," + typeRes.text;
            ruleName = "parameter_list : parameter_list COMMA type_specifier";
        }
        pendingParams.push_back(p);
        logRule(ctx->getStart()->getLine(), ruleName, text);
        return VisitResult{text, "void"};
    } else {
        auto typeRes = std::any_cast<VisitResult>(visit(ctx->type_specifier()));
        ParamInfo p;
        p.type = typeRes.type;
        std::string text, ruleName;
        if (ctx->ID()) {
            p.name = ctx->ID()->getText();
            text = typeRes.text + " " + p.name;
            ruleName = "parameter_list : type_specifier ID";
        } else {
            text = typeRes.text;
            ruleName = "parameter_list : type_specifier";
        }
        pendingParams.push_back(p);
        logRule(ctx->getStart()->getLine(), ruleName, text);
        return VisitResult{text, "void"};
    }
}

// ==================== compound_statement ====================
std::any MyVisitor::visitCompound_statement(CSubsetParser::Compound_statementContext* ctx) {
    symTable.enterScope();

    if (hasPendingParams) {
        for (auto& p : pendingParams) {
            if (!p.name.empty()) {
                SymbolInfo* sym = new SymbolInfo(p.name, "ID");
                sym->dataType = p.type;
                sym->isArray = p.isArray;
                symTable.insert(sym);
            }
        }
        hasPendingParams = false;
        pendingParams.clear();
    }

    int line = ctx->getStart()->getLine();
    std::string text, ruleName;

    if (ctx->statements()) {
        auto stmtsRes = std::any_cast<VisitResult>(visit(ctx->statements()));
        text = "{\n" + stmtsRes.text + "}\n";
        ruleName = "compound_statement : LCURL statements RCURL";
    } else {
        text = "{}\n";
        ruleName = "compound_statement : LCURL RCURL";
    }

    std::string scopeStr = symTable.exitScope();
    logRule(line, ruleName, text);
    logFile << "\n" << scopeStr << "\n";
    logFile << "\n" << symTable.printCurrent() << "\n";

    return VisitResult{text, "void"};
}

// ==================== var_declaration ====================
std::any MyVisitor::visitVar_declaration(CSubsetParser::Var_declarationContext* ctx) {
    auto typeRes = std::any_cast<VisitResult>(visit(ctx->type_specifier()));
    currentDeclType = typeRes.type;
    auto declRes = std::any_cast<VisitResult>(visit(ctx->declaration_list()));
    std::string text = typeRes.text + " " + declRes.text + ";\n";
    logRule(ctx->getStart()->getLine(), "var_declaration : type_specifier declaration_list SEMICOLON", text);
    return VisitResult{text, "void"};
}

// ==================== declaration_list ====================
std::any MyVisitor::visitDeclaration_list(CSubsetParser::Declaration_listContext* ctx) {
    int line = ctx->getStart()->getLine();

    if (ctx->declaration_list()) {
        auto listRes = std::any_cast<VisitResult>(visit(ctx->declaration_list()));
        std::string varName = ctx->ID()->getText();
        std::string text, ruleName;
        bool isArr = false;
        int arrSize = 0;

        if (ctx->CONST_INT()) {
            arrSize = std::stoi(ctx->CONST_INT()->getText());
            text = listRes.text + "," + varName + "[" + ctx->CONST_INT()->getText() + "]";
            ruleName = "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD";
            isArr = true;
        } else {
            text = listRes.text + "," + varName;
            ruleName = "declaration_list : declaration_list COMMA ID";
        }

        // Multiple declaration check BEFORE logRule
        SymbolInfo* existing = symTable.lookupCurrent(varName);
        if (existing) {
            logError(line, "Multiple declaration of " + varName);
        }

        logRule(line, ruleName, text);

        // Void type check AFTER logRule
        if (currentDeclType == "void") {
            logError(line, "Variable type cannot be void");
        }

        // Insert only if not duplicate and not void
        if (!existing && currentDeclType != "void") {
            SymbolInfo* sym = new SymbolInfo(varName, "ID");
            sym->dataType = currentDeclType;
            sym->isArray = isArr;
            sym->arraySize = arrSize;
            symTable.insert(sym);
        }

        return VisitResult{text, "void"};
    } else {
        std::string varName = ctx->ID()->getText();
        std::string text, ruleName;
        bool isArr = false;
        int arrSize = 0;

        if (ctx->CONST_INT()) {
            arrSize = std::stoi(ctx->CONST_INT()->getText());
            text = varName + "[" + ctx->CONST_INT()->getText() + "]";
            ruleName = "declaration_list : ID LTHIRD CONST_INT RTHIRD";
            isArr = true;
        } else {
            text = varName;
            ruleName = "declaration_list : ID";
        }

        // Multiple declaration check BEFORE logRule
        SymbolInfo* existing = symTable.lookupCurrent(varName);
        if (existing) {
            logError(line, "Multiple declaration of " + varName);
        }

        logRule(line, ruleName, text);

        // Void type check AFTER logRule
        if (currentDeclType == "void") {
            logError(line, "Variable type cannot be void");
        }

        // Insert only if not duplicate and not void
        if (!existing && currentDeclType != "void") {
            SymbolInfo* sym = new SymbolInfo(varName, "ID");
            sym->dataType = currentDeclType;
            sym->isArray = isArr;
            sym->arraySize = arrSize;
            symTable.insert(sym);
        }

        return VisitResult{text, "void"};
    }
}

// ==================== statements ====================
std::any MyVisitor::visitStatements(CSubsetParser::StatementsContext* ctx) {
    if (ctx->statements()) {
        auto stmtsRes = std::any_cast<VisitResult>(visit(ctx->statements()));
        auto stmtRes = std::any_cast<VisitResult>(visit(ctx->statement()));
        std::string text = stmtsRes.text + stmtRes.text;
        logRule(ctx->statement()->getStart()->getLine(), "statements : statements statement", text);
        return VisitResult{text, "void"};
    } else {
        auto stmtRes = std::any_cast<VisitResult>(visit(ctx->statement()));
        logRule(ctx->statement()->getStart()->getLine(), "statements : statement", stmtRes.text);
        return VisitResult{stmtRes.text, "void"};
    }
}

// ==================== statement ====================
std::any MyVisitor::visitStatement(CSubsetParser::StatementContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->var_declaration()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->var_declaration()));
        logRule(line, "statement : var_declaration", r.text);
        return VisitResult{r.text, "void"};
    }
    if (ctx->expression_statement() && !ctx->FOR()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->expression_statement()));
        std::string text = r.text + "\n";
        logRule(line, "statement : expression_statement", text);
        return VisitResult{text, "void"};
    }
    if (ctx->compound_statement()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->compound_statement()));
        logRule(line, "statement : compound_statement", r.text);
        return VisitResult{r.text, "void"};
    }
    if (ctx->FOR()) {
        auto es1 = std::any_cast<VisitResult>(visit(ctx->expression_statement(0)));
        auto es2 = std::any_cast<VisitResult>(visit(ctx->expression_statement(1)));
        auto expr = std::any_cast<VisitResult>(visit(ctx->expression()));
        auto stmt = std::any_cast<VisitResult>(visit(ctx->statement(0)));
        std::string text = "for(" + es1.text + es2.text + expr.text + ")" + stmt.text;
        logRule(line, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement", text);
        return VisitResult{text, "void"};
    }
    if (ctx->IF()) {
        auto expr = std::any_cast<VisitResult>(visit(ctx->expression()));
        if (ctx->ELSE()) {
            auto s1 = std::any_cast<VisitResult>(visit(ctx->statement(0)));
            auto s2 = std::any_cast<VisitResult>(visit(ctx->statement(1)));
            std::string text = "if (" + expr.text + ")" + s1.text + "else\n" + s2.text;
            logRule(line, "statement : IF LPAREN expression RPAREN statement ELSE statement", text);
            return VisitResult{text, "void"};
        } else {
            auto s = std::any_cast<VisitResult>(visit(ctx->statement(0)));
            std::string text = "if (" + expr.text + ")" + s.text;
            logRule(line, "statement : IF LPAREN expression RPAREN statement", text);
            return VisitResult{text, "void"};
        }
    }
    if (ctx->WHILE()) {
        auto expr = std::any_cast<VisitResult>(visit(ctx->expression()));
        auto s = std::any_cast<VisitResult>(visit(ctx->statement(0)));
        std::string text = "while (" + expr.text + ")" + s.text;
        logRule(line, "statement : WHILE LPAREN expression RPAREN statement", text);
        return VisitResult{text, "void"};
    }
    if (ctx->PRINTLN()) {
        std::string id = ctx->ID()->getText();
        SymbolInfo* sym = symTable.lookupAll(id);
        if (!sym) logError(line, "Undeclared variable " + id);
        std::string text = "printf(" + id + ");\n";
        logRule(line, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON", text);
        return VisitResult{text, "void"};
    }
    if (ctx->RETURN()) {
        auto expr = std::any_cast<VisitResult>(visit(ctx->expression()));
        std::string text = "return " + expr.text + ";\n";
        logRule(line, "statement : RETURN expression SEMICOLON", text);
        return VisitResult{text, "void"};
    }
    return VisitResult{"", "void"};
}

// ==================== expression_statement ====================
std::any MyVisitor::visitExpression_statement(CSubsetParser::Expression_statementContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->expression()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->expression()));
        std::string text = r.text + ";";
        logRule(line, "expression_statement : expression SEMICOLON", text);
        return VisitResult{text, r.type};
    }
    logRule(line, "expression_statement : SEMICOLON", ";");
    return VisitResult{";", "void"};
}

// ==================== variable ====================
std::any MyVisitor::visitVariable(CSubsetParser::VariableContext* ctx) {
    int line = ctx->getStart()->getLine();
    std::string varName = ctx->ID()->getText();

    if (ctx->expression()) {
        auto exprRes = std::any_cast<VisitResult>(visit(ctx->expression()));
        if (exprRes.type == "float") {
            logError(line, "Expression inside third brackets not an integer");
        }
        std::string text = varName + "[" + exprRes.text + "]";

        SymbolInfo* sym = symTable.lookupAll(varName);
        std::string type = "int";
        if (sym) {
            if (!sym->isArray && !sym->isFunction) {
                logError(line, varName + " not an array");
            }
            type = sym->dataType;
        } else {
            logError(line, "Undeclared variable " + varName);
        }
        logRule(line, "variable : ID LTHIRD expression RTHIRD", text);
        return VisitResult{text, type, false, varName};
    } else {
        SymbolInfo* sym = symTable.lookupAll(varName);
        std::string type = "int";
        bool isArr = false;
        if (sym) {
            type = sym->dataType;
            isArr = sym->isArray;
            if (isArr) {
                logError(line, "Type mismatch, " + varName + " is an array");
            }
        } else {
            logError(line, "Undeclared variable " + varName);
        }
        logRule(line, "variable : ID", varName);
        return VisitResult{varName, type, isArr, varName};
    }
}

// ==================== expression ====================
std::any MyVisitor::visitExpression(CSubsetParser::ExpressionContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->ASSIGNOP()) {
        auto varRes = std::any_cast<VisitResult>(visit(ctx->variable()));
        auto logicRes = std::any_cast<VisitResult>(visit(ctx->logic_expression()));

        if (varRes.type == "int" && logicRes.type == "float") {
            logError(line, "Type Mismatch");
        }
        if (logicRes.type == "void") {
            logError(line, "Void function used in expression");
        }

        std::string text = varRes.text + "=" + logicRes.text;
        logRule(line, "expression : variable ASSIGNOP logic_expression", text);
        return VisitResult{text, varRes.type, false, varRes.name};
    } else {
        auto r = std::any_cast<VisitResult>(visit(ctx->logic_expression()));
        logRule(line, "expression : logic expression", r.text);
        return VisitResult{r.text, r.type, r.isArray, r.name};
    }
}

// ==================== logic_expression ====================
std::any MyVisitor::visitLogic_expression(CSubsetParser::Logic_expressionContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->LOGICOP()) {
        auto left = std::any_cast<VisitResult>(visit(ctx->rel_expression(0)));
        auto right = std::any_cast<VisitResult>(visit(ctx->rel_expression(1)));
        std::string text = left.text + ctx->LOGICOP()->getText() + right.text;
        logRule(line, "logic_expression : rel_expression LOGICOP rel_expression", text);
        return VisitResult{text, "int"};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->rel_expression(0)));
    logRule(line, "logic_expression : rel_expression", r.text);
    return VisitResult{r.text, r.type, r.isArray, r.name};
}

// ==================== rel_expression ====================
std::any MyVisitor::visitRel_expression(CSubsetParser::Rel_expressionContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->RELOP()) {
        auto left = std::any_cast<VisitResult>(visit(ctx->simple_expression(0)));
        auto right = std::any_cast<VisitResult>(visit(ctx->simple_expression(1)));
        std::string text = left.text + ctx->RELOP()->getText() + right.text;
        logRule(line, "rel_expression : simple_expression RELOP simple_expression", text);
        return VisitResult{text, "int"};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->simple_expression(0)));
    logRule(line, "rel_expression : simple_expression", r.text);
    return VisitResult{r.text, r.type, r.isArray, r.name};
}

// ==================== simple_expression ====================
std::any MyVisitor::visitSimple_expression(CSubsetParser::Simple_expressionContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->ADDOP()) {
        auto left = std::any_cast<VisitResult>(visit(ctx->simple_expression()));
        auto right = std::any_cast<VisitResult>(visit(ctx->term()));
        std::string text = left.text + ctx->ADDOP()->getText() + right.text;
        logRule(line, "simple_expression : simple_expression ADDOP term", text);
        std::string type = (left.type == "float" || right.type == "float") ? "float" : "int";
        return VisitResult{text, type};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->term()));
    logRule(line, "simple_expression : term", r.text);
    return VisitResult{r.text, r.type, r.isArray, r.name};
}

// ==================== term ====================
std::any MyVisitor::visitTerm(CSubsetParser::TermContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->MULOP()) {
        auto left = std::any_cast<VisitResult>(visit(ctx->term()));
        auto right = std::any_cast<VisitResult>(visit(ctx->unary_expression()));
        std::string op = ctx->MULOP()->getText();

        if (op == "%") {
            if (left.type == "float" || right.type == "float") {
                logError(line, "Non-Integer operand on modulus operator");
            } else if (right.text == "0") {
                logError(line, "Modulus by Zero");
            }
        }
        if (right.type == "void") {
            logError(line, "Void function used in expression");
        }

        std::string text = left.text + op + right.text;
        logRule(line, "term : term MULOP unary_expression", text);
        std::string type;
        if (op == "%") type = "int";
        else type = (left.type == "float" || right.type == "float") ? "float" : "int";
        return VisitResult{text, type};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->unary_expression()));
    logRule(line, "term : unary_expression", r.text);
    return VisitResult{r.text, r.type, r.isArray, r.name};
}

// ==================== unary_expression ====================
std::any MyVisitor::visitUnary_expression(CSubsetParser::Unary_expressionContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->NOT()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->unary_expression()));
        std::string text = "!" + r.text;
        logRule(line, "unary_expression : NOT unary expression", text);
        return VisitResult{text, "int"};
    }
    if (ctx->ADDOP()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->unary_expression()));
        std::string text = ctx->ADDOP()->getText() + r.text;
        logRule(line, "unary_expression : ADDOP unary_expression", text);
        return VisitResult{text, r.type};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->factor()));
    logRule(line, "unary_expression : factor", r.text);
    return VisitResult{r.text, r.type, r.isArray, r.name};
}

// ==================== factor ====================
std::any MyVisitor::visitFactor(CSubsetParser::FactorContext* ctx) {
    int line = ctx->getStart()->getLine();

    if (ctx->CONST_INT()) {
        std::string text = ctx->CONST_INT()->getText();
        logRule(line, "factor : CONST_INT", text);
        return VisitResult{text, "int"};
    }
    if (ctx->CONST_FLOAT()) {
        std::string text = formatFloat(ctx->CONST_FLOAT()->getText());
        logRule(line, "factor : CONST_FLOAT", text);
        return VisitResult{text, "float"};
    }
    if (ctx->LPAREN() && ctx->expression()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->expression()));
        std::string text = "(" + r.text + ")";
        logRule(line, "factor : LPAREN expression RPAREN", text);
        return VisitResult{text, r.type};
    }
    if (ctx->ID() && ctx->LPAREN()) {
        std::string funcName = ctx->ID()->getText();
        auto argRes = std::any_cast<VisitResult>(visit(ctx->argument_list()));
        std::string text = funcName + "(" + argRes.text + ")";

        // All error checks BEFORE logRule
        SymbolInfo* sym = symTable.lookupAll(funcName);
        std::string retType = "int";
        if (sym) {
            if (!sym->isFunction) {
                retType = sym->dataType;
            } else {
                retType = sym->returnType;
                // Parse arg info
                std::vector<std::string> argTypes;
                if (!argRes.argInfo.empty()) {
                    std::istringstream ss(argRes.argInfo);
                    std::string entry;
                    while (std::getline(ss, entry, '|')) {
                        size_t p1 = entry.find(':');
                        argTypes.push_back(entry.substr(0, p1));
                    }
                }
                if (argTypes.size() != sym->params.size()) {
                    logError(line, "Total number of arguments mismatch in function " + funcName);
                } else {
                    for (int i = 0; i < (int)argTypes.size(); i++) {
                        if (argTypes[i] != sym->params[i].type) {
                            if (!(argTypes[i] == "int" && sym->params[i].type == "float")) {
                                logError(line, std::to_string(i+1) + "th argument mismatch in function " + funcName);
                                break;
                            }
                        }
                    }
                }
            }
        } else {
            logError(line, "Undeclared function " + funcName);
        }

        logRule(line, "factor : ID LPAREN argument_list RPAREN", text);
        return VisitResult{text, retType};
    }
    if (ctx->INCOP()) {
        auto v = std::any_cast<VisitResult>(visit(ctx->variable()));
        std::string text = v.text + "++";
        logRule(line, "factor : variable INCOP", text);
        return VisitResult{text, v.type};
    }
    if (ctx->DECOP()) {
        auto v = std::any_cast<VisitResult>(visit(ctx->variable()));
        std::string text = v.text + "--";
        logRule(line, "factor : variable DECOP", text);
        return VisitResult{text, v.type};
    }
    // factor : variable
    auto v = std::any_cast<VisitResult>(visit(ctx->variable()));
    logRule(line, "factor : variable", v.text);
    return VisitResult{v.text, v.type, v.isArray, v.name};
}

// ==================== argument_list ====================
std::any MyVisitor::visitArgument_list(CSubsetParser::Argument_listContext* ctx) {
    if (ctx->arguments()) {
        auto r = std::any_cast<VisitResult>(visit(ctx->arguments()));
        logRule(ctx->getStart()->getLine(), "argument_list : arguments", r.text);
        return VisitResult{r.text, r.type, false, "", r.argInfo};
    }
    return VisitResult{"", "void", false, "", ""};
}

// ==================== arguments ====================
std::any MyVisitor::visitArguments(CSubsetParser::ArgumentsContext* ctx) {
    int line = ctx->getStart()->getLine();
    if (ctx->arguments()) {
        auto argsRes = std::any_cast<VisitResult>(visit(ctx->arguments()));
        auto exprRes = std::any_cast<VisitResult>(visit(ctx->logic_expression()));
        std::string text = argsRes.text + "," + exprRes.text;
        logRule(line, "arguments : arguments COMMA logic_expression", text);
        std::string info = argsRes.argInfo + "|" + exprRes.type + ":" + (exprRes.isArray ? "1" : "0") + ":" + exprRes.name;
        return VisitResult{text, "void", false, "", info};
    }
    auto r = std::any_cast<VisitResult>(visit(ctx->logic_expression()));
    logRule(line, "arguments : logic_expression", r.text);
    std::string info = r.type + ":" + (r.isArray ? "1" : "0") + ":" + r.name;
    return VisitResult{r.text, r.type, r.isArray, r.name, info};
}
