#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_MODEL_CC_
#define CPP3_SMARTCALC_V2_0_1_MODEL_MODEL_CC_

#include "headers/Model.h"

namespace s21 {

std::vector<Token> Model::fromInfixToPostfix(const std::vector<Token>& tokens) {
  std::vector<Token> tokensPostfix;
  std::stack<Token> stack;
  for (const Token& token : tokens) {
    Token::Type tokenType = token.getType();
    switch (tokenType) {
      case Token::INT_NUMBER:
      case Token::FLOAT_NUMBER:
        tokensPostfix.push_back(token);
        break;
      case Token::FUNCTION:
      case Token::OPERATOR:
        if (!stack.empty() && token.getAsc() != Token::RIGHT) {
          int currentPriority = token.getPrecendance();
          Token prevOperator = stack.top();
          int prevPriority = prevOperator.getPrecendance();
          while (prevPriority >= currentPriority &&
                 prevOperator.getType() != Token::OPEN_BRACKET) {
            tokensPostfix.push_back(stack.top());
            stack.pop();
            if (stack.empty()) {
              break;
            }
            prevOperator = stack.top();
            prevPriority = prevOperator.getPrecendance();
          }
        }
        stack.push(token);
        break;
      case Token::OPEN_BRACKET:
        stack.push(token);
        break;
      case Token::CLOSE_BRACKET: {
        Token prevOperator = stack.top();
        while (prevOperator.getType() != Token::OPEN_BRACKET) {
          tokensPostfix.push_back(prevOperator);
          stack.pop();
          prevOperator = stack.top();
        }
        stack.pop();
        break;
      }
      case Token::SEPARATOR:
        break;
    }
  }
  while (!stack.empty()) {
    tokensPostfix.push_back(stack.top());
    stack.pop();
  }
  return tokensPostfix;
}

double Model::calculatePolishNotation(const std::vector<Token>& tokens,
                                      bool isGraph) {
  double result = 0;
  double tmp = 0;
  std::stack<double> stack;
  for (const Token& token : tokens) {
    Token::Type tokenType = token.getType();
    switch (tokenType) {
      case Token::INT_NUMBER:
      case Token::FLOAT_NUMBER: {
        double num = std::stod(token.getStr());
        stack.push(num);
        break;
      }
      case Token::OPERATOR: {
        if (token.getStr() == "-" && token.getAsc() == Token::RIGHT) {
          double num = stack.top();
          stack.pop();
          stack.push(num * -1);
          break;
        }
        if (stack.empty()) {
          throw Error(std::string("Bad operator sequence"), Error::Syntax);
        }
        double num1 = stack.top();
        stack.pop();
        if (stack.empty()) {
          throw Error(std::string("Bad operator sequence"), Error::Syntax);
        }
        double num2 = stack.top();
        stack.pop();
        tmp = operatorsHandler(num2, num1, token.getStr());
        stack.push(tmp);
        break;
      }
      case Token::FUNCTION: {
        if (stack.empty()) {
          throw Error(std::string("Bad operator sequence"), Error::Syntax);
        }
        double num = stack.top();
        stack.pop();
        if (!isGraph) {
          tmp = functionHandler(num, token.getStr());
        } else {
          tmp = functionHandlerForGraph(num, token.getStr());
        }

        stack.push(tmp);
        break;
      }
      case Token::OPEN_BRACKET:
      case Token::CLOSE_BRACKET:
      case Token::SEPARATOR:
        break;
    }
  }
  result = stack.top();
  return result;
}

void Model::checkCorrectBracketSequence(const std::string& expr) {
  std::stack<char> stack;
  for (const char symbol : expr) {
    if (symbol == '(') {
      stack.push(symbol);
    } else if (symbol == ')') {
      if (stack.empty()) {
        throw Error(std::string("Bad bracket sequence."), Error::Syntax);
      }
      stack.pop();
    }
  }
}

double Model::operatorsHandler(double num1, double num2,
                               const std::string& oper) {
  double res = 0;
  if (oper == "+") {
    res = num1 + num2;
  } else if (oper == "-") {
    res = num1 - num2;
  } else if (oper == "*") {
    res = num1 * num2;
  } else if (oper == "/") {
    res = num1 / num2;
  } else if (oper == "%") {
    res = static_cast<int>(num1) % static_cast<int>(num2);
  } else if (oper == "^") {
    res = std::pow(num1, num2);
  }

  return res;
}

double Model::functionHandler(double num, const std::string& oper) {
  double res = 0;
  if (oper == "sin") {
    num = num * M_PI / 180;
    res = std::sin(num);
  } else if (oper == "cos") {
    num = num * M_PI / 180;
    res = std::cos(num);
  } else if (oper == "sqrt") {
    res = std::sqrt(num);
  } else if (oper == "asin") {
    res = std::asin(num) * 180.0 / M_PI;
  } else if (oper == "acos") {
    res = std::acos(num) * 180.0 / M_PI;
  } else if (oper == "atan") {
    res = std::atan(num) * 180.0 / M_PI;
  } else if (oper == "ln") {
    res = std::log(num);
  } else if (oper == "log") {
    res = std::log10(num);
  } else if (oper == "tan") {
    num = num * M_PI / 180;
    res = std::tan(num);
  }
  return res;
}

std::string Model::formatStrForTokenize(const std::string& expr) {
  std::string str = expr;
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
  size_t pos = str.find("mod");
  while (pos != std::string::npos) {
    str.replace(pos, 3, "%");
    pos = str.find("mod", pos + 1);
  }
  return str;
}

std::string Model::replaceX(const std::string& expr, double x) {
  std::string str = expr;
  std::transform(str.begin(), str.end(), str.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  size_t pos = str.find("x");
  std::string number = std::to_string(x);
  while (pos != std::string::npos) {
    str.replace(pos, 1, number);
    pos = str.find("x", pos + 1);
  }
  return str;
}

double Model::functionHandlerForGraph(double num, const std::string& oper) {
  double res = 0;
  if (oper == "sin") {
    res = std::sin(num);
  } else if (oper == "cos") {
    res = std::cos(num);
  } else if (oper == "sqrt") {
    res = std::sqrt(num);
  } else if (oper == "asin") {
    res = std::asin(num);
  } else if (oper == "acos") {
    res = std::acos(num);
  } else if (oper == "atan") {
    res = std::atan(num);
  } else if (oper == "ln") {
    res = std::log(num);
  } else if (oper == "log") {
    res = std::log10(num);
  } else if (oper == "tan") {
    res = std::tan(num);
  }
  return res;
}

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_MODEL_cc_
