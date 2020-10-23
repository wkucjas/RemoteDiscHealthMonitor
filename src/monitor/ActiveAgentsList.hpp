
#pragma once

#include <QAbstractListModel>
#include <QSet>

#include "AgentInformation.hpp"


class ActiveAgentsList: public QAbstractListModel
{
public:
    ActiveAgentsList(QObject* parent = nullptr);

    void addAgent(const AgentInformation &);
    void removeAgent(const AgentInformation &);

    const QSet<AgentInformation>& agents() const;

    // QAbstractListModel:
    int rowCount(const QModelIndex & parent) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum Roles
    {
        AgentNameRole = Qt::UserRole + 1,
    };

private:
    QSet<AgentInformation> m_agents;
};
