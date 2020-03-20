/*
 * Defines an Exception for when an array index is accessed that is outside of bounds.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef OUT_OF_BOUNDS_EXCEPTION_H
#define OUT_OF_BOUNDS_EXCEPTION_H

class OutOfBoundsException : public BaseException {
public:
  OutOfBoundsException(string variableName, int index)
      : BaseException("Array index " + to_string(index) + " out of bounds on variable '" + variableName + "'")
  {
  }
};

#endif
