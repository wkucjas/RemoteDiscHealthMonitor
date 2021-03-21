#pragma once

#include <string>

class Disk
{
public:
    Disk() = default;
    Disk(const std::string& _deviceId);

    const std::string& GetDeviceId() const;

    friend bool operator<(const Disk& lhs, const Disk& rhs)
    {
        return lhs.m_deviceId < rhs.m_deviceId;
    }

protected:
    std::string m_deviceId;
};
