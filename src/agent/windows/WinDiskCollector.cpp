#include "WinDiskCollector.h"
#include "WMICommunication.h"

std::vector<Disk> WinDiskCollector::GetDisksList()
{
    WMICommunication wmi;
    wmi.WMIInit(WMICommunication::WmiNamespace::Discs);
    wmi.CollectInfoAboutDiscsViaWMI();
    return wmi.GetDisksCollection();
}
