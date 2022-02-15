#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QMainWindow>

namespace Ui {
class chatview;
}

class chatview : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatview(QWidget *parent = nullptr);
    ~chatview();

private:
    Ui::chatview *ui;
};

#endif // CHATVIEW_H
