#include "BaseException.h"

#ifndef CANNOTBESTRINGOPERANDEXCEPTION_H
#define CANNOTBESTRINGOPERANDEXCEPTION_H

class CannotBeStringOperandException : public BaseException {
public:
    CannotBeStringOperandException() : BaseException("A String Operand is not valid for this statement.") { }
};

#endif // CANNOTBESTRINGOPERANDEXCEPTION_H
