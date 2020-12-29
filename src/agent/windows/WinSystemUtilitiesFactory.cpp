
#include "../SystemUtilitiesFactory.h"
#include "WinDiskCollector.h"


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<WinDiskCollector>();
}
