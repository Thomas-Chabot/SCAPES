/*
 * This defines the user entered data for a single Statement in the program.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include <string>
using namespace std;

#ifndef PROGRAM_DATA_H
#define PROGRAM_DATA_H

class ProgramData {
private:
  string labelName;
  string instructionType;
  string op1;
  string op2;
  bool hasExtraData;

public:
  ProgramData();
  ProgramData(string label, string instruction, string operand1, string operand2, bool hasExtraData);

  string GetLabel();
  string GetInstruction();
  string GetOperand1();
  string GetOperand2();
  bool HasMoreData();

  void SetLabel(string);
  void SetInstruction(string);
  void SetOperand1(string);
  void SetOperand2(string);
  void SetHasMoreData(bool);
};

#endif
