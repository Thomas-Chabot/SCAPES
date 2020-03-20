/*
 * The main Compile Control class; this class handles all the logic of
 *   compiling a program in SCAPES.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */


#include <string>
using namespace std;

#ifndef COMPILE_CONTROL_H
#define COMPILE_CONTROL_H

class CompileControl{
private:

public:
  static bool Compile(string inputPath, string outputPath);
};

#endif
