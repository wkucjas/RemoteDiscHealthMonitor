#include "../SmartReader.h"
#include "WMICommunication.h"
#include <iostream>


std::string SmartReader::ReadSMARTData()
{
	WMICommunication test;
	test.WMIInit();
	test.CollectSMARTDataViaWMI();
	SmartData dane = test.GetSMARTData();

	for (const auto d : dane.smartData)
	{
		std::cout << d.first << " " << d.second.value << std::endl;
	}
	return std::string("Windows S.M.A.R.T. DATA");
}
