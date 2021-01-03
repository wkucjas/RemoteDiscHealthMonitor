#pragma once

#include <gmock/gmock.h>
#include "Disk.h"

class DiskMock : public Disk
{
public:
    DiskMock()
    {
        m_caption = "mock_caption";
        m_deviceId = "mock_deviceId";
        m_model = "mock_model";
        m_partitions = 2;
        m_size = 500000000;
    }
};