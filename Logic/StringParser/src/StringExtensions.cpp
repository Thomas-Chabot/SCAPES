#include "StringExtensions.h"

bool StringExtensions::IsNumber(string s){
    regex pattern(NUMBER_MATCH);
    return DoesMatch(s, pattern);
}

bool StringExtensions::IsString(string s){
    return s[0] == QUOTE_CHAR && s[s.length()-1] == QUOTE_CHAR;
}
string StringExtensions::GetStringContents(string s){
    return s.substr(1, s.length()-2); // take out front quote & back quote
}
