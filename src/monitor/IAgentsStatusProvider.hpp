
#pragma once

#include <QObject>

#include "AgentInformation.hpp"
#include "common/GeneralHealth.h"
#include "common/DiskInfo.h"

class IAgentsStatusProvider: public QObject
{
        Q_OBJECT

    public:
        virtual ~IAgentsStatusProvider() = default;

        virtual void observe(const AgentInformation &) = 0;

    signals:
        void statusChanged(const AgentInformation &, const GeneralHealth::Health &);
        void diskCollectionChanged(const AgentInformation&, const std::vector<DiskInfo>&);

};
