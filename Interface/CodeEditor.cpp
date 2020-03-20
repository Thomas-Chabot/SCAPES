/*
 * This program was taken from the Qt Code Editor tutorial:
 *   https://doc.qt.io/qt-5/qtwidgets-widgets-codeeditor-example.html
 *
 * Edited for the purposes of the SCAPES program by Sean Hodges, Student#101012990
 *
 */

#include "CodeEditor.h"
#include "LineNumberArea.h"

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::UpdateLineNumberAreaWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::UpdateLineNumberArea);

    UpdateLineNumberAreaWidth(0);
}
CodeEditor::~CodeEditor(){
    delete this->lineNumberArea;

}
void CodeEditor::keyPressEvent(QKeyEvent *event){
    bool ctrlPressed = event->modifiers() == Qt::ControlModifier;
    bool shiftPressed = event->modifiers() == Qt::ShiftModifier;

    // Modifiers do not do anything unless ctrl is pressed
    if (ctrlPressed){
        switch (event->key()){
            case Qt::Key_S:
                // If shift is pressed -> requesting save as
                // Otherwise -> requesting save
                if (shiftPressed)
                    emit SaveAsRequested();
                else
                    emit SaveRequested();
                break;
            case Qt::Key_O:
                emit OpenRequested();
                break;
            case Qt::Key_N:
                emit NewRequested();
                break;
        }
    }

    // Pass the event to the base class
    QPlainTextEdit::keyPressEvent(event);
}

int CodeEditor::LineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::UpdateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(LineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::UpdateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        UpdateLineNumberAreaWidth(0);
}

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), LineNumberAreaWidth(), cr.height()));
}

void CodeEditor::LineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

/*
void CodeEditor::HighlightLines(int* lineNumbers, int count)
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        for (int i = 0; i < count; i++){
            QTextEdit::ExtraSelection selection;

            QColor lineColor = QColor(Qt::red).lighter(160);

            selection.format.setBackground(lineColor);
            selection.format.setProperty(QTextFormat::FullWidthSelection, true);
            selection.cursor = lineNumbers[i];
            extraSelections.append(selection);
        }
    }

    setExtraSelections(extraSelections);
}
*/
