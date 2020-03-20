#include "Statement.h"

#ifndef JUMPSTATEMENTBASE_H
#define JUMPSTATEMENTBASE_H

class JumpStatementBase : public Statement {
private:

protected:
    void ValidateOperations();
    virtual bool ShouldJump(int flag) = 0;

public:
  JumpStatementBase(string statementType);
  JumpStatementBase(string statementType, int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif // JUMPSTATEMENTBASE_H
