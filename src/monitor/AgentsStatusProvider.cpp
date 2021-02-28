
#include <tuple>
#include <iostream>

#include "AgentsStatusProvider.hpp"


using namespace std::placeholders;

void AgentsStatusProvider::fetchStatusOf(const AgentInformation& info, const StatusCallback& callback)
{
    auto it = m_statuses.find(info);

    if (it == m_statuses.end())
    {
        QRemoteObjectNode* repNode = new QRemoteObjectNode;
        const QUrl url = QStringLiteral("tcp://%1:%2").arg(info.host()).arg(info.port());
        repNode->connectToNode(url);

        auto replica = repNode->acquire<AgentStatusReplica>();

        it = m_statuses.insert(info, {replica, repNode});

        QObject::connect(replica, &AgentStatusReplica::overallStatusChanged, std::bind(callback, info, _1));
        QObject::connect(replica, &AgentStatusReplica::initialized, [replica](){
            replica->refresh();
        });
    }
}
