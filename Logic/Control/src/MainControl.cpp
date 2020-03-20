#include "MainControl.h"
#include "Program.h"

/*
 * Calls into the Compile method to compile a program.
 *
 * Parameters:
 *   Program: The Program code to compile
 *   folderPath: The path to the folder where the compilation results should be stored
 *   fileName: The name of the program being compiled (without any extension)
 *
 * Return Value: None
 * Side Effects: If the program is successful, this will create a new file in folderPath
 *                 with the name [fileName].scaplc.
 *               Otherwise, error messages will be logged to the output window.
 */
bool MainControl::Compile(string inputPath, string outputPath){
    return CompileControl::Compile(inputPath, outputPath);
}


/*
 * Calls into the Execute method to execute a program.
 *
 */
bool MainControl::Execute(string inputPath){
    Program program(inputPath);
    if (!program.Load()) return false;

    return program.Execute();
}
