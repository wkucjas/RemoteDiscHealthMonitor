#include "DiscStatusCalculator.h"

DiscStatusCalculator::DiscStatusCalculator(std::vector<ProbePtr>& _discProbes) : m_discProbes(_discProbes)
{
}

Health DiscStatusCalculator::GetStatus()
{
    return Health();
}
