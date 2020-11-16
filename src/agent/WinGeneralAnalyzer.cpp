#include "WinGeneralAnalyzer.h"
#include "windows/CMDCommunication.h"


WinGeneralAnalyzer::HealthStatus WinGeneralAnalyzer::GetStatus()
{
    CMDCommunication reader;

    GeneralHealth res = reader.CollectDiskStatus();

    return static_cast<HealthStatus>(res.GetStatus());
}

std::string WinGeneralAnalyzer::GetRawData()
{
    return std::string();
}
