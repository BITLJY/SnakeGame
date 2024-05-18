QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    food.cpp \
    snake.cpp \
    mainwindow.cpp \
    main.cpp \
    exit.cpp \
    login.cpp \
    start.cpp \
    level.cpp

HEADERS += \
    Directions.h \
    food.h \
    snake.h \
    mainwindow.h \
    exit.h \
    login.h \
    start.h \
    level.h

FORMS += \
    mainwindow.ui \
    exit.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
