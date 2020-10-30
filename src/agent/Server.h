#pragma once
#include <qtcpserver.h>


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);
    void Init();
    void SendData();

   QTcpServer tcpServer;
};
