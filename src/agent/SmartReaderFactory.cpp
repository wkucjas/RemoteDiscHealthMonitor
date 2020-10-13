
#include "SmartReaderFactory.h"

#if defined _WIN32
#include "windows/WindowsSmartReader.h"
#else
#include "linux/LinuxSmartReader.h"
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
