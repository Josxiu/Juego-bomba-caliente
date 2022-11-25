QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomba.cpp \
    bombajefe.cpp \
    enemigo.cpp \
    jefe.cpp \
    jugador.cpp \
    main.cpp \
    juego.cpp \
    personaje.cpp \
    puntaje.cpp \
    vidajugador.cpp

HEADERS += \
    bomba.h \
    bombajefe.h \
    enemigo.h \
    jefe.h \
    juego.h \
    jugador.h \
    personaje.h \
    puntaje.h \
    vidajugador.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
