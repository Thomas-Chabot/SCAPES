/*
 * This is the factory class to be used for creating Operands.
 *  It provides many different methods for declaring different types of operands;
 *  and takes in the OperandData containing the data for the operand.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Operand.h"
#include "OperandData.h"
#include <string>
using namespace std;

#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

class OperandFactory{
private:
public:
    // Any operand that stores some variable or value
    static Operand* CreateValueOperand(OperandData& opData, Environment* env, bool canAcceptString = false);

    // Operands to be used with jump statements; refer to labels
    static Operand* CreateLabelOperand(OperandData& opData, Environment* env);

    // Operands that must have literal values
    static Operand* CreateLiteralOperand(OperandData& opData, Environment* env);

    // Operands to be used with declarations; must define a variable name
    static Operand* CreateNameOperand(OperandData& opData, Environment* env);

    // For additional operands to statements; used when the operand should not be provided
    static Operand* CreateNullOperand(OperandData& opData, Environment* env);

    // For the index / size of an array; can be only very specific kinds of Operands
    static Operand* CreateIndexOperand(string value, Environment* env);
};

#endif // OPERANDFACTORY_H
