#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QDialog>
#include "server.h"

namespace Ui {
class ChatView;
}

class ChatView : public QDialog
{
    Q_OBJECT

public:
    explicit ChatView(QWidget *parent = nullptr, server *myServer = nullptr);
    ~ChatView();

private slots:
    void on_sendDataButton_clicked();
    void showReceivedMessage(QByteArray &byteMessage);

private:
    Ui::ChatView *ui;
    server *myServer;
};

#endif // CHATVIEW_H
