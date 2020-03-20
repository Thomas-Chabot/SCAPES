/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <CodeEditor.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionCompile;
    QAction *actionRun;
    QAction *actionLog;
    QAction *actionGetInput;
    QAction *actionWarn;
    QAction *actionError;
    QAction *actionConsole;
    QAction *actionSave;
    QAction *actionSave_As;
    QWidget *centralwidget;
    CodeEditor *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuProgram;
    QMenu *menuConsole;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionCompile = new QAction(MainWindow);
        actionCompile->setObjectName(QString::fromUtf8("actionCompile"));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionLog = new QAction(MainWindow);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionGetInput = new QAction(MainWindow);
        actionGetInput->setObjectName(QString::fromUtf8("actionGetInput"));
        actionWarn = new QAction(MainWindow);
        actionWarn->setObjectName(QString::fromUtf8("actionWarn"));
        actionError = new QAction(MainWindow);
        actionError->setObjectName(QString::fromUtf8("actionError"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new CodeEditor(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 10, 791, 481));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuProgram = new QMenu(menubar);
        menuProgram->setObjectName(QString::fromUtf8("menuProgram"));
        menuConsole = new QMenu(menubar);
        menuConsole->setObjectName(QString::fromUtf8("menuConsole"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuProgram->menuAction());
        menubar->addAction(menuConsole->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuProgram->addAction(actionCompile);
        menuProgram->addAction(actionRun);
        menuConsole->addAction(actionGetInput);
        menuConsole->addAction(actionLog);
        menuConsole->addAction(actionWarn);
        menuConsole->addAction(actionError);
        menuView->addAction(actionConsole);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionCompile->setText(QCoreApplication::translate("MainWindow", "Compile", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        actionLog->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        actionGetInput->setText(QCoreApplication::translate("MainWindow", "GetInput", nullptr));
        actionWarn->setText(QCoreApplication::translate("MainWindow", "Warn", nullptr));
        actionError->setText(QCoreApplication::translate("MainWindow", "Error", nullptr));
        actionConsole->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuProgram->setTitle(QCoreApplication::translate("MainWindow", "Program", nullptr));
        menuConsole->setTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
