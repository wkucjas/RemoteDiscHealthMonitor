#include "WinDiscCollector.h"
#include "WMICommunication.h"

std::vector<Disc> WinDiscCollector::GetDiscsList()
{
    WMICommunication wmi;
    wmi.WMIInit(WMICommunication::WmiNamespace::Discs);
    wmi.CollectInfoAboutDiscsViaWMI();
    return std::vector<Disc>();
}
