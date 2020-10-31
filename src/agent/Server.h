#pragma once
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);
    bool Init();
private:
    void SendData();

   QTcpServer m_tcpServer;
};
