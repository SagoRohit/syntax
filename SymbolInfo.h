#pragma once
#include <string>
#include <vector>

struct ParamInfo {
    std::string type; // "int", "float", "void"
    std::string name; // may be empty for declarations without param names
    bool isArray = false;
};

class SymbolInfo {
public:
    std::string name;
    std::string idType; // "ID" always

    // Variable info
    std::string dataType; // "int", "float", "void"
    bool isArray = false;
    int arraySize = 0;

    // Function info
    bool isFunction = false;
    std::string returnType; // "int", "float", "void"
    std::vector<ParamInfo> params;
    bool isDefined = false;
    bool isDeclared = false;

    SymbolInfo* next = nullptr;

    SymbolInfo(const std::string& name, const std::string& idType)
        : name(name), idType(idType) {}

    ~SymbolInfo() {}
};
