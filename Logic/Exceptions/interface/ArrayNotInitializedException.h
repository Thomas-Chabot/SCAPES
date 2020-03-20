#include "BaseException.h"

#ifndef ARRAYNOTINITIALIZEDEXCEPTION_H
#define ARRAYNOTINITIALIZEDEXCEPTION_H

class ArrayNotInitializedException : public BaseException {
private:
public:
    ArrayNotInitializedException(string name) : BaseException("The array " + name + " has not yet been initialized.") { }
};

#endif // ARRAYNOTINITIALIZEDEXCEPTION_H
