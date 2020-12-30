#include "SmartAnalyzer.h"

GeneralHealth::Health WinSmartAnalyzer::GetStatus(const Disk& _disk)
{
    return GeneralHealth::Health();
}

std::string WinSmartAnalyzer::GetRawData(const Disk& _disk)
{
    return std::string();
}