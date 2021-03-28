#include <gmock/gmock.h>

#include <memory>
#include "IProbeMock.h"
#include "DiskMock.h"
#include "DiscStatusCalculator.h"

using testing::_;
using testing::Return;

TEST(DiscStatusCalculatorTest, CalculateStatusWithOneProbeWhichIsGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::GOOD}), GeneralHealth::Health::GOOD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOneProbeWhichIsBAD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::BAD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::GOOD, GeneralHealth::Health::GOOD}), GeneralHealth::Health::GOOD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreGOODandBAD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::GOOD, GeneralHealth::Health::BAD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreCHECK_STATUSandBAD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::CHECK_STATUS, GeneralHealth::Health::BAD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreCHECK_STATUSandGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::CHECK_STATUS, GeneralHealth::Health::GOOD}), GeneralHealth::Health::CHECK_STATUS);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreBADandGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::BAD, GeneralHealth::Health::GOOD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOThreeProbesWhichAreGOODandBADandGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::GOOD,
                                           GeneralHealth::Health::BAD,
                                           GeneralHealth::Health::GOOD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOThreeProbesWhichAreCHECK_STATUSandBADandGOOD)
{
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateOverallStatus({GeneralHealth::Health::CHECK_STATUS,
                                           GeneralHealth::Health::BAD,
                                           GeneralHealth::Health::GOOD}), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusForSingleDisk)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::CHECK_STATUS));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::BAD));

    std::unique_ptr<IProbeMock> probe3(new IProbeMock());
    EXPECT_CALL(*probe3, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));
    probes.emplace_back(std::move(probe3));

    const DiskMock disk;
    DiscStatusCalculator calc;

    ASSERT_EQ(calc.CalculateDiskStatus(disk, probes), GeneralHealth::Health::BAD);
}
