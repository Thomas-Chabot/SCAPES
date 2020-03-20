/*
 * Defines an Exception for when an invalid type has been passed in as an operand.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#define DATA_TYPE_ARRAY "Array"
#define DATA_TYPE_OPERAND "Operand"

#ifndef INVALIDTYPEEXCEPTION_H
#define INVALIDTYPEEXCEPTION_H

class InvalidTypeException : public BaseException {
public:
  InvalidTypeException(string name, string dataType)
      : BaseException("Invalid type specified: " + dataType + " with name '" + name + "'"){
  }
};

#endif // INVALIDTYPEEXCEPTION_H
