/*
 * This class handles Array Operands in the system.
 *  Every Array Operand has an Array Variable and an index it talks to.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Operand.h"
#include "OperandWithName.h"
#include "ArrayVariable.h"

#ifndef ARRAY_OPERAND_H
#define ARRAY_OPERAND_H

class ArrayOperand : public Operand, public OperandWithName {
private:
  ArrayVariable* variable;
  Operand* index;

  void VerifyIndex();

public:
  ArrayOperand();
  ArrayOperand(string variableName, string index, Environment* env);
  ~ArrayOperand() override{}

  void Verify() override;
  void Initialize() override;

  void GetValue(int& result) override;
  void SetValue(int value) override;

  int GetIndex();
  void SetIndex(int index);

  string GetName() override;

  Operand* GetIndexOperand();
  void SetIndexOperand(Operand* op);
};

#endif
