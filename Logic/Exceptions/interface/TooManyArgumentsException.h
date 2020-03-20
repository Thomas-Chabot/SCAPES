/*
 * Defines an Exception for when a statement is passed in too many operands.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"

#ifndef TOOMANYARGUMENTSEXCEPTION_H
#define TOOMANYARGUMENTSEXCEPTION_H

class TooManyArgumentsException : public BaseException{
public:
    TooManyArgumentsException()
        : BaseException("Too many operands passed into statement declaration")
    {
    }
};

#endif // TOOMANYARGUMENTSEXCEPTION_H
