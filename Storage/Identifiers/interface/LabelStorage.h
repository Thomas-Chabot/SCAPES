/*
 * This class is responsible for the storage of Labels.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "IdentifierStorageBase.h"
#include "Label.h"
#include <string>
using namespace std;

#ifndef LABELSTORAGE_H
#define LABELSTORAGE_H

class LabelStorage : public IdentifierStorageBase {
private:

public:
    LabelStorage();
    LabelStorage(Label* data);
};

#endif // LABELSTORAGE_H
