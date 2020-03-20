#include "StringOperand.h"

StringOperand::StringOperand() : StringOperand("", nullptr) { }
StringOperand::StringOperand(string value, Environment* env)
    : Operand(TYPE_STRING_OPERAND, true, false, env)
{
    this->value = value;
}

void StringOperand::GetValue(string& result){
    result = this->value;
}
void StringOperand::SetValue(string value){
    this->value = value;
}

string StringOperand::GetName(){ return this->value; }
