/*
 * This defines the End Statement.
 *   The End Statement takes no operands and is used for detecting the end of program execution.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Statement.h"

#ifndef END_STATEMENT_H
#define END_STATEMENT_H

class EndStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  EndStatement();
  EndStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif
