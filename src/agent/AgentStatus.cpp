
#include <QTimer>

#include "AgentStatus.h"

using namespace std::chrono_literals;


AgentStatus::AgentStatus(QObject* parent)
    : AgentStatusSource(parent)
    , m_counter(0)
{
    auto timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [this]() {
        setCounter(++m_counter);
    });

    timer->start(1s);
}


void AgentStatus::setCounter(int counter)
{
    m_counter = counter;

    emit counterChanged(m_counter);
}


int AgentStatus::counter() const
{
    return m_counter;
}
