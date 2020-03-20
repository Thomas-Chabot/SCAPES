/*
 * This defines the Print Statement.
 *  The Print statement takes a single operand and prints out the value of that operand.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Statement.h"

#ifndef PRINT_H
#define PRINT_H

class PrintStatement : public Statement {
private:
protected:
    void ValidateOperations();
public:
  PrintStatement();
  PrintStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2);

  void Compile();
  void Run();
};

#endif
