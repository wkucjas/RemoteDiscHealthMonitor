
#include "AgentStatusFetcher.hpp"
#include "common/ProtocolVersion.h"


AgentStatusFetcher::AgentStatusFetcher(const AgentInformation& info)
    : QObject()
{
    connect(&m_socket, &QTcpSocket::connected, [info]{
        qDebug() << "successfully connected to client " << info.host() << ":" << info.port();
    });

    connect(&m_socket, &QTcpSocket::readyRead, this, &AgentStatusFetcher::readStatus);

    m_inputStream.setDevice(&m_socket);
    m_inputStream.setVersion(QDataStream::Qt_5_10);

    m_socket.connectToHost(info.host(), info.port());
}


void AgentStatusFetcher::readStatus()
{
    m_inputStream.startTransaction();

    ProtocolVersion version;
    m_inputStream >> version;

    if (m_inputStream.commitTransaction() == false || version != ProtocolVersion::VER_1)
        return;

    m_inputStream.startTransaction();

    Health health;
    m_inputStream >> health;

    if (m_inputStream.commitTransaction())
        emit statusAvailable(health);
}
