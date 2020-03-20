#include "LabelOperand.h"
#include "DoesNotExistException.h"
#include "InvalidOperationException.h"
#include "LabelNotDefinedException.h"

LabelOperand::LabelOperand() : LabelOperand("", nullptr) { }
LabelOperand::LabelOperand(string name, Environment* env)
    : Operand(TYPE_LABEL_OPERAND, true, false, env), OperandWithName(name)
{

}

void LabelOperand::Initialize(){

}

void LabelOperand::GetValue(int& result){
  if (!this->VariableExists<Label>(this->name)){
      throw LabelNotDefinedException(this->name);
  }

  Label* label;
  this->GetVariable<Label>(this->name, label);

  result = label->Get();
}


string LabelOperand::GetName(){ return OperandWithName::GetName(); }
