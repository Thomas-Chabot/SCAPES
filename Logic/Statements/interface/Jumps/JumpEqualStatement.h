#include "JumpStatementBase.h"

#ifndef JUMPEQUAL_H
#define JUMPEQUAL_H

class JumpEqualStatement : public JumpStatementBase {
private:
protected:
    bool ShouldJump(int flag) override;
public:
    JumpEqualStatement();
    JumpEqualStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);
};

#endif // JUMPEQUAL_H
