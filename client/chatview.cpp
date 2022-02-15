#include "chatview.h"
#include "ui_chatview.h"

chatview::chatview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatview)
{
    ui->setupUi(this);
}

chatview::~chatview()
{
    delete ui;
}
