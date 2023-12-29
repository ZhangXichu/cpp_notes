#include <iostream>

#include "expr.hpp"


void test()
{
    // Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    // std::cout << t << std::endl;
    // t = Expr("*", t, t);
    // std::cout << t std::endl;

    auto expr_num_ptr_1 = std::make_unique<NumExpr>(5);
    auto expr_num_ptr_2 = std::make_unique<NumExpr>(4);

    OpExpr expr_op("*", std::move(expr_num_ptr_1), std::move(expr_num_ptr_2));

    std::cout << "Case : simple expression : " << expr_op << std::endl;

    Expr expr("*", Expr("-", 5), Expr("+", 3, 4));

    std::cout << "Case : compound expression (wrapper): " << expr << std::endl;

    Expr expr2 = Expr("/", Expr("-", 10), Expr("+", 2, 7));

    std::cout << "Case : move (copy elision) : " << expr2 << std::endl;

    Expr expr3 = std::move(expr2);

    std::cout << "Case : move constructor : " << expr3 << std::endl;

}

int main()
{
    test();
}