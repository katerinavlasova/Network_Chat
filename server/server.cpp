#include "server.h"

server::server() { haveInterlocutor = false; }
server::~server() {}

int server::startServer()
{
    if (this->listen(QHostAddress::LocalHost, 1010))
    {
        qDebug() << "Server is listening";
        return 0;
    }
    else
    {
        qDebug() << "Server isn't listening";
        return -1;
    }
}

void server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()),this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));
    qDebug() << "Client connected";

}

void server::socketReady()
{
    haveInterlocutor = true;
    //clear previous data
    Data.clear();

    //read data from client
    while (socket->waitForReadyRead(200))
    {
        while (socket->bytesAvailable() > 0)
        {
            Data.append(socket->readAll());
            socket->flush();
        }
    }
}

void server::socketDisc()
{
    socket->deleteLater();
    qDebug() << "Client disconnected";
    haveInterlocutor = false;
}
