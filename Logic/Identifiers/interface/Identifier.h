/*
 * This is the base class for all Identifiers in the system.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "ClassDataTypes.h"
#include <string>
using namespace std;

#ifndef IDENTIFIER_H
#define IDENTIFIER_H

class Identifier {
private:
    string name;
    string type;

public:
    Identifier(string identifierType, string name);
    virtual ~Identifier();

    string GetName();
    void SetName(string name);

    string GetType();
};

#endif // IDENTIFIER_H
