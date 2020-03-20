/*
 * This defines the Compare Statement.
 *  The Compare Statement takes two operands and sets an Environment Variable based on the
 *  comparison between its two values.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Statement.h"
#include "NotReadableException.h"

#ifndef COMPARE_STATEMENT_H
#define COMPARE_STATEMENT_H

class CompareStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  CompareStatement();
  CompareStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif
