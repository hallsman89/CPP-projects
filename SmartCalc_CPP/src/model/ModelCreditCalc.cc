#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALC_CC_
#define CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALC_CC_

#include "headers/ModelCreditCalc.h"

#include <cmath>

namespace s21 {
ModelCreditCalc::ModelCreditCalc()
    : isAnnuity_(false), totalLoanAmount_(""), term_(""), interestRate_("") {}

std::vector<std::string> ModelCreditCalc::calculate() const noexcept {
  if (isAnnuity_) {
    return annuityCredit();
  }
  return differentiatedCredit();
}

std::vector<std::string> ModelCreditCalc::annuityCredit() const noexcept {
  double totalLoanAmount = std::stod(totalLoanAmount_);
  double term = std::stod(term_) * 12.0;
  double interestRate = std::stod(interestRate_) / 12 / 100;
  double monthlyPayment =
      (totalLoanAmount * interestRate * std::pow(1 + interestRate, term)) /
      (std::pow(1 + interestRate, term) - 1);
  double totalRepayment = monthlyPayment * term;
  double loanOverpayment = totalRepayment - totalLoanAmount;
  std::vector<std::string> returnValue(3);
  returnValue[0] = std::to_string(monthlyPayment);
  returnValue[1] = std::to_string(totalRepayment);
  returnValue[2] = std::to_string(loanOverpayment);
  return returnValue;
}

std::vector<std::string> ModelCreditCalc::differentiatedCredit()
    const noexcept {
  double totalLoanAmount = std::stod(totalLoanAmount_);
  int term = std::stod(term_) * 12.0;
  double interestRate = std::stod(interestRate_) / 12 / 100;
  std::vector<double> monthlyPayment(term);
  double totalRepayment = 0.0;
  for (int i = 1; i <= term; ++i) {
    monthlyPayment[i - 1] =
        (totalLoanAmount / term) +
        (totalLoanAmount - ((totalLoanAmount * (i - 1)) / term)) * interestRate;
    totalRepayment += monthlyPayment[i - 1];
  }
  double loanOverpayment = totalRepayment - totalLoanAmount;
  std::vector<std::string> returnValue(3);
  returnValue[0] = std::to_string(monthlyPayment.front()) + "..." +
                   std::to_string(monthlyPayment.back());
  returnValue[1] = std::to_string(totalRepayment);
  returnValue[2] = std::to_string(loanOverpayment);
  return returnValue;
}

void ModelCreditCalc::setData(const std::string &totalLoanAmount,
                              const std::string &term,
                              const std::string &interestRate, bool isAnnuity) {
  isAnnuity_ = isAnnuity;
  totalLoanAmount_ = totalLoanAmount;
  term_ = term;
  interestRate_ = interestRate;
}

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALC_CC_