#pragma once
#include "../IProbe.h"

class WinSmartAnalyzer : public IProbe
{
    public:
        HealthStatus GetStatus();
        RawDataCollection GetRawData();
};