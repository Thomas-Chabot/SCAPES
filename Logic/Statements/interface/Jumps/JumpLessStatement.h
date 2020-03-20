#include "JumpStatementBase.h"

#ifndef JUMPLESS_H
#define JUMPLESS_H

class JumpLessStatement : public JumpStatementBase {
private:
protected:
    bool ShouldJump(int flag) override;
public:
    JumpLessStatement();
    JumpLessStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif // JUMPLESS_H
