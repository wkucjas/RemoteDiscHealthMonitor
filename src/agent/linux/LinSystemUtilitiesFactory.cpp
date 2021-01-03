
#include "../SystemUtilitiesFactory.h"


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return nullptr;
}

std::unique_ptr<IProbe> SystemUtilitiesFactory::generalAnalyzer()
{
    return nullptr;
}