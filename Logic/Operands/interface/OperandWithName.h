#include <string>
using namespace std;

#ifndef OPERANDWITHNAME_H
#define OPERANDWITHNAME_H

class OperandWithName  {
protected:
    string name;

public:
    OperandWithName(string name);

    string GetName();
    void SetName(string name);
};

#endif // OPERANDWITHNAME_H
