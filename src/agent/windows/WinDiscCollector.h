#pragma once
#include "../IDiscCollector.h"

class WinDiscCollector : public IDiscCollector
{
public:
    std::vector<Disk> GetDiscsList();
};