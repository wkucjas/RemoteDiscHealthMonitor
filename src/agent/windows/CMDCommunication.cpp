#include "CMDCommunication.h"
#include <fstream>
#include <iostream>
#include <QProcess>

GeneralHealth CMDCommunication::CollectDiskStatus(const Disk& _disk)
{
    const std::string commandResult = ExecuteDiscStatusCommand(_disk);

    m_generalHealth.SetStatus(GeneralHealth::UNKNOWN);

    if (commandResult == "OK")
    {
        m_generalHealth.SetStatus(GeneralHealth::GOOD);
    }
    else if (commandResult == "Degraded")
    {
        m_generalHealth.SetStatus(GeneralHealth::CHECK_STATUS);
    }
    else if (commandResult == "PredFail")
    {
        m_generalHealth.SetStatus(GeneralHealth::BAD);
    }

    return m_generalHealth;
}

std::string CMDCommunication::ExecuteDiscStatusCommand(const Disk& _disk) const
{
    QProcess proc;
    proc.start("wmic diskdrive get deviceid,status");
    proc.waitForFinished();
    QString output = proc.readAllStandardOutput();

    std::string ret = output.toStdString();
    
    auto diskPos = ret.find(_disk.deviceId());
    auto statusPosStart = ret.find_first_not_of(' ', diskPos + (_disk.deviceId()).size());
    auto statusPosStop = ret.find_first_of(' ', statusPosStart);
    ret = ret.substr(statusPosStart, statusPosStop - statusPosStart);
    return ret;
}