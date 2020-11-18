#pragma once

#include <QObject>
#include "Health.h"


class GeneralHealth : public QObject
{
    Q_OBJECT

public:
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
