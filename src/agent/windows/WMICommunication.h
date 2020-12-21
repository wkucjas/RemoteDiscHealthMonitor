#pragma once

#include <vector>
#include <memory>
#include <Wbemidl.h>
#include "common/SmartData.h"
#include "../Disc.h"



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
	const std::vector<Disc> GetDiscsCollection() const;

private:
	IWbemLocator* m_initialLocatorToWMI;
	IWbemServices* m_services;
	IEnumWbemClassObject* m_pEnumerator;
	SmartData m_smartData;
	std::vector<Disc> m_discsCollection;

	void FeedSmartDataStructure(const std::vector<BYTE>& _data, const LONG& _dataSize);
	std::string StringFromVariant(VARIANT& vt);
	
	
};
