#pragma once
#include "ISmartReader.h"

class WindowsSmartReader : public ISmartReader
{

	std::string ReadSMARTData() override;

};
