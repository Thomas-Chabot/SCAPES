#include "UserInterface.h"
#include "GuiInterface.h"

UserInterface::UserInterface(UiBase* interface){
  this->interface = interface;
}
UserInterface::~UserInterface(){
  delete this->interface;
}

void UserInterface::ReadInt(int& input){
  this->interface->ReadInt(input);
}
void UserInterface::Log(string message){
  this->interface->Log(message);
}
void UserInterface::Warn(int line, string message){
  this->interface->Warn(line, message);
}
void UserInterface::Error(int line, string message){
  this->interface->Error(line, message);
}

UserInterface& UserInterface::GetSingleton(){
  static UserInterface implementer(new GuiInterface());
  return implementer;
}
