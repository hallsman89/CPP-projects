#include "graphwindow.h"

#include <iostream>

#include "ui_graphwindow.h"

GraphWindow::GraphWindow(s21::Controller* controller, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::GraphWindow), controller_(controller) {
  ui->setupUi(this);
  connect(ui->lineEdit_f_x, SIGNAL(returnPressed()), this,
          SLOT(on_pushButton_draw_clicked()));
  setAttribute(Qt::WA_DeleteOnClose);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::on_pushButton_draw_clicked() {
  double x_min = QString(ui->doubleSpinBox_start_x->text()).toDouble();
  double x_max = QString(ui->doubleSpinBox_end_x->text()).toDouble();
  double y_min = QString(ui->doubleSpinBox_min_y->text()).toDouble();
  double y_max = QString(ui->doubleSpinBox_max_y->text()).toDouble();
  double step = QString(ui->doubleSpinBox_step->text()).toDouble();
  std::string str = ui->lineEdit_f_x->text().toLower().toStdString();

  try {
    std::pair<std::vector<double>, std::vector<double>> coordinates =
        controller_->apiForGraph(str, x_min, x_max, step);
    QVector<double> qX(coordinates.first.begin(), coordinates.first.end());
    QVector<double> qY(coordinates.second.begin(), coordinates.second.end());
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(qX, qY, true);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
  } catch (s21::Error& e) {
    ui->lineEdit_f_x->setText(QString(e.what().c_str()));
  } catch (const std::exception& e) {
    ui->lineEdit_f_x->setText(QString(e.what()));
  }

  ui->widget->replot();
}
