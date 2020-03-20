#include "IntOperandStorage.h"

IntOperandStorage::IntOperandStorage(IntOperand* data) : OperandStorage(data), OperandWithNameStorage(data){
}

void IntOperandStorage::Write(QJsonObject &json) const{
    OperandStorage::Write(json);
    OperandWithNameStorage::Write(json);
}

void IntOperandStorage::Read(const QJsonObject &json, Operand*& result, Environment*) {
    // Have to redeclare here, so if it's non-null, throw an error
    if (result != nullptr) throw runtime_error("Operand passed to read must be null"); // TODO should be an exception class

    IntOperand* operand = new IntOperand();
    OperandWithNameStorage::Read(json, operand);

    result = operand;
}
