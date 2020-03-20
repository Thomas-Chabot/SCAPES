#include "OperandData.h"

OperandData::OperandData() : OperandData("", "", false){

}
OperandData::OperandData(string valueData, string arrayIndex, bool isArray){
    this->valueData = valueData;
    this->isArray = isArray;
    this->arrayIndex = arrayIndex;
}

string OperandData::GetValueData(){return this->valueData;}
string OperandData::GetIndex(){return this->arrayIndex;}
bool OperandData::IsArray(){return this->isArray;}

void OperandData::SetValueData(string data){this->valueData = data;}
void OperandData::SetIndex(string index){this->arrayIndex = index;}
void OperandData::SetIsArray(bool isArray){this->isArray = isArray;}
