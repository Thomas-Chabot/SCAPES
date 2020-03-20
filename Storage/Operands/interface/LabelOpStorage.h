// Handles the logic for reading/writing LabelOperands into storage

#include "LabelOperand.h"
#include "OpStorage.h"

#ifndef LABELOPSTORAGE_H
#define LABELOPSTORAGE_H

class LabelOpStorage : public OpStorage {
public:
    LabelOpStorage(LabelOperand* arr);

    void Read(const QJsonObject &json) override;
    void Write(QJsonObject &json) const override;
};

#endif // LABELOPSTORAGE_H
