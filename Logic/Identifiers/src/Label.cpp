#include "Label.h"

Label::Label() : Label("", 0) { }
Label::Label(string name, int lineNumber) : Identifier(TYPE_LABEL_IDENTIFIER, name) {
  this->lineNumber = lineNumber;
}

int Label::Get(){
  return this->lineNumber;
}
void Label::Set(int line){
    this->lineNumber = line;
}
