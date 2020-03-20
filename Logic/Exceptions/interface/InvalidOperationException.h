/*
 * Defines an Exception for when an operation is called that is invalid.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef INVALID_OPERATIONS_EXCEPTION_H
#define INVALID_OPERATIONS_EXCEPTION_H

class InvalidOperationException : public BaseException {
public:
  InvalidOperationException(string name, string operationName)
      : BaseException("The operation " + name + "." + operationName + " is invalid.")
  {
  }
};

#endif
