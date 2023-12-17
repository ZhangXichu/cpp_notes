#include <iostream>


void test()
{
    Expr t = Expr("*", Expr("-", 5), Expr("+", 3, 4));
    std::cout << t << std::endl;
    t = Expr("*", t, t);
    std::cout << t std::endl;
}

int main()
{
    test();
}