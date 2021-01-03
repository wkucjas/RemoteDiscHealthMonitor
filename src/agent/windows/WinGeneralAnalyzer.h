#pragma once
#include "../IProbe.h"

class WinGeneralAnalyzer : public IProbe
{
public:
    GeneralHealth::Health GetStatus(const Disk& _disk) override;
    std::string GetRawData(const Disk& _disk) override;
};
