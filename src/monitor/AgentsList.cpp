
#include <chrono>
#include <iterator>
#include <QDebug>

#include "AgentsList.hpp"


using namespace std::placeholders;
using namespace std::chrono_literals;


AgentsList::AgentsList(IAgentsStatusProvider& statusProvider, QObject* p)
    : QAbstractListModel(p)
    , m_statusProvider(statusProvider)
{
    connect(&m_statusProvider, &IAgentsStatusProvider::statusChanged, this, &AgentsList::updateAgentHealth);
    connect(&m_statusProvider, &IAgentsStatusProvider::diskCollectionChanged, this, &AgentsList::updateAgentDiskInfoCollection);
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

        m_statusProvider.observe(info);
    }
}


void AgentsList::removeAgent(const AgentInformation& info)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), info);

    if (it != m_agents.end())
    {
        const int pos = std::distance(m_agents.begin(), it);

       removeAgentAt(pos);
    }
}


void AgentsList::removeAgentAt(int position)
{
    const AgentInformation info = m_agents[position];

    beginRemoveRows({}, position, position);
    m_agents.removeAt(position);
    m_health.remove(info);
    endRemoveRows();
}


const QVector<AgentInformation>& AgentsList::agents() const
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

            result = it == m_health.end()? GeneralHealth::UNKNOWN: it.value();
        }
        else if (role == AgentDetectionType)
        {
            result = static_cast<int>(m_agents[row].detectionSource());
        }
    }

    return result;
}


QHash<int, QByteArray> AgentsList::roleNames() const
{
    auto existingRoles = QAbstractListModel::roleNames();
    existingRoles.insert(AgentNameRole, "agentName");
    existingRoles.insert(AgentHealthRole, "agentHealth");
    existingRoles.insert(AgentDetectionType, "agentDetectionType");
    existingRoles.insert(AgentDiskInfoCollectionRole, "agentDiskInfoCollectionRole");

    return existingRoles;
}


void AgentsList::updateAgentHealth(const AgentInformation& info, const GeneralHealth::Health& health)
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

void AgentsList::updateAgentDiskInfoCollection(const AgentInformation& _info, const std::vector<DiskInfo>& _diskInfoCollection)
{
    auto it = std::find(m_agents.begin(), m_agents.end(), _info);

    if (it != m_agents.end())
    {
        m_diskInfoCollection[_info] = _diskInfoCollection;

        const int pos = std::distance(m_agents.begin(), it);
        const QModelIndex idx = index(pos, 0);

        emit dataChanged(idx, idx, { AgentDiskInfoCollectionRole });
    }
}
