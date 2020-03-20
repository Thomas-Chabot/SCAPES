#include "Operand.h"

Operand::Operand(string opType, bool canGet, bool canSet, Environment* env){
    this->type = opType;
    this->isSettable = canSet;
    this->isGettable = canGet;
    this->environment = env;
}
Operand::~Operand(){

}

void Operand::Verify(){

}
void Operand::Initialize(){

}

string Operand::GetType(){
    return this->type;
}

void Operand::GetValue(int&){ throw ; }
void Operand::GetValue(string&){ throw; }
void Operand::SetValue(int){ throw ; } // TODO implement
void Operand::SetValue(string){ throw ; }

void Operand::SetEnvironment(Environment *env){
    this->environment = env;
}
