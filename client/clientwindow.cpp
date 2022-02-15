#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QMessageBox>

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}


void ClientWindow::on_LoginButton_clicked()
{
    QString username = ui->NameLineEdit->text();
    QString userpassword = ui->PasswordLineEdit->text();
    if (username == "123" && userpassword == "123")
    {
        chat = new chatview(this);
        hide();
        chat->show();
    }
    else
        QMessageBox::warning(this, "Warning", "Wrong data!");
}

