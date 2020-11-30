#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator(std::vector<ProbePtr>& _discProbes) : m_discProbes(_discProbes)
{
}

GeneralHealth::Health DiscStatusCalculator::GetStatus()
{
    GeneralHealth::Health status = GeneralHealth::Health::UNKNOWN;

    for (auto& probe : m_discProbes)
    {
        GeneralHealth::Health tmpStatus = probe->GetStatus();
        if (tmpStatus > status)
        {
            status = tmpStatus;
        }
    }
    return status;
}
