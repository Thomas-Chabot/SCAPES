/*
 * The main Facade class for interacting with the Control classes of the system.
 *
 * Written by Sean Hodges, last edited Nov 8, 2019.
 */

#include "CompileControl.h"

#ifndef MAINCONTROL_H
#define MAINCONTROL_H

class MainControl {
public:
    static bool Compile(string programInput, string compilationOutput);
    static bool Execute(string compilationInput);
};

#endif // MAINCONTROL_H
