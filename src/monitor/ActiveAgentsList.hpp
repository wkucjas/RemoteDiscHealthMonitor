
#pragma once

#include <QAbstractListModel>

#include "AgentInformation.hpp"


class ActiveAgentsList: QAbstractListModel
{
public:
    void addAgent(const AgentInformation &);
    void removeAgent(const AgentInformation &);

    // QAbstractListModel:
    int rowCount(const QModelIndex & parent) const override;
    QVariant data(const QModelIndex & index, int role) const override;
};
