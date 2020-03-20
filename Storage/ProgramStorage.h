/*
 * This is the main class responsible for storage of the program.
 *
 * Written by Sean Hodges, last edited November 10th, 2019
 */

#include "Program.h"

#include "StorageBase.h"

#include "ArrayStorage.h"
#include "IntStorage.h"
#include "LabelStorage.h"
#include "StatementStorage.h"

#include <vector>

#ifndef PROGRAM_STORAGE_H
#define PROGRAM_STORAGE_H

class ProgramStorage : StorageBase {
private:
    vector<ArrayStorage*> arrays;
    vector<IntStorage*> ints;
    vector<StatementStorage*> statements;

public:
    ProgramStorage();
    ~ProgramStorage() override;

    void AddArray(ArrayStorage*);
    void AddInt(IntStorage*);
    void AddStatement(StatementStorage*);

    void Write(QJsonObject &json) const override;

    static void Read(const QJsonObject& json, Program* program);
};

#endif // PROGRAM_H
