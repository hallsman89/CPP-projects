#ifndef CPP3_SMARTCALC_V2_0_1_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_CONTROLLER_H_

#include <vector>
#include <string>
#include "model/headers/Model.h"
#include "model/headers/ModelCreditCalc.h"

namespace s21
{
    class Controller
    {
    public:
        explicit Controller(Model* model, ModelCreditCalc* creditCalcModel) : model_(model), creditCalcModel_(creditCalcModel) {}
        double apiForCalculateStr(const std::string& expr, bool isGraph = false);
        double apiForCalculateStrWithX(const std::string &expr, double x, bool isGraph = false);
        std::vector<std::string> apiForCreditCalc(const std::string &totalLoanAmount, const std::string &term, const std::string &interestRate, bool isAnnuity);
        std::pair<std::vector<double>, std::vector<double>> apiForGraph(const std::string &expr, double start_x, double end_x, double step);
    private:
        Model *model_;
        ModelCreditCalc* creditCalcModel_;
    };

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_CONTROLLER_H_
