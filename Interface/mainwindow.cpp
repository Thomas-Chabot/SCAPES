#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConsoleView.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    ui->menubar->removeAction(ui->menuConsole->menuAction());

    this->console = ConsoleView::GetSingleton(this);

    int width = QApplication::primaryScreen()->geometry().width();
    console->SetWidth(width);

    connect(ui->textEdit, SIGNAL(NewRequested()), this, SLOT(Key_NewRequested()));
    connect(ui->textEdit, SIGNAL(OpenRequested()), this, SLOT(Key_OpenRequested()));
    connect(ui->textEdit, SIGNAL(SaveRequested()), this, SLOT(Key_SaveRequested()));
    connect(ui->textEdit, SIGNAL(SaveAsRequested()), this, SLOT(Key_SaveAsRequested()));
}

MainWindow::~MainWindow()
{
    delete console;
    delete ui;
}

bool MainWindow::IsModified(){
    return ui->textEdit->document()->isModified();
}
void MainWindow::SetModified(bool isModified){
    ui->textEdit->document()->setModified(isModified);
}

const QString MainWindow::GetText(){
    return ui->textEdit->toPlainText();
}
void MainWindow::SetText(QString text){
    ui->textEdit->document()->setPlainText(text);
}
void MainWindow::ClearText(){
    ui->textEdit->clear();
}

void MainWindow::SetTitle(QString title){
    this->setWindowTitle(title);
}


void MainWindow::closeEvent(QCloseEvent *event){
    // we can't quit here because the user may want to save first;
    // emit the CloseRequested() event and let the main control handle it
    event->ignore();
    emit CloseRequested();
}

void MainWindow::on_actionNew_triggered()
{
    emit NewRequested();
}

void MainWindow::on_actionConsole_triggered()
{
    console->Show();
}

void MainWindow::on_actionSave_triggered()
{
    emit SaveRequested();
}

void MainWindow::on_actionSave_As_triggered()
{
    emit SaveAsRequested();
}

void MainWindow::on_actionOpen_triggered()
{
    emit OpenRequested();
}


void MainWindow::on_textEdit_textChanged()
{
    emit TextChanged();
}

void MainWindow::on_actionCompile_triggered()
{
    emit CompileRequested();
}
void MainWindow::on_actionRun_triggered()
{
    emit ExecuteRequested();
}

void MainWindow::on_actionClear_triggered()
{
    console->Clear();
}

void MainWindow::Key_NewRequested(){
    emit NewRequested();
}
void MainWindow::Key_SaveRequested(){
    emit SaveRequested();
}
void MainWindow::Key_SaveAsRequested(){
    emit SaveAsRequested();
}
void MainWindow::Key_OpenRequested(){
    emit OpenRequested();
}
