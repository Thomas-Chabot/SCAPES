/*
 * This is a Facade class that directs the program in communication with the Logic subsystem.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#include <QString>

#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

class ControlManager
{
public:
    // This returns the result - will be used eventually for execution,
    //  to make sure compilation was successful before running
    static bool Compile(const QString& inputPath, const QString& outputPath);

    // Run
    static bool Execute(const QString& inputPath);
};

#endif // CONTROLMANAGER_H
