#include "WinSmartAnalyzer.h"
#include "../SmartReader.h"

GeneralHealth::Health WinSmartAnalyzer::GetStatus(const Disk& _disk)
{
	return GeneralHealth::Health::UNKNOWN;
}

IProbe::RawData WinSmartAnalyzer::GetRawData(const Disk& _disk)
{
	SmartReader reader;

	return reader.ReadSMARTData(_disk);
}
