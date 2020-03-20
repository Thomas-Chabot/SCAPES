/*
 * Defines an Exception for when a user attempts to redeclare a variable
 *  that already exists.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef VARIABLE_ALREADY_EXISTS_EXCEPTION_H
#define VARIABLE_ALREADY_EXISTS_EXCEPTION_H

class VariableAlreadyExistsException : public BaseException {
public:
  VariableAlreadyExistsException(string variableType, string name)
      : BaseException("Attempt to redefine " + variableType + " with name '" + name + "'")
  {
  }
};

#endif
