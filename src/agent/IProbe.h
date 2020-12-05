#pragma once
#include <iostream>
#include "common/GeneralHealth.h"

class IProbe
{
public:
    
    virtual ~IProbe() = default;
    virtual GeneralHealth::Health GetStatus() = 0;
    virtual std::string GetRawData() = 0;
};