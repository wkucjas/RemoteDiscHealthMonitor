#include "WinGeneralAnalyzer.h"
#include "CMDCommunication.h"


GeneralHealth::Health WinGeneralAnalyzer::GetStatus()
{
    CMDCommunication reader;

    GeneralHealth res = reader.CollectDiskStatus();

    return static_cast<GeneralHealth::Health>(res.GetStatus());
}

std::string WinGeneralAnalyzer::GetRawData()
{
    return std::string();
}
