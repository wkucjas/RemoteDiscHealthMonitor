
#pragma once

#include <QSettings>

#include "AgentInformation.hpp"


class Configuration final
{
    public:
        Configuration();
        ~Configuration();

        void storeAgents(const QVector<AgentInformation> &);
        QVector<AgentInformation> readAgents();

    private:
        QSettings m_settings;
};
