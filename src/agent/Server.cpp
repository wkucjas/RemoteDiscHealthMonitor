#include "Server.h"
#include <QNetworkInterface>
#include <QDataStream>
#include <QTcpSocket>
#include <iostream>
#include "common/constants.hpp"


Server::Server(QObject * parent)
{
    connect(&m_tcpServer, &QTcpServer::newConnection, this, &Server::SendData);
}

bool Server::Init()
{
        if (!m_tcpServer.listen(QHostAddress::Any, RDHMPort)) {
            return false;
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

        std::cout << "The server is running on IP: " << ipAddress.toStdString() << " port: "<< m_tcpServer.serverPort() << std::endl;

        return true;
}

void Server::SendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    qint8 temporaryResponse_1 = 1;
    quint8 temporaryResponse_2 = 1;

    out << temporaryResponse_1;
    out << temporaryResponse_2;

    QTcpSocket* clientConnection = m_tcpServer.nextPendingConnection();

    connect(clientConnection, &QAbstractSocket::disconnected,clientConnection, &QObject::deleteLater);

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}
