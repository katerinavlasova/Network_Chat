#include "client.h"

client::client() {}

void client::startClient()
{
    socket = new QTcpSocket();
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));
    socket->connectToHost(QHostAddress::LocalHost, 1010);
    socket->write("lolo");
    socket->waitForBytesWritten(50);
}
void client::socketReady()
{
    qDebug() << "client reasy read";
}
void client::socketDisc()
{
    socket->deleteLater();
}
