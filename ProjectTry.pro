QT       += core gui
QT += sql charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpair.cpp \
    chart.cpp \
    deletepair.cpp \
    findpair.cpp \
    main.cpp \
    mainmenu.cpp \
    modelsofbrand.cpp \
    showinformation.cpp

HEADERS += \
    addpair.h \
    chart.h \
    deletepair.h \
    findpair.h \
    mainmenu.h \
    modelsofbrand.h \
    showinformation.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    addpair.ui \
    deletepair.ui \
    findpair.ui \
    mainmenu.ui \
    modelsofbrand.ui \
    showinformation.ui
