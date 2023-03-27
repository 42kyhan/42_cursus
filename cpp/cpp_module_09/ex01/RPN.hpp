#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
private:
    std::stack<double> rpn;
public:
    RPN() { return; }
    ~RPN() {}
    RPN& operator=(RPN const &obj) {
        if (this != &obj) {
            this->rpn = obj.rpn;
        }
        return (*this);
    }
    RPN(RPN const &obj) {
        *this = obj;
    }

    void calculate(std::string numbers) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == ' ')
                continue;
            else if (isdigit(numbers[i]))
                this->rpn.push(numbers[i] - '0');
            else if (numbers[i] == '+' && this->rpn.size() >= 2) {
                double b = this->rpn.top();
                this->rpn.pop();
                double a = this->rpn.top();
                this->rpn.pop();
                this->rpn.push(a + b);
            }
            else if (numbers[i] == '-' && this->rpn.size() >= 2) {
                double b = this->rpn.top();
                this->rpn.pop();
                double a = this->rpn.top();
                this->rpn.pop();
                this->rpn.push(a - b);
            }
            else if (numbers[i] == '*' && this->rpn.size() >= 2) {
                double b = this->rpn.top();
                this->rpn.pop();
                double a = this->rpn.top();
                this->rpn.pop();
                this->rpn.push(a * b);
            }
            else if (numbers[i] == '/' && this->rpn.size() >= 2) {
                double b = this->rpn.top();
                this->rpn.pop();
                double a = this->rpn.top();
                this->rpn.pop();
                if (!b) {
                    std::cerr << "DO NOT divide by ZERO" << std::endl;
                    return ;
                }
                this->rpn.push(a / b);
            }
            else {
                std::cerr << "Error" << std::endl;
                return ;
            }
        }
        if (this->rpn.size() == 1) {
            double result = this->rpn.top();
            this->rpn.pop();
            std::cout << result << std::endl;
        }
        else {
            std::cerr << "Error" << std::endl;
        }
    }
};

#endif