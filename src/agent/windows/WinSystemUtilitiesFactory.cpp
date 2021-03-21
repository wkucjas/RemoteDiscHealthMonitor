
#include "../SystemUtilitiesFactory.h"
#include "WinDiskCollector.h"
#include "agent/IProbe.h"
#include "WinGeneralAnalyzer.h"
#include "WinSmartAnalyzer.h"


struct SystemUtilitiesFactory::State {};

SystemUtilitiesFactory::SystemUtilitiesFactory()
    : m_state(nullptr)
{

}

SystemUtilitiesFactory::~SystemUtilitiesFactory()
{

}


std::unique_ptr<IDiskCollector> SystemUtilitiesFactory::diskCollector()
{
    return std::make_unique<WinDiskCollector>();
}

std::unique_ptr<IProbe> SystemUtilitiesFactory::generalAnalyzer()
{
    return std::make_unique<WinGeneralAnalyzer>();
}

std::unique_ptr<IProbe> SystemUtilitiesFactory::smartAnalyzer()
{
    return std::make_unique<WinSmartAnalyzer>();
}
