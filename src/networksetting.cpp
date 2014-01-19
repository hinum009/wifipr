#include "networksetting.h"

NetworkSetting::NetworkSetting(QObject *parent)
    : QObject(parent)
{
}

NetworkSetting::NetworkSetting(const QString &name, const QString &passphrase, const QString &lastip, const QString &directory, QObject *parent)
    : QObject(parent), l_name(name), l_passphrase(passphrase), l_lastip(lastip), l_directory(directory)
{
}

QString NetworkSetting::name() const
{
    return l_name;
}

void NetworkSetting::setName(const QString &name)
{
    if (name != l_name) {
        l_name = name;
        emit nameChanged();
    }
}

QString NetworkSetting::passphrase() const
{
    return l_passphrase;
}

void NetworkSetting::setPassphrase(const QString &passphrase)
{
    if (passphrase != l_passphrase) {
        l_passphrase = passphrase;
        emit passphraseChanged();
    }
}

QString NetworkSetting::directory() const
{
    return l_directory;
}

void NetworkSetting::setDirectory(const QString &directory)
{
    if (directory != l_directory) {
        l_directory = directory;
//        emit directoryChanged();
    }
}

QString NetworkSetting::lastip() const
{
    return l_lastip;
}

void NetworkSetting::setLastip(const QString &lastip)
{
    if (lastip != l_lastip) {
        l_lastip = lastip;
        emit lastipChanged();
    }
}
