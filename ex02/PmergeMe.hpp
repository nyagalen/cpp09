/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:18:58 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/29 18:58:36 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe
{
private:
    PmergeMe(/* args */);
    bool odd;
    std::vector<size_t> j_indexes;
    std::vector<size_t> jacobstahlIndexes(size_t size);
    
public:
    
    PmergeMe(int argc);
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();
    void sortVector(char **argv);
    void sortDeque(int argc, char **argv);
    void sortVector(int argc, char **argv);
    
};

bool validArgs(int argc, char **argv);
bool isSorted(int argc, char **argv);

