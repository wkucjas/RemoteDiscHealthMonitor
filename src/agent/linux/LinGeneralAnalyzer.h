#pragma once

#include "../IProbe.h"

class LinGeneralAnalyzer : public IProbe
{
public:
    GeneralHealth::Health GetStatus();
    std::string GetRawData();
};