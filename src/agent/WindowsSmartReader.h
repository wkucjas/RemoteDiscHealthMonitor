#pragma once
#include "SmartReader.h"

class WindowsSmartReader : public SmartReader
{

	std::string ReadSMARTData() override;

};
