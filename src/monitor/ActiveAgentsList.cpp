
#include "ActiveAgentsList.hpp"

void ActiveAgentsList::addAgent(const AgentInformation& info)
{
    m_agents.insert(info);
}


int ActiveAgentsList::rowCount(const QModelIndex& parent) const
{
    return m_agents.size();
}


QVariant ActiveAgentsList::data(const QModelIndex& index, int role) const
{
    return 0;
}
