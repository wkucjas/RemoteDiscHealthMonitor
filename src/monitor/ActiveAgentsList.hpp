
#pragma once

#include <QAbstractListModel>
#include <QVector>

#include "AgentInformation.hpp"


class ActiveAgentsList: public QAbstractListModel
{
public:
    ActiveAgentsList(QObject* parent = nullptr);

    void addAgent(const AgentInformation &);
    void removeAgent(const AgentInformation &);

    const QVector<AgentInformation>& agents() const;

    // QAbstractListModel:
    int rowCount(const QModelIndex & parent) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum Roles
    {
        AgentNameRole = Qt::UserRole + 1,
    };

private:
    QVector<AgentInformation> m_agents;
};
