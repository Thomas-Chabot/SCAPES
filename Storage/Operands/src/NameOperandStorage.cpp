#include "NameOperandStorage.h"

NameOperandStorage::NameOperandStorage(NameOperand* data) : OperandStorage(data), OperandWithNameStorage(data){ }

void NameOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    OperandWithNameStorage::Write(json);
}

void NameOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment*){
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null"); // TODO should be an exception class

    NameOperand* operand = new NameOperand();
    OperandWithNameStorage::Read(json, operand);

    result = operand;
}
