#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator(const std::vector<ProbePtr>& _discProbes, const std::vector<Disk>& _disks) : m_discProbes(_discProbes), m_disks(_disks)
{
}

GeneralHealth::Health DiscStatusCalculator::GetStatus()
{
    GeneralHealth::Health status = GeneralHealth::Health::UNKNOWN;

    for (const auto& probe : m_discProbes)
    {
        for (const auto& disk : m_disks)
        {

            GeneralHealth::Health probeStatus = probe->GetStatus(disk);
            if (probeStatus > status)
            {
                status = probeStatus;
            }
        }
    }
    return status;
}


GeneralHealth::Health DiscStatusCalculator::CalculateDiskStatus(const Disk& _disk, const std::vector<ProbePtr>& _discProbes)
{
    GeneralHealth::Health status = GeneralHealth::Health::UNKNOWN;

    for (const auto& probe : _discProbes)
    {
        GeneralHealth::Health probeStatus = probe->GetStatus(_disk);
        if (probeStatus > status)
        {
            status = probeStatus;
        }
    }

    return status;
}
