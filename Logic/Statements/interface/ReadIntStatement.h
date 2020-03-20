/*
 * This defines the ReadInt Statement.
 *  The ReadInt statement takes a single variable operand as its value and reads user input
 *  into the referenced variable's value.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Statement.h"

#ifndef READ_INT_H
#define READ_INT_H

class ReadIntStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  ReadIntStatement();
  ReadIntStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif
