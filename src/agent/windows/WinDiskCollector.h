#pragma once
#include "../IDiskCollector.h"

class WinDiskCollector : public IDiskCollector
{
public:
    std::vector<Disk> GetDisksList() override;
};
