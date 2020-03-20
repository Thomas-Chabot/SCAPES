#include "ReadIntStatement.h"
#include "OperandFactory.h"
#include "UserInterface.h"

ReadIntStatement::ReadIntStatement() : Statement(TYPE_READINT_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 1) { }
ReadIntStatement::ReadIntStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_READINT_STATEMENT, line, env, label, OperandFactory::CreateValueOperand(op1, env), OperandFactory::CreateNullOperand(op2, env), 1)
{
}

void ReadIntStatement::Compile(){
    Statement::Compile();
}

void ReadIntStatement::Run(){
    int value;
    UserInterface::GetSingleton().ReadInt(value);

    Operand* op = this->GetOperand(0);
    op->SetValue(value);
}

void ReadIntStatement::ValidateOperations(){
  this->CheckWritable(this->GetOperand(0));
}
