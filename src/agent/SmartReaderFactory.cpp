#include "SmartReaderFactory.h"
#include "WindowsSmartReader.h"

std::unique_ptr<SmartReader> SmartReaderFactory::GetSMARTReader()
{
#if defined _WIN32

	std::unique_ptr<SmartReader> ptr(new WindowsSmartReader());
	return ptr;

#else

	std::unique_ptr<SmartReader> ptr(new LinuxSmartReader());
	return ptr;

#endif
}
