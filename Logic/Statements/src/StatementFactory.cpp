#include "StatementFactory.h"
#include "AddStatement.h"
#include "CompareStatement.h"
#include "DeclareIntStatement.h"
#include "DeclareArrayStatement.h"
#include "EndStatement.h"
#include "JumpStatement.h"
#include "JumpEqualStatement.h"
#include "JumpLessStatement.h"
#include "JumpMoreStatement.h"
#include "MoveStatement.h"
#include "PrintStatement.h"
#include "ReadIntStatement.h"

Statement* StatementFactory::CreateStatement(int line, string statementType, Environment* env, Label* label, OperandData& operand1, OperandData& operand2){
    if (statementType == INSTRUCTION_ADD)
        return new AddStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_DECLAREINT)
        return new DeclareIntStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_DECLAREARRAY)
        return new DeclareArrayStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_READINT)
        return new ReadIntStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_PRINT)
        return new PrintStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_COMPARE)
        return new CompareStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_JUMPEQUAL)
        return new JumpEqualStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_JUMPLESS)
        return new JumpLessStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_JUMPMORE)
        return new JumpMoreStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_JUMP)
        return new JumpStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_MOVE)
        return new MoveStatement(line, env, label, operand1, operand2);
    else if (statementType == INSTRUCTION_END)
        return new EndStatement(line, env, label, operand1, operand2);
    return nullptr;
}

bool StatementFactory::BuildFromTypeString(string type, Statement*& result){
    result = nullptr;
    if (type == TYPE_ADD_STATEMENT)
        result = new AddStatement();
    else if (type == TYPE_COMPARE_STATEMENT)
        result = new CompareStatement();
    else if (type == TYPE_DECLAREINT_STATEMENT)
        result = new DeclareIntStatement();
    else if (type == TYPE_DECLAREARRAY_STATEMENT)
        result = new DeclareArrayStatement();
    else if (type == TYPE_END_STATEMENT)
        result = new EndStatement();
    else if (type == TYPE_JUMPEQUAL_STATEMENT)
        result = new JumpEqualStatement();
    else if (type == TYPE_JUMPLESS_STATEMENT)
        result = new JumpLessStatement();
    else if (type == TYPE_JUMPMORE_STATEMENT)
        result = new JumpMoreStatement();
    else if (type == TYPE_JUMP_STATEMENT)
        result = new JumpStatement();
    else if (type == TYPE_MOVE_STATEMENT)
        result = new MoveStatement();
    else if (type == TYPE_PRINT_STATEMENT)
        result = new PrintStatement();
    else if (type == TYPE_READINT_STATEMENT)
        result = new ReadIntStatement();

    return result == nullptr;
}
