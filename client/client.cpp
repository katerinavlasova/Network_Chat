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
    qDebug() << "client reasy read";

    //clear previous data
    Data.clear();
    //read data from server
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        QByteArray byteMessage;
        in >> byteMessage;
        QString stringMessage = QString(byteMessage);
        qDebug() << "mess client :: " << stringMessage;
        emit showSignal(byteMessage);
    }

    //    Data = socket->readAll();
//    qDebug() << Data;
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
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    //QString str = QString(byteMessage);
    out << byteMessage;
    socket->write(Data);
    //socket->write(byteMessage);
    qDebug() << "send ata mess :";
    //socket->waitForBytesWritten(50);
    return true;
}
