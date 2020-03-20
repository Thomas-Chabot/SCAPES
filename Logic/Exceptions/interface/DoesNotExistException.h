/*
 * Defines an Exception for when a referenced variable has not been declared.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef DOES_NOT_EXIST_EXCEPTION_H
#define DOES_NOT_EXIST_EXCEPTION_H

class DoesNotExistException : public BaseException {
public:
  DoesNotExistException(string variableType, string name)
      : BaseException(variableType + " with name '" + name + "' does not exist")
  {
  }
};

#endif
