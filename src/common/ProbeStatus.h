
#pragma once

#include "agent/IProbe.h"


struct ProbeStatus
{
    GeneralHealth::Health health;
    IProbe::RawData rawData;
};
