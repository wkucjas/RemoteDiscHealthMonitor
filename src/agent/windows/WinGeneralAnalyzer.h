#pragma once
#include "../IProbe.h"

class WinGeneralAnalyzer : public IProbe
{
public:
    HealthStatus GetStatus();
    RawDataCollection GetRawData();
};
