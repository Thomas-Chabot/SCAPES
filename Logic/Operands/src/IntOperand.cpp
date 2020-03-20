#include "IntOperand.h"
#include "IntVariable.h"
#include "DataContainer.h"
#include "DoesNotExistException.h"

IntOperand::IntOperand() : IntOperand("", nullptr){ }
IntOperand::IntOperand(string name, Environment* env)
    : Operand(TYPE_INT_OPERAND, true, true, env), OperandWithName(name)
{
    this->variable = nullptr;
}

void IntOperand::Verify(){
  if (not this->VariableExists<IntVariable>(this->name))
    throw DoesNotExistException("IntVariable", this->name);
}
void IntOperand::Initialize(){
  this->Verify();

  IntVariable* var;
  this->GetVariable<IntVariable>(this->name, var);

  this->variable = var;
}

void IntOperand::GetValue(int& result){
    result = this->variable->Get();
};
void IntOperand::SetValue(int value){
  if (!this->variable) return;
  this->variable->Set(value);
}


string IntOperand::GetName(){ return OperandWithName::GetName(); }
