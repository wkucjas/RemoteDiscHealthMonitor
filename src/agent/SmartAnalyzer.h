#pragma once
#include "IProbe.h"

class WinSmartAnalyzer : public IProbe
{
    public:
        GeneralHealth::Health GetStatus(const Disk& _disk) override;
        std::string GetRawData(const Disk& _disk) override;
};