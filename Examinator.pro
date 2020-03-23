QT += quick sql

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/headers
INCLUDEPATH += $$PWD/src/source

SOURCES += \
        src/main.cpp \
        src/sources/connectionmanager.cpp \
        src/sources/executor.cpp \
        src/sources/manipulator.cpp \
        src/sources/processor.cpp \
        src/sources/selector.cpp \
    src/sources/testmodel.cpp \
    src/sources/testworker.cpp \
        src/sources/theory.cpp \
        src/sources/theoryreader.cpp \
        src/sources/user.cpp \
        src/sources/userreader.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/src/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    src/headers/Types.h \
    src/headers/connectionmanager.h \
    src/headers/dbmapper.h \
    src/headers/dbtypes.h \
    src/headers/executor.h \
    src/headers/manipulator.h \
    src/headers/processor.h \
    src/headers/selector.h \
    src/headers/testmodel.h \
    src/headers/testworker.h \
    src/headers/theory.h \
    src/headers/theoryreader.h \
    src/headers/user.h \
    src/headers/userreader.h \
