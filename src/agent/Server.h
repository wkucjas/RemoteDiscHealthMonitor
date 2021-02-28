
#pragma once

#include <QRemoteObjectHost>

#include "common/GeneralHealth.h"
#include "common/constants.hpp"
#include "rep_AgentStatus_source.h"
#include "common/DiskInfo.h"
#include "common/DiskInfoSerialize.h"


class Server : public AgentStatusSource
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr);
    bool Init();

    const QString& ip() const;
    quint16 port() const;

    void setOverallStatus(GeneralHealth::Health overallStatus) override;
    void setDiskInfoCollection(DiskInfo diskInfoCollection) override;
    void addDiskInfo(DiskInfo& diskInfo) /*override*/;
    GeneralHealth::Health overallStatus() const override;
    DiskInfo diskInfoCollection() const override;
    void refresh() override;

private:
    void CollectInfoAboutDiscs();

    GeneralHealth::Health m_health;
    //std::vector<DiskInfo> m_diskInfoCollection;
    DiskInfo m_diskInfoCollection;

    QRemoteObjectHost m_ROHost;
    QString m_ip;
};