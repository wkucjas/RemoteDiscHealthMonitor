
#ifndef MANUALAGENTSVALIDATOR_HPP
#define MANUALAGENTSVALIDATOR_HPP

#include <QObject>

#include "AgentInformation.hpp"


class ManualAgentsValidator : public QObject
{
    Q_OBJECT

    public:

    public slots:
        void addNewAgent(const QString& name, const QString& ip, const QString& port);

    signals:
        void agentDiscovered(const AgentInformation &);
};

#endif
