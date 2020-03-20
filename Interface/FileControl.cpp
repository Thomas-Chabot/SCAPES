#include "FileControl.h"

FileControl::FileControl()
{
    this->filePath = "";
}

const QString& FileControl::GetProgramPath(){
    return this->filePath;
}
const QString FileControl::GetCompilationPath(){
    // Compiled file = Folder + Filename + . + Scaplc
    QFileInfo data(this->filePath);
    return data.path() + '/' + data.baseName() + COMPILATION_FILE_EXTENSION;
}

bool FileControl::Save(const QString& contents, QString& errorMsg){
    if (this->filePath.isEmpty()) {
        return this->SaveAs(contents, errorMsg);
    } else {
        return SaveFile(this->filePath, contents, errorMsg);
    }
}
bool FileControl::Open(QString& contents, QString& errorMsg){
    QString fileName = QFileDialog::getOpenFileName(nullptr);
    if (!fileName.isEmpty())
        return LoadFile(fileName, contents, errorMsg);

    errorMsg = ERROR_OP_CANCELLED;
    return false;
}

bool FileControl::SaveAs(const QString& contents, QString& errorMsg){
    QFileDialog dialog(nullptr);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted){
        errorMsg = ERROR_OP_CANCELLED;
        return false;
    }
    return SaveFile(dialog.selectedFiles().first(), contents, errorMsg);
}

void FileControl::New(){
    SetCurrentFile("");
}

bool FileControl::SaveFile(const QString& filePath, const QString& contents, QString& errorMsg){
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        errorMsg = QString(ERROR_CANNOT_WRITE).arg(QDir::toNativeSeparators(filePath),
                                                   file.errorString());
        return false;
    }

    QTextStream out(&file);
    out << contents;
    SetCurrentFile(filePath);

    return true;
}

bool FileControl::LoadFile(const QString &fileName, QString& contents, QString& errorMsg)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        errorMsg = QString(ERROR_CANNOT_READ).arg(QDir::toNativeSeparators(fileName), file.errorString());
        return false;
    }

    QTextStream in(&file);
    contents = in.readAll();

    SetCurrentFile(fileName);
    return true;
}

void FileControl::SetCurrentFile(const QString& path){
    this->filePath = path;
    emit FilePathUpdated(path);
}

bool FileControl::HasCompilationOutput(){
    return QFileInfo::exists(this->GetCompilationPath());
}
