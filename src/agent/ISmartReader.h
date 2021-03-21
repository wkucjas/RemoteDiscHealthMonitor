#pragma once

#include <string>

#include "common/GeneralHealth.h"
#include "agent/Disk.h"
#include "common/DiskInfo.h"


class ISmartReader
{
public:
	virtual ~ISmartReader() = default;
	virtual SmartData ReadSMARTData(const Disk & _disk) = 0;
	virtual GeneralHealth ReadDisksStatus(const Disk & _disk) = 0;
};
