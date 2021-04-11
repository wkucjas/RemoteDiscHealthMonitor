
#include <gmock/gmock.h>

#include "ProbeStatus.h"
#include "ProbeStatusSerialize.h"


TEST(ProbeStatusTest, serializationOfStringRawData)
{
    ProbeStatus status;
    status.health = GeneralHealth::GOOD;
    status.rawData = std::string("test data");

    QByteArray array;

    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << status;

    ProbeStatus status2;
    QDataStream stream2(&array, QIODevice::ReadOnly);
    stream2 >> status2;

    EXPECT_EQ(status.health, status2.health);
    EXPECT_EQ(std::get<std::string>(status.rawData), std::get<std::string>(status2.rawData));
}



TEST(ProbeStatusTest, serializationOfSmartRawData)
{
    ProbeStatus status;
    status.health = GeneralHealth::BAD;
    status.rawData = SmartData{ .smartData =
        {
            {1, {1,2,3,4,5}},
            {4, {8,9,4,12,3}}
        }
    };

    QByteArray array;

    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << status;

    ProbeStatus status2;
    QDataStream stream2(&array, QIODevice::ReadOnly);
    stream2 >> status2;

    EXPECT_EQ(status.health, status2.health);
    EXPECT_EQ(std::get<SmartData>(status.rawData), std::get<SmartData>(status2.rawData));
}
