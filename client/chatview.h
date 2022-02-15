#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class chatview;
}

class chatview : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatview(QWidget *parent = nullptr, client *Client = nullptr);
    ~chatview();

private slots:
    void on_sendButton_clicked();

private:
    Ui::chatview *ui;
    client *Myclient;
};

#endif // CHATVIEW_H
