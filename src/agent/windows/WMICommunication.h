#pragma once

#include <vector>
#include <Wbemidl.h>


class WMICommunication
{
public:
	~WMICommunication();

	bool WMIInit();
	bool GetSMARTDataViaWMI();

	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	
private:
	std::vector<unsigned char> dataVector;	// In future here will be SMARTDATA structure
	void FeedSmartDataStructure(std::vector<BYTE>& data, const LONG& dataSize);
		
};
