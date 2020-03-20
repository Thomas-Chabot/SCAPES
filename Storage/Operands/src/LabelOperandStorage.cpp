#include "LabelOperandStorage.h"

LabelOperandStorage::LabelOperandStorage(LabelOperand* data) : OperandStorage(data), OperandWithNameStorage(data){
}

void LabelOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    OperandWithNameStorage::Write(json);
}

void LabelOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment*){
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null"); // TODO should be an exception class

    LabelOperand* operand = new LabelOperand();
    OperandWithNameStorage::Read(json, operand);

    result = operand;
}
