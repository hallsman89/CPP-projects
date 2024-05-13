#include "mainwindow.h"

#include <iostream>

#include "../model/headers/Error.h"
#include "./creditwindow.h"
#include "./debitwindow.h"
#include "./graphwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller_(controller) {
  ui->setupUi(this);
  set_signals();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::buttons() {
  ui->lineEdit->setText(ui->lineEdit->text() +
                        (qobject_cast<QPushButton *>((sender()))->text()));
}

void MainWindow::on_pushButton_equal_clicked() {
  std::string str = ui->lineEdit->text().toLower().toStdString();

  try {
    double res = controller_->apiForCalculateStr(str);
    ui->lineEdit->setText(QString::number((double)res));
  } catch (s21::Error &e) {
    ui->lineEdit->setText(QString(e.what().c_str()));
  } catch (const std::exception &e) {
    ui->lineEdit->setText(QString(e.what()));
  }
}

void MainWindow::on_pushButton_clear_clicked() { ui->lineEdit->clear(); }

void MainWindow::on_pushButton_graph_clicked() {
  GraphWindow *graph = new GraphWindow(controller_);
  graph->show();
}

void MainWindow::on_pushButton_credit_clicked() {
  CreditWindow *credit = new CreditWindow(controller_);
  credit->show();
}

void MainWindow::set_signals() {
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(buttons()));
  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(buttons()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(buttons()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(buttons()));

  // equal (click = and ENTER)
  connect(ui->pushButton_equal, SIGNAL(clicked()), this,
          SLOT(on_pushButton_equal_clicked()));
  connect(ui->lineEdit, SIGNAL(returnPressed()), this,
          SLOT(on_pushButton_equal_clicked()));
}

void MainWindow::on_pushButton_debit_clicked() {
  debitWindow *debit = new debitWindow;
  debit->show();
}
