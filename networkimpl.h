#ifndef NETWORKIMPL_H
#define NETWORKIMPL_H

#include "network.h"

#include <QObject>

namespace yasem
{

class NetworkImpl : public QObject, public Network
{
    Q_OBJECT
public:
    explicit NetworkImpl(QObject *parent = 0);
    bool isConnected();
    bool isLanConnected();
    bool isWifiConnected();
    bool isInterfaceConnected(QNetworkInterface iface);
    QList<QNetworkInterface> getInterfaces();

signals:

public slots:

};

}

#endif // NETWORKIMPL_H