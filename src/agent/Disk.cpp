#include "Disk.h"

Disk::Disk(const std::string& _deviceId)
    : m_deviceId(_deviceId)
{
}

const std::string& Disk::deviceId() const
{
    return m_deviceId;
}

