
#pragma once

#include "IAgentsStatusProvider.hpp"

class AgentsStatusProvider : public IAgentsStatusProvider
{
public:
    virtual void fetchStatusOf(const AgentInformation& , const IAgentsStatusProvider::StatusCallback& ) = 0;

};
