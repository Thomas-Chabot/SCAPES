/*
 * This class is responsible for the storage of LabelOperands.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "OperandStorage.h"
#include "LabelOperand.h"
#include "OperandWithNameStorage.h"

#ifndef LABELOPERANDSTORAGE_H
#define LABELOPERANDSTORAGE_H

class LabelOperandStorage : public OperandStorage, public OperandWithNameStorage {
private:

public:
    LabelOperandStorage(LabelOperand* data);

    void Write(QJsonObject &json) const override;
    static void Read(const QJsonObject &json, Operand*& result, Environment*);
};

#endif // LABELOPERANDSTORAGE_H
