#pragma once

#include <gmock/gmock.h>
#include "Disk.h"

class DiskMock : public Disk
{
public:
    DiskMock()
    {
        caption = "mock_caption";
        deviceId = "mock_deviceId";
        model = "mock_model";
        partitions = 2;
        size = 500000000;
    }
};