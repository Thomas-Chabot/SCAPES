#include <string>
using namespace std;

#ifndef LITERAL_VALUE_H
#define LITERAL_VALUE_H

class LiteralValue {
private:
  string name;
  int value;

public:
  LiteralValue(string name, int value);
  int Get();
};

#endif
