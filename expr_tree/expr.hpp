#pragma once

#include <string>
#include <memory>
#include <iostream>

class ExprBase
{
public:
    virtual ~ExprBase() = default;
    virtual void print(std::ostream& os) const = 0;
};

class OpExpr : public ExprBase
{
private:
    std::string _op_name;

    // children of OpExpr can be either Op or Num
    std::unique_ptr<ExprBase> _left_expr;
    std::unique_ptr<ExprBase> _right_expr;

public:
    OpExpr(std::string op_name, std::unique_ptr<ExprBase> left_expr, std::unique_ptr<ExprBase> right_expr) 
        : _op_name(op_name),
          _left_expr(std::move(left_expr)),
          _right_expr(std::move(right_expr))
          {}
        
    void print(std::ostream& os) const override;

};

class NumExpr : public ExprBase
{
private:
    int _value;

    // Num is definitely a leaf

public:
    NumExpr(int value) : _value(value) {}
    void print(std::ostream& os) const override;
};


// wrapper class, exposed to user
class Expr
{
private:
    std::unique_ptr<ExprBase> _expr;

public:
    Expr(int val) : _expr(std::make_unique<NumExpr>(val)) {}
    Expr(std::string op_name, int value); // unary 
    Expr(std::string op_name, int value_1, int value_2);  // binary
    Expr(std::string op_name, Expr&& expr_left, Expr&& expr_right);
    Expr(Expr&& other);
    Expr(Expr& other) = delete;

    friend std::ostream& operator<< (std::ostream& os, const Expr& expr);
};


std::ostream& operator<< (std::ostream& os, const ExprBase& expr);
