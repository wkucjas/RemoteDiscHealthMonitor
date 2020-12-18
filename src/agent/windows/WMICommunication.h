#pragma once

#include <vector>
#include <memory>
#include <Wbemidl.h>
#include "common/SmartData.h"



class WMICommunication
{

public:

	enum WmiNamespace
	{
		Smart, Discs
	};

	~WMICommunication();

	bool WMIInit(const WmiNamespace _namespace = Smart);
	bool CollectSMARTDataViaWMI();
	bool CollectInfoAboutDiscsViaWMI();

	const SmartData& GetSMARTData() const;

private:
	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	SmartData m_smartData;

	void FeedSmartDataStructure(const std::vector<BYTE>& _data, const LONG& _dataSize);
	
};
