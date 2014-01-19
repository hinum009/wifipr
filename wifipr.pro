# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = wifipr

CONFIG += sailfishapp

SOURCES += src/wifipr.cpp \
    src/netsettingsreader.cpp \
    src/networksetting.cpp

OTHER_FILES += qml/wifipr.qml \
    qml/cover/CoverPage.qml \
    rpm/wifipr.spec \
    rpm/wifipr.yaml \
    wifipr.desktop \
    qml/pages/MainPage.qml \
    qml/pages/AboutPage.qml \
    qml/pages/WifiDetails.qml \
    qml/components/ValueTitleItem.qml \
    qml/pages/LicensePage.qml

HEADERS += \
    src/netsettingsreader.h \
    src/networksetting.h

