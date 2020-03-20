#include "JumpStatementBase.h"
#include "OperandFactory.h"

JumpStatementBase::JumpStatementBase(string statementType) : Statement(statementType, 0, nullptr, nullptr, nullptr, nullptr, 1) { }
JumpStatementBase::JumpStatementBase(string statementType, int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(statementType, line, env, label, OperandFactory::CreateLabelOperand(op1, env), OperandFactory::CreateNullOperand(op2, env), 1)
{
}

void JumpStatementBase::Compile(){
    Statement::Compile();
}
void JumpStatementBase::Run(){
    if (this->ShouldJump(environment->GetFlag())){
        int line;

        this->GetOperand(0)->GetValue(line);
        environment->SetLine(line);
    }
}

void JumpStatementBase::ValidateOperations(){
    this->CheckReadable(this->GetOperand(0));
}
