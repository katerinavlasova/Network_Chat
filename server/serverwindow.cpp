#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
ServerWindow::ServerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}


void ServerWindow::on_LoginButton_clicked()
{
    QString username = ui->NameLineEdit->text();
    QString userpassword = ui->PasswordLineEdit->text();
    if (username == "123" && userpassword == "123")
    {
        myServer.startServer();
        chat = new ChatView(this, &myServer);
        hide();
        chat->show();
    }
    else
        QMessageBox::warning(this, "Warning", "Wrong data!");
}

