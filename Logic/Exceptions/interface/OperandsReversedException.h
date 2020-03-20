/*
 * Defines an exception for when the operands provided for a Statement have been reversed;
 *   That is, no operand is provided as the first argument, but an operand has been provided for the second argument.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"

#ifndef INVALIDARGUMENTSEXCEPTION_H
#define INVALIDARGUMENTSEXCEPTION_H

class OperandsReversedException : public BaseException{
public:
    OperandsReversedException() : BaseException("The Operands specified for the statement are invalid."){
    }
};

#endif // INVALIDARGUMENTSEXCEPTION_H
