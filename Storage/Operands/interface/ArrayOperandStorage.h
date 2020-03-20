/*
 * This class is responsible for the storage of ArrayOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "ArrayOperand.h"
#include "OperandWithNameStorage.h"

#ifndef ARRAYOPERANDSTORAGE_H
#define ARRAYOPERANDSTORAGE_H

class ArrayOperandStorage : public OperandStorage, public OperandWithNameStorage {
private:
    OperandStorage* index;

public:
    ArrayOperandStorage(ArrayOperand* data);

    virtual void Write(QJsonObject& json) const;
    static void Read(const QJsonObject& json, Operand*& result, Environment*);
};

#endif // ARRAYOPERANDSTORAGE_H
