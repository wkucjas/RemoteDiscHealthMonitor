#include "Server.h"
#include <qnetworkinterface.h>
#include <iostream>


void Server::Init()
{
    try {
        if (!tcpServer.listen()) {
            throw std::exception("Unable to start the server");
        }

        QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

        for (int i = 0; i < ipAddressesList.size(); ++i) 
        {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) 
            {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }

        if (ipAddress.isEmpty())
        {
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        }

        std::cout << "The server is running on IP: " << ipAddress.toStdString() << " port: "<< tcpServer.serverPort() << std::endl;
    }
    catch (std::exception e)
    {
    }
}
