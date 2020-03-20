/*
 * This maps User Input to the console.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

// User Interface implemented through the console
#include "UiBase.h"

#ifndef CONSOLE_INTERFACE_H
#define CONSOLE_INTERFACE_H

class ConsoleInterface : public UiBase {
private:
public:
  void ReadInt(int& input);
  void Log(string message);
  void Warn(int line, string message);
  void Error(int line, string message);
};

#endif
