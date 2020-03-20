/*
 * This is the main class for handling Labels.
 * Every Label has a representative line number and a name.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019
 */

#include "Identifier.h"
#include <string>
using namespace std;

#ifndef LABEL_H
#define LABEL_H

class Label : public Identifier {
private:
  int lineNumber;
public:
  Label();
  Label(string name, int lineNumber);

  int Get();
  void Set(int lineNumber);
};

#endif
