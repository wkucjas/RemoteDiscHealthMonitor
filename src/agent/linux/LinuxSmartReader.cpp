
#include "../SmartReader.h"


std::string SmartReader::ReadSMARTData()
{
	return std::string("Linux S.M.A.R.T. DATA");
}


GeneralHealth SmartReader::ReadDisksStatus()
{
    return Health::UNKNOWN;
}
