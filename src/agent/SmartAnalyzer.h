#pragma once
#include "IProbe.h"

class WinSmartAnalyzer : public IProbe
{
    public:
        GeneralHealth::Health GetStatus();
        std::string GetRawData();
};