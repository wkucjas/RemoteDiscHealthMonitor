#pragma once

#include <vector>
#include <string>
#include "Disc.h"

class IDiscCollector
{
public:

    virtual ~IDiscCollector() = default;
    virtual std::vector<Disc> GetDiscsList() = 0;
};
