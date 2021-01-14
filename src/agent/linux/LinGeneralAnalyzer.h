
#pragma once

#include <set>
#include <QStringList>

#include "../IProbe.h"


class IPartitionsManager;

class LinGeneralAnalyzer : public IProbe
{
public:
    LinGeneralAnalyzer(const IPartitionsManager &);

    GeneralHealth::Health GetStatus(const Disk& disk) override;
    std::string GetRawData(const Disk& disk) override;

private:
    std::map<Disk, std::set<QString>> m_errors;
    const IPartitionsManager& m_partitionsManager;

    void refreshState();
};
