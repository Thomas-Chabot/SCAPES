#include "OperandWithName.h"

OperandWithName::OperandWithName(string name){
    this->name = name;
}

string OperandWithName::GetName(){
    return this->name;
}
void OperandWithName::SetName(string name){
    this->name = name;
}
