TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lSDL2 -lSDL2_image
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
	object.cpp \
    gamestate.cpp \
    player.cpp \
    background.cpp

HEADERS += \
	object.h \
    gamestate.h \
    vector2d.h \
    player.h \
    background.h

