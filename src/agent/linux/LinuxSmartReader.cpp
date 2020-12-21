
#include "../SmartReader.h"


std::string SmartReader::ReadSMARTData(const Disc &)
{
	return std::string("Linux S.M.A.R.T. DATA");
}


GeneralHealth SmartReader::ReadDisksStatus(const Disc &)
{
    return GeneralHealth::GOOD;
}
