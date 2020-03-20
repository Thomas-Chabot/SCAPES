#include "LiteralOperand.h"
#include "InvalidOperationException.h"
#include <string>
using namespace std;

LiteralOperand::LiteralOperand() : LiteralOperand(-1, nullptr) { }
LiteralOperand::LiteralOperand(int value, Environment* env)
    : Operand(TYPE_LITERAL_OPERAND, true, false, env)
{
  this->value = value;
}

void LiteralOperand::GetValue(int& result){
  result = this->value;
}
void LiteralOperand::SetValue(int value){
    this->value = value;
}

string LiteralOperand::GetName(){ return to_string(this->value); }
