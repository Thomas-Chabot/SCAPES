######################################################################
# Automatically generated by qmake (3.1) Sat Oct 26 19:30:30 2019
######################################################################

QT += core

INCLUDEPATH += . $$PWD/ClassData/. \
                 $$PWD/ClassData/Instruction/interface/. \
                 $$PWD/ClassData/Operand/interface/. \
                 $$PWD/ClassData/Statement/interface/. \
                 $$PWD/Constants/. \
                 $$PWD/Control/interface/. \
                 $$PWD/Core/interface/. \
                 $$PWD/DataStructures/interface/. \
                 $$PWD/Exceptions/interface/. \
                 $$PWD/FileManager/interface/. \
                 $$PWD/Identifiers/interface/. \
                 $$PWD/Managers/interface/. \
                 $$PWD/Operands/interface/. \
                 $$PWD/ParserObjects/interface/. \
                 $$PWD/Statements/interface/. \
                 $$PWD/Statements/interface/Declarations/. \
                 $$PWD/Statements/interface/Jumps/. \
                 $$PWD/StringParser/interface/. \
                 $$PWD/UserInterface/interface/.

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += \
           $$PWD/ClassData/Instruction/interface/ArrayIdentifierData.h \
           $$PWD/ClassData/Instruction/interface/IdentifierData.h \
           $$PWD/ClassData/Instruction/interface/IntIdentifierData.h \
           $$PWD/ClassData/Instruction/interface/LabelIdentifierData.h \
           $$PWD/ClassData/Operand/interface/ArrayOperandData.h \
           $$PWD/ClassData/Operand/interface/IntOperandData.h \
           $$PWD/ClassData/Operand/interface/LabelOperandData.h \
           $$PWD/ClassData/Operand/interface/LiteralOperandData.h \
           $$PWD/ClassData/Operand/interface/NameOperandData.h \
           $$PWD/ClassData/Operand/interface/OperandClassData.h \
           $$PWD/ClassData/Operand/interface/OperandWithNameDataBase.h \
           $$PWD/ClassData/Operand/interface/StringOperandData.h \
           $$PWD/ClassData/Statement/interface/StatementData.h \
           $$PWD/Constants/ClassDataTypes.h \
           $$PWD/Constants/ErrorConstants.h \
           $$PWD/Constants/InstructionDeclarations.h \
           $$PWD/Constants/OutputMessageTags.h \
           $$PWD/Constants/RegexPatterns.h \
           $$PWD/Constants/StringLiterals.h \
           $$PWD/Constants/VariableType.h \
           $$PWD/Control/interface/CompileControl.h \
           $$PWD/Control/interface/MainControl.h \
           $$PWD/Core/interface/Environment.h \
           $$PWD/Core/interface/Program.h \
           $$PWD/DataStructures/interface/Container.h \
           $$PWD/Exceptions/interface/ArrayNotInitializedException.h \
           $$PWD/Exceptions/interface/BaseException.h \
           $$PWD/Exceptions/interface/CannotBeStringOperandException.h \
           $$PWD/Exceptions/interface/CannotUseAsNameException.h \
           $$PWD/Exceptions/interface/CommentHasLabelException.h \
           $$PWD/Exceptions/interface/DoesNotExistException.h \
           $$PWD/Exceptions/interface/ExpectingNullException.h \
           $$PWD/Exceptions/interface/InstructionNotRecognizedException.h \
           $$PWD/Exceptions/interface/InvalidOperationException.h \
           $$PWD/Exceptions/interface/InvalidTypeException.h \
           $$PWD/Exceptions/interface/JumpedToVariableDeclarationException.h \
           $$PWD/Exceptions/interface/LabelNotDefinedException.h \
           $$PWD/Exceptions/interface/NotEnoughArgumentsException.h \
           $$PWD/Exceptions/interface/NotReadableException.h \
           $$PWD/Exceptions/interface/NotWritableException.h \
           $$PWD/Exceptions/interface/OperandsReversedException.h \
           $$PWD/Exceptions/interface/OutOfBoundsException.h \
           $$PWD/Exceptions/interface/ReachedEndOfExecutionException.h \
           $$PWD/Exceptions/interface/TestException.h \
           $$PWD/Exceptions/interface/TooManyArgumentsException.h \
           $$PWD/Exceptions/interface/VariableAlreadyExistsException.h \
           $$PWD/FileManager/interface/FileManager.h \
           $$PWD/Identifiers/interface/ArrayVariable.h \
           $$PWD/Identifiers/interface/DataContainer.h \
           $$PWD/Identifiers/interface/Identifier.h \
           $$PWD/Identifiers/interface/IntVariable.h \
           $$PWD/Identifiers/interface/Label.h \
           $$PWD/Managers/interface/StorageManager.h \
           $$PWD/Operands/interface/ArrayOperand.h \
           $$PWD/Operands/interface/IOperand.h \
           $$PWD/Operands/interface/IntOperand.h \
           $$PWD/Operands/interface/LabelOperand.h \
           $$PWD/Operands/interface/LiteralOperand.h \
           $$PWD/Operands/interface/NameOperand.h \
           $$PWD/Operands/interface/Operand.h \
           $$PWD/Operands/interface/OperandFactory.h \
           $$PWD/Operands/interface/OperandWithName.h \
           $$PWD/Operands/interface/StringOperand.h \
           $$PWD/ParserObjects/interface/OperandData.h \
           $$PWD/ParserObjects/interface/ProgramData.h \
           $$PWD/Statements/interface/AddStatement.h \
           $$PWD/Statements/interface/CompareStatement.h \
           $$PWD/Statements/interface/Declarations/DeclarationStatementBase.h \
           $$PWD/Statements/interface/Declarations/DeclareArrayStatement.h \
           $$PWD/Statements/interface/Declarations/DeclareIntStatement.h \
           $$PWD/Statements/interface/EndStatement.h \
           $$PWD/Statements/interface/Jumps/JumpEqualStatement.h \
           $$PWD/Statements/interface/Jumps/JumpLessStatement.h \
           $$PWD/Statements/interface/Jumps/JumpMoreStatement.h \
           $$PWD/Statements/interface/Jumps/JumpStatement.h \
           $$PWD/Statements/interface/Jumps/JumpStatementBase.h \
           $$PWD/Statements/interface/MoveStatement.h \
           $$PWD/Statements/interface/PrintStatement.h \
           $$PWD/Statements/interface/ReadIntStatement.h \
           $$PWD/Statements/interface/Statement.h \
           $$PWD/Statements/interface/StatementFactory.h \
           $$PWD/StringParser/interface/OperandParser.h \
           $$PWD/StringParser/interface/ParserBase.h \
           $$PWD/StringParser/interface/ProgramParser.h \
           $$PWD/StringParser/interface/StringExtensions.h \
           $$PWD/UserInterface/interface/ConsoleInterface.h \
           $$PWD/UserInterface/interface/GuiInterface.h \
           $$PWD/UserInterface/interface/UiBase.h \
           $$PWD/UserInterface/interface/UserInterface.h \
           $$PWD/UserInterface/src/GuiInterface.h
