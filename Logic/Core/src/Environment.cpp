#include "Environment.h"

Environment::Environment(){
    this->lineNumber = 0;
    this->isRunning = false;
}
Environment::~Environment(){

}

void Environment::StartRun(){ this->isRunning = true; }
void Environment::EndExecution(){ this->isRunning = false; }
bool Environment::IsRunning(){ return this->isRunning; }

void Environment::SetFlag(int flag){ this->comparisonFlag = flag; }
int Environment::GetFlag(){ return this->comparisonFlag; }

void Environment::SetLine(int line){ this->lineNumber = line; }
int Environment::GetLine(){ return this->lineNumber; }

bool Environment::AnyIdentifierExists(string name){
    return this->data.Contains(name);
}
