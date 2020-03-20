// Handles the logic of converting an ArrayOperand to JSON data
// And converting that JSON data back into an ArrayOperand
#include "ArrayOperand.h"
#include "OpStorage.h"

#ifndef ARRAYOPSTORAGE_H
#define ARRAYOPSTORAGE_H

class ArrayOpStorage : public OpStorage {
public:
    ArrayOpStorage(ArrayOperand* arr);

    void Read(const QJsonObject &json) override;
    void Write(QJsonObject &json) const override;
};

#endif // ARRAYOPSTORAGE_H
