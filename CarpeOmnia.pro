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

