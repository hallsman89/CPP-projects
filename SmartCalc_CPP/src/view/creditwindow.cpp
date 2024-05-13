#include "creditwindow.h"

#include <iostream>

#include "ui_creditwindow.h"

CreditWindow::CreditWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreditWindow), controller_(controller) {
  ui->setupUi(this);
  connect(ui->pushButton_calc_credit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_calc_credit_clicked()));
  setAttribute(Qt::WA_DeleteOnClose);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_calc_credit_clicked() {
  std::string totalLoanAmount =
      ui->doubleSpinBox_deposit_amount->text().toStdString();
  std::string term = ui->spinBox_term->text().toStdString();
  std::string interestRate = ui->spinBox_insert_rate->text().toStdString();
  bool isAnnuity = ui->comboBox_credit_type->currentIndex() ? false : true;

  std::vector<std::string> outputData = controller_->apiForCreditCalc(
      totalLoanAmount, term, interestRate, isAnnuity);

  ui->label_loan_overpayment->setText(QString(outputData[2].c_str()));
  ui->label_monthly_payment->setText(QString(outputData[0].c_str()));
  ui->label_total_repayment->setText(QString(outputData[1].c_str()));
}
