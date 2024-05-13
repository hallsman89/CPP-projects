#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_H_

#include <string>

namespace s21 
{

class Token
{
public:
    enum Type
    {
        OPERATOR,
        OPEN_BRACKET,
        CLOSE_BRACKET,
        INT_NUMBER,
        FLOAT_NUMBER,
        FUNCTION,
        SEPARATOR
    };

    enum OperatorAssociativity
    {
        NONE,
        RIGHT,
        LEFT
    };

    Token(const std::string &token, Type type, OperatorAssociativity asc = NONE);

    int getPrecendance() const noexcept;

    const Type& getType() const { return type_; }
    const OperatorAssociativity& getAsc() const { return operatorAsc_; }
    const std::string& getStr() const { return str_; }
private:
    Type type_;
    OperatorAssociativity operatorAsc_;
    std::string str_;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_MODEL_HEADERS_TOKEN_HPP_