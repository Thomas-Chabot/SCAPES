/*
 * This defines the Jump Statement.
 *   The jump statement takes a label as an operand and jumps to that label.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "JumpStatementBase.h"

#ifndef JUMP_EQUAL_H
#define JUMP_EQUAL_H

class JumpStatement : public JumpStatementBase {
private:

protected:
    bool ShouldJump(int flag) override;

public:
  JumpStatement();
  JumpStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif
