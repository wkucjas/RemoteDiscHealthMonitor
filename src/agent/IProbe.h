#pragma once
#include <iostream>
#include "common/Health.h"

class IProbe
{
public:
    
    virtual Health GetStatus() = 0;
    virtual std::string GetRawData() = 0;
};