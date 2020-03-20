#include "OperandParser.h"
#include "RegexPatterns.h"

void OperandParser::Parse(string opData, OperandData& result){
    regex arrayPattern(OP_MATCH);
    vector<string> matches;
    GetMatches(opData, arrayPattern, matches);

    if (matches.size() == 0){
        // In this case, it's just a standard variable / value
        result.SetValueData(opData);
        result.SetIndex("");
        result.SetIsArray(false);
    }else{
        result.SetValueData(matches[0]);
        result.SetIndex(matches[1]);
        result.SetIsArray(true);
    }


    /*bool isArray = matches[0] == "$";
    string opValue = matches[1];
    string arrayIndex = isArray ? matches[2] : "";

    result.SetValueData(opValue);
    result.SetIndex(arrayIndex);
    result.SetIsArray(isArray);*/
}
