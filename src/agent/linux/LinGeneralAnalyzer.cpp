#include "LinGeneralAnalyzer.h"
#include "../../common/GeneralHealth.h"


GeneralHealth::Health LinGeneralAnalyzer::GetStatus()
{
    return GeneralHealth::Health::GOOD;
}

std::string LinGeneralAnalyzer::GetRawData()
{
    return std::string();
}