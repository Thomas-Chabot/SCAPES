/*
 * Defines an exception for declaring a variable with an invalid name.
 *  Some examples are a string ("Hello World"), a number (251), etc.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */


#include "BaseException.h"
#include <string>
using namespace std;

#ifndef CANNOTUSEASNAMEEXCEPTION_H
#define CANNOTUSEASNAMEEXCEPTION_H

class CannotUseAsNameException : public BaseException{
public:
    CannotUseAsNameException(string type)
        : BaseException("Variable name cannot be a " + type){
    }
};

#endif // CANNOTUSENUMBERASNAMEEXCEPTION_H
