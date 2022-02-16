#include "chatview.h"
#include "ui_chatview.h"

ChatView::ChatView(QWidget *parent, server *server) :
    QDialog(parent),
    ui(new Ui::ChatView)
{
    ui->setupUi(this);
    myServer = server;
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
    ui->ChattextBrowser->append(message);
}

