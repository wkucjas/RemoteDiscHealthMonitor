
#ifndef AGENTSENUMERATOR_HPP
#define AGENTSENUMERATOR_HPP

#include <QObject>

#include "QtZeroConf/qzeroconf.h"


class AgentsEnumerator: public QObject
{
public:
    AgentsEnumerator(QObject* parent = nullptr);

    void startListening();

private:
    QZeroConf m_zeroConf;

    void newAgent(const QZeroConfService &);
    void lostAgent(const QZeroConfService &);
};

#endif
