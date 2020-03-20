#include "PrintStatement.h"
#include "OperandFactory.h"
#include "UserInterface.h"

PrintStatement::PrintStatement() : Statement(TYPE_PRINT_STATEMENT, 0, nullptr, nullptr, nullptr, nullptr, 1) { }
PrintStatement::PrintStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : Statement(TYPE_PRINT_STATEMENT, line, env, label, OperandFactory::CreateValueOperand(op1, env, true), OperandFactory::CreateNullOperand(op2, env), 1)
{
}

void PrintStatement::Compile(){
    Statement::Compile();
}
void PrintStatement::Run(){
    Operand* op = this->GetOperand(0);
    UserInterface& ui = UserInterface::GetSingleton();
    if (op->GetType() == TYPE_STRING_OPERAND){
        // In this case, we need to react to the string value
        string value;
        op->GetValue(value);

        ui.Log(value);
    }else{
        int value;
        op->GetValue(value);
        ui.Log(to_string(value));
    }
}

void PrintStatement::ValidateOperations(){
  this->CheckReadable(this->GetOperand(0));
}
