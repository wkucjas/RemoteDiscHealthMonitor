#include "CMDCommunication.h"
#include <fstream>
#include <iostream>

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
    std::string command = "wmic diskdrive get status";
    std::string fileName = "dh.txt";
    system((command + " > " + fileName).c_str());

    std::ifstream ifs(fileName);
    std::string ret((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    ifs.close();
    if (std::remove(fileName.c_str()) != 0) {
        std::cout << "Error deleting temporary file" << std::endl;
    }

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