#ifndef NETSETTINGSREADER_H
#define NETSETTINGSREADER_H
#include <QFile>
#include <QStringList>
#include <QQmlListProperty>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQuickView>
#include <QtQml>
#include "networksetting.h"

class NetSettingsReader : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString getTestString READ getTestString)
    Q_PROPERTY(QList<QObject*> getNetworkList READ getNetworkList)

public:
    explicit NetSettingsReader(QObject *parent = 0);
    ~NetSettingsReader();

    void readWifi();
    NetworkSetting getNetworkSetting(int index);
    QString getTestString() const;
    QList<QObject*> getNetworkList();

private:
    QList<QObject*> networkList;
};

#endif // NETSETTINGSREADER_H
