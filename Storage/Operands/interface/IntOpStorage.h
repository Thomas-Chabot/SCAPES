#include "IntOperand.h"
#include "OpStorage.h"

#ifndef INTOPSTORAGE_H
#define INTOPSTORAGE_H

class IntOpStorage : public OpStorage {
public:
    IntOpStorage(IntOperand* arr);

    void Read(const QJsonObject &json) override;
    void Write(QJsonObject &json) const override;
};

#endif // INTOPSTORAGE_H
