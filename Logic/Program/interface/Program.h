/*
 * This is the main class that handles general program concepts such as Compilation,
 *   Constructing objects from program code, execution, etc.
 *
 * Written by Sean Hodges, last edited Nov. 11, 2019.
 */

#ifndef PROGRAM_H
#define PROGRAM_H

class Operand;

#include "Statement.h"
#include "StorageManager.h"
#include "FileManager.h"
#include "ProgramData.h"
#include "OperandData.h"
#include "Operand.h"

#include <string>
#include <vector>
using namespace std;

class Program {
private:
    FileManager file;

    int comparisonFlag;
    vector<Statement*>* statements;

    void ParseLine(string line, ProgramData& programData, OperandData& op1, OperandData& op2);
    void CreateStatement(int lineNumber, ProgramData& data, OperandData& op1, OperandData& op2);

    void StoreIdentifier(StorageManager& storage, Identifier* identifier);
    void StoreStatement(StorageManager& storage, Statement* statement);

    void ThrowError(int lineNumber, BaseException& exception);
    void ThrowError(int lineNumber, const char* message);
public:
    Program(string pathToFile);
    ~Program();

    bool CreateStatements();
    bool Compile();
    bool Execute();
    bool Save();
};

template <class T>
bool Program::GetVariable(string name, T* result){
    return this->data.Get<T>(name, result);
}

template <class T>
bool Program::CheckVariableExists(string name){
    return this->data.Exists<T>(name);
}

#endif // PROGRAM_H
