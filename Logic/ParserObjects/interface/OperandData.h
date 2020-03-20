/*
 * This defines the user entered data for an Operand.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include <string>
using namespace std;

#ifndef OPERANDDATA_H
#define OPERANDDATA_H

class OperandData {
private:
    string valueData;
    string arrayIndex;
    bool isArray;

public:
    OperandData(string valueData, string arrayIndex, bool isArray);
    OperandData();

    string GetValueData();
    string GetIndex();
    bool IsArray();

    void SetValueData(string type);
    void SetIndex(string index);
    void SetIsArray(bool isArray);
};

#endif // OPERANDDATA_H
