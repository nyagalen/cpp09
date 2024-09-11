/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:00:57 by svydrina          #+#    #+#             */
/*   Updated: 2024/08/27 20:18:35 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {fillMap();}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    this->database = rhs.database;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

std::map<std::string, float> BitcoinExchange::getDatabase()
{
    return this->database;
}

static bool validDayOfMonth(int year, int month, int day)
{
    if (day > 31)
        return false;
    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2 && ((year % 4 == 0 && day > 29) || day > 28)) 
        return false;
    return true;
}

static bool validMonth(int month)
{
    return month <= 12;
}

static bool validYear(int year)
{
    return year >= 2009 && year <= 2022;
}

void BitcoinExchange::fillMap()
{
    std::string line;
    std::ifstream db_stream("data.csv");
    if (db_stream.fail())
    {
        std::cout << "Failed reading database" << std::endl;
        exit(1);
    }
    std::getline(db_stream, line);
    while(std::getline(db_stream, line))
        this->database[line.substr(0, 10)] = ft_strtof(line, 10);
    db_stream.close();
}

float BitcoinExchange::getRateForDate(std::string date)
{
    if (this->database.find(date) != database.end())
        return this->database.at(date);
    return (--this->database.lower_bound(date))->second;
}

static bool validDate(std::string date)
{
    std::string::size_type start = 0;
    std::string::size_type end;
    int i = 0;
    int year, month;
    while ((end = date.find('-', start)) != std::string::npos)
    {
        int value = std::atoi(date.substr(start, end - start).c_str());
        switch (i)
        {
        case 0:
            year = value;
            if (!validYear(value))
            {
                std::cerr << "Error: invalid year => "<< value << std::endl;
                return false;
            }
            break;
        case 1:
            month = value;
            if (!validMonth(value))
            {
                std::cerr << "Error: invalid month => " << value << std::endl;
                return false;
            }
            break;
        case 2:
            if (!validDayOfMonth(year, month, value))
            {
                std::cerr << "Error: invalid day of month => " << value << std::endl;
                return false;
            }
            break;
        default:
            std::cerr << "Error: it's not even a date => " << date << std::endl;
            return false;
            break;
        }
        i++;
        start = end+1;
    }
    return true;
}

static bool validDateAmount(std::string date, std::string amount)
{
    float amountF = ft_strtof(amount, 0);
    if (amountF < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (amountF > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return validDate(date);
}

static bool validLine(std::string line)
{
    if (line.length() < 14)
        return false;
    int digits[] = {0, 1, 2, 3, 5, 6, 8, 9};
    for (size_t i = 0; i < sizeof(digits)/sizeof(digits[0]); i++)
    {
        if (!std::isdigit(line.at(digits[i])))
            return false;
    }
    return line.at(11) == '|' && line.at(4) == '-' && line.at(7) == '-'
        && line.at(10) == ' ' && line.at(12) == ' ';
}

void handle_input(char* input_file, BitcoinExchange be)
{
    std::string line;
    std::ifstream input_stream(input_file, std::ifstream::in);
    std::getline(input_stream, line);
    while (std::getline(input_stream, line))
    {
        if (!validLine(line)) //line.length() < 14 || line.at(11) != '|'
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, 10);
        float rate = be.getRateForDate(date);
        std::string amount = line.substr(12);
        if (validDateAmount(date, amount))
            std::cout << line.substr(0, 10) << " =>" << amount << " = " << std::setprecision(2) << ft_strtof(amount, 0) * rate << std::endl;
    }
    input_stream.close();
}

float ft_strtof(std::string line, size_t pos)
{
    char* end;
    return std::strtof(line.substr(pos + 1).c_str(), &end);
}



