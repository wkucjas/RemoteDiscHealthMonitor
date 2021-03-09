#include "Disk.h"

Disk::Disk(const std::string& _deviceId)
    : m_deviceId(_deviceId)
{
}

const std::string& Disk::GetDeviceId() const
{
    return m_deviceId;
}

