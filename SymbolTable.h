#pragma once
#include "ScopeTable.h"
#include <string>
#include <sstream>
#include <fstream>

class SymbolTable {
public:
    ScopeTable* currentScope;

    SymbolTable() {
        currentScope = new ScopeTable("1");
    }

    ~SymbolTable() {
        while (currentScope) {
            ScopeTable* parent = currentScope->parentScope;
            delete currentScope;
            currentScope = parent;
        }
    }

    void enterScope() {
        currentScope->childCount++;
        std::string newId = currentScope->id + "." + std::to_string(currentScope->childCount);
        ScopeTable* newScope = new ScopeTable(newId, currentScope);
        currentScope = newScope;
    }

    std::string exitScope() {
        std::string result = currentScope->print();
        ScopeTable* parent = currentScope->parentScope;
        delete currentScope;
        currentScope = parent;
        return result;
    }

    bool insert(SymbolInfo* sym) {
        return currentScope->insert(sym);
    }

    SymbolInfo* lookupCurrent(const std::string& name) {
        return currentScope->lookup(name);
    }

    SymbolInfo* lookupAll(const std::string& name) {
        ScopeTable* scope = currentScope;
        while (scope) {
            SymbolInfo* sym = scope->lookup(name);
            if (sym) return sym;
            scope = scope->parentScope;
        }
        return nullptr;
    }

    std::string printCurrent() {
        return currentScope->print();
    }

    std::string printAll() {
        std::string result;
        ScopeTable* scope = currentScope;
        while (scope) {
            result += scope->print();
            scope = scope->parentScope;
        }
        return result;
    }
};
