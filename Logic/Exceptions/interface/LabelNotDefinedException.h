/*
 * Thrown when jumping to a label that has not been defined.
 *
 * Written by Sean Hodges, last edited Nov. 13 2019
 */

#include "BaseException.h"

#ifndef LABELNOTDEFINEDEXCEPTION_H
#define LABELNOTDEFINEDEXCEPTION_H

class LabelNotDefinedException : public BaseException {
public:
    LabelNotDefinedException(string label) : BaseException("Attempted to jump to undefined label '" + label + "'") {}
};

#endif // LABELNOTDEFINEDEXCEPTION_H
