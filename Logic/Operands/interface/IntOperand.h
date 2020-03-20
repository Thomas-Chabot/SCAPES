/*
 * This is class which controls Int Operands.
 *  Every IntOperand has an IntVariable which defines its value.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Operand.h"
#include "OperandWithName.h"
#include "IntVariable.h"
#include <string>
using namespace std;

#ifndef INT_OPERAND_H
#define INT_OPERAND_H

class IntOperand : public Operand, public OperandWithName {
private:
  IntVariable* variable;

public:
  IntOperand();
  IntOperand(string name, Environment* env);

  void Verify() override;
  void Initialize() override;

  void GetValue(int& result) override;
  void SetValue(const int value) override;

  string GetName() override;
};

#endif
