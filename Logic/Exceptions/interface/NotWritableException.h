/*
 * Defines an Exception for when a statement is expecting to set the value of an operand,
 *   but the operand does not provide rewritable data.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef NOT_WRITABLE_EXCEPTION_H
#define NOT_WRITABLE_EXCEPTION_H

class NotWritableException : public BaseException {
public:
  NotWritableException(string name)
      : BaseException("Variable '" + name + "' is not writable")
  {
  }
};

#endif
