#include "WinSmartAnalyzer.h"

GeneralHealth::Health WinSmartAnalyzer::GetStatus(const Disk& _disk)
{
	return GeneralHealth::Health::UNKNOWN;
}

std::string WinSmartAnalyzer::GetRawData(const Disk& _disk)
{
	return std::string();
}
