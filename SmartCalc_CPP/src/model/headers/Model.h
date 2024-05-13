#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_

#include <stack>
#include <cmath>
#include <algorithm>
#include "Tokenizer.h"
#include "Error.h"

namespace s21
{
class Model
{
public:
    std::vector<Token> fromInfixToPostfix(const std::vector<Token> &tokens);
    double calculatePolishNotation(const std::vector<Token> &tokens, bool isGraph = false);
    void checkCorrectBracketSequence(const std::string &expr);
    std::string formatStrForTokenize(const std::string &expr);
    double operatorsHandler(double num1, double num2, const std::string& oper);
    double functionHandler(double num, const std::string& oper);
    void checkCorrectOperatorSequence(const std::string &expr);
    std::string replaceX(const std::string &expr, double x);
    double functionHandlerForGraph(double num, const std::string& oper);
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_MODEL_H_
