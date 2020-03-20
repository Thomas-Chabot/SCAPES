// Handles the Storage interface for Name Operands
#include "NameOpStorage.h"

NameOpStorage::NameOpStorage(NameOperand* op) : OpStorage(op){

}

void NameOpStorage::Write(QJsonObject &json) const{
    NameOperand* op = static_cast<NameOperand*>(this->GetOperand());
    json["name"] = op->GetName().c_str();
}
void NameOpStorage::Read(const QJsonObject &json){

}
