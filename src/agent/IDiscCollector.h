#pragma once

#include <vector>
#include <string>
#include "Disk.h"

class IDiskCollector
{
public:

    virtual ~IDiskCollector() = default;
    virtual std::vector<Disk> GetDisksList() = 0;
};
