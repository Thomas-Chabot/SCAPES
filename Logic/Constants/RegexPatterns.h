/*
 * This defines the Regex expressions that can be used to match SCAPL program data.
 *   It includes things like matching a single statement, an operand, etc.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

// Program Patterns

// This matches against the end of a line
#define SPLIT_LINE_PATTERN "[\\r\\n]"

// The Statement Pattern is complex; the idea is that we will look for:
//      LABEL : statementType operand1 operand2
//   or statementType operand1 operand2
//   or statementType "operand 1" operand2
// ...etc.
// The first result will be either the label or the statement type;
// The second result will be a flag, the character ':' if a label is provided, otherwise the empty string;
// The third result will be either the first operand or the statement type;
// The fourth result will be either the second or first operand;
// The fifth result will be the second operand (if a label was not provided);
// Beyond the fifth result, the program will return all additional data passed into the line.
#define STATEMENT_PATTERN "[ ]*([^ :]*)[ ]*([:]*)[ ]*(\".*?\"|[^ ]*)[ ]*(\".*?\"|[^ ]*)[ ]*(\".*?\"|[^ ]*)[ ]*(.*)$"

// This matches any line that contains no data; that is, a line which is made up of only whitespace.
#define BLANK_LINE_PATTERN "^[ ]*$"

// Operand Patterns
// This matches an operand; either parsing out the data for the operand as an array,
//  or the data for the operand as it is (a number, string, etc.)
#define OP_MATCH "^[$](.+)[+](.+)$"


// Matches against a string that is a number; must contain digits in all places except the first,
//   whereas the first character can either be a - (for a negative number) or a digit.
// Returns a null value if the string it is matched against is not a number.
#define NUMBER_MATCH "^[-]*[0-9]+$"
