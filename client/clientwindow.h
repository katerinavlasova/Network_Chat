#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "chatview.h"
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_LoginButton_clicked();

private:
    Ui::ClientWindow *ui;
    chatview *chat;
    client myClient;
};
#endif // CLIENTWINDOW_H
