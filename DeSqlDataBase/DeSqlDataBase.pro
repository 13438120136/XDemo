# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = DeSqlDataBase
DESTDIR = ../
QT += core sql
CONFIG += release
DEFINES += QT_LARGEFILE_SUPPORT QT_SQL_LIB DESQLDATABASE_LIB
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/Debug \
    .
	

DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

HEADERS += \
    dealermtable.h \
    dedevicetable.h \
    deradioactivesourcetable.h \
    desqldatabase.h \
    desqldatabase_global.h \
    deusertable.h \
	delogtable.h \
	desystemparam.h \
	detectortable.h \
    devalueobjectinterface.h

SOURCES += \
    dealermtable.cpp \
    dedevicetable.cpp \
    deradioactivesourcetable.cpp \
    desqldatabase.cpp \
    deusertable.cpp \
	delogtable.cpp \
	desystemparam.cpp \
	detectortable.cpp \
    devalueobjectinterface.cpp
