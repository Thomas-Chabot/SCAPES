#include "StorageBase.h"
#include "Identifier.h"
#include "Environment.h"
#include <string>
using namespace std;

#ifndef IDENTIFIERSTORAGEBASE_H
#define IDENTIFIERSTORAGEBASE_H

class IdentifierStorageBase : public StorageBase {
private:
    string name;

protected:

public:
    IdentifierStorageBase(Identifier*);

    virtual void Write(QJsonObject &json) const override;

    static void Read(const QJsonObject &json, Identifier* result, Environment*);
};

#endif // IDENTIFIERSTORAGEBASE_H
