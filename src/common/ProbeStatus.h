
#pragma once

#include "agent/IProbe.h"


struct ProbeStatus
{
    GeneralHealth::Health health;
    IProbe::RawData rawData;

    auto operator<=>(const ProbeStatus &) const = default;
};
