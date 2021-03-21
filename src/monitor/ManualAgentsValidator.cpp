
#include "ManualAgentsValidator.hpp"


void ManualAgentsValidator::addNewAgent(const QString& name, const QString& ip, const QString& port)
{
    const auto segments = ip.split('.');
    const bool ipValid = std::all_of(segments.begin(), segments.end(), [](const QString& segment) {
        const int number = segment.toInt();
        return number >= 0 && number <= 255;
    });

    const int portNum = port.toInt();

    if (ipValid && portNum >= 0 && portNum <= 65535)
    {
        const AgentInformation info(name, QHostAddress(ip), portNum, AgentInformation::DetectionSource::Hardcoded);

        emit agentDiscovered(info);
    }
}
