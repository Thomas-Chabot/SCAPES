#include "ProgramParser.h"
#include "RegexPatterns.h"

void ProgramParser::SplitByLine(string statement, vector<string>& container){
    regex pattern(SPLIT_LINE_PATTERN);
    Split(statement, pattern, container);
}

void ProgramParser::ParseLine(string line, ProgramData& result){
    regex pattern(STATEMENT_PATTERN);
    vector<string> data;

    GetMatches(line, pattern, data);

    // The match at index 1 is a flag: will be : if there's a label, otherwise a space
    bool hasLabel = data[1] == ":";
    unsigned long labelOffset = hasLabel ? 2 : 1;

    string label = hasLabel ? data[0] : "";
    string instruction = hasLabel ? data[labelOffset] : data[0];
    string op1 = data[labelOffset + 1];
    string op2 = data[labelOffset + 2];

    bool hasMoreDataFlag = data.size() > 5 && data[5] != "";

    result.SetLabel(label);
    result.SetInstruction(instruction);
    result.SetOperand1(op1);
    result.SetOperand2(op2);
    result.SetHasMoreData(hasMoreDataFlag);
}

bool ProgramParser::IsEmptyLine(string line){
    regex pattern(BLANK_LINE_PATTERN);
    return DoesMatch(line, pattern);
}
