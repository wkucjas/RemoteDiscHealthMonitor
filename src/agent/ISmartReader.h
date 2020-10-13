#pragma once
#include <memory>
#include <string>

class ISmartReader
{
public:

	virtual std::string ReadSMARTData() = 0;

};
