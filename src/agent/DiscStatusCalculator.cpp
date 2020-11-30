#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator(std::vector<ProbePtr>& _discProbes) : m_discProbes(_discProbes)
{
}

GeneralHealth::Health DiscStatusCalculator::GetStatus()
{
    return GeneralHealth::Health::GOOD;
}
