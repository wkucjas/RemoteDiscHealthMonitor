#pragma once

#include <vector>
#include <string>
#include "Disk.h"

class IDiscCollector
{
public:

    virtual ~IDiscCollector() = default;
    virtual std::vector<Disk> GetDiscsList() = 0;
};
