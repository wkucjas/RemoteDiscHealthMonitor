#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator(const std::vector<ProbePtr>& _discProbes) : m_discProbes(_discProbes)
{
}

GeneralHealth::Health DiscStatusCalculator::GetStatus()
{
    GeneralHealth::Health status = GeneralHealth::Health::UNKNOWN;

    for (const auto& probe : m_discProbes)
    {
        GeneralHealth::Health probeStatus = probe->GetStatus();
        if (probeStatus > status)
        {
            status = probeStatus;
        }
    }
    return status;
}
