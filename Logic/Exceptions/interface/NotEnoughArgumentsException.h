/*
 * Defines an Exception for when a statement has not been provided with enough arguments.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef NOT_ENOUGH_ARGS_EXCEPTION_H
#define NOT_ENOUGH_ARGS_EXCEPTION_H

class NotEnoughArgumentsException : public BaseException {
public:
  NotEnoughArgumentsException()
      : BaseException("Not enough arguments passed to statement declaration")
  {
  }
};

#endif
