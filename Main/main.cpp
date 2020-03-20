/*
 * This is the main program entry point; it creates the QT interface
 *   from the Interface subsystem.
 *
 * Written by Sean Hodges, last edited Nov. 8, 2019.
 */

#include "UIControl.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIControl c;
    c.Start();
    return a.exec();
}
