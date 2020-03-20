/*
 * This class is responsible for the storage of ArrayIdentifiers.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "IdentifierStorageBase.h"
#include "OperandStorage.h"
#include "ArrayVariable.h"
#include <string>
using namespace std;

#ifndef ARRAYSTORAGE_H
#define ARRAYSTORAGE_H

class ArrayStorage : public IdentifierStorageBase
{
private:
    OperandStorage* size;

public:
    ArrayStorage();
    ArrayStorage(ArrayVariable* data);

    void Write(QJsonObject &json) const override;

    static void Read(const QJsonObject &json, ArrayVariable* result, Environment*);
};

#endif // ARRAYSTORAGE_H
