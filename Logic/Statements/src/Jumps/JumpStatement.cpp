#include "JumpStatement.h"
#include "OperandFactory.h"

JumpStatement::JumpStatement() : JumpStatementBase(TYPE_JUMP_STATEMENT) { }
JumpStatement::JumpStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : JumpStatementBase(TYPE_JUMP_STATEMENT, line, env, label, op1, op2)
{
}

bool JumpStatement::ShouldJump(int){
    return true;
}
