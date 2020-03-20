#include "LineNumberArea.h"

LineNumberArea::LineNumberArea(CodeEditor *editor) : QWidget(editor)
{
    this->codeEditor = editor;
}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor -> LineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event){
    codeEditor->LineNumberAreaPaintEvent(event);
}
