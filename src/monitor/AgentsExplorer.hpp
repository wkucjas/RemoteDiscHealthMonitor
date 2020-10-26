
#ifndef AGENTSENUMERATOR_HPP
#define AGENTSENUMERATOR_HPP

#include <QObject>

#include "QtZeroConf/qzeroconf.h"
#include "AgentInformation.hpp"


class AgentsExplorer: public QObject
{
    Q_OBJECT

public:
    AgentsExplorer(QObject* parent = nullptr);

    void startListening();

signals:
    void agentDiscovered(const AgentInformation &);
    void agentLost(const AgentInformation &);

private:
    QZeroConf m_zeroConf;

    void newAgent(const QZeroConfService &);
    void lostAgent(const QZeroConfService &);
};

#endif
