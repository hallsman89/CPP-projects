#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_TOKEN_CC_
#define CPP3_SMARTCALC_V2_0_1_MODEL_TOKEN_CC_

#include "headers/Token.h"

#include <map>
#include <stdexcept>

#include "headers/Error.h"

namespace s21 {

Token::Token(const std::string &token, Type type, OperatorAssociativity asc)
    : type_(type), str_(token) {
  if (type == OPERATOR && asc == NONE) {
    throw std::logic_error("Associativity required!");
  } else if (type != OPERATOR && asc != NONE) {
    throw std::logic_error("Non-operator token can't have an associativity!");
  }
  operatorAsc_ = asc;
}

int Token::getPrecendance() const noexcept {
  static std::map<std::string, int> leftAssociativOperators = {
      {"+", 2}, {"-", 2}, {"/", 3}, {"*", 3}, {"^", 6},
  };

  static std::map<std::string, int> rightAssociativOperators = {
      {"-", 4},
  };

  switch (operatorAsc_) {
    case LEFT:
      if (leftAssociativOperators.find(str_) != leftAssociativOperators.end()) {
        return leftAssociativOperators[str_];
      }
      break;
    case RIGHT:
      if (rightAssociativOperators.find(str_) !=
          rightAssociativOperators.end()) {
        return rightAssociativOperators[str_];
      }
    case NONE:
      break;
    default:
      break;
  }
  return 5;
}

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_TOKEN_CC_
