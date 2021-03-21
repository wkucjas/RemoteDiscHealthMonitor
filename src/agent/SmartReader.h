#pragma once
#include "ISmartReader.h"

class SmartReader : public ISmartReader
{
public:
	SmartData ReadSMARTData(const Disk & _disk) override;
	GeneralHealth ReadDisksStatus(const Disk & _disk) override;
};
