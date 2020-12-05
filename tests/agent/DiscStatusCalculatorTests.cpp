#include <gmock/gmock.h>

#include "IProbe.h"
#include <memory>
#include "IprobeMock.h"
#include "DiscStatusCalculator.h"

using testing::_;
using testing::Return;

TEST(DiscStatusCalculatorTest, CalculateStatusWithGeneralProbe)
{
    std::unique_ptr<IProbeMock> mock(new IProbeMock());
    EXPECT_CALL(*mock, GetStatus())
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(mock));
    
    DiscStatusCalculator calc(probes);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::GOOD);
}