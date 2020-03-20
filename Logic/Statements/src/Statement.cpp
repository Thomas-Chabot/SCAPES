#include "Statement.h"
#include "NotReadableException.h"
#include "NotWritableException.h"
#include "NotEnoughArgumentsException.h"
#include "OperandsReversedException.h"
#include "TooManyArgumentsException.h"

Statement::Statement(string statementType, int line, Environment* env, Label* label, Operand* op1, Operand* op2, int expectedOperands){
  if (op1 == nullptr && op2 != nullptr){
      throw OperandsReversedException();
  }

  this->operands[0] = op1;
  this->operands[1] = op2;
  this->expectedOperands = expectedOperands;

  this->statementType = statementType;
  this->line = line;
  this->label = label;
  this->environment = env;
}
Statement::~Statement(){
    delete this->operands[0];
    delete this->operands[1];
}

void Statement::Compile(){
    this->VerifyLabel();
    this->Initialize();
}
void Statement::Initialize(){
    this->VerifyOperands();
    this->ValidateOperations();
    //this->InitializeOperands();
}

void Statement::InitializeOperands(){
    if (this->operands[0] != nullptr) this->operands[0]->Initialize();
    if (this->operands[1] != nullptr) this->operands[1]->Initialize();
}

void Statement::VerifyOperands(){
    this->VerifyOperandsCount();

    if (this->operands[0] != nullptr) this->operands[0]->Verify();
    if (this->operands[1] != nullptr) this->operands[1]->Verify();
}
void Statement::VerifyOperandsCount(){
  int totalOperands = 0;
  if (this->operands[0] != nullptr) totalOperands ++;
  if (this->operands[1] != nullptr) totalOperands ++;

  if (totalOperands > expectedOperands)
    throw TooManyArgumentsException();

  if (totalOperands < expectedOperands)
    throw NotEnoughArgumentsException();
}
void Statement::VerifyLabel(){
    if (this->label == nullptr) return;

    string labelName = this->label->GetName();
    if (environment->AnyIdentifierExists(labelName))
        throw VariableAlreadyExistsException("Label", labelName);

    environment->AddIdentifier<Label>(this->label);
}

void Statement::CheckReadable(Operand* op){
  if (!op->CanGetValue())
    throw NotReadableException(op->GetName());
}
void Statement::CheckWritable(Operand* op){
  if (!op->CanSetValue())
    throw NotWritableException(op->GetName());
}

Operand* Statement::GetOperand(int index){
  return this->operands[index];
}
Label* Statement::GetLabel(){
    return this->label;
}
int Statement::GetLine(){
    return this->line;
}
string Statement::GetType(){
    return this->statementType;
}

void Statement::SetLine(int line){
    this->line = line;
}
void Statement::SetLabel(Label* label){
    this->label = label;
}
void Statement::SetOperand(int index, Operand* operand){
    this->operands[index] = operand;
}
void Statement::SetEnvironment(Environment *env){
    this->environment = env;

    // Add the Environment to the operands
    if (this->operands[0] != nullptr) this->operands[0]->SetEnvironment(env);
    if (this->operands[1] != nullptr) this->operands[1]->SetEnvironment(env);

    // Add the label into the environment, if we have one
    if (this->label != nullptr)
        env->AddIdentifier<Label>(this->label);
}
