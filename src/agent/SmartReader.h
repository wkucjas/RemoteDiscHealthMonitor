#pragma once
#include "ISmartReader.h"

class SmartReader : public ISmartReader
{
public:
	std::string ReadSMARTData(const Disk &) override;
	GeneralHealth ReadDisksStatus(const Disk &) override;
};
