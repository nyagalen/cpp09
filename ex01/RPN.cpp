/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:24:20 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/28 22:14:09 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::RPN(const RPN& rhs)
{
    *this = rhs;
}

RPN& RPN::operator=(const RPN& rhs)
{
    this->nums = rhs.nums;
    return *this;
}

RPN::~RPN()
{
}

std::stack<int> RPN::getStack()
{
    return this->nums;
}

static bool isSign(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*';
}

static bool validChar(char c)
{
    return isSign(c) || c == ' ' || isdigit(c);
}

static bool numSignCount(char* expression)
{
    int signs = 0;
    int nums = 0;
    while (*expression)
    {
        if(isSign(*expression)) signs++;
        else if (isdigit(*expression)) nums++;
        expression++;
    }
    return nums == signs + 1;
}

static bool valid(char* expression)
{
    int i = 0;
    if (!isdigit(expression[i])) return false;
    while (expression[i])
    {
        if (!validChar(expression[i])) return false;
        if (i % 2 == 1 && expression[i] != ' ') return false;
        if (i % 2 == 0 && !(isdigit(expression[i]) || isSign(expression[i]))) return false;
        i++;
    }
    if (!isSign(expression[i - 1])) return false;
    if (!numSignCount(expression))
    {
        std::cerr << "The expression is poorly written" << std::endl;
        return false;
    }
    return true;
}

int RPN::calculate(int a, int b, char sign)
{
    switch (sign)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b == 0)
            throw DivisionByZeroException();    
        return a / b;
        break;
    default:
        break;
    }
    return 0;
}

int RPN::handleExpression(char* expression)
{
    if (!valid(expression))
    {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    static size_t i = 0;
    std::string exp_str(expression);

    while (i < exp_str.length())
    {
        if (isdigit(exp_str.at(i)))
        {
            nums.push(exp_str.at(i) - 48);
            i++;
        } 
        else if (isSign(exp_str.at(i)))
        {
            if (nums.size() >= 2)
            {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                nums.push(calculate(a, b, exp_str.at(i)));
            }
            else
            {
                std::cerr << "This expression sucks, try a better one" << std::endl;
                exit(1);
            }
            return ++i == exp_str.length();
        }
        i++;
    }
    return true;
}
