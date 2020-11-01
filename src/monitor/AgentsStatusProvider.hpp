
#pragma once

#include "IAgentsStatusProvider.hpp"

class AgentsStatusProvider : public IAgentsStatusProvider
{
public:
    void fetchStatusOf(const AgentInformation& , const IAgentsStatusProvider::StatusCallback& ) override;
};
