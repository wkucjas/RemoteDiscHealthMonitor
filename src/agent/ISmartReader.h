#pragma once

#include <string>

#include "common/GeneralHealth.h"
#include "agent/Disk.h"


class ISmartReader
{
public:
	virtual ~ISmartReader() = default;
	virtual std::string ReadSMARTData(const Disk &) = 0;
	virtual GeneralHealth ReadDisksStatus(const Disk &) = 0;
};
