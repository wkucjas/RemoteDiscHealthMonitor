
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
    std::unique_ptr<IProbe> generalAnalyzer();
    std::unique_ptr<IProbe> smartAnalyzer();

private:
    struct State;
    std::unique_ptr<State> m_state;
};
