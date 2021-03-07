
#pragma once

#include <QAbstractListModel>
#include <QHash>
#include <QVector>

#include "common/GeneralHealth.h"
#include "AgentInformation.hpp"
#include "IAgentsStatusProvider.hpp"


class AgentsList: public QAbstractListModel
{
    Q_OBJECT

public:
    AgentsList(IAgentsStatusProvider &, QObject* parent = nullptr);

    void addAgent(const AgentInformation &);
    void removeAgent(const AgentInformation &);
    Q_INVOKABLE void removeAgentAt(int position);

    const QVector<AgentInformation>& agents() const;

    // QAbstractListModel:
    int rowCount(const QModelIndex & parent) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum Roles
    {
        AgentNameRole = Qt::UserRole + 1,
        AgentHealthRole,
        AgentDetectionType,
    };

private:
    QVector<AgentInformation> m_agents;
    QHash<AgentInformation, GeneralHealth::Health> m_health;
    IAgentsStatusProvider& m_statusProvider;

    void updateAgentHealth(const AgentInformation &, const GeneralHealth::Health &);
};
