TEMPLATE = app
CONFIG += qt console c++11
CONFIG -= app_bundle

INCLUDEPATH += \
        $$PWD \
        $$PWD/Identifiers/interface \
        $$PWD/Operands/interface \
        $$PWD/Statements/interface

SOURCES += \
        $$PWD/Identifiers/src/ArrayStorage.cpp \
        $$PWD/Identifiers/src/IdentifierStorageBase.cpp \
        $$PWD/Identifiers/src/IntStorage.cpp \
        $$PWD/Identifiers/src/LabelStorage.cpp \
        $$PWD/Operands/src/ArrayOperandStorage.cpp \
        $$PWD/Operands/src/IntOperandStorage.cpp \
        $$PWD/Operands/src/LabelOperandStorage.cpp \
        $$PWD/Operands/src/LiteralOperandStorage.cpp \
        $$PWD/Operands/src/NameOperandStorage.cpp \
        $$PWD/Operands/src/OperandStorage.cpp \
        $$PWD/Operands/src/OperandWithNameStorage.cpp \
        $$PWD/Operands/src/StringOperandStorage.cpp \
        $$PWD/ProgramStorage.cpp \
        $$PWD/Statements/src/StatementStorage.cpp \
        $$PWD/Storage.cpp \
        $$PWD/StorageBase.cpp

HEADERS += \
    $$PWD/Constants.h \
    $$PWD/Identifiers/interface/ArrayStorage.h \
    $$PWD/Identifiers/interface/IdentifierStorageBase.h \
    $$PWD/Identifiers/interface/IntStorage.h \
    $$PWD/Identifiers/interface/LabelStorage.h \
    $$PWD/Identifiers/interface/StorageBase.h \
    $$PWD/Operands/interface/ArrayOperandStorage.h \
    $$PWD/Operands/interface/IntOperandStorage.h \
    $$PWD/Operands/interface/LabelOperandStorage.h \
    $$PWD/Operands/interface/LiteralOperandStorage.h \
    $$PWD/Operands/interface/NameOperandStorage.h \
    $$PWD/Operands/interface/OperandStorage.h \
    $$PWD/Operands/interface/OperandWithNameStorage.h \
    $$PWD/Operands/interface/StringOperandStorage.h \
    $$PWD/ProgramStorage.h \
    $$PWD/Statements/interface/StatementStorage.h \
    $$PWD/Storage.h \
    $$PWD/StorageBase.h

DISTFILES +=