SOURCES += $$PWD/Identifiers/src/ArrayVariable.cpp \
           $$PWD/Control/src/CompileControl.cpp \
           $$PWD/Control/src/MainControl.cpp \
           $$PWD/Core/src/Environment.cpp \
           $$PWD/Core/src/Program.cpp \
           $$PWD/FileManager/src/FileManager.cpp \
           $$PWD/Identifiers/src/Identifier.cpp \
           $$PWD/Identifiers/src/IntVariable.cpp \
           $$PWD/Identifiers/src/Label.cpp \
           $$PWD/Managers/src/StorageManager.cpp \
           $$PWD/Operands/src/ArrayOperand.cpp \
           $$PWD/Operands/src/IntOperand.cpp \
           $$PWD/Operands/src/LabelOperand.cpp \
           $$PWD/Operands/src/LiteralOperand.cpp \
           $$PWD/Operands/src/NameOperand.cpp \
           $$PWD/Operands/src/Operand.cpp \
           $$PWD/Operands/src/OperandFactory.cpp \
           $$PWD/Operands/src/OperandWithName.cpp \
           $$PWD/Operands/src/StringOperand.cpp \
           $$PWD/ParserObjects/src/OperandData.cpp \
           $$PWD/ParserObjects/src/ProgramData.cpp \
           $$PWD/Statements/src/AddStatement.cpp \
           $$PWD/Statements/src/CompareStatement.cpp \
           $$PWD/Statements/src/Declarations/DeclarationStatementBase.cpp \
           $$PWD/Statements/src/Declarations/DeclareArrayStatement.cpp \
           $$PWD/Statements/src/Declarations/DeclareIntStatement.cpp \
           $$PWD/Statements/src/EndStatement.cpp \
           $$PWD/Statements/src/Jumps/JumpEqualStatement.cpp \
           $$PWD/Statements/src/Jumps/JumpLessStatement.cpp \
           $$PWD/Statements/src/Jumps/JumpMoreStatement.cpp \
           $$PWD/Statements/src/Jumps/JumpStatement.cpp \
           $$PWD/Statements/src/Jumps/JumpStatementBase.cpp \
           $$PWD/Statements/src/MoveStatement.cpp \
           $$PWD/Statements/src/PrintStatement.cpp \
           $$PWD/Statements/src/ReadIntStatement.cpp \
           $$PWD/Statements/src/Statement.cpp \
           $$PWD/Statements/src/StatementFactory.cpp \
           $$PWD/StringParser/src/OperandParser.cpp \
           $$PWD/StringParser/src/ParserBase.cpp \
           $$PWD/StringParser/src/ProgramParser.cpp \
           $$PWD/StringParser/src/StringExtensions.cpp \
           $$PWD/UserInterface/src/ConsoleInterface.cpp \
           $$PWD/UserInterface/src/GuiInterface.cpp \
           $$PWD/UserInterface/src/UserInterface.cpp
