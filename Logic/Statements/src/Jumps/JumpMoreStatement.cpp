#include "JumpMoreStatement.h"
#include "OperandFactory.h"

JumpMoreStatement::JumpMoreStatement() : JumpStatementBase(TYPE_JUMPMORE_STATEMENT) { }
JumpMoreStatement::JumpMoreStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : JumpStatementBase(TYPE_JUMPMORE_STATEMENT, line, env, label, op1, op2)
{
}

bool JumpMoreStatement::ShouldJump(int flag){
    return flag > 0;
}
