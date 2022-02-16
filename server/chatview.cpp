#include "chatview.h"
#include "ui_chatview.h"
#include <QTime>

ChatView::ChatView(QWidget *parent, server *server) :
    QDialog(parent),
    ui(new Ui::ChatView)
{
    ui->setupUi(this);
    myServer = server;
    connect(server, SIGNAL(showSignal(QByteArray&)), this, SLOT(showReceivedMessage(QByteArray&)));
}

ChatView::~ChatView()
{
    delete ui;
}

void ChatView::on_sendDataButton_clicked()
{
    QString message = ui->messageLineEdit->text();
    QByteArray byteMessage = message.toUtf8();
    qDebug() << "BITON data" << message;
    myServer->SendData(byteMessage);

    ui->messageLineEdit->clear();
    ui->ChattextBrowser->append(QTime::currentTime().toString());
    ui->ChattextBrowser->append(message);
}

void ChatView::showReceivedMessage(QByteArray &byteMessage)
{
    QString stringMessage = QString(byteMessage);
    ui->ChattextBrowser->append(QTime::currentTime().toString());
    ui->ChattextBrowser->append(stringMessage);
}
