#pragma once

#include <gmock/gmock.h>
#include "Disk.h"

class DiskMock : public Disk
{
public:
    DiskMock()
    {
        m_deviceId = "mock_deviceId";
    }
};
