/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:24:29 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/20 16:09:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <stdlib.h>

#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class RPN
{
private:
    std::stack<int> nums;
public:
    RPN(/* args */);
    RPN(const RPN& rhs);
    RPN& operator=(const RPN& rhs);
    ~RPN();
    std::stack<int> getStack();
    int handleExpression(char* expression);
    int calculate(int a, int b, char sign);
    
    class DivisionByZeroException : public std::exception
    {
        virtual const char* what() const throw() {return RED "Division by zero" RESET;}
    };
};




