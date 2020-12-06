#pragma once

#include <vector>
#include <memory>
#include "IProbe.h"
#include "../common/GeneralHealth.h"


class DiscStatusCalculator
{
public:
    typedef std::unique_ptr<IProbe> ProbePtr;

    DiscStatusCalculator(const std::vector<ProbePtr>& _discProbes);

    GeneralHealth::Health GetStatus();

private:
    const std::vector<ProbePtr>& m_discProbes;
};