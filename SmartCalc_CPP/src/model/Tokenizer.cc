#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_CC_
#define CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_CC_

#include "headers/Tokenizer.h"

#include <iostream>
#include <map>
#include <string>

#include "headers/Error.h"

namespace s21 {

void tokenize(const std::string &expr, std::vector<Token> &tokens) {
  State state = S0;
  std::string validOperators = "+-*^/%";
  bool isDigit, isLetter, isOperator, isPoint, isSep, isBracket, isCloseBracket,
      isOpenBracket;
  std::string buffer;
  Token::Type bufferTokenType = Token::INT_NUMBER;

  for (char symbol : expr) {
    if (symbol == 'x' || symbol == 'X') {
      throw Error(std::string("X is only used in the graph"), Error::Syntax);
    }
    isDigit = std::isdigit(symbol);
    isLetter = std::isalpha(symbol);
    isOpenBracket = symbol == '(';
    isCloseBracket = symbol == ')';
    isBracket = isOpenBracket || isCloseBracket;
    isPoint = symbol == '.';
    isSep = symbol == ',';
    isOperator = validOperators.find(symbol) != validOperators.npos;

    if (!(isDigit || isLetter || isBracket || isPoint || isSep || isOperator)) {
      throw Error(std::string("Unknow symbol: ") + symbol, Error::Syntax);
    }

    switch (state) {
      case S0:
        if (isOperator && (symbol == '-' || symbol == '+')) {
          state = S1;
        } else if (isDigit) {
          state = S2;
        } else if (isLetter) {
          state = S4;
        } else if (isOpenBracket) {
          state = S6;
        } else if (isPoint || isSep || isCloseBracket || isOperator) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S1:
        if (isDigit) {
          state = S2;
        } else if (isLetter) {
          state = S4;
        } else if (isOpenBracket) {
          state = S6;
        } else if (isPoint || isSep || isCloseBracket || isOperator) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S2:
        bufferTokenType = Token::INT_NUMBER;
        if (isPoint) {
          state = S3;
        } else if (isCloseBracket || isOperator || isSep) {
          state = S5;
        } else if (isLetter || isOpenBracket) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S3:
        bufferTokenType = Token::FLOAT_NUMBER;
        if (isCloseBracket || isOperator || isSep) {
          state = S5;
        } else if (isPoint || isOpenBracket || isLetter) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S4:
        bufferTokenType = Token::FUNCTION;
        if (isOpenBracket) {
          state = S5;
        } else if (isOperator || isCloseBracket || isSep) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S5:
        if (isOperator) {
          state = S1;
        } else if (isDigit) {
          state = S2;
        } else if (isLetter) {
          state = S4;
        } else if (isBracket) {
          state = S6;
        } else if (isPoint || isSep) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
      case S6:
        if (isDigit) {
          state = S2;
        } else if (isOperator) {
          state = S1;
        } else if (isLetter) {
          state = S4;
        } else if (isPoint || isSep || isCloseBracket) {
          throw Error(std::string("Unexpected symbol: ") + symbol,
                      Error::Syntax);
        }
        break;
    }

    auto tokenizeOperatorsBracketsSep = [&]() {
      if (isOperator) {
        if (tokens.empty() || tokens.back().getType() == Token::OPEN_BRACKET ||
            tokens.back().getStr() == "-" ||
            tokens.back().getType() == Token::OPERATOR)
          tokens.push_back(
              {std::string{symbol}, Token::OPERATOR, Token::RIGHT});
        else
          tokens.push_back({std::string{symbol}, Token::OPERATOR, Token::LEFT});
      } else if (isBracket) {
        tokens.push_back({std::string{symbol}, isCloseBracket
                                                   ? Token::CLOSE_BRACKET
                                                   : Token::OPEN_BRACKET});
      } else if (isSep) {
        tokens.push_back({std::string{symbol}, Token::SEPARATOR});
      }
    };

    switch (state) {
      case S0:
        break;
      case S1:
      case S6:
        tokenizeOperatorsBracketsSep();
        break;
      case S2:
      case S3:
      case S4:
        buffer.push_back(symbol);
        break;
      case S5:
        if (!buffer.empty()) tokens.push_back({buffer, bufferTokenType});
        buffer.clear();
        tokenizeOperatorsBracketsSep();
        break;
    }
  }

  if (!buffer.empty()) {
    tokens.push_back({buffer, bufferTokenType});
  }
}

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_CC_
