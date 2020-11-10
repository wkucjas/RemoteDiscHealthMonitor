#pragma once
#include "ISmartReader.h"

class SmartReader : public ISmartReader
{
public:
	std::string ReadSMARTData() override;
	GeneralHealth ReadDisksStatus() override;
};
