/*
 * This handles the Line Number selections that are showed at the side of the code editor.
 * It was adapted from the CodeEditor QT example for use in the SCAPES system.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QWidget>
#include "CodeEditor.h"

class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(CodeEditor* editor);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    CodeEditor *codeEditor;

signals:

public slots:
};

#endif // LINENUMBERAREA_H
