#include "LiteralOperandStorage.h"
#include "LiteralOperand.h"

LiteralOperandStorage::LiteralOperandStorage(LiteralOperand* data) : OperandStorage(data){
    data->GetValue(this->value);
}

void LiteralOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    json["value"] = this->value;
}

void LiteralOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment*){
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null");

    LiteralOperand* operand = new LiteralOperand();
    operand->SetValue(json["value"].toInt());

    result = operand;
}
