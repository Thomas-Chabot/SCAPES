#include "ConsoleInterface.h"
#include <iostream>
using namespace std;

void ConsoleInterface::ReadInt(int& input){
  cin >> input;
}
void ConsoleInterface::Log(string message){
  cout << message << endl;
}
void ConsoleInterface::Warn(int line, string message){
  cout << WARNING_TEXT << line << ": " << message << endl;
}
void ConsoleInterface::Error(int line, string message){
  cout << ERROR_TEXT << line << ": " << message << endl;
}
