/*
 * This class takes care of all FileSystem manipulation, such as loading and saving files.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include "Constants.h"

#ifndef FILECONTROL_H
#define FILECONTROL_H


class FileControl : public QObject
{
    Q_OBJECT

private:
    QString filePath;

    bool SaveFile(const QString& filePath, const QString& contents, QString& errorMsg);
    bool LoadFile(const QString &fileName, QString& contents, QString& errorMsg);
    void SetCurrentFile(const QString& filePath);

public:
    FileControl();

    bool Save(const QString& contents, QString& errorMsg);
    bool SaveAs(const QString& contents, QString& errorMsg);
    bool Open(QString& contents, QString& errorMsg);
    void New();

    bool HasCompilationOutput();

    const QString GetCompilationPath();
    const QString& GetProgramPath();
signals:
    void FilePathUpdated(const QString newPath);
};

#endif // FILECONTROL_H
