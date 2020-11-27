#pragma once

#include <QObject>


class GeneralHealth
{
    Q_GADGET

public:
    enum Health : quint8
    {
        UNKNOWN = 0,
        GOOD,
        BAD,
        CHECK_STATUS
    };

    Q_ENUM(Health)

    GeneralHealth();
    GeneralHealth(const Health& _health);
    GeneralHealth(const GeneralHealth& _health) = default;
    GeneralHealth& operator=(const GeneralHealth& _health) = default;

    Health GetStatus() const;

    void SetStatus(Health _health);

private:
    Health m_health;
};
