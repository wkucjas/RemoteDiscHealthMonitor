
#include "../SystemUtilitiesFactory.h"
#include "LinuxDiskCollector.h"


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<LinuxDiskCollector>();
}

std::unique_ptr<IProbe> SystemUtilitiesFactory::generalAnalyzer()
{
    return nullptr;
}