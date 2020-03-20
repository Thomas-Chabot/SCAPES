#include "NameOperand.h"
#include "InvalidOperationException.h"
#include "CannotUseAsNameException.h"
#include "StringExtensions.h"
#include "VariableType.h"

NameOperand::NameOperand() : NameOperand("", nullptr) { }
NameOperand::NameOperand(string name, Environment* env)
    : Operand(TYPE_NAME_OPERAND, true, false, env), OperandWithName(name)
{

}

void NameOperand::Initialize(){
    if (StringExtensions::IsNumber(name))
        throw CannotUseAsNameException(VARIABLE_TYPE_INTEGER);
    if (StringExtensions::IsString(name))
        throw CannotUseAsNameException(VARIABLE_TYPE_STRING);
}


string NameOperand::GetName(){ return OperandWithName::GetName(); }
