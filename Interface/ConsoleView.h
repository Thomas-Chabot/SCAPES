/*
 * This class takes care of everything related to the Console, including showing output messages,
 *  logging errors, and getting user input.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#include <QtWidgets>
#include <string>
using namespace std;

#ifndef CONSOLE_H
#define CONSOLE_H

#define LOG_COLOR "black"
#define WARN_COLOR ""
#define ERROR_COLOR "red"

class ConsoleView : public QObject {
    Q_OBJECT

private:
    QDockWidget* outputWidget;
    QScrollArea* scrollArea;
    QGridLayout* mainLayout;
    QWidget* content;

    QLineEdit* SetupInput(QValidator* validator = nullptr);
    void SetupOutput(const int lineNumber, const QString& text, const char* textColor);
    void WaitForTextInput(QLineEdit* textbox);
public:
    ConsoleView(QMainWindow* parent);
    ~ConsoleView();

    QString GetInput(QValidator* validator = nullptr);
    int GetInputInt();

    void Log(const QString& text);
    void Warn(int lineNumber, const QString& text);
    void Error(int lineNumber, const QString& text);

    void Log(const string text);
    void Warn(int lineNumber, const string text);
    void Error(int lineNumber, const string text);

    void Show();
    void SetWidth(int width);

    void Clear();

    static ConsoleView* GetSingleton(QMainWindow* parent = nullptr);

private slots:
    void ScrollToBottom(int min, int max);
};

#endif // CONSOLE_H
