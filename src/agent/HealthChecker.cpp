#include "HealthChecker.h"
#include "SmartReaderFactory.h"
#include <iostream>

std::string HealthChecker::CheckDiscHealth()
{
	SmartReaderFactory readerFactory;

	std::unique_ptr<SmartReader> discSMARTReader = readerFactory.GetSMARTReader();
	
	return discSMARTReader->ReadSMARTData();
}
