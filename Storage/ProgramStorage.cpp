#include "ProgramStorage.h"
#include <QJsonArray>
#include <type_traits>

template <typename T>
void Free(vector<T*> vector);

template <typename T>
void WriteToArray(vector<T*> objects, QJsonArray& arr);
void ReadArray(QJsonValue value, function<void(QJsonObject)> f);

ProgramStorage::ProgramStorage() : StorageBase(nullptr){

}
ProgramStorage::~ProgramStorage(){
    Free(this->arrays);
    Free(this->ints);
}

void ProgramStorage::AddArray(ArrayStorage* arr){
    this->arrays.push_back(arr);
}
void ProgramStorage::AddInt(IntStorage* intVar){
    this->ints.push_back(intVar);
}
void ProgramStorage::AddStatement(StatementStorage* statement){
    this->statements.push_back(statement);
}

void ProgramStorage::Write(QJsonObject &json) const{
    QJsonArray arrays, ints, literals, statements;

    WriteToArray(this->arrays, arrays);
    WriteToArray(this->ints, ints);
    WriteToArray(this->statements, statements);

    json["statements"] = statements;
    json["arrays"] = arrays;
    json["ints"] = ints;
}

void ProgramStorage::Read(const QJsonObject &json, Program* result){
    Environment* env = result->GetEnvironment();

    ReadArray(json["ints"], [&result, env](QJsonObject obj){
        IntVariable* variable = new IntVariable();
        IntStorage::Read(obj, variable, env);

        result->AddIntVariable(variable);
    });
    ReadArray(json["arrays"], [&result, env](QJsonObject obj){
        ArrayVariable* variable = new ArrayVariable();
        ArrayStorage::Read(obj, variable, env);

        result->AddArrayVariable(variable);
    });
    ReadArray(json["statements"], [&result, env](QJsonObject obj){
        Statement* statement = nullptr;
        StatementStorage::Read(obj, statement, env); // Statement gets created inside here

        result->AddStatement(statement);
    });
}


// write all the data from a given vector into a QJsonArray object
// NOTE: T must implement Write() for this method to work
template <typename T>
void WriteToArray(vector<T*> objects, QJsonArray& array){
    for (auto obj : objects){
        QJsonObject jsonObject;
        obj->Write(jsonObject);

        array.append(jsonObject);
    }
}

// This function wraps around a reference to some QJsonArray, and calls a
//  function to initialize all the values of that array
void ReadArray(QJsonValue value, function<void(QJsonObject)> f){
    QJsonArray array = value.toArray();
    for (QJsonValueRef value : array){
        QJsonObject obj = value.toObject();
        f(obj);
    }
}

// free up all the data used for a vector
template <typename T>
void Free(vector<T*> vector){
    for (auto obj : vector){
        delete obj;
    }
}

