#include "IntVariable.h"
using namespace std;

IntVariable::IntVariable() : IntVariable("") { }
IntVariable::IntVariable(string name) : Identifier(TYPE_INT_IDENTIFIER, name) { }

void IntVariable::Set(int value){
  this->value = value;
}
int IntVariable::Get(){
  return this->value;
}
