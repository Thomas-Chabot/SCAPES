/*
 * This is the base class from which all other Storage objects derive.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */



// The base class for all objects that will be implemented as part of the Storage

#include <QJsonObject>

#ifndef STORAGEBASE_H
#define STORAGEBASE_H

class StorageBase {
private:
    void* data;

protected:
    void* GetDataPointer() const;

public:
    StorageBase(void *data);

    virtual ~StorageBase(){}
    virtual void Write(QJsonObject& json) const = 0;
};

#endif // STORAGEBASE_H
