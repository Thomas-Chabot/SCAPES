/*
 * This defines the base class for a Statement.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#ifndef STATEMENT_H
#define STATEMENT_H

#include "Operand.h"
#include "OperandData.h"
#include "ClassDataTypes.h"
#include "Label.h"

class Statement {
private:
  string statementType;
  int line;
  int expectedOperands;

  Operand* operands[2];
  Label* label;

  void InitializeOperands();
  void VerifyLabel();
  void VerifyOperandsCount();
protected:
  Environment* environment;

  void Verify();
  void VerifyOperands();
  void CheckReadable(Operand* op);
  void CheckWritable(Operand* op);

  virtual void ValidateOperations() = 0;

  template <class T>
  inline bool Declare(T* data);
public:
  Statement(string statementType, int line, Environment* env, Label* label, Operand* op1, Operand* op2, int expectedOperands);
  virtual ~Statement();

  virtual void Compile() = 0;
  virtual void Run() = 0;

  void Initialize();

  int GetLine();
  Label* GetLabel();
  Operand* GetOperand(int index);
  string GetType();

  void SetLine(int line);
  void SetLabel(Label* label);
  void SetOperand(int index, Operand* operand);
  void SetEnvironment(Environment*);
};


template <class T>
bool Statement::Declare(T* data){
  if (environment->AnyIdentifierExists(data->GetName()))
      return false;

  return environment->AddIdentifier<T>(data);
}

#endif
