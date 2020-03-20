#include "StatementStorage.h"
#include "ClassDataTypes.h"

// Statement Types
#include "StatementFactory.h"

StatementStorage::StatementStorage(Statement* data) : StorageBase(data) {
    this->statementType = data->GetType();
    this->lineNumber = data->GetLine();
    this->op1 = data->GetOperand(0) == nullptr ? nullptr : OperandStorage::Create(data->GetOperand(0));
    this->op2 = data->GetOperand(1) == nullptr ? nullptr : OperandStorage::Create(data->GetOperand(1));
    this->label = data->GetLabel() == nullptr ? nullptr : new LabelStorage(data->GetLabel());
}
StatementStorage::~StatementStorage(){
    if (this->op1 != nullptr) delete this->op1;
    if (this->op2 != nullptr) delete this->op2;
    if (this->label != nullptr) delete this->label;
}

void StatementStorage::Write(QJsonObject &json) const{
    json["type"] = this->statementType.c_str();
    json["lineNumber"] = this->lineNumber;

    this->AddToJson(json, "operand1", this->op1);
    this->AddToJson(json, "operand2", this->op2);
    this->AddToJson(json, "label", this->label);
}
void StatementStorage::Read(const QJsonObject &json, Statement*& result, Environment* env){
    StatementStorage::InitializeStatement(json["type"].toString().toStdString(), result);

    int line = json["lineNumber"].toInt();
    result->SetLine(line);

    if (!json["label"].isUndefined()){
        Label* label = new Label();
        LabelStorage::Read(json["label"].toObject(), label, env);

        label->Set(line);
        result->SetLabel(label);
    }
    if (!json["operand1"].isUndefined()){
        Operand* operand = nullptr;
        OperandStorage::Read(json["operand1"].toObject(), operand, env);
        result->SetOperand(0, operand);
    }
    if (!json["operand2"].isUndefined()){
        Operand* operand = nullptr;
        OperandStorage::Read(json["operand2"].toObject(), operand, env);
        result->SetOperand(1, operand);
    }
}

void StatementStorage::AddToJson(QJsonObject& json, string name, StorageBase* op) const{
    if (op == nullptr) return;

    QJsonObject operandJson;
    op->Write(operandJson);

    json[name.c_str()] = operandJson;
}

bool StatementStorage::InitializeStatement(string type, Statement*& result){
    return StatementFactory::BuildFromTypeString(type, result);
}
