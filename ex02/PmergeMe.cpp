/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:18:48 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/29 19:04:20 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::PmergeMe(int argc)
{
	odd = argc % 2 == 0;
	j_indexes = jacobstahlIndexes((argc - 1 )/2);
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
		odd = rhs.odd;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static bool compareFirst(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.first < b.first;
}

std::vector<size_t> PmergeMe::jacobstahlIndexes(size_t size)
{
    std::vector<size_t> indexes;
    int arr[size];
    int lastNumber = 2;
    
    arr[0] = 0;
    arr[1] = 1;
    for (size_t i = 2; indexes.size() < size; i++)
    {
        arr[i] = arr[i - 1] + 2 * arr[i - 2];
        indexes.push_back(arr[i]);
        for (int j = arr[i] - 1; j > lastNumber; j--)
            indexes.push_back(j);
        lastNumber = arr[i];
    }
	for (size_t i = 0; i < indexes.size(); i++)
		indexes[i] -= 1;
    return indexes;
}

void PmergeMe::sortDeque(int argc, char **argv)
{
	std::deque<std::pair<int, int> > dq;
	std::deque<int> as;

	if (odd) argc -= 1;
	std::clock_t start = std::clock();
	for (int i = 1; i < argc; i += 2)
		dq.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	for (size_t i = 0; i< dq.size(); i++)
	{
		if (dq[i].first < dq[i].second)
			std::swap(dq[i].first, dq[i].second);
	}
	std::sort(dq.begin(), dq.end(), compareFirst);
	for (size_t i = 0; i < dq.size(); i++)
		as.push_back(dq[i].first);
	for (size_t i = 0; i < j_indexes.size(); i++)
	{
		if (j_indexes[i] < dq.size())
			as.insert(std::lower_bound(as.begin(), as.end(), dq[j_indexes[i]].second), dq[j_indexes[i]].second);
	}
	if (odd)
		as.insert(std::lower_bound(as.begin(), as.end(), std::atoi(argv[argc])), std::atoi(argv[argc])); 
	std::clock_t end = std::clock();
	std::cout << "Time to process a range of " << as.size() << " elements with std::deque : " << static_cast<double>(end - start)/CLOCKS_PER_SEC << " us" << std::endl;
}

void PmergeMe::sortVector(int argc, char **argv)
{
	std::vector<std::pair<int, int> > vec;
	std::vector<int> as;

	if (odd) argc -= 1;
	std::clock_t start = std::clock();
	for (int i = 1; i < argc; i += 2)
		vec.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	for(size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].first < vec[i].second)
			std::swap(vec[i].first, vec[i].second);
	}
    std::sort(vec.begin(), vec.end(), compareFirst);
	for (size_t i = 0; i < vec.size(); i++)
		as.push_back(vec[i].first);
	for (size_t i = 0; i < j_indexes.size(); i++)
	{
		if (j_indexes[i] < vec.size())
			as.insert(std::lower_bound(as.begin(), as.end(), vec[j_indexes[i]].second), vec[j_indexes[i]].second);
	}
	if (odd)
		as.insert(std::lower_bound(as.begin(), as.end(), std::atoi(argv[argc])), std::atoi(argv[argc]));
	std::clock_t end = std::clock();
	std::cout << "After: ";
	for(size_t i = 0; i < as.size(); i++)
		std::cout << as[i] << " ";
	
	std::cout << std::endl;
	std::cout << "Time to process a range of " << as.size() << " elements with std::vector : " << std::fixed << static_cast<double>(end - start)/CLOCKS_PER_SEC << " us" << std::endl;
		
}

bool validArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string s(argv[i]);
		for (size_t i = 0; i < s.length(); i++)
		{
			if (!isdigit(s.at(i)))
				return false;
		}
	}
	return true;
}

bool isSorted(int argc, char **argv)
{
	if (argc == 2) 
		return true;
	return std::string(argv[argc - 1]) >= std::string(argv[argc - 2]) && isSorted(argc - 1, argv);
}