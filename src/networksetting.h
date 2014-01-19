#ifndef NETWORKSETTING_H
#define NETWORKSETTING_H

#include <QObject>

class NetworkSetting : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString passphrase READ passphrase WRITE setPassphrase NOTIFY passphraseChanged)
    Q_PROPERTY(QString lastip READ lastip WRITE setLastip NOTIFY lastipChanged)

public:
    NetworkSetting(QObject *parent=0);
    NetworkSetting(const QString &name, const QString &passphrase, const QString &lastip, const QString &directory, QObject *parent=0);

    QString name() const;
    void setName(const QString &name);

    QString passphrase() const;
    void setPassphrase(const QString &passphrase);

    QString lastip() const;
    void setLastip(const QString &lastip);

    QString directory() const;
    void setDirectory(const QString &directory);

signals:
    void nameChanged();
    void passphraseChanged();
    void lastipChanged();

private:
    QString l_name;
    QString l_passphrase;
    QString l_lastip;
    QString l_directory;
};

#endif // NETWORKSETTING_H
