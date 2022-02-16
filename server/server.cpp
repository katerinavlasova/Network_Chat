#include "server.h"

server::server() { haveInterlocutor = false; }
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

    qDebug() << "Client connected";

}

void server::socketReady()
{
    //qDebug() << Data << " socket reay";
    haveInterlocutor = true;
    //clear previous data
    Data.clear();
    socket = (QTcpSocket*)sender();
    //read data from client
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        qDebug() << "read";
        QString strMessage;
        QByteArray byteMessage;
        in >> byteMessage;
        strMessage = QString(byteMessage);
        qDebug() << strMessage;
    }
    //Data = socket->readAll();
//    while (socket->waitForReadyRead(20))
//    {
//        while (socket->bytesAvailable() > 0)
//        {
//            Data.append(socket->readAll());
//            socket->flush();
//        }
//    }
    //SendData(Data);
    //qDebug() << Data << " dwe";

}

void server::socketDisc()
{
    socket->deleteLater();
    qDebug() << "Client disconnected";
    haveInterlocutor = false;
}

void server::SendData(QByteArray &byteMessage)
{
    Data.clear();
    qDebug() << "send data";
    //socket->write(Data);
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << byteMessage;
    //Data = byteMessage;
    //QString str = byteMessage.toStdString();

    for (int i = 0; i < sockets.size(); i++)
        sockets[i]->write(Data);
    //socket->connectToHost(QHostAddress::LocalHost, 1010);
    QString mess = QString(byteMessage);
    qDebug() << "write data :" << mess;
    //socket->write("all");
    //socket->write(byteMessage);
    qDebug() << "send ata mess :";
    //socket->waitForBytesWritten(50);
}
