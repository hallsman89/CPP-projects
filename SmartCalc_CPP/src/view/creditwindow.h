#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMainWindow>

#include "../controller.h" // path - controller

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditWindow(s21::Controller *controller, QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_calc_credit_clicked();

private:
    Ui::CreditWindow *ui;
    s21::Controller *controller_;
};

#endif // CREDITWINDOW_H
