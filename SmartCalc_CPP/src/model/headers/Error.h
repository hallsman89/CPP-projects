#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_

#include <string>

namespace s21
{

class Error
{
public:
    enum Type
    {
        Syntax,
    } type_;

    Error(const std::string &message, Type errorType) : type_(errorType)
    {
        switch (errorType)
        {
            case Syntax:
                msg_ = "Syntax Error: " + message;
                break;
        }
    }

    std::string what() { return msg_; }

private:
    std::string msg_;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_ERROR_H_