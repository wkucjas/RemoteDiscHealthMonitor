#pragma once
#include <QObject>

class GeneralHealth: public QObject
{
    Q_OBJECT

public:
    enum Health : quint8
    {
        UNKNOWN = 0,
        GOOD,
        BAD,
        CHECK_STATUS
    };

    Q_ENUMS(Health)

    uint8_t GetStatus()
    {
        return m_status;
    }

    void SetStatus(Health _health)
    {
        m_status = _health;
    }

private:
    uint8_t m_status;
};
