#ifndef CPP3_SMARTCALC_V2_0_1_CONTROLLER_CC_
#define CPP3_SMARTCALC_V2_0_1_CONTROLLER_CC_

#include "controller.h"

namespace s21 {

double Controller::apiForCalculateStr(const std::string &expr, bool isGraph) {
  std::vector<Token> tokensInfix;
  std::string str = model_->formatStrForTokenize(expr);
  model_->checkCorrectBracketSequence(str);
  tokenize(str, tokensInfix);
  std::vector<Token> tokensPostfix = model_->fromInfixToPostfix(tokensInfix);
  double result = model_->calculatePolishNotation(tokensPostfix, isGraph);
  return result;
}

double Controller::apiForCalculateStrWithX(const std::string &expr, double x,
                                           bool isGraph) {
  std::string str = model_->replaceX(expr, x);
  return apiForCalculateStr(str, isGraph);
}

std::pair<std::vector<double>, std::vector<double>> Controller::apiForGraph(
    const std::string &expr, double start_x, double end_x, double step) {
  std::vector<double> x;
  std::vector<double> y;
  for (double current_x = start_x; current_x <= end_x; current_x += step) {
    double tmp = apiForCalculateStrWithX(expr, current_x, true);
    x.push_back(current_x);
    y.push_back(tmp);
  }
  return std::make_pair(x, y);
}

std::vector<std::string> Controller::apiForCreditCalc(
    const std::string &totalLoanAmount, const std::string &term,
    const std::string &interestRate, bool isAnnuity) {
  creditCalcModel_->setData(totalLoanAmount, term, interestRate, isAnnuity);
  return creditCalcModel_->calculate();
}

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CONTROLLER_CC_
