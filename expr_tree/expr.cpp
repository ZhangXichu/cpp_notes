#include "expr.hpp"

std::ostream& operator<< (std::ostream& os, const ExprBase& expr)
{
    expr.print(os);

    return os;
}

void OpExpr::print(std::ostream& os) const
{
    os << "(" << *(_left_expr);
    os << _op_name;
    if (_right_expr) // binary operator
    {
        os << *(_right_expr) << ")";
    } else { // unary operator
        os << ")";
    }
}

void NumExpr::print(std::ostream& os) const
{
    os << _value; 
}

