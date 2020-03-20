/*
 * This maps User Input to the QT Guis provided by the Interface subsystem.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "UiBase.h"
#include "ConsoleView.h"

#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

class GuiInterface : public UiBase {
private:
    ConsoleView* console;

public:
    GuiInterface();

    void ReadInt(int& input);
    void Log(string message);
    void Warn(int line, string message);
    void Error(int line, string message);
};

#endif
