#include "Statement.h"
#include "Operand.h"

#ifndef DECLARATIONSTATEMENTBASE_H
#define DECLARATIONSTATEMENTBASE_H

class DeclarationStatementBase : public Statement{
private:
  int timesReached;

protected:
  void ValidateOperations();
  virtual void DeclareVariable(string name) = 0;
  virtual void ExecuteStatement() = 0;
public:
  DeclarationStatementBase(string statementType, int expectedOperands);
  DeclarationStatementBase(string statementType, int line, Environment* env, Label* label, Operand* op1, Operand* op2, int expectedOperands);

  void Compile();
  void Run();
};

#endif // DECLARATIONSTATEMENTBASE_H
