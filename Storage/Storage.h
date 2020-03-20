/*
 * This is the main control class for everything related to Storage.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "ArrayStorage.h"
#include "IntStorage.h"
#include "LabelStorage.h"
#include "ProgramStorage.h"

#include "Statement.h"
#include "Identifier.h"

#include "ClassDataTypes.h"

#include <string>
#include <vector>
using namespace std;

#ifndef STORAGE_H
#define STORAGE_H

class Storage {
private:
    ProgramStorage* program;
    string path;

protected:

public:
    Storage(string path);
    ~Storage();

    void AddIdentifier(Identifier* identifier);
    void AddStatement(Statement* statement);

    bool Save(string& errorMsg);
    bool Load(Program* program, string& errorMsg);
};

#endif // STORAGE_H
