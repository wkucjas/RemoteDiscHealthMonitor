
#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

#include "common/GeneralHealth.h"
#include "AgentInformation.hpp"


class AgentStatusFetcher: public QObject
{
    Q_OBJECT

    public:
        AgentStatusFetcher(const AgentInformation &);

    signals:
        void statusAvailable(const Health &);

    private:
        QTcpSocket m_socket;
        QDataStream m_inputStream;

        void readStatus();
};
