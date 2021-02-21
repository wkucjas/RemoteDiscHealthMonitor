
#pragma once

#include <QRemoteObjectHost>

#include "common/GeneralHealth.h"
#include "common/constants.hpp"
#include "AgentStatus.h"

class Server: public QObject
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

    QRemoteObjectHost m_ROHost;
    AgentStatus m_agentStatus;
    QString m_ip;
};
