/*
 * This class handles popup messages for the SCAPES subsystem, such as the "save?" message.
 *
 * Written by Sean Hodges, last edited November 8, 2019
 */

#include "Constants.h"
#include <QString>
#include <QMessageBox>

#ifndef MESSAGEPOPUP_H
#define MESSAGEPOPUP_H


class MessagePopup
{
private:
    static bool ShouldShow(const QString& message);

public:
    static void ShowError(const QString& message);
    static bool Confirm(const QString& message);
};

#endif // MESSAGEPOPUP_H
