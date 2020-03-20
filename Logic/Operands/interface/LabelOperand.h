/*
 * This is class which controls Label Operands.
 *  Every LabelOperand has a name which it uses to identify its label.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */


#include "Operand.h"
#include "OperandWithName.h"
#include "Label.h"

#ifndef LABEL_OPERAND_H
#define LABEL_OPERAND_H

class LabelOperand : public Operand, public OperandWithName{
private:

public:
  LabelOperand();
  LabelOperand(string name, Environment* env);

  void Initialize() override;

  void GetValue(int& result) override;

  string GetName() override;

};

#endif
