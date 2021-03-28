#pragma once

#include <vector>
#include <memory>
#include "IProbe.h"
#include "../common/GeneralHealth.h"
#include "agent/Disk.h"


class DiscStatusCalculator
{
public:
    typedef std::unique_ptr<IProbe> ProbePtr;

    DiscStatusCalculator();

    GeneralHealth::Health CalculateOverallStatus(const std::vector<GeneralHealth::Health> &) const;
    GeneralHealth::Health CalculateDiskStatus(const Disk& _disk, const std::vector<ProbePtr>& _discProbes);
};
