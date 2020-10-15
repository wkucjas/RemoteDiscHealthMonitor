
#include "HealthChecker.h"
#include "ISmartReader.h"

HealthChecker::HealthChecker(ISmartReader& reader)
    : m_smartReader(reader)
{

}


std::string HealthChecker::CheckDiscHealth()
{
	return m_smartReader.ReadSMARTData();
}
