#pragma once

#include <memory>
#include <vector>
#include <Wbemidl.h>


class WMICommunication
{
public:
	~WMICommunication();


	bool WMIInit();

	bool GetSMARTDataViaWMI();

	std::shared_ptr<IWbemLocator> initialLocatorToWMI;
	IWbemServices* services;
	IEnumWbemClassObject* pEnumerator;
	
private:
	std::vector<unsigned char> dataVector;	// In future here will be SMARTDATA structure
	void FeedSmartDataStructure(BYTE* data, LONG& dataSize);
	
	
};