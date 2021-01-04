#pragma once

#include <string>

class Disk
{
public:
    Disk() = default;
    Disk(const std::string& _deviceId);

    const std::string& deviceId() const;

protected:
    std::string m_deviceId;
};
