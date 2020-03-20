#include "Program.h"
#include "DataContainer.h"
#include "IntVariable.h"
#include "ArrayVariable.h"
#include "BaseException.h"

#include "ProgramParser.h"
#include "OperandParser.h"

#include "StatementFactory.h"

#include "UserInterface.h"
#include "StorageManager.h"

#include "CommentHasLabelException.h"
#include "InstructionNotRecognizedException.h"
#include "ReachedEndOfExecutionException.h"

Program::Program(string compilationPath) : Program("", compilationPath) { }

Program::Program(string programInput, string compilationPath) {
    this->programPath = programInput;
    this->compilationPath = compilationPath;

    this->comparisonFlag = 0;
    this->statements = new vector<Statement*>();
    this->environment = new Environment();
}

Program::~Program(){
    for (auto statement : *statements){
        delete statement;
    }
    delete statements;
    delete this->environment;
}

/*
 * Purpose: This creates the Statements from a program file.
 * Returns: Success value. If false, there was an error.
 */
bool Program::CreateStatements(){
    string programCode;
    vector<string> programLines;
    ProgramData programData;
    OperandData op1, op2;

    FileManager::Read(this->programPath, programCode);
    ProgramParser::SplitByLine(programCode, programLines);

    bool hasEnd = false;
    bool hasError = false;
    for (size_t currentLine = 1; currentLine <= programLines.size(); currentLine++){
        try{
            string lineContents = programLines[currentLine - 1];
            this->ParseLine(lineContents, programData, op1, op2);

            // skip empty lines
            if (ProgramParser::IsEmptyLine(programLines[currentLine - 1]))
                continue;

            // Special Cases: Comments and end statements
            if (programData.GetInstruction() == INSTRUCTION_COMMENT){
                if (programData.GetLabel() != "")
                    throw CommentHasLabelException();
                continue;
            } else if (programData.GetInstruction() == INSTRUCTION_END){
                hasEnd = true;
            }

            this->CreateStatement(static_cast<int>(currentLine), programData, op1, op2);
        } catch (BaseException& ex){
            this->ThrowError(static_cast<int>(currentLine), ex);
            hasError = true;
        } catch (exception& ex){
            this->ThrowError(static_cast<int>(currentLine), ex);
            hasError = true;
        }
    }

    if (!hasEnd){
        this->ThrowError(static_cast<int>(programLines.size()), ERROR_NO_END);
        hasError = true;
    }

    return !hasError;
}
bool Program::Compile(){
    bool hasError = false;

    // NOTE: We want to reset the variables at the start of program compilation
    // So that variables won't carry over from a previous compilation
    for (auto statement : *statements){
        try {
            statement->Compile();
        } catch (BaseException& ex) {
            this->ThrowError(statement->GetLine(), ex);
            hasError = true;
        } catch (exception& ex) {
            this->ThrowError(statement->GetLine(), ex);
            hasError = true;
        }
    }

    return !hasError;
}
bool Program::Execute(){
    Environment* env = this->environment;
    int runningLine = 0;
    try{
        env->StartRun();
        while (env->IsRunning()){
            // Go to next line
            size_t lineNumber = static_cast<size_t>(env->GetLine());
            env->SetLine(env->GetLine() + 1);

            // Make sure that a statement exists
            if (lineNumber >= statements->size()){
                throw ReachedEndOfExecutionException();
            }

            // Run the statement
            Statement* statement = this->statements->at(lineNumber);
            runningLine = statement->GetLine(); // in case of error
            statement->Run();
        }
    } catch (BaseException ex) {
        this->ThrowError(runningLine, ex);
        return false;
    } catch (exception& ex){
        this->ThrowError(runningLine, ex);
        return false;
    }

    return true;
}
bool Program::Save(){
    StorageManager storage(this->compilationPath);

    // Save all the identifiers
    environment->EachIdentifier<IntVariable>([&storage](IntVariable* var){
        storage.AddIdentifier(var);
    });
    environment->EachIdentifier<ArrayVariable>([&storage](ArrayVariable* var){
        storage.AddIdentifier(var);
    });

    // Save all the statements
    for (auto statement : *statements){
        storage.AddStatement(statement);
    }

    // If we have an error, log it out
    string error;
    if (!storage.Save(error)){
        this->ThrowError(-1, error.c_str());
        return false;
    }

    return true;
}
bool Program::Load(){
    StorageManager storage(this->compilationPath);

    string errorMsg;
    if (!storage.Load(this, errorMsg)){
        this->ThrowError(-1, errorMsg.c_str());
        return false;
    }

    return true;
}

void Program::CreateStatement(int lineNumber, ProgramData& data, OperandData& op1, OperandData& op2){
    Label* label = data.GetLabel() == "" ? nullptr : new Label(data.GetLabel(), static_cast<int>(lineNumber));
    Statement* statement = StatementFactory::CreateStatement(static_cast<int>(lineNumber), data.GetInstruction(), this->environment, label,  op1, op2);

    if (statement == nullptr){
        throw InstructionNotRecognizedException(data.GetInstruction());
    }

    statements->push_back(statement);
}

void Program::ParseLine(string line, ProgramData& programData, OperandData& op1, OperandData& op2){
    ProgramParser::ParseLine(line, programData);
    OperandParser::Parse(programData.GetOperand1(), op1);
    OperandParser::Parse(programData.GetOperand2(), op2);
}

// Logs out exceptions to the UserInterface
void Program::ThrowError(int lineNumber, BaseException& exception){
    this->ThrowError(lineNumber, exception.what()); // The "what" will be an actual message here
}
void Program::ThrowError(int lineNumber, exception &exception){
    this->ThrowError(lineNumber, typeid(exception).name()); // The main message here will be the type of the exception
}
void Program::ThrowError(int lineNumber, const char* message){
    UserInterface::GetSingleton().Error(lineNumber, message);
}

void Program::AddLabel(Label *label){ this->environment->AddIdentifier(label); }
void Program::AddIntVariable(IntVariable *variable){ this->environment->AddIdentifier(variable); }
void Program::AddArrayVariable(ArrayVariable *variable){ this->environment->AddIdentifier(variable); }
void Program::AddStatement(Statement *statement){
    statement->SetEnvironment(this->environment);

    Label* label = statement->GetLabel();
    if (label != nullptr){
        int statementLineNumber = statements->size();
        label->Set(statementLineNumber);
    }

    //statement->Initialize();
    statements->push_back(statement);
}


Environment* Program::GetEnvironment(){ return this->environment; }
