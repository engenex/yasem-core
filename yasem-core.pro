#-------------------------------------------------
#
# Project created by QtCreator 2014-02-01T19:32:45
#
#-------------------------------------------------

VERSION = 0.1.0
TARGET = yasem
TEMPLATE = app

include($${top_srcdir}/common.pri)

QT += core widgets network
equals(QT_MAJOR_VERSION, 5): {
    QT -= gui
}

CONFIG -= console
QT.testlib.CONFIG -= console


#DEFINES += EXTRA_DEBUG_INFO #Set this flag to show extra information in logger output

TRANSLATIONS = lang/en_US.qm \
    lang/ru_RU.qm \
    lang/uk_UA.qm

SOURCES += main.cpp \
    pluginmanagerimpl.cpp \
    coreimpl.cpp \
    profilemanageimpl.cpp \
    networkimpl.cpp \
    pluginthread.cpp \
    loggercore.cpp \
    yasemapplication.cpp \
    diskinfo.cpp \
    stacktrace.cxx \
    profileconfigparserimpl.cpp \
    sambaimpl.cpp \
    mountpointinfo.cpp \
    sambanode.cpp \
    plugin.cpp \
    webserverplugin.cpp \
    mediaplayerpluginobject.cpp \
    stbpluginobject.cpp

HEADERS += \
    pluginmanager.h \
    pluginmanagerimpl.h \
    coreimpl.h \
    core.h \
    mainwindow.h \
    plugindependency.h \
    profilemanager.h \
    profilemanageimpl.h \
    networkimpl.h \
    stbprofile.h \
    customkeyevent.h \
    plugin.h \
    macros.h \
    enums.h  \
    datasourceplugin.h \
    pluginthread.h \
    core-network.h \
    loggercore.h \
    yasemapplication.h \
    diskinfo.h \
    webobjectinfo.h \
    profile_config_parser.h \
    profileconfigparserimpl.h \
    samba.h \
    sambaimpl.h \
    mountpointinfo.h \
    sambanode.h \
    webserverplugin.h \
    abstractwebpage.h \
    mediainfo.h \
    plugin_p.h \
    stbsubmodule.h \
    webserverplugin_p.h \
    abstractpluginobject.h \
    stbpluginobject.h \
    stbpluginobject_p.h \
    mediaplayerpluginobject.h \
    browserpluginobject.h \
    guipluginobject.h \
    datasourcepluginobject.h

#unix:!mac{
#  QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/
#  QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/libs
#  QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/plugins
#  QMAKE_RPATH=
#}

OTHER_FILES += \
    LICENSE \
    README.md



