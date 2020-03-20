/*
 * This is the Factory for creating new Statements in the system.
 *   It takes in data for the statement along with its statementType and
 *   returns a new instance of the given statement type.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "Statement.h"
#include "Operand.h"
#include "InstructionDeclarations.h"
#include <string>
using namespace std;

#ifndef STATEMENT_FACTORY_H
#define STATEMENT_FACTORY_H

class StatementFactory {
private:
public:
  static Statement* CreateStatement(int line, string statementType, Environment* env, Label* label, OperandData& op1, OperandData& op2);
  static bool BuildFromTypeString(string type, Statement*& result);
};

#endif
