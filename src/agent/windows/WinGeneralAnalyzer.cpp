#include "WinGeneralAnalyzer.h"
#include "CMDCommunication.h"


Health WinGeneralAnalyzer::GetStatus()
{
    CMDCommunication reader;

    GeneralHealth res = reader.CollectDiskStatus();

    return static_cast<Health>(res.GetStatus());
}

std::string WinGeneralAnalyzer::GetRawData()
{
    return std::string();
}
