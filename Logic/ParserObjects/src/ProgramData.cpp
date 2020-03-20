#include "ProgramData.h"

ProgramData::ProgramData() : ProgramData("", "", "", "", false){

}
ProgramData::ProgramData(string label, string instruction, string operand1, string operand2, bool hasExtraData){
    this->labelName = label;
    this->instructionType = instruction;
    this->op1 = operand1;
    this->op2 = operand2;
    this->hasExtraData = hasExtraData;
}

string ProgramData::GetLabel(){ return this->labelName; }
string ProgramData::GetInstruction(){ return this->instructionType; }
string ProgramData::GetOperand1(){ return this->op1; }
string ProgramData::GetOperand2(){ return this->op2; }
bool ProgramData::HasMoreData(){ return this->hasExtraData; }

void ProgramData::SetLabel(string label){ this->labelName = label; }
void ProgramData::SetInstruction(string instruction){ this->instructionType = instruction; }
void ProgramData::SetOperand1(string op1){ this->op1 = op1; }
void ProgramData::SetOperand2(string op2){ this->op2 = op2; }
void ProgramData::SetHasMoreData(bool hasMoreData){ this->hasExtraData = hasMoreData; }
