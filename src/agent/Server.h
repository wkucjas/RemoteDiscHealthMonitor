#pragma once
#include <qtcpserver.h>

class Server
{
public:
    void Init();

   QTcpServer tcpServer;
};