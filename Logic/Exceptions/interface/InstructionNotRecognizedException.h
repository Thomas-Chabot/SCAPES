/*
 * Defines an Exception for when an instruction type has been used but is not recognized.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "BaseException.h"

#ifndef INSTRUCTIONNOTRECOGNIZEDEXCEPTION_H
#define INSTRUCTIONNOTRECOGNIZEDEXCEPTION_H

class InstructionNotRecognizedException : public BaseException {
public:
    InstructionNotRecognizedException(string instruction)
        : BaseException("Instruction Type not recognized: '" + instruction + "'")
    {
    }
};

#endif // INSTRUCTIONNOTRECOGNIZEDEXCEPTION_H
