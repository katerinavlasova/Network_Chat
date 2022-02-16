#include "chatview.h"
#include "ui_chatview.h"

chatview::chatview(QWidget *parent, client *Client) :
    QMainWindow(parent),
    ui(new Ui::chatview)
{
    ui->setupUi(this);
    Myclient = Client;
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
    ui->chattextBrowser->append(message);


}

