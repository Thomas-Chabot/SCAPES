/*
 * The Environment constitutes the environment of a program;
 *   All the Identifiers, the comparison flag, etc.
 *
 * Written by Sean Hodges, last edited Nov. 13, 2019.
 */

#include "DataContainer.h"

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment {
private:
    DataContainer data;
    int comparisonFlag;
    int lineNumber;
    bool isRunning;

public:
    Environment();
    ~Environment();

    // End of Execution flag
    void StartRun();
    void EndExecution();
    bool IsRunning();

    // Line Number
    void SetLine(int line);
    int GetLine();

    // Comparison Flag
    void SetFlag(int value);
    int GetFlag();

    // Data Container methods
    template <class T>
    inline bool AddIdentifier(T* data);

    template <class T>
    inline bool GetIdentifier(string name, T*& result);

    template <class T>
    inline bool IdentifierExists(string name);
    bool AnyIdentifierExists(string name); // Checks against all identifiers

    template <class T>
    inline void EachIdentifier(function<void (T*)> f);
};


// Inline Code
template <class T>
bool Environment::AddIdentifier(T* data){
    return this->data.Add(data);
}

template <class T>
bool Environment::GetIdentifier(string name, T*& result){
    return this->data.Get(name, result);
}

template <class T>
bool Environment::IdentifierExists(string name){
    return this->data.Exists<T>(name);
}

template <class T>
void Environment::EachIdentifier(function<void (T*)> f){
    this->data.Each(f);
}

#endif // ENVIRONMENT_H
