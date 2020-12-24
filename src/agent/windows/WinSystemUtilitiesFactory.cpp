
#include "../SystemUtilitiesFactory.h"
#include "WinDiscCollector.h"


std::unique_ptr<IDiscCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<WinDiscCollector>();
}
