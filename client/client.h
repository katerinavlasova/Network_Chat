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
    bool sendData(QByteArray &byteMessage);
};

#endif // CLIENT_H
