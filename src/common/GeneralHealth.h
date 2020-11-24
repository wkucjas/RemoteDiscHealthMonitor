#pragma once

#include <QObject>


class GeneralHealth : public QObject
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

    GeneralHealth();
    GeneralHealth(const Health& _health);
    GeneralHealth(const GeneralHealth& _health);
    GeneralHealth& operator=(const GeneralHealth& _health);

    Health GetStatus() const;

    void SetStatus(Health _health);

private:
    Health m_health;
};
