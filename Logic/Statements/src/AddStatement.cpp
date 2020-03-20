#include "AddStatement.h"
#include "OperandFactory.h"
#include "UserInterface.h"

AddStatement::AddStatement() : Statement(TYPE_ADD_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 2) { }
AddStatement::AddStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_ADD_STATEMENT, line, env, label, OperandFactory::CreateValueOperand(op1, env), OperandFactory::CreateValueOperand(op2, env), 2)
{
}

void AddStatement::Compile(){
    Statement::Compile();
}

void AddStatement::Run(){
    int sourceValue, destinationValue;

    Operand* source = this->GetOperand(0);
    Operand* destination = this->GetOperand(1);

    source->GetValue(sourceValue);
    destination->GetValue(destinationValue);

    destination->SetValue(sourceValue + destinationValue);
}

void AddStatement::ValidateOperations(){
  this->CheckReadable(this->GetOperand(0));

  this->CheckReadable(this->GetOperand(1));
  this->CheckWritable(this->GetOperand(1));
}
