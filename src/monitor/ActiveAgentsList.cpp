
#include "ActiveAgentsList.hpp"

void ActiveAgentsList::addAgent(const AgentInformation& info)
{
    m_agents.insert(info);
}


void ActiveAgentsList::removeAgent(const AgentInformation& info)
{
    m_agents.remove(info);
}


const QSet<AgentInformation> & ActiveAgentsList::agents() const
{
    return m_agents;
}


int ActiveAgentsList::rowCount(const QModelIndex& parent) const
{
    return m_agents.size();
}


QVariant ActiveAgentsList::data(const QModelIndex& index, int role) const
{
    return 0;
}
