
#pragma once

#include <QObject>
#include <QString>

class AgentInformation
{
    Q_GADGET

public:
    enum class DetectionSource {
        ZeroConf,
        Hardcoded,
    };

    Q_ENUM(DetectionSource)

    AgentInformation(const QString& name, const QString& host, quint16 port, DetectionSource);

    const QString& name() const;
    const QString& host() const;
    quint16 port() const;
    DetectionSource detectionSource() const;

    bool operator==(const AgentInformation &) const;

private:
    friend uint qHash(const AgentInformation &, uint);

    QString m_name;
    QString m_host;
    quint16 m_port;
    DetectionSource m_detectionSource;
};


uint qHash(const AgentInformation &, uint seed);
