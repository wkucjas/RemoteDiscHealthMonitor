
#pragma once
#include <string>

class ISmartReader
{
public:
	virtual ~ISmartReader() = default;
	virtual std::string ReadSMARTData() = 0;
};
