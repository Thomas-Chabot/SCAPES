#include "Identifier.h"

Identifier::Identifier(string identifierType, string name){
    this->type = identifierType;
    this->name = name;
}
Identifier::~Identifier(){}
string Identifier::GetName(){
    return this->name;
}
string Identifier::GetType(){
    return this->type;
}

void Identifier::SetName(string name){
    this->name = name;
}
