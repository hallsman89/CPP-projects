#include "debitwindow.h"

#include <QDate>
#include <QDebug>
#include <QLineEdit>

#include "ui_debitwindow.h"

debitWindow::debitWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::debitWindow) {
  ui->setupUi(this);
  setAttribute(Qt::WA_DeleteOnClose);
}

debitWindow::~debitWindow() { delete ui; }

void debitWindow::on_pushButton_calculate_clicked() {
  QDate debitStart = QDate::currentDate();
  double initialAmount = ui->doubleSpinBox_amount->text().toDouble();
  int depositPeriod = ui->spinBox_period->text().toInt();
  double interestRate = ui->spinBox_interest->text().toDouble();
  double taxRate = ui->spinBox_tax->text().toDouble();
  double totalInterest = 0;
  double totalTax = 0;
  double currentSavings = initialAmount;
  QDate debitEnd = debitStart.addYears(depositPeriod);

  int daysToAddInPeriod;
  int monthsInYear = 12;
  interestRate /= 100;
  taxRate /= 100;
  int totalCycles = depositPeriod;

  switch (ui->comboBox->currentIndex()) {
    case 0:
      totalCycles *= 365;
      daysToAddInPeriod = 1;
      interestRate /= 365;
      break;
    case 1:
      totalCycles *= 52;
      daysToAddInPeriod = 7;
      interestRate /= 52;
      break;
    case 2:
      totalCycles *= 12;
      daysToAddInPeriod = 30;
      interestRate /= 12;
      break;
    case 3:
      totalCycles *= 4;
      daysToAddInPeriod = 120;
      interestRate /= 4;
      break;
    case 4:
      totalCycles *= 2;
      daysToAddInPeriod = 182;
      interestRate /= 2;
      break;
    case 5:
      totalCycles *= 1;
      daysToAddInPeriod = 365;
      break;
    case 6:
      totalCycles = 1;
      daysToAddInPeriod = depositPeriod * 365;
      interestRate *= depositPeriod;
      break;
  }

  for (int i = 0; i < totalCycles; ++i) {
    for (int i = 0; i < ui->tableWidget_replenishment->rowCount(); ++i) {
      QDate repleinshmentDate = QDate::fromString(
          ui->tableWidget_replenishment->item(i, 0)->text(), "dd/MM/yyyy");
      if (debitStart <= repleinshmentDate && repleinshmentDate <= debitEnd) {
        currentSavings +=
            ui->tableWidget_replenishment->item(i, 1)->text().toDouble();
      }
    }
    for (int i = 0; i < ui->tableWidget_withdrawal->rowCount(); ++i) {
      QDate repleinshmentDate = QDate::fromString(
          ui->tableWidget_withdrawal->item(i, 0)->text(), "dd/MM/yyyy");
      if (debitStart <= repleinshmentDate && repleinshmentDate <= debitEnd) {
        currentSavings -=
            ui->tableWidget_withdrawal->item(i, 1)->text().toDouble();
        ui->tableWidget_withdrawal->takeItem(i, 1);
        ui->tableWidget_withdrawal->takeItem(i, 0);
        int row = ui->tableWidget_withdrawal->rowCount();
        ui->tableWidget_withdrawal->setRowCount(row - 1);
      }
    }
    if (ui->checkBox->isChecked()) {
      double interest = currentSavings * interestRate;
      totalInterest += interest;
      currentSavings += interest;
    } else {
      double interest = currentSavings * interestRate;
      totalInterest += interest;
    }
    debitStart = debitStart.addDays(daysToAddInPeriod);
  }
  for (int i = 0; i < depositPeriod; ++i) {
    totalTax += totalInterest * taxRate;
  }

  double finalSavings = currentSavings;
  ui->label_totalInterest->setText(QString::number(totalInterest));
  ui->label_totalTax->setText(QString::number(totalTax));
  ui->label_finalSavings->setText(QString::number(finalSavings));
}

void debitWindow::on_pushButton_replenishment_clicked() {
  int row = ui->tableWidget_replenishment->rowCount();
  ui->tableWidget_replenishment->setRowCount(row + 1);
  QTableWidgetItem *itm = new QTableWidgetItem;
  QTableWidgetItem *item = new QTableWidgetItem;
  ui->tableWidget_replenishment->setItem(
      ui->tableWidget_replenishment->rowCount(), 0, itm);
  ui->tableWidget_replenishment->setItem(
      ui->tableWidget_replenishment->rowCount(), 1, item);
}

void debitWindow::on_pushButton_withdrawal_clicked() {
  int row = ui->tableWidget_withdrawal->rowCount();
  ui->tableWidget_withdrawal->setRowCount(row + 1);
  QTableWidgetItem *itm = new QTableWidgetItem;
  QTableWidgetItem *item = new QTableWidgetItem;
  ui->tableWidget_replenishment->setItem(ui->tableWidget_withdrawal->rowCount(),
                                         0, itm);
  ui->tableWidget_replenishment->setItem(ui->tableWidget_withdrawal->rowCount(),
                                         1, item);
}
