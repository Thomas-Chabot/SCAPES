#include "OperandFactory.h"
#include "ArrayOperand.cpp"
#include "IntOperand.cpp"
#include "LabelOperand.cpp"
#include "LiteralOperand.cpp"
#include "StringOperand.h"
#include "NameOperand.cpp"

#include "InvalidTypeException.h"
#include "ExpectingNullException.h"
#include "CannotBeStringOperandException.h"

#include "StringExtensions.h"

void CheckNotArray(OperandData& opData){
    if (opData.IsArray() || opData.GetIndex() != "")
        throw InvalidTypeException(opData.GetValueData(), DATA_TYPE_ARRAY);
}

Operand* CreateLiteral(string value, Environment* env){
    int actualValue = stoi(value);
    return new LiteralOperand(actualValue, env);
}

Operand* OperandFactory::CreateIndexOperand(string indexValue, Environment* env){
    if (StringExtensions::IsNumber(indexValue))
        return CreateLiteral(indexValue, env);

    return new IntOperand(indexValue, env);

}
Operand* OperandFactory::CreateValueOperand(OperandData& opData, Environment* env, bool canAcceptString){
    string value = opData.GetValueData();
    if (value == "") return nullptr;

    if (opData.IsArray())
        return new ArrayOperand(value, opData.GetIndex(), env);
    if (StringExtensions::IsNumber(value))
        return CreateLiteral(value, env);
    if (StringExtensions::IsString(value)) {
        if (!canAcceptString)
            throw CannotBeStringOperandException();
        return new StringOperand(StringExtensions::GetStringContents(value), env);
    }
    return new IntOperand(opData.GetValueData(), env);
}
Operand* OperandFactory::CreateLabelOperand(OperandData& opData, Environment* env){
    if (opData.GetValueData() == "") return nullptr;

    CheckNotArray(opData);
    return new LabelOperand(opData.GetValueData(), env);
}
Operand* OperandFactory::CreateLiteralOperand(OperandData& opData, Environment* env){
    string value = opData.GetValueData();
    if (value == "") return nullptr;

    CheckNotArray(opData);
    if (!StringExtensions::IsNumber(value))
        throw InvalidTypeException(value, DATA_TYPE_OPERAND);

    return CreateLiteral(value, env);
}
Operand* OperandFactory::CreateNameOperand(OperandData& opData, Environment* env){
    if (opData.GetValueData() == "") return nullptr;

    CheckNotArray(opData);
    return new NameOperand(opData.GetValueData(), env);
}

Operand* OperandFactory::CreateNullOperand(OperandData& opData, Environment*){
    CheckNotArray(opData);
    if (opData.GetValueData() != "")
        throw ExpectingNullException(opData.GetValueData());
    return nullptr;
}
