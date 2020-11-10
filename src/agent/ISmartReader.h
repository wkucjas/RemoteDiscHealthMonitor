#pragma once

#include <string>
#include "common/GeneralHealth.h"

class ISmartReader
{
public:
	virtual ~ISmartReader() = default;
	virtual std::string ReadSMARTData() = 0;
	virtual GeneralHealth ReadDisksStatus() = 0;
};
