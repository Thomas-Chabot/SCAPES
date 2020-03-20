/*
 * This is class which controls Literal Operands.
 *  Literal Operands have a constant, integer value.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Operand.h"

#ifndef LITERAL_OPERAND_H
#define LITERAL_OPERAND_H

class LiteralOperand : public Operand{
private:
  int value;

public:
  LiteralOperand();
  LiteralOperand(int value, Environment* env);

  void GetValue(int& result) override;
  void SetValue(int value) override;

  string GetName() override;
};

#endif
