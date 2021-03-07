
#pragma once

#include "IAgentsStatusProvider.hpp"
#include "rep_AgentStatus_replica.h"


class AgentsStatusProvider: public IAgentsStatusProvider
{
public:
    void observe(const AgentInformation &) override;

private:
    QHash<AgentInformation, std::pair<AgentStatusReplica*, QRemoteObjectNode*>> m_statuses;
};
