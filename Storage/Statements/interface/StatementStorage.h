/*
 * This class is responsible for the storage of Statements.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "Statement.h"
#include "StorageBase.h"
#include "OperandStorage.h"
#include "LabelStorage.h"

#ifndef STATEMENTSTORAGE_CPP
#define STATEMENTSTORAGE_CPP

class StatementStorage : public StorageBase {
private:
    string statementType;
    int lineNumber;
    OperandStorage* op1;
    OperandStorage* op2;
    LabelStorage* label;


    void AddToJson(QJsonObject& json, string name, StorageBase* op) const;
    static bool InitializeStatement(const string type, Statement*& result);
public:
    StatementStorage(Statement* statement);
    ~StatementStorage() override;

    void Write(QJsonObject &json) const override;

    static void Read(const QJsonObject &json, Statement*& result, Environment* env);
};

#endif // STATEMENTSTORAGE_CPP
