#include "HealthChecker.h"
#include "SmartReader.h"
#include <iostream>

std::string HealthChecker::CheckDiscHealth()
{
	using readerPointer = std::unique_ptr<SmartReader>;

	SmartReader smartReader;

	readerPointer reader = smartReader.GetProperSMARTReader();

	return reader->ReadSMARTData();

}
