#include "StringOperandStorage.h"

StringOperandStorage::StringOperandStorage(StringOperand* data) : OperandStorage(data){
    data->GetValue(this->value);
}

void StringOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    json["value"] = this->value.c_str();
}

void StringOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment*){
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null"); // TODO should be an exception class

    StringOperand* operand = new StringOperand();
    operand->SetValue(json["value"].toString().toStdString());

    result = operand;
}
