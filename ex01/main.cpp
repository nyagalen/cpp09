/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:24:02 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:29 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (1);
    }
    RPN rpn;
    try
    {
        if (rpn.handleExpression(argv[1]) == -1)
            return (1);
        while  (!rpn.handleExpression(argv[1]));
        std::cout << rpn.getStack().top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return (0);
}