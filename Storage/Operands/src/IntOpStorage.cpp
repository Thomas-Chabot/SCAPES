// Implements the IntOpStorage interface
#include "IntOpStorage.h"

IntOpStorage::IntOpStorage(IntOperand* op) : OpStorage(op){

}

void IntOpStorage::Write(QJsonObject &json) const{
    IntOperand* op = static_cast<IntOperand*>(this->GetOperand());

    json["name"] = op->GetName().c_str();
}
void IntOpStorage::Read(const QJsonObject &json){

}
