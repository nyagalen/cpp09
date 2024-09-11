/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:00:42 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/20 02:47:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <cfloat>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float> database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();
		std::map<std::string, float> getDatabase();
		void fillMap();
		float getRateForDate(std::string date);
	
	
};

float ft_strtof(std::string line, size_t pos);
void handle_input(char* input_file, BitcoinExchange be);