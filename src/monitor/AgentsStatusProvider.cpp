
#include <tuple>
#include <iostream>

#include "AgentsStatusProvider.hpp"


using namespace std::placeholders;

void AgentsStatusProvider::observe(const AgentInformation& info)
{
    auto it = m_statuses.find(info);

    if (it == m_statuses.end())
    {
        QRemoteObjectNode* repNode = new QRemoteObjectNode;
        const QUrl url = QStringLiteral("tcp://%1:%2").arg(info.host().toString()).arg(info.port());
        repNode->connectToNode(url);

        auto replica = repNode->acquire<AgentStatusReplica>();

        it = m_statuses.insert(info, {replica, repNode});

        QObject::connect(replica, &AgentStatusReplica::overallStatusChanged,
                         std::bind(&AgentsStatusProvider::statusChanged, this, info, _1));
        QObject::connect(replica, &AgentStatusReplica::initialized, [replica](){
            replica->refresh();
        });
    }
}
