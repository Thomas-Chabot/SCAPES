#include "LiteralValue.h"

LiteralValue::LiteralValue(string name, int value){
  this->name = name;
  this->value = value;
}

int LiteralValue::Get(){
  return this->value;
}
