
#include "HealthChecker.h"
#include "SmartReaderFactory.h"


std::string HealthChecker::CheckDiscHealth()
{
	SmartReaderFactory readerFactory;

	std::unique_ptr<ISmartReader> discSMARTReader = readerFactory.GetSMARTReader();

	return discSMARTReader->ReadSMARTData();
}
