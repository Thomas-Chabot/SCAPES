/*
 * This is the main class for handling matching against the program code.
 *   It converts the string data used for the program into internal data that can be used
 *   with the CompileControl class.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */


#include "ParserBase.h"

#include <vector>
#include <string>
#include <regex>
#include "ProgramData.h"
using namespace std;

#ifndef STRING_LIB_H
#define STRING_LIB_H

class ProgramParser : ParserBase{
public:
    static void SplitByLine(string statement, vector<string>& result);
    static void ParseLine(string line, ProgramData& result);
    static bool IsEmptyLine(string line);
};

#endif
