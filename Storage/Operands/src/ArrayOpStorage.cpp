// Implements the ArrayOpStorage interface
#include "ArrayOpStorage.h"

ArrayOpStorage::ArrayOpStorage(ArrayOperand* op) : OpStorage(op){

}

void ArrayOpStorage::Write(QJsonObject &json) const{
    ArrayOperand* op = static_cast<ArrayOperand*>(this->GetOperand());

    json["name"] = op->GetName().c_str();
    json["index"] = op->GetValue();
}
void ArrayOpStorage::Read(const QJsonObject &json){

}
