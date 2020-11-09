#include "CMDCommunication.h"
#include <fstream>
#include <iostream>
#include <QProcess>

GeneralHealth CMDCommunication::CollectDiskStatus()
{
    const std::string commandResult = ExecuteDiscStatusCommand();

    m_generalHealth.SetStatus(GeneralHealth::Health::UNKNOWN);

    if (commandResult == "OK")
    {
        m_generalHealth.SetStatus(GeneralHealth::Health::GOOD);
    }
    else if (commandResult == "Degraded")
    {
        m_generalHealth.SetStatus(GeneralHealth::Health::CHECK_STATUS);
    }
    else if (commandResult == "Pred Fail")
    {
        m_generalHealth.SetStatus(GeneralHealth::Health::BAD);
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
    std::string::iterator retEnd = ret.end();
    for (auto i = ret.begin(); i < retEnd; ++i)
    {
        if (*i == '\0' || *i == '\n' || *i == '\r' || *i == ' ')
        {
            ret.erase(i);

            if (i > ret.begin())
            {
                --i;
            }
            --retEnd;
        }
    }

    std::string response = (ret.substr(ret.find("Status") + 6));

    return response;
}