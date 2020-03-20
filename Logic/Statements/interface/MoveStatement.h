#include "Statement.h"

#ifndef MOVESTATEMENT_H
#define MOVESTATEMENT_H

class MoveStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  MoveStatement();
  MoveStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif // MOVESTATEMENT_H
