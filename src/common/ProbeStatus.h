
#pragma once

#include "IProbe.h"

struct ProbeStatus
{
    GeneralHealth::Health health;
    IProbe::RawData rawData;
};
