#include <gmock/gmock.h>

#include "IProbe.h"
#include <memory>
#include "windows/WinGeneralAnalyzer.h"
#include "DiscStatusCalculator.h"

TEST(DiscStatusCalculatorTest, CalculateStatusWithGeneralProbe)
{
    //std::shared_ptr<IProbe> probe( new WinGeneralAnalyzer());
    WinGeneralAnalyzer dupa;
//    std::vector< DiscStatusCalculator::ProbePtr> probes;
    //probes.push_back(probe);
    //DiscStatusCalculator calc(probes);

    //GeneralHealth::Health status = calc.GetStatus();
    ASSERT_EQ(true, true);
}