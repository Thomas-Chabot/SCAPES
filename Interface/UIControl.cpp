#include "UIControl.h"
#include "ControlManager.h"
#include "MessagePopup.h"

UIControl::UIControl(QObject *parent) : QObject(parent)
{
    connect(&window, SIGNAL(CompileRequested()), this, SLOT(onCompileRequested()));
    connect(&window, SIGNAL(CloseRequested()), this, SLOT(onCloseRequested()));
    connect(&window, SIGNAL(ExecuteRequested()), this, SLOT(onExecuteRequested()));
    connect(&window, SIGNAL(NewRequested()), this, SLOT(onNewRequested()));
    connect(&window, SIGNAL(OpenRequested()), this, SLOT(onOpenRequested()));
    connect(&window, SIGNAL(SaveRequested()), this, SLOT(onSaveRequested()));
    connect(&window, SIGNAL(SaveAsRequested()), this, SLOT(onSaveAsRequested()));
    connect(&window, SIGNAL(TextChanged()), this, SLOT(onTextChanged()));
    connect(&file, SIGNAL(FilePathUpdated(QString)), this, SLOT(onFilePathUpdated(QString)));

    UpdateTitle();
}

void UIControl::Start(){
    window.show();
}

bool UIControl::Execute(){
    if (!Compile()) return false;

    ControlManager::Execute(this->file.GetCompilationPath());
    return true;
}
bool UIControl::Compile(){
    if (!CheckSave(MSG_CONFIRM_SAVE_BEFORE_COMPILE, false)) return false;

    return ControlManager::Compile(this->file.GetProgramPath(), this->file.GetCompilationPath());
}
bool UIControl::Save(){
    QString error;
    bool result = file.Save(window.GetText(), error);
    if (!result)
        MessagePopup::ShowError(error);

    return result;
}
void UIControl::SaveAs(){
    QString error;
    if (!file.SaveAs(window.GetText(), error))
        MessagePopup::ShowError(error);
}
void UIControl::Open(){
    QString fileContents, error;
    if (file.Open(fileContents, error))
        window.SetText(fileContents);
    else
        MessagePopup::ShowError(error);
    SetNotModified();
}
void UIControl::New(){
    if (this->CheckSave(MSG_CONFIRM_SAVE_BEFORE_NEW)){
        file.New();
        window.ClearText();
    }
}

void UIControl::UpdateTitle(){
    char modifiedChar = IsModified() ? '*' : ' ';
    window.SetTitle(QString(EDITOR_TITLE) + modifiedChar);
}
void UIControl::SetNotModified(){
    window.SetModified(false);
    UpdateTitle();
}

bool UIControl::IsModified(){
    return window.IsModified();
}
bool UIControl::IsCompiled(){
    return file.HasCompilationOutput();
}

bool UIControl::CheckSave(QString message, bool canCancel){
    if (!IsModified()) return true;

    bool didConfirmSave = MessagePopup::Confirm(message);
    if (didConfirmSave)
        return Save();

    return canCancel;
}
void UIControl::CheckClose(){
    if (CheckSave(MSG_CONFIRM_SAVE_BEFORE_CLOSE, true))
        qApp->quit();
}

void UIControl::onCompileRequested(){
    Compile();
}
void UIControl::onCloseRequested(){
    CheckClose();
}
void UIControl::onExecuteRequested(){
    Execute();
}
void UIControl::onNewRequested(){
    New();
}
void UIControl::onOpenRequested(){
    Open();
}
void UIControl::onSaveRequested(){
    Save();
}
void UIControl::onSaveAsRequested(){
    SaveAs();
}
void UIControl::onTextChanged(){
    UpdateTitle();
}

void UIControl::onFilePathUpdated(QString){
    SetNotModified();
}
