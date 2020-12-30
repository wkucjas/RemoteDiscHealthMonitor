
#include "../SystemUtilitiesFactory.h"


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return nullptr;
}

std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::generalAnalyzer()
{
    return nullptr;
}