#pragma once
#include "../IDiscCollector.h"

class WinDiskCollector : public IDiskCollector
{
public:
    std::vector<Disk> GetDisksList();
};
