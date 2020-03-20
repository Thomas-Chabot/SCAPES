#include "DeclarationStatementBase.h"
#include "Operand.h"

#ifndef DECLAREARRAYSTATEMENT_H
#define DECLAREARRAYSTATEMENT_H

class DeclareArrayStatement : public DeclarationStatementBase{
private:
protected:
  void DeclareVariable(string name);
  void ExecuteStatement();
public:
  DeclareArrayStatement();
  DeclareArrayStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif // DECLAREARRAYSTATEMENT_H
