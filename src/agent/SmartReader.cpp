#include "SmartReader.h"
#include "WindowsSmartReader.h"

SmartReader::SmartReader()
{
}

std::unique_ptr<SmartReader> SmartReader::GetProperSMARTReader()
{
#ifdef _WIN32
	std::unique_ptr<SmartReader> ptr(new WindowsSmartReader());
#else
	std::unique_ptr<SmartReader> ptr();
#endif
	return ptr;
}

std::string SmartReader::ReadSMARTData()
{
	return std::string();
}
;
