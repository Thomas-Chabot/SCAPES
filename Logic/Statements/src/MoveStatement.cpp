#include "MoveStatement.h"
#include "OperandFactory.h"
#include "UserInterface.h"

MoveStatement::MoveStatement() : Statement(TYPE_MOVE_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 2) { }
MoveStatement::MoveStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_MOVE_STATEMENT, line, env, label, OperandFactory::CreateValueOperand(op1, env), OperandFactory::CreateValueOperand(op2, env), 2)
{
}

void MoveStatement::Compile(){
    Statement::Compile();
}

void MoveStatement::Run(){
    int value;

    Operand* source = this->GetOperand(0);
    Operand* destination = this->GetOperand(1);

    source->GetValue(value);
    destination->SetValue(value);
}

void MoveStatement::ValidateOperations(){
  this->CheckReadable(this->GetOperand(0));
  this->CheckWritable(this->GetOperand(1));
}
