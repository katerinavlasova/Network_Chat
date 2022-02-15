#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class server : public QTcpServer
{
    Q_OBJECT

private:
    QTcpSocket *socket;
    QByteArray Data;
    bool haveInterlocutor;
public:
    server();
    ~server();

public slots:
    int startServer();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisc();

signals:
    //signal to show picture
    void showSignal(QByteArray &bytePicture);
};

#endif // SERVER_H
