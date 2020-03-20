#include "CompareStatement.h"
#include "OperandFactory.h"

CompareStatement::CompareStatement() : Statement(TYPE_COMPARE_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 2) { }
CompareStatement::CompareStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_COMPARE_STATEMENT, line, env, label, OperandFactory::CreateValueOperand(op1, env), OperandFactory::CreateValueOperand(op2, env), 2)
{
}

void CompareStatement::Compile(){
    Statement::Compile();
}
void CompareStatement::Run(){
    int value1 = 0, value2 = 0;
    this->GetOperand(0)->GetValue(value1);
    this->GetOperand(1)->GetValue(value2);

    environment->SetFlag(value1 - value2);
}

void CompareStatement::ValidateOperations(){
    this->CheckReadable(this->GetOperand(0));
    this->CheckReadable(this->GetOperand(1));
}
