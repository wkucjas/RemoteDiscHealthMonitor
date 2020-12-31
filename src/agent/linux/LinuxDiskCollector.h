
#pragma once

#include "../IDiskCollector.h"


class LinuxDiskCollector: public IDiskCollector
{
public:
    std::vector<Disk> GetDisksList() override;
};
