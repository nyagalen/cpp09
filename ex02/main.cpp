/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:18:17 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/26 23:07:56 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Please enter some arguments" << std::endl;
        return (1);
    }
    if (!validArgs(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if (isSorted(argc, argv)) 
    {
        std::cout << "It's already sorted" << std::endl;
        return (0);
    }
    PmergeMe pm(argc);
    std::cout << "Before: ";
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
    pm.sortVector(argc, argv);
    pm.sortDeque(argc, argv);
    return (0);
}
