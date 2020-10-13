#pragma once

#include "ISmartReader.h"

class LinuxSmartReader : public ISmartReader
{

	std::string ReadSMARTData() override;

};