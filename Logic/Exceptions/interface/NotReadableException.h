/*
 * Defines an Exception for when a statement is expecting to read a value from an operand,
 *   but the operand does not provide readable data.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef NOT_READABLE_EXCEPTION_H
#define NOT_READABLE_EXCEPTION_H

class NotReadableException : public BaseException {
public:
  NotReadableException(string name)
      : BaseException("Variable '" + name + "' is not readable")
  {
  }
};

#endif
