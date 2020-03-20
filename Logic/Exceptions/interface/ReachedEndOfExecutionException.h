#include "BaseException.h"

#ifndef REACHEDENDOFEXECUTIONEXCEPTION_H
#define REACHEDENDOFEXECUTIONEXCEPTION_H

class ReachedEndOfExecutionException : public BaseException {
public:
    ReachedEndOfExecutionException() : BaseException("Program execution did not reach 'end' statement") { }
};

#endif // REACHEDENDOFEXECUTIONEXCEPTION_H
