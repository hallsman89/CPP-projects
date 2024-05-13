#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKENIZER_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKENIZER_H_

#include <vector>
#include "Token.h"

namespace s21 
{

enum State
{
    S0, // Стартовое
    S1, // Токенизация оператора
    S2, // Запись целого числа в буфер
    S3, // Запись floating-point числа в буфер
    S4, // Запись функции в буфер
    S5, // Токенизация записанного числа/функции из буфера
    S6  // Токенизация скобки
};

void tokenize(const std::string &expr, std::vector<Token> &tokens);

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKENIZER_H_
