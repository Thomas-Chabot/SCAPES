/*
 * This is the main class for handling Array Variables.
 * Every variable has a name, a size, and an array of values.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Identifier.h"
#include "IOperand.h"
#include <string>
#include <stdexcept>
using namespace std;

#ifndef ARRAY_VARIABLE_H
#define ARRAY_VARIABLE_H

class ArrayVariable : public Identifier {
private:
  int* values;
  IOperand* size;
  int isInitialized;

  void VerifyGetSet(int index);
public:
  ArrayVariable();
  ArrayVariable(string name, IOperand* size);
  ~ArrayVariable();

  void Initialize();

  int Get(int index);
  void Set(int index, int value);
  IOperand* Size();

  void SetSize(IOperand* size);
  bool IsInBounds(int index);
};

#endif
