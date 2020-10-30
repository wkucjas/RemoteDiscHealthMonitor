
#pragma once

#include "AgentInformation.hpp"
#include "common/GeneralHealth.h"

class IAgentsStatusProvider
{
    public:
        typedef std::function<void(const AgentInformation &, const GeneralHealth &)> StatusCallback;

        virtual ~IAgentsStatusProvider() = default;

        virtual void fetchStatusOf(const AgentInformation &, const StatusCallback &) = 0;
};
