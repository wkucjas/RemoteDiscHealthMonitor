#include "WinGeneralAnalyzer.h"
#include "CMDCommunication.h"


WinGeneralAnalyzer::HealthStatus WinGeneralAnalyzer::GetStatus()
{
    CMDCommunication reader;

    GeneralHealth res = reader.CollectDiskStatus();

    return static_cast<HealthStatus>(res.GetStatus());
}

WinGeneralAnalyzer::RawDataCollection WinGeneralAnalyzer::GetRawData()
{
    return RawDataCollection();
}
