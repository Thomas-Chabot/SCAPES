#include "ArrayVariable.h"
#include "OutOfBoundsException.h"
#include "ArrayNotInitializedException.h"
#include "Operand.h"

ArrayVariable::ArrayVariable() : ArrayVariable("", nullptr){ }
ArrayVariable::ArrayVariable(string name, IOperand* size) : Identifier(TYPE_ARRAY_IDENTIFIER, name) {
  this->size = size;
  this->isInitialized = false;
}

ArrayVariable::~ArrayVariable(){
  if (!this->isInitialized) return;
  delete[] this->values;
}

void ArrayVariable::Initialize(){
    int size;
    this->size->GetValue(size);

    this->values = new int[size];
    this->isInitialized = true;
}
int ArrayVariable::Get(int index){
  this->VerifyGetSet(index);
  return this->values[index];
}
void ArrayVariable::Set(int index, int value){
  this->VerifyGetSet(index);
  this->values[index] = value;
}

void ArrayVariable::VerifyGetSet(int index){
  if (!this->isInitialized)
    throw ArrayNotInitializedException(this->GetName());
  if (!this->IsInBounds(index))
    throw OutOfBoundsException(this->GetName(), index);
}

bool ArrayVariable::IsInBounds(int index){
  int size;
  this->size->GetValue(size);

  return (index >= 0 && index < size);
}

IOperand* ArrayVariable::Size(){ return this->size; }
void ArrayVariable::SetSize(IOperand* size){ this->size = size; }
