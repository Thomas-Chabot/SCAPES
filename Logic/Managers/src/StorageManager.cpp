/*
 * NOTE: This stores the Storage as a void pointer;
 *  That way, the Storage is not stored in the header and this fixes the
 *  circular dependencies issue.
 *
 * Written by Sean Hodges, last edited Nov 13 2019
 */

#include "StorageManager.h"
#include "Storage.h"

StorageManager::StorageManager(string path){
    this->storage = new Storage(path);
}
StorageManager::~StorageManager(){
    delete static_cast<Storage*>(this->storage);
}

void StorageManager::AddIdentifier(Identifier *data){
    static_cast<Storage*>(this->storage)->AddIdentifier(data);
}
void StorageManager::AddStatement(Statement *data){
    static_cast<Storage*>(this->storage)->AddStatement(data);
}

bool StorageManager::Save(string& errorMsg){
    return static_cast<Storage*>(this->storage)->Save(errorMsg);
}
bool StorageManager::Load(Program *program, string &errorMsg){
    return static_cast<Storage*>(this->storage)->Load(program, errorMsg);
}
