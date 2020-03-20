/*
 * This is the Exception type used for handling UnitTest errors.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"
#include <string>
using namespace std;

#ifndef TEST_EXCEPTION_H
#define TEST_EXCEPTION_H

class TestException : public BaseException {
public:
  TestException(string message) : BaseException(message){}
};

#endif
