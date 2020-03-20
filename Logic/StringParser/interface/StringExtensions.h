/*
 * This provides extension methods that can be used
 *   in the program for handling string data.
 *
 * Written by Sean Hodges, last edited Nov. 8, 2019.
 */

#include "StringLiterals.h"
#include "ParserBase.h"
#include "RegexPatterns.h"
#include <string>
using namespace std;

#ifndef STRINGEXTENSIONS_H
#define STRINGEXTENSIONS_H

class StringExtensions : public ParserBase {
public:
    static bool IsNumber(string);
    static bool IsString(string);
    static string GetStringContents(string);
};

#endif // STRINGEXTENSIONS_H
