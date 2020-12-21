#pragma once

#include <string>

#include "common/GeneralHealth.h"
#include "agent/Disc.h"


class ISmartReader
{
public:
	virtual ~ISmartReader() = default;
	virtual std::string ReadSMARTData(const Disc &) = 0;
	virtual GeneralHealth ReadDisksStatus(const Disc &) = 0;
};
