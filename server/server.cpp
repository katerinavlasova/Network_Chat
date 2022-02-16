#include "server.h"

server::server() { }
server::~server() {}

int server::startServer()
{
    if (this->listen(QHostAddress::Any, 1010))
    {
        qDebug() << "Server is listening";
        return 0;
    }
    else
    {
        qDebug() << "Server isn't listening";
        return -1;
    }
    return 0;
}

void server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()),this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));

    sockets.push_back(socket);
}

void server::socketReady()
{
    //clear previous data
    Data.clear();

    //read data from client
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);

    if (in.status() == QDataStream::Ok)
    {
        QString strMessage;
        QByteArray byteMessage;
        in >> byteMessage;
        emit showSignal(byteMessage);
    }
}

void server::socketDisc()
{
    socket->deleteLater();
    qDebug() << "Client disconnected";
}

void server::SendData(QByteArray &byteMessage)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << byteMessage;

    for (int i = 0; i < sockets.size(); i++)
        sockets[i]->write(Data);
}
