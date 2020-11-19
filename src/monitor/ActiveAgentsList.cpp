
#include <iterator>

#include "ActiveAgentsList.hpp"


using namespace std::placeholders;


AgentsList::AgentsList(IAgentsStatusProvider& statusProvider, QObject* p)
    : QAbstractListModel(p)
    , m_statusProvider(statusProvider)
{

}


void AgentsList::addAgent(const AgentInformation& info)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    // we do not need duplicates
    if (it == m_agents.end())
    {
        beginInsertRows({}, m_agents.size(), m_agents.size());
        m_agents.append(info);
        endInsertRows();

        m_statusProvider.fetchStatusOf(info, std::bind(&AgentsList::updateAgentHealth, this, _1, _2));
    }
}


void AgentsList::removeAgent(const AgentInformation& info)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    if (it != m_agents.end())
    {
        const int pos = std::distance(m_agents.begin(), it);

        beginRemoveRows({}, pos, pos);
        m_agents.removeAt(pos);
        m_health.remove(info);
        endRemoveRows();
    }
}


const QVector<AgentInformation> & AgentsList::agents() const
{
    return m_agents;
}


int AgentsList::rowCount(const QModelIndex& parent) const
{
    return parent.isValid()? 0: m_agents.size();
}


QVariant AgentsList::data(const QModelIndex& index, int role) const
{
    QVariant result;

    if (index.column() == 0 && index.row() < m_agents.size())
    {
        const int row = index.row();

        if (role == AgentNameRole)
            result = m_agents[row].name();
        else if (role == AgentHealthRole)
        {
            auto it = m_health.find(m_agents[row]);

            result = it == m_health.end()? Health::UNKNOWN: it.value();
        }
    }

    return result;
}


QHash<int, QByteArray> AgentsList::roleNames() const
{
    auto existingRoles = QAbstractListModel::roleNames();
    existingRoles.insert(AgentNameRole, "agentName");
    existingRoles.insert(AgentHealthRole, "agentHealth");

    return existingRoles;
}


void AgentsList::updateAgentHealth(const AgentInformation& info, const Health& health)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    if (it != m_agents.end())
    {
        m_health[info] = health;

        const int pos = std::distance(m_agents.begin(), it);
        const QModelIndex idx = index(pos, 0);

        emit dataChanged(idx, idx, {AgentHealthRole});
    }
}
