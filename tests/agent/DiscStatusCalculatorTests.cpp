#include <gmock/gmock.h>

#include "IProbe.h"
#include <memory>
#include "windows/WinGeneralAnalyzer.h"
#include "DiscStatusCalculator.h"

TEST(DiscStatusCalculatorTest, CalculateStatusWithGeneralProbe)
{
    std::vector< DiscStatusCalculator::ProbePtr> probes;
    probes.emplace_back(std::make_unique<WinGeneralAnalyzer>());
    
    DiscStatusCalculator calc(probes);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::GOOD);
}