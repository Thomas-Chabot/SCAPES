#include "OperandWithName.h"
#include "OperandStorage.h"

#ifndef OPERANDWITHNAMESTORAGE_H
#define OPERANDWITHNAMESTORAGE_H

class OperandWithNameStorage {
private:
    string name;

protected:
    static void Read(const QJsonObject &json, OperandWithName* result);

public:
    OperandWithNameStorage(OperandWithName* data);

    virtual void Write(QJsonObject &json) const;
};

#endif // OPERANDWITHNAMESTORAGE_H
