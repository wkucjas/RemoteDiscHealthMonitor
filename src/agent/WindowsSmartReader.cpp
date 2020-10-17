#include "WindowsSmartReader.h"

std::string WindowsSmartReader::ReadSMARTData()
{
	WMICommunication test;
	bool a = test.WMIInit();
	test.GetSMARTDataViaWMI();
	return std::string("Windows S.M.A.R.T. DATA");
}
