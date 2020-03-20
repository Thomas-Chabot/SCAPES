/*
 * Defines an Exception for when operand data is provided in place of an empty string.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"

#ifndef EXPECTINGNULLEXCEPTION_H
#define EXPECTINGNULLEXCEPTION_H

class ExpectingNullException : public BaseException {
public:
    ExpectingNullException(string actualData)
        : BaseException("Expecting empty operand, instead received " + actualData)
    {
    }
};


#endif // EXPECTINGNULLEXCEPTION_H
