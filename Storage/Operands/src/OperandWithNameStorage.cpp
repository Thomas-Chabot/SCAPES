#include "OperandWithNameStorage.h"

OperandWithNameStorage::OperandWithNameStorage(OperandWithName* data){
    this->name = data->GetName();
}

void OperandWithNameStorage::Write(QJsonObject &json) const{
    json["name"] = this->name.c_str();
}
void OperandWithNameStorage::Read(const QJsonObject &json, OperandWithName* result){
    result->SetName(json["name"].toString().toStdString());
}
