#include "JumpLessStatement.h"

JumpLessStatement::JumpLessStatement() : JumpStatementBase(TYPE_JUMPLESS_STATEMENT) { }
JumpLessStatement::JumpLessStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : JumpStatementBase(TYPE_JUMPLESS_STATEMENT, line, env, label, op1, op2)
{
}

bool JumpLessStatement::ShouldJump(int flag){
    return flag < 0;
}
