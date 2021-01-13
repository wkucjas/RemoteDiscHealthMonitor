
#include <gmock/gmock.h>

#include "linux/DmesgParser.h"
#include "IPartitionsManagerMock.h"


using testing::NiceMock;
using testing::Return;


TEST(DmesgParserTest, NoErrors)
{
    IPartitionsManagerMock pm;

    DmesgParser dp(pm);

    const auto errors = dp.parse(
    R"(
        [ 1444.081302] usb 2-1: new high-speed USB device number 8 using xhci_hcd
        [ 1444.266866] usb 2-1: New USB device found, idVendor=2717, idProduct=ff40, bcdDevice= 3.18
        [ 1444.266867] usb 2-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
        [ 1444.266868] usb 2-1: Product: Android
        [ 1444.266869] usb 2-1: Manufacturer: Android
        [ 1444.266869] usb 2-1: SerialNumber: 42bfcc2e7d64
        [ 1446.026294] ata4: SATA link up 6.0 Gbps (SStatus 133 SControl 300)
        [ 1446.066268] ata2: SATA link up 6.0 Gbps (SStatus 133 SControl 300)
        [ 1446.158564] ata4.00: configured for UDMA/133
        [ 1446.161245] ata2.00: configured for UDMA/133
    )"
    );

    EXPECT_TRUE(errors.empty());
}


TEST(DmesgParserTest, BufferIOError)
{
    NiceMock<IPartitionsManagerMock> pm;
    ON_CALL(pm, isPartition(QString("sdb1"))).WillByDefault(Return(true));
    ON_CALL(pm, diskForPartition(QString("sdb1"))).WillByDefault(Return("sdb"));

    DmesgParser dp(pm);

    const auto errors = dp.parse(
    R"(
        [19737.431050] Buffer I/O error on device sdb1, logical block 6160400
        [19737.431060] Buffer I/O error on device sdb1, logical block 6160401
        [19737.431067] Buffer I/O error on device sdb1, logical block 6160402
        [19737.431075] Buffer I/O error on device sdb1, logical block 6160403
        [19737.431082] Buffer I/O error on device sdb1, logical block 6160404
        [19737.431088] Buffer I/O error on device sdb1, logical block 6160405
        [19737.431096] Buffer I/O error on device sdb1, logical block 6160406
        [19737.431102] Buffer I/O error on device sdb1, logical block 6160407
        [19737.431114] Buffer I/O error on device sdb1, logical block 6160408
        [19737.431121] Buffer I/O error on device sdb1, logical block 6160409
    )"
    );

    const Disk failedDisk("sdb");

    ASSERT_EQ(errors.size(), 1);
    ASSERT_NE(errors.find(failedDisk), errors.end());
}
