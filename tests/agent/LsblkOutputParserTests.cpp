
#include <gmock/gmock.h>

#include "linux/LsblkOutputParser.h"

using testing::UnorderedElementsAre;

TEST(LsblkOutputParserTest, fullOutput)
{
    const auto result = LsblkOutputParser::parse(
        R"(NAME MAJ:MIN RM SIZE RO TYPE MOUNTPOINT
           sda 8:0 0 120034123776 0 disk
           sda2 8:2 0 119822876672 0 part /
           sda1 8:1 0 209715200 0 part /boot
           sdb 8:16 0 1000204886016 0 disk
           sdb1 8:17 0 1000203837440 0 part
           sdc 8:32 0 2000398934016 0 disk
           sdc1 8:33 0 1000203837440 0 part
           sdd 8:48 0 1000204886016 0 disk
           sdd1 8:49 0 1000203091968 0 part
           sde 8:64 0 120034123776 0 disk
           sde2 8:66 0 119822876672 0 part
           sde1 8:65 0 209715200 0 part
           md0 9:0 0 2000137748480 0 raid5
           md0p2 259:1 0 1978661863424 0 part /home
           md0p1 259:0 0 21474836480 0 part [SWAP]
           sr0 11:0 1 490340352 0 rom
        )"
    );

    EXPECT_THAT(result, UnorderedElementsAre(
        LsblkOutputParser::LsblkEntry{ .name = "sda", .type = "disk",  .size = 120034123776,  .partitions = 2, .major = 8, .minor = 0 },
        LsblkOutputParser::LsblkEntry{ .name = "sdb", .type = "disk",  .size = 1000204886016, .partitions = 1, .major = 8, .minor = 16},
        LsblkOutputParser::LsblkEntry{ .name = "sdc", .type = "disk",  .size = 2000398934016, .partitions = 1, .major = 8, .minor = 32},
        LsblkOutputParser::LsblkEntry{ .name = "sdd", .type = "disk",  .size = 1000204886016, .partitions = 1, .major = 8, .minor = 48},
        LsblkOutputParser::LsblkEntry{ .name = "sde", .type = "disk",  .size = 120034123776,  .partitions = 2, .major = 8, .minor = 64},
        LsblkOutputParser::LsblkEntry{ .name = "md0", .type = "raid5", .size = 2000137748480, .partitions = 2, .major = 9, .minor = 0 }
    ));
}

