
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
    : AgentStatusSource(parent)
    , m_health(GeneralHealth::UNKNOWN)
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

    const bool status = m_ROHost.enableRemoting(this);

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


void Server::setOverallStatus(GeneralHealth::Health overallStatus)
{
    m_health = overallStatus;

    emit overallStatusChanged(m_health);
}

void Server::setDiskInfoCollection(std::vector<DiskInfo> diskInfoCollection)
{
    m_diskInfoCollection = diskInfoCollection;

    emit diskInfoCollectionChanged(m_diskInfoCollection);
}


GeneralHealth::Health Server::overallStatus() const
{
    return m_health;
}

std::vector<DiskInfo> Server::diskInfoCollection() const
{
    return m_diskInfoCollection;
}


void Server::refresh()
{
    CollectInfoAboutDiscs();
}

void Server::CollectInfoAboutDiscs()
{
    SystemUtilitiesFactory systemUtilsFactory;
    auto diskCollector = systemUtilsFactory.diskCollector();
    auto diskCollection = diskCollector->GetDisksList();
    const std::vector<std::unique_ptr<IProbe>> probes = systemUtilsFactory.getProbes();

    DiscStatusCalculator calc;

    std::vector<DiskInfo> discInfoCollection;

    for (auto disk : diskCollection)
    {
        std::vector<ProbeStatus> probesStatuses;
        probesStatuses.reserve(probes.size());

        for(const auto& probe: probes)
        {
            ProbeStatus status;
            status.health = probe->GetStatus(disk);
            status.rawData = probe->GetRawData(disk);

            probesStatuses.push_back(status);
        }

        DiskInfo diskInfo;
        diskInfo.SetName(QString::fromStdString(disk.GetDeviceId()));
        diskInfo.SetHealth(calc.CalculateDiskStatus(disk, probes));
        diskInfo.SetProbesStatuses(probesStatuses);

        discInfoCollection.push_back(diskInfo);
    }

    std::vector<GeneralHealth::Health> diskStatuses;
    std::transform(discInfoCollection.begin(), discInfoCollection.end(), std::back_inserter(diskStatuses), [](const auto& diskInfo) {
        return diskInfo.GetHealth();
    });

    setOverallStatus(calc.CalculateCumulativeStatus(diskStatuses));
    setDiskInfoCollection(discInfoCollection);
}

