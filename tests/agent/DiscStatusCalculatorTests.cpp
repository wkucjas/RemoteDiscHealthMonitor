#include <gmock/gmock.h>

#include <memory>
#include "IProbeMock.h"
#include "DiskMock.h"
#include "DiscStatusCalculator.h"

using testing::_;
using testing::Return;

TEST(DiscStatusCalculatorTest, CalculateStatusWithOneProbeWhichIsGOOD)
{
    std::unique_ptr<IProbeMock> probe(new IProbeMock());

    EXPECT_CALL(*probe, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe));
    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_TRUE(calc.GetStatus() == GeneralHealth::Health::GOOD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOneProbeWhichIsBAD)
{
    std::unique_ptr<IProbeMock> probe(new IProbeMock());
    EXPECT_CALL(*probe, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::BAD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe));
    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreGOOD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::GOOD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreGOODandBAD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::BAD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreCHECK_STATUSandBAD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::CHECK_STATUS));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::BAD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreCHECK_STATUSandGOOD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::CHECK_STATUS));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::CHECK_STATUS);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOTwoProbesWhichAreBADandGOOD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::BAD));

    std::unique_ptr<IProbeMock> probe2(new IProbeMock());
    EXPECT_CALL(*probe2, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

    std::vector< DiscStatusCalculator::ProbePtr> probes;

    probes.emplace_back(std::move(probe1));
    probes.emplace_back(std::move(probe2));

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOThreeProbesWhichAreGOODandBADandGOOD)
{
    std::unique_ptr<IProbeMock> probe1(new IProbeMock());
    EXPECT_CALL(*probe1, GetStatus(_))
        .Times(1)
        .WillOnce(Return(GeneralHealth::Health::GOOD));

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

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}

TEST(DiscStatusCalculatorTest, CalculateStatusWithOThreeProbesWhichAreCHECK_STATUSandBADandGOOD)
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

    std::vector<Disk> disks;
    const DiskMock disk;
    disks.push_back(disk);
    DiscStatusCalculator calc(probes, disks);

    ASSERT_EQ(calc.GetStatus(), GeneralHealth::Health::BAD);
}