QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatlistwidget.cpp \
    chatwidget.cpp \
    createaccountwidget.cpp \
    loginwidget.cpp \
    main.cpp \
    message.cpp \
    myinfo.cpp \
    searchid.cpp \
    widget.cpp

HEADERS += \
    chatlistwidget.h \
    chatwidget.h \
    createaccountwidget.h \
    loginwidget.h \
    message.h \
    myinfo.h \
    searchid.h \
    widget.h

FORMS += \
    chatlistwidget.ui \
    chatwidget.ui \
    createaccountwidget.ui \
    loginwidget.ui \
    searchid.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
