#include "DeclareIntStatement.h"
#include "IntVariable.h"
#include "VariableAlreadyExistsException.h"
#include "OperandFactory.h"

DeclareIntStatement::DeclareIntStatement() : DeclarationStatementBase(TYPE_DECLAREINT_STATEMENT, 1) {
}
DeclareIntStatement::DeclareIntStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : DeclarationStatementBase(TYPE_DECLAREINT_STATEMENT, line, env, label, OperandFactory::CreateNameOperand(op1, env), OperandFactory::CreateNullOperand(op2, env), 1)
{
}

void DeclareIntStatement::DeclareVariable(string name){
    IntVariable* var = new IntVariable(name);
    if (!this->Declare<IntVariable>(var))
        throw VariableAlreadyExistsException("IntVariable", name);
}
void DeclareIntStatement::ExecuteStatement(){

}
