#include "ArrayStorage.h"
#include <QJsonArray>

ArrayStorage::ArrayStorage(ArrayVariable* data) : IdentifierStorageBase(data)
{
    this->size = OperandStorage::Create(data->Size());
}

void ArrayStorage::Write(QJsonObject& json) const{
    IdentifierStorageBase::Write(json);

    QJsonObject sizeObj;
    this->size->Write(sizeObj);
    json["size"] = sizeObj;
}

void ArrayStorage::Read(const QJsonObject &json, ArrayVariable* result, Environment* env){
    IdentifierStorageBase::Read(json, result, env);

    Operand* op;
    OperandStorage::Read(json["size"].toObject(), op, env);

    result->SetSize(op);
}
