QT       += core gui widgets opengl openglwidgets concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(../qtgifimage/src/gifimage/qtgifimage.pri)

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    geometryengine.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    view_widget.cpp

HEADERS += \
    controller.h \
    converter.h \
    geometryengine.h \
    mainwindow.h \
    memento.h \
    model.h \
    singleton.h \
    view_widget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shaders.qrc

DISTFILES += \
    fshader.glsl \
    new_settings.cfg \
    vshader.glsl

macx::ICON = logo.icns
