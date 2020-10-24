
#include <iterator>

#include "ActiveAgentsList.hpp"


ActiveAgentsList::ActiveAgentsList(QObject* p)
    : QAbstractListModel(p)
{

}


void ActiveAgentsList::addAgent(const AgentInformation& info)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    // we do not need duplicates
    if (it == m_agents.end())
    {
        beginInsertRows({}, m_agents.size(), m_agents.size());
        m_agents.append(info);
        endInsertRows();
    }
}


void ActiveAgentsList::removeAgent(const AgentInformation& info)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    if (it != m_agents.end())
    {
        const int pos = std::distance(m_agents.begin(), it);

        m_agents.removeAt(pos);
    }
}


const QVector<AgentInformation> & ActiveAgentsList::agents() const
{
    return m_agents;
}


int ActiveAgentsList::rowCount(const QModelIndex& parent) const
{
    return m_agents.size();
}


QVariant ActiveAgentsList::data(const QModelIndex& index, int role) const
{
    QVariant result;

    if (index.column() == 0 && index.row() < m_agents.size())
    {
        const int row = index.row();

        auto it = m_agents.begin();
        std::advance(it, row);

        if (role == AgentNameRole)
            result = it->name();
    }

    return result;
}


QHash<int, QByteArray> ActiveAgentsList::roleNames() const
{
    auto existingRoles = QAbstractListModel::roleNames();
    existingRoles.insert(AgentNameRole, "agentName");

    return existingRoles;
}

