/*
 * This is class which controls Name Operands,
 *   used in turn with declaration statements.
 *
 * Every NameOperand provides a name to be used for the statement;
 *  This name is then used to declare a new variable in the system.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */


#include "Operand.h"
#include "OperandWithName.h"

#ifndef NAME_OPERAND_H
#define NAME_OPERAND_H

class NameOperand : public Operand, public OperandWithName {
private:

public:
  NameOperand();
  NameOperand(string name, Environment* env);
  void Initialize() override;

  string GetName() override;
};

#endif
