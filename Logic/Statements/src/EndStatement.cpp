#include "EndStatement.h"
#include "OperandFactory.h"

EndStatement::EndStatement() : Statement(TYPE_END_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 0) { }
EndStatement::EndStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_END_STATEMENT, line, env, label, OperandFactory::CreateNullOperand(op1, env), OperandFactory::CreateNullOperand(op2, env), 0)
{

}

void EndStatement::Compile(){
    Statement::Compile();
}
void EndStatement::Run(){
    environment->EndExecution();
}

void EndStatement::ValidateOperations(){}
