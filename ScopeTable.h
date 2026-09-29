#pragma once
#include "SymbolInfo.h"
#include <string>
#include <sstream>

class ScopeTable {
public:
    static const int NUM_BUCKETS = 30;
    SymbolInfo* table[NUM_BUCKETS];
    ScopeTable* parentScope;
    std::string id;
    int childCount = 0;

    ScopeTable(const std::string& id, ScopeTable* parent = nullptr)
        : id(id), parentScope(parent) {
        for (int i = 0; i < NUM_BUCKETS; i++)
            table[i] = nullptr;
    }

    ~ScopeTable() {
        for (int i = 0; i < NUM_BUCKETS; i++) {
            SymbolInfo* cur = table[i];
            while (cur) {
                SymbolInfo* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }

    static unsigned long SDBMHash(const std::string& str) {
        unsigned long hash = 0;
        for (char c : str)
            hash = c + (hash << 6) + (hash << 16) - hash;
        return hash;
    }

    bool insert(SymbolInfo* sym) {
        unsigned long idx = SDBMHash(sym->name) % NUM_BUCKETS;
        // Check for duplicate
        SymbolInfo* cur = table[idx];
        while (cur) {
            if (cur->name == sym->name) return false;
            cur = cur->next;
        }
        // Tail insertion (oldest first when printing)
        sym->next = nullptr;
        if (!table[idx]) {
            table[idx] = sym;
        } else {
            SymbolInfo* tail = table[idx];
            while (tail->next) tail = tail->next;
            tail->next = sym;
        }
        return true;
    }

    SymbolInfo* lookup(const std::string& name) {
        unsigned long idx = SDBMHash(name) % NUM_BUCKETS;
        SymbolInfo* cur = table[idx];
        while (cur) {
            if (cur->name == name) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    std::string print() {
        std::ostringstream oss;
        oss << "\nScopeTable # " << id << "\n";
        for (int i = 0; i < NUM_BUCKETS; i++) {
            if (table[i] != nullptr) {
                oss << " " << i << " --> ";
                SymbolInfo* cur = table[i];
                while (cur) {
                    oss << "< " << cur->name << " , " << cur->idType << " > ";
                    cur = cur->next;
                }
                oss << "\n";
            }
        }
        return oss.str();
    }
};
