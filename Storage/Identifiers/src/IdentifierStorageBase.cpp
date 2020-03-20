#include "IdentifierStorageBase.h"

IdentifierStorageBase::IdentifierStorageBase(Identifier* data) : StorageBase(data){
    this->name = (data == nullptr) ? "" : data->GetName();
}

void IdentifierStorageBase::Read(const QJsonObject& json, Identifier* result, Environment*){
    result->SetName(json["name"].toString().toStdString());
}
void IdentifierStorageBase::Write(QJsonObject& json) const{
    json["name"] = this->name.c_str();
}
