#pragma once
#include "ISmartReader.h"

class SmartReader : public ISmartReader
{
	std::string ReadSMARTData() override;
};
