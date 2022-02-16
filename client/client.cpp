#include "client.h"
#include "chatview.h"

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
    //clear previous data
    Data.clear();
    //read data from server
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QByteArray byteMessage;
        in >> byteMessage;
        emit showSignal(byteMessage);
    }
}

void client::socketDisc()
{
    socket->deleteLater();
}

bool client::sendData(QByteArray &byteMessage)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << byteMessage;
    socket->write(Data);
    return true;
}
