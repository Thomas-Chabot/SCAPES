#include "Statement.h"

#ifndef ADDSTATEMENT_H
#define ADDSTATEMENT_H

class AddStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  AddStatement();
  AddStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif // ADDSTATEMENT_H
