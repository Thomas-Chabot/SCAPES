/*
 * This is class which controls String Operands.
 *  Literal Operands have a constant, string value.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Operand.h"

#ifndef STRINGOPERAND_H
#define STRINGOPERAND_H

class StringOperand : public Operand{
private:
  string value;

public:
  StringOperand();
  StringOperand(string value, Environment* env);

  void GetValue(string& result) override;
  void SetValue(string value) override;

  string GetName() override;
};
#endif // STRINGHEADER_H
