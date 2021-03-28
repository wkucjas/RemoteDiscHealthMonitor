
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
    std::vector<GeneralHealth::Health> statuses;

    std::transform(_discProbes.begin(), _discProbes.end(), std::back_inserter(statuses), [&_disk](const auto& probe) {
        return probe->GetStatus(_disk);
    });

    return CalculateOverallStatus(statuses);
}
