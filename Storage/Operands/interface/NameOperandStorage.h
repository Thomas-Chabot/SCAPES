/*
 * This class is responsible for the storage of NameOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "NameOperand.h"
#include "OperandWithNameStorage.h"

#ifndef NAMEOPERANDSTORAGE_H
#define NAMEOPERANDSTORAGE_H

class NameOperandStorage : public OperandStorage, public OperandWithNameStorage {
private:

public:
    NameOperandStorage(NameOperand* data);

    void Write(QJsonObject &json) const override;
    static void Read(const QJsonObject &json, Operand*& result, Environment*);
};

#endif // NAMEOPERANDSTORAGE_H
