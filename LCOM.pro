QT       += core gui sql serialport svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

FORMS += \
    uiWidget/llistwidget/llistwidget.ui \
    uiWidget/mainwidow/mainwindow.ui

DISTFILES += \
    image/check/app.rc \
    image/check/bianji.png \
    image/check/clear.png \
    image/check/close.png \
    image/check/expand.png \
    image/check/expclear.png \
    image/check/expfileand.png \
    image/check/file.png \
    image/check/list.png \
    image/check/locm.png \
    image/check/max.png \
    image/check/min.png \
    image/check/open.png \
    image/check/save.png \
    image/check/serial.png \
    image/check/serialSet.png \
    image/check/setWidget.png \
    image/check/time.png \
    image/noCheck/baocun.png \
    image/noCheck/bianji.png \
    image/noCheck/expand.png \
    image/noCheck/guanbi.png \
    image/noCheck/guanbi_1.png \
    image/noCheck/open.png \
    image/noCheck/quanping.png \
    image/noCheck/serial.png \
    image/noCheck/time.png \
    image/qss/default.qss \
    image/svg/file.svg

HEADERS += \
    library/sql/sqllist.h \
    thread/mainThread/mainthread.h \
    thread/recvThread/recvThread.h \
    thread/sendThread/sendThread.h \
    uiWidget/fameless/framelessmainwindow.h \
    uiWidget/lcombobox/lcombobox.h \
    uiWidget/llistwidget/llistwidget.h \
    uiWidget/llistwidget/ui_llistwidget.h \
    uiWidget/lpushbutton/lpushbutton.h \
    uiWidget/ltabwidget/ltabwidget.h \
    uiWidget/mainwidow/mainwindow.h

SOURCES += \
    library/sql/sqllist.cpp \
    main/main.cpp \
    thread/mainThread/mainthread.cpp \
    thread/recvThread/recvThread.cpp \
    thread/sendThread/sendThread.cpp \
    uiWidget/fameless/framelessmainwindow.cpp \
    uiWidget/lcombobox/lcombobox.cpp \
    uiWidget/llistwidget/llistwidget.cpp \
    uiWidget/lpushbutton/lpushbutton.cpp \
    uiWidget/ltabwidget/ltabwidget.cpp \
    uiWidget/mainwidow/mainwindow.cpp
