#include "ControlManager.h"
#include "MainControl.h"
#include <string>
using namespace std;

bool ControlManager::Compile(const QString& inputPath, const QString& outputPath){
    return MainControl::Compile(inputPath.toStdString(), outputPath.toStdString());
}
bool ControlManager::Execute(const QString& inputPath){
    return MainControl::Execute(inputPath.toStdString());
}
