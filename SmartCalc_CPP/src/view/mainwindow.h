#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

#include "../controller.h" // path - controller

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttons();

    void on_pushButton_equal_clicked();

    void on_pushButton_clear_clicked();

   void on_pushButton_graph_clicked();

    void on_pushButton_credit_clicked();

   void on_pushButton_debit_clicked();

private:
    Ui::MainWindow *ui;
    s21::Controller *controller_;
    void set_signals();
};
#endif // MAINWINDOW_H
