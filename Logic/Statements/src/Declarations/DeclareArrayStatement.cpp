#include "DeclareArrayStatement.h"
#include "ArrayVariable.h"
#include "VariableAlreadyExistsException.h"
#include "OperandFactory.h"

DeclareArrayStatement::DeclareArrayStatement() : DeclarationStatementBase(TYPE_DECLAREARRAY_STATEMENT, 2) {
}
DeclareArrayStatement::DeclareArrayStatement(int line, Environment* env, Label* label, OperandData& op1, OperandData& op2)
    : DeclarationStatementBase(TYPE_DECLAREARRAY_STATEMENT, line, env, label, OperandFactory::CreateNameOperand(op1, env), OperandFactory::CreateIndexOperand(op2.GetValueData(), env), 2)
{
}

void DeclareArrayStatement::DeclareVariable(string name){
    Operand* op = this->GetOperand(1);
    ArrayVariable* var = new ArrayVariable(name, op);
    if (!this->Declare<ArrayVariable>(var))
        throw VariableAlreadyExistsException("ArrayVariable", name);
}
void DeclareArrayStatement::ExecuteStatement(){
    string name = this->GetOperand(0)->GetName();

    ArrayVariable* var;
    this->environment->GetIdentifier<ArrayVariable>(name, var);

    var->Initialize();
}
