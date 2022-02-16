#include "client.h"

client::client() {}

void client::startClient()
{
    socket = new QTcpSocket();
    socket->connectToHost(QHostAddress::LocalHost, 1010);
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisc()));

}
void client::socketReady()
{
    qDebug() << "client reasy read";
    //clear previous data
    Data.clear();
    //read data from client
    Data = socket->readAll();
    qDebug() << Data;
}
void client::socketDisc()
{
    socket->deleteLater();
}

bool client::sendData(QByteArray &byteMessage)
{
    qDebug() << "coonect tonhos";
    //socket->connectToHost(QHostAddress::LocalHost, 1010);
    qDebug() << "write data :";
    socket->write(byteMessage);
    qDebug() << "send ata mess :";
    socket->waitForBytesWritten(50);
    return true;
}
