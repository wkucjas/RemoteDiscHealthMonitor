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

    DiscStatusCalculator(const std::vector<ProbePtr>& _discProbes, const std::vector<Disk>& _disks);

    GeneralHealth::Health GetStatus();

private:
    const std::vector<ProbePtr>& m_discProbes;
    const std::vector<Disk>& m_disks;
};