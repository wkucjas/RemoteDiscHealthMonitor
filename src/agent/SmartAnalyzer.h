#pragma once
#include "IProbe.h"

class WinSmartAnalyzer : public IProbe
{
    public:
        Health GetStatus();
        std::string GetRawData();
};