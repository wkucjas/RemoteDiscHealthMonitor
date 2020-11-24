#include "CMDCommunication.h"
#include <fstream>
#include <iostream>
#include <QProcess>

GeneralHealth CMDCommunication::CollectDiskStatus()
{
    const std::string commandResult = ExecuteDiscStatusCommand();

    m_generalHealth.SetStatus(GeneralHealth::UNKNOWN);

    if (commandResult == "StatusOK")
    {
        m_generalHealth.SetStatus(GeneralHealth::GOOD);
    }
    else if (commandResult == "StatusDegraded")
    {
        m_generalHealth.SetStatus(GeneralHealth::CHECK_STATUS);
    }
    else if (commandResult == "StatusPredFail")
    {
        m_generalHealth.SetStatus(GeneralHealth::BAD);
    }

    return m_generalHealth;
}

std::string CMDCommunication::ExecuteDiscStatusCommand() const
{
    QProcess proc;
    proc.start("wmic diskdrive get status");
    proc.waitForFinished();
    QString output = proc.readAllStandardOutput();

    std::string ret = output.toStdString();
    
    ret.erase(std::remove_if(ret.begin(), 
        ret.end(),
        [](unsigned char x){ return std::isspace(x);}),
        ret.end());

    return ret;
}