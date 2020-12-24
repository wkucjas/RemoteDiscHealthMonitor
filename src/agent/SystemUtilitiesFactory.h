
#pragma once

#include <memory>

#include "IDiscCollector.h"


class SystemUtilitiesFactory
{
public:
    SystemUtilitiesFactory() = default;

    std::unique_ptr<IDiscCollector> diskCollector();
};
