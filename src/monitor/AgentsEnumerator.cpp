
#include <QDebug>

#include "AgentsEnumerator.hpp"


AgentsEnumerator::AgentsEnumerator(QObject* parent)
{
    connect(&m_zeroConf, &QZeroConf::serviceAdded, this, &AgentsEnumerator::newAgent);
    connect(&m_zeroConf, &QZeroConf::serviceRemoved, this, &AgentsEnumerator::lostAgent);
}


void AgentsEnumerator::startListening()
{
    m_zeroConf.startBrowser("_RDHMonitor._tcp");
}


void AgentsEnumerator::newAgent(const QZeroConfService& info)
{
    qDebug() << "New agent discovered on: " << info->host() << ":" << info->port();
}


void AgentsEnumerator::lostAgent(const QZeroConfService& info)
{
    qDebug() << "Agent lost: " << info->host() << ":" << info->port();
}
