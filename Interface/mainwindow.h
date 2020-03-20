/*
 * This class controls the main window of SCAPES and handles all user interaction.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "ConsoleView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool IsModified();
    void SetModified(bool);

    const QString GetText();
    void SetText(QString);
    void ClearText();

    void SetTitle(QString);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actionNew_triggered();

    void on_actionConsole_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionOpen_triggered();

    void Key_OpenRequested();
    void Key_SaveRequested();
    void Key_SaveAsRequested();
    void Key_NewRequested();

    void on_textEdit_textChanged();

    void on_actionCompile_triggered();

    void on_actionClear_triggered();

    void on_actionRun_triggered();

private:
    Ui::MainWindow *ui;
    ConsoleView* console;

signals:
    void CompileRequested();
    void CloseRequested();
    void ExecuteRequested();
    void NewRequested();
    void OpenRequested();
    void SaveRequested();
    void SaveAsRequested();

    void TextChanged();
};

#endif // MAINWINDOW_H
