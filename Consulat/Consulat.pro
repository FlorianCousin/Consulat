#-------------------------------------------------
#
# Project created by QtCreator 2019-01-20T17:31:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Consulat
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    controller/concretecontroller.cpp \
    controller/controller.cpp \
    view/filemanagerwidget.cpp \
    view/mainwindow.cpp \
    view/observer.cpp \
    view/tablewidget.cpp \
    view/textfile.cpp \
    view/treewidget.cpp \
    model/data.cpp \
    model/subjectdata.cpp \
    model/treemodel.cpp

HEADERS += \
        mainwindow.h \
    controller/concretecontroller.h \
    controller/controller.h \
    view/filemanagerwidget.h \
    view/mainwindow.h \
    view/observer.h \
    view/tablewidget.h \
    view/treewidget.h \
    model/data.h \
    model/subjectdata.h \
    model/treemodel.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# For the curl library
LIBS += -LD:/OpenSSL-Win64/lib/ -llibcrypto -llibssl

win32:CONFIG(release, debug|release): LIBS += -LD:/OpenSSL-Win64/lib/ -lopenssl
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/OpenSSL-Win64/lib/ -lopenssl#d

INCLUDEPATH += $$PWD/../../../../../OpenSSL-Win64/include
DEPENDPATH += $$PWD/../../../../../OpenSSL-Win64/include

PRE_TARGETDEPS += D:/OpenSSL-Win64/lib/openssl.lib
