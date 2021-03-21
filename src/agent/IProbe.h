#pragma once
#include <iostream>
#include <variant>
#include "common/GeneralHealth.h"
#include "agent/Disk.h"
#include "common/SmartData.h"

class IProbe
{
public:
    using RawData = std::variant<std::string, SmartData>;
    
    virtual ~IProbe() = default;
    virtual GeneralHealth::Health GetStatus(const Disk& _disk) = 0;
    virtual RawData GetRawData(const Disk& _disk) = 0;
};