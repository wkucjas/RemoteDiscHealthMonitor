
#pragma once

#include <QStringList>

#include "../IProbe.h"

class LinGeneralAnalyzer : public IProbe
{
public:
    LinGeneralAnalyzer();

    GeneralHealth::Health GetStatus(const Disk& disk) override;
    std::string GetRawData(const Disk& disk) override;

private:
    QStringList m_errorLines;

    void refreshState();
};
