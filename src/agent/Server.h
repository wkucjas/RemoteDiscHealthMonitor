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
private:
    void SendData();
    void CollectInfoAboutDiscs();

    GeneralHealth m_health;

   QTcpServer m_tcpServer;
};
