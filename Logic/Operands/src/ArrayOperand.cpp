#include "ArrayOperand.h"
#include "OutOfBoundsException.h"
#include "DoesNotExistException.h"
#include "OperandFactory.h"

ArrayOperand::ArrayOperand() : ArrayOperand("", "-1", nullptr){ }
ArrayOperand::ArrayOperand(string valueName, string index, Environment* env)
    : Operand(TYPE_ARRAY_OPERAND, true, true, env), OperandWithName(valueName)
{
  this->index = OperandFactory::CreateIndexOperand(index, env);
}

void ArrayOperand::Verify(){
    if (!this->VariableExists<ArrayVariable>(this->name))
      throw DoesNotExistException("ArrayVariable", this->name);
}
void ArrayOperand::Initialize(){
  this->Verify();

  ArrayVariable* var;
  this->GetVariable<ArrayVariable>(this->name, var);
  this->variable = var;

  this->index->SetEnvironment(this->environment);
  this->index->Initialize();
}

void ArrayOperand::VerifyIndex(){
    int index = this->GetIndex();
    if (!variable->IsInBounds(index))
      throw OutOfBoundsException(this->name, index);
}

void ArrayOperand::GetValue(int& result){
    result = this->variable->Get(this->GetIndex());
}
void ArrayOperand::SetValue(int value){
    this->variable->Set(this->GetIndex(), value);
}

int ArrayOperand::GetIndex(){
    int result;
    this->index->GetValue(result);

    return result;
}
void ArrayOperand::SetIndex(int index){
    this->index->SetValue(index);
}

string ArrayOperand::GetName(){ return OperandWithName::GetName(); }


Operand* ArrayOperand::GetIndexOperand(){ return this->index; }
void ArrayOperand::SetIndexOperand(Operand* op){ this->index = op; }
