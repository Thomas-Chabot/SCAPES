/*
 * This class provides helper functions for working with Regular Expressions for string matching.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include <string>
#include <regex>
#include <vector>
using namespace std;

#ifndef PARSERBASE_H
#define PARSERBASE_H

class ParserBase {
protected:
    // Returns true or false based on if the statement matches the given pattern
    static bool DoesMatch(string statement, regex pattern);

    // Returns a vector of matches for each match in the statement of the given pattern
    static void GetMatches(string statement, regex pattern, vector<string>& result);

    // Splits the statement into separate values, based on the given pattern
    static void Split(string statement, regex pattern, vector<string>& result);
};

#endif // PARSERBASE_H
