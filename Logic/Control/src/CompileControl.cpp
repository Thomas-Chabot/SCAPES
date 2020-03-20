#include "CompileControl.h"
#include "Program.h"
#include "UserInterface.h"

/*
 * The main Compile method; this will compile a program.
 *
 * Parameters:
 *   Program: The Program code to compile
 *   folderPath: The path to the folder where the compilation results should be stored
 *   fileName: The name of the program being compiled (without any extension)
 *
 * Return Value: Error Status - if true, the compilation failed
 * Side Effects: If the program is successful, this will create a new file in folderPath
 *                 with the name [fileName].scaplc
 *               Otherwise, error messages will be logged to the output window.
 */
bool CompileControl::Compile(string inputPath, string outputPath){
    UserInterface& ui = UserInterface::GetSingleton();

    ui.Log("Starting program compilation");
    Program program(inputPath, outputPath);

    try {
        // As soon as something errors, exit - can't compile
        if (!program.CreateStatements()) return false;
        if (!program.Compile()) return false;
        if (!program.Save()) return false;
    } catch (BaseException ex) {
        ui.Error(-1, ex.what());
        return false;
    }

    ui.Log("Compilation completed");
    return true;
}
