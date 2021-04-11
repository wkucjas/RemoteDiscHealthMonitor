
#pragma once

#include <memory>

#include "IDiskCollector.h"
#include "agent/IProbe.h"


class SystemUtilitiesFactory
{
public:
    SystemUtilitiesFactory();
    ~SystemUtilitiesFactory();

    std::unique_ptr<IDiskCollector> diskCollector();
    std::vector<std::unique_ptr<IProbe>> getProbes();

private:
    struct State;
    std::unique_ptr<State> m_state;
};
