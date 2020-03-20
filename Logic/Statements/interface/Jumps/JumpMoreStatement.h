/*
 * This defines the Jump More Statement.
 *   The JumpMore statement takes a label as an operand and jumps to that label
 *   if the previous comparison value was greater than 0.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "JumpStatementBase.h"

#ifndef JUMP_MORE_H
#define JUMP_MORE_H

class JumpMoreStatement : public JumpStatementBase {
private:

protected:
    bool ShouldJump(int flag) override;

public:
  JumpMoreStatement();
  JumpMoreStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif
