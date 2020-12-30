#include "WinGeneralAnalyzer.h"
#include "CMDCommunication.h"


GeneralHealth::Health WinGeneralAnalyzer::GetStatus(const Disk& _disk)
{
    CMDCommunication reader;

    GeneralHealth res = reader.CollectDiskStatus();

    return static_cast<GeneralHealth::Health>(res.GetStatus());
}

std::string WinGeneralAnalyzer::GetRawData(const Disk& _disk)
{
    return std::string();
}
