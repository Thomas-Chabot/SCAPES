#ifndef UICONTROL_H
#define UICONTROL_H

#include <QObject>

#include "FileControl.h"
#include "mainwindow.h"

class UIControl : public QObject
{
    Q_OBJECT

public:
    explicit UIControl(QObject *parent = nullptr);
    void Start();

protected:
    bool Compile();
    bool Execute();
    bool Save();
    void SaveAs();
    void New();
    void Open();

    bool IsModified();
    bool IsCompiled();

    bool CheckSave(QString message, bool canCancel = true);
    void CheckClose();

    void UpdateTitle();
    void SetNotModified();

private:
    FileControl file;
    MainWindow window;

signals:

public slots:
    void onCompileRequested();
    void onCloseRequested();
    void onExecuteRequested();
    void onNewRequested();
    void onOpenRequested();
    void onSaveRequested();
    void onSaveAsRequested();
    void onTextChanged();

    void onFilePathUpdated(QString);
};

#endif // UICONTROL_H
