#pragma once
#include "ISmartReader.h"

class SmartReader : public ISmartReader
{
public:
	std::string ReadSMARTData(const Disc &) override;
	GeneralHealth ReadDisksStatus(const Disc &) override;
};
