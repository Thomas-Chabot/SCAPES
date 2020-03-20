#include "BaseException.h"

#ifndef JUMPEDTOVARIABLEDECLARATION_H
#define JUMPEDTOVARIABLEDECLARATION_H

class JumpedToVariableDeclarationException : public BaseException {
public:
    JumpedToVariableDeclarationException() : BaseException("A declaration statement was hit multiple times") { } // TODO better name
};


#endif // JUMPEDTOVARIABLEDECLARATION_H
