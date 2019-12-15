QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AIComponent.cpp \
    AIStrategy.cpp \
    AIStrategyFactory.cpp \
    AIStrategyImpl.cpp \
    Character.cpp \
    CharacterGenerator.cpp \
    Enemy.cpp \
    EnemyOverworld.cpp \
    Game.cpp \
    HealthComponent.cpp \
    HealthView.cpp \
    ImageComponent.cpp \
    LayoutGenerator.cpp \
    MoveView.cpp \
    Player.cpp \
    PlayerOverworld.cpp \
    ProgressBarView.cpp \
    SpriteView.cpp \
    TimeComponent.cpp \
    TimeView.cpp \
    ViewGenerator.cpp \
    main.cpp

HEADERS += \
    AIComponent.h \
    AIStrategy.h \
    AIStrategyFactory.h \
    AIStrategyImpl.h \
    Character.h \
    CharacterGenerator.h \
    Enemy.h \
    EnemyOverworld.h \
    Game.h \
    HealthComponent.h \
    HealthView.h \
    ImageComponent.h \
    LayoutGenerator.h \
    MoveView.h \
    Player.h \
    PlayerOverworld.h \
    ProgressBarView.h \
    SpriteView.h \
    TimeComponent.h \
    TimeView.h \
    ViewGenerator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
