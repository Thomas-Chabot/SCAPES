/*
 *
 * This is the base class for all Operands in the system.
 *   It provides public methods for checking if an operand is settable, is gettable,
 *   and for serializing its data.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "IOperand.h"
#include "DoesNotExistException.h"
#include "VariableAlreadyExistsException.h"
#include "Environment.h"
#include <string>
using namespace std;

#ifndef OPERAND_H
#define OPERAND_H

class Operand : public IOperand {
private:
    string type;

protected:
  Environment* environment;

  Operand(string opType, bool canGet, bool canSet, Environment* env);

  template <class T>
  inline bool GetVariable(string name, T*& result);

  template <class T>
  inline bool VariableExists(string name);

  bool isSettable = false;
  bool isGettable = false;
public:
  virtual ~Operand();

  virtual void Verify();
  virtual void Initialize();

  bool CanSetValue(){ return this->isSettable; }
  bool CanGetValue(){ return this->isGettable; }

  virtual string GetName() = 0;
  string GetType();

  virtual void GetValue(int& result);
  virtual void GetValue(string& result);
  virtual void SetValue(int value);
  virtual void SetValue(string value);

  void SetEnvironment(Environment* env);
};

template <class T>
bool Operand::GetVariable(string name, T*& result){
  if (not this->VariableExists<T>(name)){
    throw DoesNotExistException("Variable", name);
  }

  return this->environment->GetIdentifier<T>(name, result);
}

template <class T>
bool Operand::VariableExists(string name){
    return this->environment->IdentifierExists<T>(name);
}

#endif
