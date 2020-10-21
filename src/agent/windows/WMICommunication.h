#pragma once

#include <vector>
#include <Wbemidl.h>


class WMICommunication
{

public:
	~WMICommunication();

	bool WMIInit();
	bool GetSMARTDataViaWMI();

private:

	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	std::vector<unsigned char> m_dataVector;	// In future here will be SMARTDATA structure
	void FeedSmartDataStructure(std::vector<BYTE>& data, const LONG& dataSize);
		
};
