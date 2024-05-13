#include <gtest/gtest.h>
#include <cmath>
#include "../controller.h"

TEST(Plus, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2+2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 4.0);
}

TEST(Minus, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2-2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 0.0);
}

TEST(Mul, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "3*2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 6.0);
}

TEST(Div, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "10/5";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 2.0);
}

TEST(Sin, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "sin(90)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(Asin, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "asin(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 90.0);
}

TEST(Acos, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "acos(0.5)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 60.0);
}

TEST(Pow, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2^3";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 8.0);
}

TEST(Cos, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "cos(60)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 0.5);
}

TEST(Unary1, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-(-2)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 2.0);
}

TEST(Unary2, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), -2.0);
}

TEST(Ln, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "ln(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 0.0);
}

TEST(Log, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "log(100)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 2.0);
}

TEST(Sqrt, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "sqrt(144)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 12.0);
}

TEST(Atan, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "atan(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 45.0);
}

TEST(UnaryPlus, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2+3";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(Mod, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "5mod2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(Brackets, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "(2+2)*2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 8.0);
}

TEST(Test1, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2+2*2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 6.0);
}

TEST(Tan, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "tan(45)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(Test, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "()sin";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test2, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "(.)/(.)";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test3, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2)+(2";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(UnaryMinus, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2-2";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), -4.0);
}

TEST(UnaryMinus1, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2+3";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(UnaryMinus2, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2-(-3)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 1.0);
}

TEST(UnaryMinus3, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-2-3";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), -5.0);
}

TEST(Y01k4, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "(acos(0.6877) + atan(0.666778) ) ^3 + ( ( ln(66) + lg(88) * (78 + (-8) * 7) ) / (tan(88))^4";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), 516740.92455125228);
}

TEST(Test4, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "*5";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test5, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "5**5";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test6, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-.5";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test7, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "5sin(90)";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test8, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "5.5.5";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test9, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2+.2";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test10, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "sin+cos";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test11, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "~5";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test12, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "tan1";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(Test13, False)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "x+2";
    ASSERT_ANY_THROW(controller.apiForCalculateStr(expr));
}

TEST(UnaryMinusFunction, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "-sin(90)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), -1.0);
}

TEST(UnaryMinys, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2*-10";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr), -20.0);
}

TEST(TestGraph, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "2*x+1";
    std::pair<std::vector<double>, std::vector<double>> val = controller.apiForGraph(expr, -10, 10, 0.1);
    int index = 0;
    for (double current_x = -10; current_x <= 10; current_x += 0.1) {
        double tmp = controller.apiForCalculateStrWithX(expr, current_x, true);
        ASSERT_DOUBLE_EQ(val.first[index], current_x);
        ASSERT_DOUBLE_EQ(val.second[index], tmp);
        ++index;
    }
}

TEST(TestGraph2, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "sin(90)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::sin(90));
}

TEST(TestGraph3, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "cos(90)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::cos(90));
}

TEST(TestGraph4, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "sqrt(144)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::sqrt(144));
}

TEST(TestGraph5, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "asin(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::asin(1));
}

TEST(TestGraph6, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "ln(256)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::log(256));
}

TEST(TestGraph7, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "log(256)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::log10(256));
}

TEST(TestGraph8, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "atan(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::atan(1));
}

TEST(TestGraph9, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "tan(90)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::tan(90));
}

TEST(TestGraph10, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::string expr = "acos(1)";
    ASSERT_DOUBLE_EQ(controller.apiForCalculateStr(expr, true), std::acos(1));
}

TEST(CreditrCalc1, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::vector<std::string> answer = controller.apiForCreditCalc("1000", "1", "5", true);
    double first = std::stod(answer[0]);
    double second = std::stod(answer[1]);
    double third = std::stod(answer[2]);
    ASSERT_DOUBLE_EQ(first, 85.607482);
    ASSERT_DOUBLE_EQ(second, 1027.289781);
    ASSERT_DOUBLE_EQ(third, 27.289781);
}

TEST(CreditrCalc2, True)
{
    s21::Model model_t;
    s21::ModelCreditCalc creditCalc;
    s21::Controller controller(&model_t, &creditCalc);
    std::vector<std::string> answer = controller.apiForCreditCalc("10000", "1", "5", false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
