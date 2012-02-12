TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    genericprovider.cpp \
    pcapfileprovider.cpp \
    pcapliveprovider.cpp

OTHER_FILES += \
    Readme.txt

HEADERS += \
    genericprovider.h \
    pcapfileprovider.h \
    pcapliveprovider.h

LIBS += -lpcap -lglog

# config4star linking
INCLUDEPATH += /home/gerry/Downloads/libraries/config4cpp/include
LIBS  += -L/home/gerry/Downloads/libraries/config4cpp/lib -lconfig4cpp
