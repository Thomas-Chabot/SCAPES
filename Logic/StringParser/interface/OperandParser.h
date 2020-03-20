/*
 * This class parses out the data for a single operand from the program.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "ParserBase.h"
#include "OperandData.h"

#ifndef OPERANDPARSER_H
#define OPERANDPARSER_H

class OperandParser : ParserBase {
public:
    static void Parse(string opData, OperandData& result);
};

#endif // OPERANDPARSER_H
