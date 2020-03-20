#include "Storage.h"
#include "Constants.h"
#include <QFile>
#include <QJsonDocument>

#define ERROR_FILE_NOT_WRITABLE "The program could not be opened for writing."
#define ERROR_FILE_NOT_READABLE "The program could not be opened for reading."

Storage::Storage(string path){
    this->program = new ProgramStorage();
    this->path = path;
}
Storage::~Storage(){
    delete this->program;
}

void Storage::AddIdentifier(Identifier* data){
    if (data->GetType() == TYPE_INT_IDENTIFIER)
        this->program->AddInt(new IntStorage(static_cast<IntVariable*>(data)));
    else if (data->GetType() == TYPE_ARRAY_IDENTIFIER)
        this->program->AddArray(new ArrayStorage(static_cast<ArrayVariable*>(data)));
    else{
        // TODO: what do here
    }
}
void Storage::AddStatement(Statement *statement){
    this->program->AddStatement(new StatementStorage(statement));
}

bool Storage::Save(string& errorMsg){
    // Get the absolute path, file name, and extension
    string fullName = this->path;

    // Save the file
    QFile saveFile(QString::fromStdString(fullName));
    if (!saveFile.open(QIODevice::WriteOnly)){
        errorMsg = ERROR_FILE_NOT_WRITABLE;
        return false;
    }

    QJsonObject json;
    this->program->Write(json);

    QJsonDocument saveDocument(json);
    saveFile.write(saveDocument.toJson());

    return true;
}

bool Storage::Load(Program* program, string& errorMsg){
    string fullName = this->path;

    // Load the file
    QFile loadFile(QString::fromStdString(fullName));
    if (!loadFile.open(QIODevice::ReadOnly)){
        errorMsg = ERROR_FILE_NOT_READABLE;
        return false;
    }

    QByteArray fileContents = loadFile.readAll();
    QJsonDocument compilationData(QJsonDocument::fromJson(fileContents));

    try{
        ProgramStorage::Read(compilationData.object(), program);
    } catch (exception& ex){
        errorMsg = ex.what();
        return false;
    }

    return true;
}
