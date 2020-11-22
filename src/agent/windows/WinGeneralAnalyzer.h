#pragma once
#include "../IProbe.h"

class WinGeneralAnalyzer : public IProbe
{
public:
    GeneralHealth::Health GetStatus();
    std::string GetRawData();
};
