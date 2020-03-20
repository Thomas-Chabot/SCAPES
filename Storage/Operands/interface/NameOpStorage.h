// Handles the logic for reading/writing NameOperands from Storage
#include "NameOperand.h"
#include "OpStorage.h"

#ifndef NAMEOPSTORAGE_H
#define NAMEOPSTORAGE_H

class NameOpStorage : public OpStorage {
public:
    NameOpStorage(NameOperand* arr);

    void Read(const QJsonObject &json) override;
    void Write(QJsonObject &json) const override;
};

#endif // NAMEOPSTORAGE_H
