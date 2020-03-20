/*
 * This class is responsible for the storage of IntIdentifiers.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "IdentifierStorageBase.h"
#include "IntVariable.h"
#include <string>
using namespace std;

#ifndef INTSTORAGE_H
#define INTSTORAGE_H

class IntStorage : public IdentifierStorageBase {
private:

public:
    IntStorage();
    IntStorage(IntVariable* data);
};

#endif // INTSTORAGE_H
