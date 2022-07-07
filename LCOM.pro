QT       += core gui sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    framelessmainwindow.cpp \
    lcombobox.cpp \
    llistwidget.cpp \
    lpushbutton.cpp \
    ltabwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    setwidget.cpp \
    sqllist.cpp

HEADERS += \
    framelessmainwindow.h \
    lcombobox.h \
    llistwidget.h \
    lpushbutton.h \
    ltabwidget.h \
    mainwindow.h \
    setwidget.h \
    sqllist.h

FORMS += \
    llistwidget.ui \
    mainwindow.ui \
    setwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
