#include "StorageBase.h"

StorageBase::StorageBase(void* pointer){
    this->data = pointer;
}

void* StorageBase::GetDataPointer() const{
    return this->data;
}
