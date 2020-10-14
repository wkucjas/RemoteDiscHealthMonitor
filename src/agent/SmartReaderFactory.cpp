
#include "SmartReaderFactory.h"
#include "SmartReader.h"


std::unique_ptr<ISmartReader> SmartReaderFactory::GetSMARTReader()
{
	std::unique_ptr<ISmartReader> ptr = std::make_unique<SmartReader>();
	return ptr;
}
