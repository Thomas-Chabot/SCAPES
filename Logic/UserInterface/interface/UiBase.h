/*
 * This is the interface for all UI interaction.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "OutputMessageTags.h"
#include <string>
using namespace std;

#ifndef UI_BASE_H
#define UI_BASE_H

class UiBase {
private:
protected:
public:
  virtual ~UiBase(){}
  
  virtual void ReadInt(int& input) = 0;
  virtual void Log(string message) = 0;
  virtual void Warn(int line, string message) = 0;
  virtual void Error(int line, string message) = 0;
};

#endif
