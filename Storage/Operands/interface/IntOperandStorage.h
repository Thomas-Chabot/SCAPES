/*
 * This class is responsible for the storage of IntOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "IntOperand.h"
#include "OperandWithNameStorage.h"

#ifndef INTOPERANDSTORAGE_H
#define INTOPERANDSTORAGE_H

class IntOperandStorage : public OperandStorage, public OperandWithNameStorage {
private:

public:
    IntOperandStorage(IntOperand* data);

    void Write(QJsonObject &json) const override;
    static void Read(const QJsonObject &json, Operand*& result, Environment*);
};

#endif // INTOPERANDSTORAGE_H
