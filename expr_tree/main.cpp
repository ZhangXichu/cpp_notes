#include <iostream>

#include "expr.hpp"


void test()
{
    // Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    // std::cout << t << std::endl;
    // t = Expr("*", t, t);
    // std::cout << t std::endl;

    NumExpr expr(5);

    std::cout << expr << std::endl;
}

int main()
{
    test();
}