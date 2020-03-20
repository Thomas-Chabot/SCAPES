/*
 * This is the base class responsible for Operand Storage.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "StorageBase.h"
#include "Operand.h"

#ifndef OPERAND_STORAGE_H
#define OPERAND_STORAGE_H

class OperandStorage : public StorageBase {
private:
    string operandType;

protected:
    string GetType();

    void WriteValue(QJsonObject& json, int value) const;
    void WriteValue(QJsonObject& json, string value) const;
public:
    OperandStorage(Operand* data);

    virtual void Write(QJsonObject &json) const override;
    static void Read(const QJsonObject &json, Operand*& result, Environment* data);

    static OperandStorage* Create(IOperand* data);
};

#endif
