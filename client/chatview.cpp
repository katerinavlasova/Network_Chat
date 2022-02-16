#include "chatview.h"
#include "ui_chatview.h"
#include <QTime>

chatview::chatview(QWidget *parent, client *Client) :
    QMainWindow(parent),
    ui(new Ui::chatview)
{
    ui->setupUi(this);
    Myclient = Client;
    connect(Myclient, SIGNAL(showSignal(QByteArray&)), this, SLOT(showReceivedMessage(QByteArray&)));
}

chatview::~chatview()
{
    delete ui;
}

void chatview::on_sendButton_clicked()
{
    QString message = ui->MessagelineEdit->text();
    qDebug() << "text client :" << message;
    QByteArray byteMessage = message.toUtf8();
    Myclient->sendData(byteMessage);
    ui->MessagelineEdit->clear();
    ui->chattextBrowser->append(QTime::currentTime().toString());
    ui->chattextBrowser->append(message);
}

void chatview::showReceivedMessage(QByteArray &byteMessage)
{
    QString stringMessage = QString(byteMessage);
    ui->chattextBrowser->append(QTime::currentTime().toString());
    ui->chattextBrowser->append(stringMessage);
}
