
#pragma once

#include <memory>

#include "IDiscCollector.h"


class SystemUtilitiesFactory
{
public:
    SystemUtilitiesFactory();

    std::unique_ptr<IDiscCollector> diskCollector();
};
