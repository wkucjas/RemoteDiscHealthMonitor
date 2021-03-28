
#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator()
{

}


GeneralHealth::Health DiscStatusCalculator::CalculateOverallStatus(const std::vector<GeneralHealth::Health>& _statuses) const
{
    GeneralHealth::Health overallStatus = GeneralHealth::Health::UNKNOWN;

    for (const auto status : _statuses)
    {
        if (status > overallStatus)
        {
            overallStatus = status;
        }
    }

    return overallStatus;
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
