#include "ConsoleView.h"
#include <QIntValidator>
#include <LineNumberArea.h>

ConsoleView::ConsoleView(QMainWindow* mainWindow){
    QDockWidget *dock = new QDockWidget(mainWindow);
    QScrollArea *scrollArea = new QScrollArea();
    QWidget *contentWidget = new QWidget();
    QGridLayout *layout = new QGridLayout();

    QLabel* lineHeader = new QLabel();
    QLabel* messageHeader = new QLabel();
    QWidget* empty = new QWidget();

    lineHeader->setText("#");
    messageHeader->setText("Message");

    lineHeader->setStyleSheet("font-weight: bold");
    messageHeader->setStyleSheet("font-weight: bold");

    empty->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    layout->setAlignment(Qt::AlignTop);

    layout->addWidget(lineHeader, 0, 0);
    layout->addWidget(messageHeader, 0, 1);
    layout->addWidget(empty, 0, 2);
    contentWidget->setLayout(layout);
    scrollArea->setWidget(contentWidget);
    scrollArea->setWidgetResizable(true);
    dock->setWidget(scrollArea);
    mainWindow->addDockWidget(Qt::BottomDockWidgetArea, dock);

    QObject::connect(scrollArea->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(ScrollToBottom(int, int)));

    this->outputWidget = dock;
    this->scrollArea = scrollArea;
    this->content = contentWidget;
    this->mainLayout = layout;
}
ConsoleView::~ConsoleView(){
    delete this->mainLayout;
    delete this->content;
    delete this->scrollArea;
    delete this->outputWidget;
}

void ConsoleView::Show(){
    this->outputWidget->show();
}

QString ConsoleView::GetInput(QValidator* validator){
    QLineEdit *line = this->SetupInput(validator);
    line->setText("");

    this->Show();
    this->WaitForTextInput(line);
    line->setReadOnly(true);

    return line->text();
}
void ConsoleView::Log(const QString& text){
    this->SetupOutput(-1, text, LOG_COLOR);
}
void ConsoleView::Warn(int lineNumber, const QString& text){
    this->SetupOutput(lineNumber, text, WARN_COLOR);
}
void ConsoleView::Error(int lineNumber, const QString& text){
    this->SetupOutput(lineNumber, text, ERROR_COLOR);
}

int ConsoleView::GetInputInt(){
    QIntValidator validator(this->mainLayout);

    QString input = this->GetInput(&validator);
    return stoi(input.toStdString());
}
void ConsoleView::Log(const string text){
    this->Log(QString::fromStdString(text));
}
void ConsoleView::Warn(int lineNumber, const string text){
    this->Warn(lineNumber, QString::fromStdString(text));
}
void ConsoleView::Error(int lineNumber, const string text){
    this->Error(lineNumber, QString::fromStdString(text));
}

void ConsoleView::SetWidth(int width){
    this->content->resize(width, this->content->height());
}

void ConsoleView::Clear(){
    QLayoutItem* item;
    while ((item = this->mainLayout->takeAt(0)) != nullptr){
        delete item->widget();
        delete item;
    }
}

void ConsoleView::WaitForTextInput(QLineEdit *textbox){
    QEventLoop loop;
    QObject::connect(textbox, SIGNAL(returnPressed()), &loop, SLOT(quit()));
    loop.exec();
}

QLineEdit* ConsoleView::SetupInput(QValidator* validator){
    QLineEdit* input = new QLineEdit(this->outputWidget);
    if (validator != nullptr) input->setValidator(validator);
    input->setPlaceholderText("Enter Int Value");

    this->mainLayout->addWidget(input, this->mainLayout->rowCount(), 1);
    this->scrollArea->verticalScrollBar()->setSliderPosition(this->scrollArea->verticalScrollBar()->maximum());

    return input;
}
void ConsoleView::SetupOutput(const int lineNumber, const QString& text, const char* colorType){
    QLabel *textLbl = new QLabel();
    QString textFormat("<font color=\"%1\">%2</font>");
    textLbl->setText(textFormat.arg(colorType, text));

    int rowNumber = this->mainLayout->rowCount();

    if (lineNumber >= 0){
        // NOTE: Can pass a negative value to avoid showing the line number label
        QLabel *lineLbl = new QLabel();
        QString lineNumberFormat("%1");
        lineLbl->setText(lineNumberFormat.arg(lineNumber));

        this->mainLayout->addWidget(lineLbl, rowNumber, 0, Qt::AlignLeft);
    }

    this->mainLayout->addWidget(textLbl, rowNumber, 1, Qt::AlignLeft);
    this->scrollArea->verticalScrollBar()->setSliderPosition(this->scrollArea->verticalScrollBar()->maximum());
}

ConsoleView* ConsoleView::GetSingleton(QMainWindow *parent){
    static ConsoleView* console = new ConsoleView(parent);
    return console;
}

void ConsoleView::ScrollToBottom(int min, int max){
    Q_UNUSED(min)
    scrollArea->verticalScrollBar()->setValue(max);
}
