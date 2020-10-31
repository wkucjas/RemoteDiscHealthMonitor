
#include "AgentStatusFetcher.hpp"


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

    QString status;
    m_inputStream >> status;

    if (m_inputStream.commitTransaction())
    {
        qDebug() << "Client status: " << status;

        emit statusAvailable(status);
    }
}
