/*
 * This is the main class that handles general program concepts such as Compilation,
 *   Constructing objects from program code, execution, etc.
 *
 * Written by Sean Hodges, last edited Nov. 11, 2019.
 */

#include "Statement.h"
#include "FileManager.h"
#include "ProgramData.h"
#include "OperandData.h"
#include "Operand.h"
#include "Environment.h"

#include <string>
#include <vector>
using namespace std;

#ifndef PROGRAM_H
#define PROGRAM_H

class Program {
private:
    string programPath;
    string compilationPath;

    Environment* environment;

    int comparisonFlag;
    vector<Statement*>* statements;

    void ParseLine(string line, ProgramData& programData, OperandData& op1, OperandData& op2);
    void CreateStatement(int lineNumber, ProgramData& data, OperandData& op1, OperandData& op2);

    void ThrowError(int lineNumber, BaseException& ex);
    void ThrowError(int lineNumber, exception& exception);
    void ThrowError(int lineNumber, const char* message);
public:
    Program(string programInput, string compilationPath);
    Program(string compilationPath);
    ~Program();

    bool CreateStatements();
    bool Compile();
    bool Execute();

    bool Save();
    bool Load();

    void AddIntVariable(IntVariable* variable);
    void AddArrayVariable(ArrayVariable* variable);
    void AddLabel(Label* label);
    void AddStatement(Statement* statement);

    Environment* GetEnvironment();
};

#endif // PROGRAM_H
