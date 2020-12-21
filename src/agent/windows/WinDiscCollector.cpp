#include "WinDiscCollector.h"
#include "WMICommunication.h"

std::vector<Disk> WinDiscCollector::GetDiscsList()
{
    WMICommunication wmi;
    wmi.WMIInit(WMICommunication::WmiNamespace::Discs);
    wmi.CollectInfoAboutDiscsViaWMI();
    return std::vector<Disk>();
}
