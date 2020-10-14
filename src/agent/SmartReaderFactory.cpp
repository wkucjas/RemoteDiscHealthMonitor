
#include "SmartReaderFactory.h"

#if defined _WIN32
#include "WindowsSmartReader.h"
#else
#include "LinuxSmartReader.h"
#endif


std::unique_ptr<ISmartReader> SmartReaderFactory::GetSMARTReader()
{
#if defined _WIN32

	std::unique_ptr<ISmartReader> ptr(new WindowsSmartReader());
	return ptr;

#else

	std::unique_ptr<ISmartReader> ptr(new LinuxSmartReader());
	return ptr;
#endif
}
