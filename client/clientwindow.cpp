#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QMessageBox>
#include <QFile.h>

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
    QFile file("../users.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Warning", "No data about users!");
    }
    QString username = ui->NameLineEdit->text();
    QString userpassword = ui->PasswordLineEdit->text();

    QTextStream in(&file);
    bool userFound = false;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if (username == fields[0] && userpassword == fields[1])
        {
            userFound = true;
            myClient.startClient();
            chat = new chatview(this, &myClient);
            hide();
            chat->show();
            file.close();
            break;
        }
    }
    if (userFound == false)
    {
        QMessageBox::warning(this, "Warning", "Wrong data!");
    }
}

