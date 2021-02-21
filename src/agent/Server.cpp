#include "Server.h"
#include <QNetworkInterface>
#include <QDataStream>
#include <QTcpSocket>
#include <iostream>
#include "common/constants.hpp"
#include "common/ProtocolVersion.h"
#include "AgentStatus.h"
#include "SmartReader.h"
#include "SystemUtilitiesFactory.h"
#include "DiscStatusCalculator.h"

Server::Server(QObject* parent)
    : QObject(parent)
    , m_ROHost()
{

}

bool Server::Init()
{
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            m_ip = ipAddressesList.at(i).toString();
            break;
        }
    }

    if (m_ip.isEmpty())
    {
        m_ip = QHostAddress(QHostAddress::LocalHost).toString();
    }

    const QUrl url = QStringLiteral("tcp://%1:%2").arg(m_ip).arg(RDHMPort);
    m_ROHost.setHostUrl(url);

    std::cout << "The server is running on: " << url.toDisplayString().toStdString() << '\n';

    const bool status = m_ROHost.enableRemoting(&m_agentStatus);

    if (status)
        std::cout << "RemoteObjects network setup properly.\n";
    else
        std::cerr << "RemoteObjects network setup fatal error.\n";

    return true;
}

const QString& Server::ip() const
{
    return m_ip;
}


quint16 Server::port() const
{
    return RDHMPort;
}


void Server::SendData()
{
    CollectInfoAboutDiscs();

    m_agentStatus.setOverallStatus(m_health.GetStatus());
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

