#include "DeclarationStatementBase.h"
#include "IntVariable.h"
#include "DataContainer.h"
#include "VariableAlreadyExistsException.h"
#include "JumpedToVariableDeclarationException.h"
#include "OperandFactory.h"

DeclarationStatementBase::DeclarationStatementBase(string statementType, int expectedOperands)
    : Statement(statementType, 0, nullptr, nullptr, nullptr, nullptr, expectedOperands)
{
    this->timesReached = 0;
}
DeclarationStatementBase::DeclarationStatementBase(string statementType, int line, Environment* env, Label* label, Operand* op1, Operand* op2, int expectedOperands)
    : Statement(statementType, line, env, label, op1, op2, expectedOperands)
{
    this->timesReached = 0;
}

void DeclarationStatementBase::Compile(){
  Statement::Compile();
  string name = this->GetOperand(0)->GetName();

  this->DeclareVariable(name);
}
void DeclarationStatementBase::Run(){
    this->timesReached ++;
    if (this->timesReached > 1)
        throw JumpedToVariableDeclarationException();

    this->ExecuteStatement();
}

void DeclarationStatementBase::ValidateOperations(){}
