/*
 * This is the main class for handling Int Variables.
 * Every Variable has a name and a value.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Identifier.h"
#include <string>
using namespace std;

#ifndef INT_VARIABLE_H
#define INT_VARIABLE_H

class IntVariable : public Identifier {
private:
  int value;

public:
  IntVariable();
  IntVariable(string name);

  int Get();
  void Set(int value);
};

#endif
