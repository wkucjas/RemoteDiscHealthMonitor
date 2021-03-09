
#pragma once

#include <memory>
#include <set>
#include <QStringList>

#include "../IProbe.h"


class IPartitionsManager;

class LinGeneralAnalyzer : public IProbe
{
public:
    LinGeneralAnalyzer(std::shared_ptr<IPartitionsManager>);

    GeneralHealth::Health GetStatus(const Disk& disk) override;
    RawData GetRawData(const Disk& disk) override;

private:
    std::map<Disk, std::set<QString>> m_errors;
    std::shared_ptr<IPartitionsManager> m_partitionsManager;

    void refreshState();
};
