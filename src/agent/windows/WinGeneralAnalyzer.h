#pragma once
#include "../IProbe.h"

class WinGeneralAnalyzer : public IProbe
{
public:
    Health GetStatus();
    std::string GetRawData();
};
