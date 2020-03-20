#include "MessagePopup.h"

void MessagePopup::ShowError(const QString& message){
    if (message.isEmpty()) return;
    QMessageBox::warning(nullptr, ERROR_APPERROR, message);
}

bool MessagePopup::Confirm(const QString& message){
    QMessageBox::StandardButton response = QMessageBox::question(nullptr, MSGBOX_TITLE_CONFIRM, message);
    return response == QMessageBox::Yes;
}

bool MessagePopup::ShouldShow(const QString& error){
    return !error.isEmpty();
}
