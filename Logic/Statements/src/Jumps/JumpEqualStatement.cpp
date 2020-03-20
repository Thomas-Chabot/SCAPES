#include "JumpEqualStatement.h"

JumpEqualStatement::JumpEqualStatement() : JumpStatementBase(TYPE_JUMPEQUAL_STATEMENT) { }
JumpEqualStatement::JumpEqualStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : JumpStatementBase(TYPE_JUMPEQUAL_STATEMENT, line, env, label, op1, op2)
{
}

bool JumpEqualStatement::ShouldJump(int flag){
    return flag == 0;
}
