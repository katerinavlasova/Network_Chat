#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:
    client();

private:
    QTcpSocket *socket;
    QByteArray Data;
    bool haveInterlocutor;

public slots:
    void startClient();
    void socketReady();
    void socketDisc();
    //send data to server
    bool sendData(QByteArray &byteMessage);

signals:
    //signal to show message in chat
    void showSignal(QByteArray &byteMessage);
};

#endif // CLIENT_H
