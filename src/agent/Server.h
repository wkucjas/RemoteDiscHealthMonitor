#pragma once
#include <QTcpServer>
#include "common/GeneralHealth.h"
#include "common/constants.hpp"

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);
    bool Init();

    const QString& ip() const;
    quint16 port() const;

private:
    void SendData();
    void CollectInfoAboutDiscs();

    GeneralHealth m_health;

    QTcpServer m_tcpServer;
    QString m_ip;
};
