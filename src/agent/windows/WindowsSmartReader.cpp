#include "../SmartReader.h"
#include "WMICommunication.h"
#include "CMDCommunication.h"
#include <iostream>


SmartData SmartReader::ReadSMARTData(const Disk& _disk)
{
	WMICommunication wmi;
	wmi.WMIInit();
	wmi.CollectSMARTDataViaWMI(_disk);
	SmartData dane = wmi.GetSMARTData();

	for (const auto d : dane.smartData)
	{
		std::cout << d.first << " " << d.second.value << std::endl;
	}
	//return std::string("Windows S.M.A.R.T. DATA");
	return dane;
}

GeneralHealth SmartReader::ReadDisksStatus(const Disk& _disk)
{
	CMDCommunication reader;
	return reader.CollectDiskStatus(_disk);
}
