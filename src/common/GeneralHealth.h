#pragma once

#include <QObject>



class GeneralHealth : public QObject
{
    Q_OBJECT

public:

    enum  Health : quint8
    {
        UNKNOWN = 0,
        GOOD,
        BAD,
        CHECK_STATUS
    };

    GeneralHealth();
    GeneralHealth(GeneralHealth& _health);
    GeneralHealth operator=(GeneralHealth& _health);
    


    Q_ENUMS(Health)

    Health GetStatus() const;

    void SetStatus(Health _health);



private:
    Health m_status;
};
