#pragma once

#include <vector>

#include "IProbe.h"
#include "../common/GeneralHealth.h"


class DiscStatusCalculator
{
public:
    typedef std::unique_ptr<IProbe> ProbePtr;

    DiscStatusCalculator(std::vector<ProbePtr>& _discProbes);

    GeneralHealth::Health GetStatus();

private:
    std::vector<ProbePtr>& m_discProbes;
};