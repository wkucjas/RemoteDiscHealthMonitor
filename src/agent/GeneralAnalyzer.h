#pragma once
#include "IProbe.h"

class GeneralAnalyzer : public IProbe
{
public:
    HealthStatus GetStatus();
    std::string GetRawData();
};
