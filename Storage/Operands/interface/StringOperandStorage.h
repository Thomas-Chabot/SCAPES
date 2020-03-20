/*
 * This class is responsible for the storage of StringOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "StringOperand.h"

#ifndef STRINGOPERANDSTORAGE_H
#define STRINGOPERANDSTORAGE_H

class StringOperandStorage : public OperandStorage {
private:
    string value;

public:
    StringOperandStorage(StringOperand* data);

    virtual void Write(QJsonObject& json) const;
    static void Read(const QJsonObject &json, Operand*& result, Environment*);
};

#endif // STRINGOPERANDSTORAGE_H
