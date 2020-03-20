/*
 * This class is responsible for the storage of LiteralOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "LiteralOperand.h"

#ifndef LITERALOPERANDSTORAGE_H
#define LITERALOPERANDSTORAGE_H

class LiteralOperandStorage : public OperandStorage {
private:
    int value;

public:
    LiteralOperandStorage(LiteralOperand* data);

    virtual void Write(QJsonObject& json) const override;
    static void Read(const QJsonObject &json, Operand*& result, Environment*);
};

#endif // LITERALOPERANDSTORAGE_H
