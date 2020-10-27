#pragma once

#include <vector>
#include <memory>
#include <Wbemidl.h>
#include "../../common/SmartData.h"


class WMICommunication
{

public:
	WMICommunication();
	~WMICommunication();

	bool WMIInit();
	bool CollectSMARTDataViaWMI();

	std::shared_ptr<SmartData> GetSMARTData();

private:

	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	std::shared_ptr<SmartData> m_smartData;
	void FeedSmartDataStructure(const std::vector<BYTE>& data, const LONG& dataSize);
		
};
