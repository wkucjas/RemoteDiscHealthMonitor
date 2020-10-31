#pragma once
#include <QTcpServer>
#include "common/ProtocolVersion.h"
#include "common/GeneralHealth.h"
#include "common/constants.hpp"

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);
    bool Init();
private:
    void SendData();
    void CollectInfoAboutDiscs();

    ProtocolVersion m_protocolVersion = VersionOfProtocol;
    GeneralHealth m_health;

   QTcpServer m_tcpServer;
};
