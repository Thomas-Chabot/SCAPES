#include "ArrayOperandStorage.h"

ArrayOperandStorage::ArrayOperandStorage(ArrayOperand* data) : OperandStorage(data), OperandWithNameStorage(data){
    this->index = OperandStorage::Create(data->GetIndexOperand());
}

void ArrayOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    OperandWithNameStorage::Write(json);

    QJsonObject indexObject;
    this->index->Write(indexObject);
    json["index"] = indexObject;
}

void ArrayOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment* env){
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null"); // TODO should be an exception class

    ArrayOperand* operand = new ArrayOperand();
    Operand* indexOperand;
    OperandWithNameStorage::Read(json, operand);

    QJsonObject indexObject = json["index"].toObject();
    OperandStorage::Read(indexObject, indexOperand, env);
    operand->SetIndexOperand(indexOperand);

    result = operand;
}
