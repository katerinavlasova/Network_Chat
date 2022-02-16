#include "serverwindow.h"
#include "ui_serverwindow.h"
#include <QMessageBox>
#include <QFile>

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
            myServer.startServer();
            chat = new ChatView(this, &myServer);
            hide();
            chat->show();
            file.close();
            break;
        }
    }
    if (userFound == false)
        QMessageBox::warning(this, "Warning", "Wrong data!");
}

