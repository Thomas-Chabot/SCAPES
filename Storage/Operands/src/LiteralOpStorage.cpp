// Handles the Storage interface for Literals
#include "LiteralOpStorage.h"

LiteralOpStorage::LiteralOpStorage(LiteralOperand* op) : OpStorage(op){

}

void LiteralOpStorage::Write(QJsonObject &json) const{
    LiteralOperand* op = static_cast<LiteralOperand*>(this->GetOperand());
    json["value"] = op->GetValue();
}
void LiteralOpStorage::Read(const QJsonObject &json){

}
