#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QVector>

class server : public QTcpServer
{
    Q_OBJECT

private:
    QTcpSocket *socket;
    QByteArray Data;
    QVector<QTcpSocket*> sockets;

public:
    server();
    ~server();

public slots:
    int startServer();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisc();
    //send data to client
    void SendData(QByteArray &byteMessage);

signals:
    //signal to show message in chat
    void showSignal(QByteArray &byteMessage);
};

#endif // SERVER_H
