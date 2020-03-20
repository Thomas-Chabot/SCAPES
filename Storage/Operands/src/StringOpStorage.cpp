// Handles encoding/decoding StringOperands from Storage
#include "StringOperand.h"
#include "StringOpStorage.h"

StringOpStorage::StringOpStorage(StringOperand* op) : OpStorage(op){

}

void StringOpStorage::Write(QJsonObject &json) const{
    StringOperand* op = static_cast<StringOperand*>(this->GetOperand());

    json["value"] = op->GetValue().c_str();
}
void StringOpStorage::Read(const QJsonObject &json){

}
