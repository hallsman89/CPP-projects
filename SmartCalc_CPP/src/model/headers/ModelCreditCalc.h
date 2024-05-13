#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_

#include <string>
#include <vector>

namespace s21
{
    class ModelCreditCalc
    {
    public:
        ModelCreditCalc();
        void setData(const std::string &totalLoanAmount, const std::string &term, const std::string &interestRate, bool isAnnuity);
        std::vector<std::string> calculate() const noexcept;
    private:
        std::vector<std::string> annuityCredit() const noexcept;
        std::vector<std::string> differentiatedCredit() const noexcept;
    
    private:
        bool isAnnuity_;
        std::string totalLoanAmount_;
        std::string term_;
        std::string interestRate_;
    };


} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_CREDITCALC_H_