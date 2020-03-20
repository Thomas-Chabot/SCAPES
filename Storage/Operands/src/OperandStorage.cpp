#include "OperandStorage.h"

#include "ArrayOperandStorage.h"
#include "IntOperandStorage.h"
#include "LabelOperandStorage.h"
#include "LiteralOperandStorage.h"
#include "NameOperandStorage.h"
#include "StringOperandStorage.h"

#include "ClassDataTypes.h"

OperandStorage::OperandStorage(Operand *data) : StorageBase(data) {
    this->operandType = data->GetType();
}

void OperandStorage::Write(QJsonObject &json) const{
    json["type"] = this->operandType.c_str();
}
void OperandStorage::Read(const QJsonObject& json, Operand*& result, Environment* env){
    result = nullptr;
    string type = json["type"].toString().toStdString();

    if (type == TYPE_ARRAY_OPERAND)
        ArrayOperandStorage::Read(json, result, env);
    else if (type == TYPE_INT_OPERAND)
        IntOperandStorage::Read(json, result, env);
    else if (type == TYPE_LABEL_OPERAND)
        LabelOperandStorage::Read(json, result, env);
    else if (type == TYPE_LITERAL_OPERAND)
        LiteralOperandStorage::Read(json, result, env);
    else if (type == TYPE_NAME_OPERAND)
        NameOperandStorage::Read(json, result, env);
    else if (type == TYPE_STRING_OPERAND)
        StringOperandStorage::Read(json, result, env);
    else
        throw runtime_error("Unknown Operand Type: " + type);

    result->SetEnvironment(env);
    result->Initialize();
}

OperandStorage* OperandStorage::Create(IOperand *data){
    if (data->GetType() == TYPE_ARRAY_OPERAND)
        return new ArrayOperandStorage(static_cast<ArrayOperand*>(data));
    else if (data->GetType() == TYPE_INT_OPERAND)
        return new IntOperandStorage(static_cast<IntOperand*>(data));
    else if (data->GetType() == TYPE_LABEL_OPERAND)
        return new LabelOperandStorage(static_cast<LabelOperand*>(data));
    else if (data->GetType() == TYPE_LITERAL_OPERAND)
        return new LiteralOperandStorage(static_cast<LiteralOperand*>(data));
    else if (data->GetType() == TYPE_NAME_OPERAND)
        return new NameOperandStorage(static_cast<NameOperand*>(data));
    else if (data->GetType() == TYPE_STRING_OPERAND)
        return new StringOperandStorage(static_cast<StringOperand*>(data));
    else
        return nullptr;
}

