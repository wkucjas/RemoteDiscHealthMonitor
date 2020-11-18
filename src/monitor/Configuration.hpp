
#pragma once

#include <QSettings>

#include "AgentInformation.hpp"


class Configuration final
{
    public:
        Configuration();
        ~Configuration();

        void storeAgents(const QVector<AgentInformation> &);

    private:
        QSettings m_settings;
};
