#include "../SmartReader.h"
#include "WMICommunication.h"
#include "CMDCommunication.h"
#include <iostream>


std::string SmartReader::ReadSMARTData()
{
	WMICommunication wmi;
	wmi.CollectSMARTDataViaWMI();
	SmartData dane = wmi.GetSMARTData();

	for (const auto d : dane.smartData)
	{
		std::cout << d.first << " " << d.second.value << std::endl;
	}
	return std::string("Windows S.M.A.R.T. DATA");
}

GeneralHealth SmartReader::ReadDisksStatus()
{
	CMDCommunication reader;
	return reader.CollectDiskStatus();
}
