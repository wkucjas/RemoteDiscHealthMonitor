#pragma once

#include <memory>
#include <vector>
#include <Wbemidl.h>


class WMICommunication
{
public:
	WMICommunication();
	~WMICommunication();

//private:
	bool WMIInit();

	bool GetSMARTDataViaWMI();

	std::shared_ptr<IWbemLocator> initialLocatorToWMI;
	IWbemServices* services;
	IEnumWbemClassObject* pEnumerator;

	std::vector<unsigned char> dataVector;
	void FeedSmartDataStructure(BYTE* data, int dataSize);
	
	
};