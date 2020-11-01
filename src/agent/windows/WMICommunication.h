#pragma once

#include <vector>
#include <memory>
#include <Wbemidl.h>
#include "common/SmartData.h"
#include "common/GeneralHealth.h"


class WMICommunication
{

public:
	~WMICommunication();

	bool WMIInit();
	bool CollectSMARTDataViaWMI();
	const GeneralHealth CollectDiskStatus() const;

	const SmartData& GetSMARTData() const;

private:

	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	SmartData m_smartData;
	GeneralHealth m_generalHealth;
	void FeedSmartDataStructure(const std::vector<BYTE>& _data, const LONG& _dataSize);
	std::string ExecuteCommand(const std::string& _command) const;
		
};
