#include <string>
#include <memory>

class Expr 
{
private:
    std::string value;
    std::unique_ptr<Expr> left_expr;
    std::unique_ptr<Expr> right_expr;

};