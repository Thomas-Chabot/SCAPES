#include "GuiInterface.h"

GuiInterface::GuiInterface(){
    this->console = ConsoleView::GetSingleton();
}

void GuiInterface::ReadInt(int& input){
    input = this->console->GetInputInt();
}
void GuiInterface::Log(string message){
    this->console->Log(message);
}
void GuiInterface::Warn(int line, string message){
    this->console->Warn(line, WARNING_TEXT + message);
}
void GuiInterface::Error(int line, string message){
    this->console->Error(line, ERROR_TEXT + message);
}
