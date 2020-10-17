
#include <QDebug>

#include "AgentsEnumerator.hpp"
#include "common/constants.hpp"


AgentsExplorer::AgentsExplorer(QObject* parent)
{
    connect(&m_zeroConf, &QZeroConf::serviceAdded, this, &AgentsExplorer::newAgent);
    connect(&m_zeroConf, &QZeroConf::serviceRemoved, this, &AgentsExplorer::lostAgent);
}


void AgentsExplorer::startListening()
{
    m_zeroConf.startBrowser(ZeroConfServiceName);
}


void AgentsExplorer::newAgent(const QZeroConfService& info)
{
    qDebug() << "New agent discovered on: " << info->host() << ":" << info->port();

    AgentInformation agentInfo(info->name(), info->host(), info->port());
    emit agentDiscovered(agentInfo);
}


void AgentsExplorer::lostAgent(const QZeroConfService& info)
{
    qDebug() << "Agent lost: " << info->host() << ":" << info->port();

    AgentInformation agentInfo(info->name(), info->host(), info->port());
    emit agentLost(agentInfo);
}
