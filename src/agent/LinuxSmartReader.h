#pragma once

#include "SmartReader.h"

class LinuxSmartReader : public ISmartReader
{

	std::string ReadSMARTData() override;

};