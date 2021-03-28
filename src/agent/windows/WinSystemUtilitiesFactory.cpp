
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


std::vector<std::unique_ptr<IProbe>> SystemUtilitiesFactory::getProbes()
{
    std::vector<std::unique_ptr<IProbe>> probes;
    probes.emplace_back(std::make_unique<WinGeneralAnalyzer>());
    probes.emplace_back(std::make_unique<WinSmartAnalyzer>());

    return probes;
}

