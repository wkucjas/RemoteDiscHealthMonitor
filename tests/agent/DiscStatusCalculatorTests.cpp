#include <gmock/gmock.h>

#include "IProbe.h"
#include <memory>
#if(_WIN32)
#include "windows/WinGeneralAnalyzer.h"
#else
#include "linux/LinGeneralAnalyzer.h"
#endif
#include "DiscStatusCalculator.h"

TEST(DiscStatusCalculatorTest, CalculateStatusWithGeneralProbe)
{
    std::vector< DiscStatusCalculator::ProbePtr> probes;

#if(_WIN32)
    
    probes.emplace_back(std::make_unique<WinGeneralAnalyzer>());
    
#else
    
    probes.emplace_back(std::make_unique<LinGeneralAnalyzer>());
#endif
    
    DiscStatusCalculator calc(probes);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::GOOD);
}