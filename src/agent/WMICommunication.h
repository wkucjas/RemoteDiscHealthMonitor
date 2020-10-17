#pragma once

#include <memory>
#include <Wbemidl.h>


class WMICommunication
{
public:
	WMICommunication();
	~WMICommunication();

//private:
	bool WMIInit();

	void GetSMARTDataViaWMI();

	std::shared_ptr<IWbemLocator> initialLocatorToWMI;
	IWbemServices* services;
	IEnumWbemClassObject* pEnumerator;
	
};