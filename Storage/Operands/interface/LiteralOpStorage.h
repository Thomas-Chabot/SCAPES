// Handles the logic for reading/writing Literals from Storage

#include "LiteralOperand.h"
#include "OpStorage.h"

#ifndef LITERALOPSTORAGE_H
#define LITERALOPSTORAGE_H

class LiteralOpStorage : public OpStorage {
public:
    LiteralOpStorage(LiteralOperand* arr);

    void Read(const QJsonObject &json) override;
    void Write(QJsonObject &json) const override;
};

#endif // LITERALOPSTORAGE_H
