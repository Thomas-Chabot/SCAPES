#include "FileManager.h"
#include <fstream>
#include <sstream>

void FileManager::Read(string path, string& result){
    ifstream inFile(path);
    stringstream buffer;

    buffer << inFile.rdbuf();
    result = buffer.str();
}
