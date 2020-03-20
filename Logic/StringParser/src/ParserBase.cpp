#include "ParserBase.h"
#include <iterator>
using namespace std;

bool ParserBase::DoesMatch(string statement, regex pattern){
    return regex_match(statement, pattern);
}

void ParserBase::GetMatches(string statement, regex pattern, vector<string>& result){
    smatch match;
    regex_match(statement, match, pattern);
    for (unsigned int i = 1; i < match.size(); i++){
        result.push_back(match[i]);
    }
}

void ParserBase::Split(string statement, regex pattern, vector<string>& result){
    auto iter = sregex_token_iterator(statement.begin(), statement.end(), pattern, -1);
    for (sregex_token_iterator end; end != iter; iter++){
        result.push_back(iter->str());
    }
}

