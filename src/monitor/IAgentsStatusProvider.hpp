
#pragma once

#include "AgentInformation.hpp"
#include "common/GeneralHealth.h"
#include <functional>

class IAgentsStatusProvider
{
    public:
        typedef std::function<void(const AgentInformation &, const Health &)> StatusCallback;

        virtual ~IAgentsStatusProvider() = default;

        virtual void fetchStatusOf(const AgentInformation &, const StatusCallback &) = 0;
};
