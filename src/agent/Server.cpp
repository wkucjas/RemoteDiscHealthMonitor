#include "Server.h"
#include <QNetworkInterface>
#include <QDataStream>
#include <QTcpSocket>
#include <iostream>
#include "common/constants.hpp"
#include "common/ProtocolVersion.h"
#include "SmartReader.h"
#include "SystemUtilitiesFactory.h"
#include "DiscStatusCalculator.h"


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
    CollectInfoAboutDiscs();

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << ProtocolVersion::VER_1;
    out << static_cast<quint8>(m_health.GetStatus());

    QTcpSocket* clientConnection = m_tcpServer.nextPendingConnection();

    connect(clientConnection, &QAbstractSocket::disconnected,clientConnection, &QObject::deleteLater);

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}

void Server::CollectInfoAboutDiscs()
{
    SystemUtilitiesFactory systemUtilsFactory;
    auto diskCollector = systemUtilsFactory.diskCollector();
    auto discCollection = diskCollector->GetDisksList();
    std::vector< DiscStatusCalculator::ProbePtr> probes;
    auto probe = systemUtilsFactory.generalAnalyzer();
    probes.emplace_back(std::move(probe));

    DiscStatusCalculator calc(probes, discCollection);
    m_health = calc.GetStatus();
}

