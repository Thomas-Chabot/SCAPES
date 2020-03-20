/*
 * This defines the Declare Int statement.
 *   The Declare Int statement takes one operand and defines a new integer
 *   variable in the system.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "DeclarationStatementBase.h"
#include "Operand.h"

#ifndef DECLARE_INT_H
#define DECLARE_INT_H

class DeclareIntStatement : public DeclarationStatementBase{
private:
protected:
  void DeclareVariable(string name);
  void ExecuteStatement();
public:
  DeclareIntStatement();
  DeclareIntStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif
