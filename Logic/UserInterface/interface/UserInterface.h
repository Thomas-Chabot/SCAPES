/*
 * This class provides methods for handling User Input.
 *
 * It implements the Bridge design pattern for handling data
 *   and switching between console input and the QT User Interface.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "UiBase.h"

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

class UserInterface {
private:
  UiBase* interface;

public:
  UserInterface(UiBase* implementation);
  ~UserInterface();
  
  void ReadInt(int& input);
  void Log(string message);
  void Warn(int line, string message);
  void Error(int line, string message);

  static UserInterface& GetSingleton();
};
#endif
