#pragma once

#include <memory>
#include <Wbemidl.h>


class WMICommunication
{
public:
	WMICommunication();

//private:
	bool WMIInit();

	std::shared_ptr<IWbemLocator> initialLocatorToWMI;
	IWbemServices* services;
	
};