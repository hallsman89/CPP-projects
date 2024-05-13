#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::Model calculateModel;
  s21::ModelCreditCalc creditCalcModel;
  s21::Controller controller(&calculateModel, &creditCalcModel);
  QApplication a(argc, argv);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
