/*
 * This is the DataContainer class that stores all Identifiers in the program.
 *  It provides operations for getting Array Variables, Labels, and Int Variables.
 *
 * The class implements the Singleton Design Pattern to ensure data is constant
 *   through the entire system.
 *
 * All template methods can be provided with either:
 *   ArrayVariable
 *   IntVariable
 *   Label
 * Any attempt to call the method without providing one of these three data types
 *   will result in a return value of null.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "ArrayVariable.h"
#include "IntVariable.h"
#include "Label.h"
#include "Container.h"

#ifndef DATA_CONTAINER_H
#define DATA_CONTAINER_H

/* Interface */
class DataContainer {
private:
  Container<ArrayVariable>* arrayVariables;
  Container<IntVariable>* intVariables;
  Container<Label>* labels;

  template <class T> Container<T>* GetContainer();
public:
  inline DataContainer();
  inline ~DataContainer();

  template <class T>
  inline bool Add(T* data);

  template <class T>
  inline bool Get(string name, T*& data);

  template <class T>
  inline bool Exists(string name);
  inline bool Contains(string name); // checks all identifiers

  inline void Reset();

  template <class T>
  inline void Each(function<void (T*)> f);
};

/* Implementation */
DataContainer::DataContainer(){
  this->arrayVariables = new Container<ArrayVariable>();
  this->intVariables = new Container<IntVariable>();
  this->labels = new Container<Label>();
}
DataContainer::~DataContainer(){
    delete this->arrayVariables;
    delete this->intVariables;
    delete this->labels;
}

void DataContainer::Reset(){
    this->arrayVariables->Clear();
    this->intVariables->Clear();
    this->labels->Clear();
}

template <class T>
bool DataContainer::Add(T* variable){
  return this->GetContainer<T>()->Add(variable->GetName(), variable);
}

template <class T>
bool DataContainer::Get(string name, T*& data){
  return this->GetContainer<T>()->Get(name, &data);
}

template <class T>
bool DataContainer::Exists(string name){
  return this->GetContainer<T>()->Contains(name);
}

bool DataContainer::Contains(string name){
    return this->Exists<Label>(name) || this->Exists<IntVariable>(name);
}

template <class T>
void DataContainer::Each(function<void (T*)> f){
    this->GetContainer<T>()->Each([&f](string, T* data){
       f(data);
    });
}

template <class T> Container<T>* DataContainer::GetContainer(){
  return NULL;
}
template<> inline Container<ArrayVariable>* DataContainer::GetContainer<ArrayVariable>(){
  return this->arrayVariables;
}
template<> inline Container<IntVariable>* DataContainer::GetContainer<IntVariable>(){
  return this->intVariables;
}
template<> inline Container<Label>* DataContainer::GetContainer<Label>(){
  return this->labels;
}

#endif
