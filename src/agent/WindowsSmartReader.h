#pragma once
#include "SmartReader.h"

class WindowsSmartReader : public ISmartReader
{

	std::string ReadSMARTData() override;

};
