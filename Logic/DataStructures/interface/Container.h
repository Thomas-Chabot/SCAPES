/*
 * Provides a wrapper around the data storage for some data.
 * Its main purpose in the system is to handle pointers of data, so that the data
 *   can be freed by deleting the container object.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */


#include <map>
#include <unordered_map>
#include <functional>
using namespace std;

#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
private:
  unordered_map<string, T*> *map;

public:
  typedef typename unordered_map<string, T*>::iterator iterator;

  Container(){
    map = new unordered_map<string, T*>();
  }
  ~Container(){
      this->FreeData();
      delete map;
  }

  bool Add(string name, T* data){
    if (Contains(name))
      return false;

    (*(this->map))[name] = data;
    return true;
  }

  bool Contains(string name){
    return (this->map->find(name) != this->map->end());
  }

  bool Get(string name, T** result){
    if (not this->Contains(name)){
      *result = nullptr;
      return false;
    }

    *result = ((*(this->map))[name]);
    return true;
  }

  void Clear(){
      this->FreeData();
      this->map->clear();
  }

  void Each(function<void (string, T*)> f){
      for (auto content : *this->map){
          f(content.first, content.second);
      }
  }

  void FreeData(){
      for (auto it = this->map->begin(); it != this->map->end(); ++it)
      {
        delete it->second;
      }
  }
};

#endif
