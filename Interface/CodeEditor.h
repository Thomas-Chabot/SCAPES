/*
 * This class takes care of creating the main Code Editor window, where every line
 *   has an associated line number. It has been adapted from QT's CodeEditor example.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QObject>
#include <QWidget>
#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = nullptr);
    ~CodeEditor() override;

    void LineNumberAreaPaintEvent(QPaintEvent *event);
    int LineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *e) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QWidget *lineNumberArea;

signals:
    void SaveRequested();
    void SaveAsRequested();
    void OpenRequested();
    void NewRequested();

private slots:
    void UpdateLineNumberAreaWidth(int newBlockCount);
    void UpdateLineNumberArea(const QRect &, int);
};

#endif // CODEEDITOR_H
