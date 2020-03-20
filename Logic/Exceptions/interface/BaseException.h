/*
 * This is the main Exception object for the system. All other Exceptions
 *   derive from this class.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */


#include "ErrorConstants.h"
#include <string>
#include <stdexcept>
using namespace std;

#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

class BaseException : public exception {
private:
protected:
    string msg;

public:
  BaseException(string msg = ERROR_UNKNOWN) : exception(){
      this->msg = msg;
  }
  ~BaseException(){}
 virtual const char* what() const noexcept {
   return msg.c_str();
 }
};

#endif
