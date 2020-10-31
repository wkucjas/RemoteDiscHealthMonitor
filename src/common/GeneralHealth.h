#pragma once
#include <stdint.h>

class GeneralHealth
{
public:
    enum Health : uint8_t
    {
        UNKNOWN = 0,
        GOOD,
        BAD,
        CHECK_STATUS
    };

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
