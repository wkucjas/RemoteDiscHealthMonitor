#pragma once
#include "../IDiscCollector.h"

class WinDiscCollector : public IDiscCollector
{
    std::vector<Disc> GetDiscsList();
};