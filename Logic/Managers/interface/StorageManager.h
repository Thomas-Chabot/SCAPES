/*
 * This is the Facade class that can be used to communicate with Storage.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "Identifier.h"
#include "Statement.h"
#include "Program.h"

#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

class StorageManager{
private:
    void* storage;

public:
    StorageManager(string path);
    ~StorageManager();

    void AddIdentifier(Identifier* data);
    void AddStatement(Statement* data);

    bool Save(string& errorMsg);
    bool Load(Program* program, string& errorMsg);
};

#endif
