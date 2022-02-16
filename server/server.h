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
    bool haveInterlocutor;
    QVector<QTcpSocket*> sockets;

public:
    server();
    ~server();

public slots:
    int startServer();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisc();
    void SendData(QByteArray &byteMessage);

signals:
    //signal to show picture
    void showSignal(QByteArray &bytePicture);
};

#endif // SERVER_H
