
#include "../SystemUtilitiesFactory.h"
#include "WinDiscCollector.h"


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<WinDiskCollector>();
}
