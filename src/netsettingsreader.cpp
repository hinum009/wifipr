#include "netsettingsreader.h"
#include "networksetting.h"
#include <QDir>
#include <QTextStream>
#include <QDebug>

NetSettingsReader::NetSettingsReader(QObject *parent) :
    QObject(parent)
{
    QString path = "/var/lib/connman";
    QDir settingsDir(path);
    settingsDir.setNameFilters(QStringList()<<"wifi_*");

    QStringList dirList = settingsDir.entryList();

    for (int var = 0; var < dirList.count();var++){
        QFile file(path+"/"+dirList[var]+"/settings");
        QString pass;
        QString name;
        QString lastip;
        QString dir;
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            while (!file.atEnd()) {
                QString line = file.readLine();
                if (line.indexOf("=")>0){
                    QStringList splitL = line.split("=");
                    if (splitL.at(0).contains("Name")){
                        name = splitL.at(1);
                    }
                    if (splitL.at(0).contains("Passphrase")){
                        pass = splitL.at(1);
                    }
                    if (splitL.at(0).contains("LastAddress")){
                        lastip = splitL.at(1);
                    }

                } else {
                }
            }
        }
        networkList.append(new NetworkSetting(name,pass,lastip,"dir"));
    }
}

NetSettingsReader::~NetSettingsReader(){
}

QList<QObject*> NetSettingsReader::getNetworkList(){
    return networkList;
}

QString NetSettingsReader::getTestString() const
{
    return "Test";
}
