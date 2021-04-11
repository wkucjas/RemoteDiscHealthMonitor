#pragma once
#include "../IProbe.h"

class LinSmartAnalyzer : public IProbe
{
public:
    GeneralHealth::Health GetStatus(const Disk& _disk) override
    {
        return GeneralHealth::Health();
    };
    RawData GetRawData(const Disk& _disk) override
    {
        return SmartData();
    };
};