#pragma once

#include <vector>

#include "IProbe.h"
#include "../common/Health.h"


class DiscStatusCalculator
{
public:
    DiscStatusCalculator(std::vector<IProbe>);

    Health GetStatus();
};