// Handles the Storage interface for Labels
#include "LabelOpStorage.h"

LabelOpStorage::LabelOpStorage(LabelOperand* op) : OpStorage(op){

}

void LabelOpStorage::Write(QJsonObject &json) const{
    LabelOperand* op = static_cast<LabelOperand*>(this->GetOperand());
    json["name"] = op->GetName().c_str();
}
void LabelOpStorage::Read(const QJsonObject &json){

}
