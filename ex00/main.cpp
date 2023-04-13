/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:16:04 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/04 10:44:03 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <utility>
#include <string>

#include "BitcoinExchange.hpp"

int Error(std::string msg, int val)
{
	std::cout << "Error : " << msg << std::endl;
	return (val);
}

int checkData(double i, std::string &date, BitcoinExchange& btc)
{
	try
	{
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 7));
		int day = stoi(date.substr(8, 10));
		if (year < 2009 || month < 1 || day < 1)
			throw (BitcoinExchange::RandomBadInputException());
		if (month > 12 || day > 31)
			throw (BitcoinExchange::RandomBadInputException());
	}
	catch (std::exception)
	{
		std::cout << "Error : bad input => " << date << std::endl;
		btc.getData().erase(date);
		return (666);
	}
	if (i < 0)
		return Error("not a positive number.", 4);
	if (i > INT_MAX)
		return Error("too large number.", 3);
	return (0);
}

void	print(BitcoinExchange &btc, std::string& date, double i)
{
	static std::string replDate;

	if (btc.getData().count(date))
		replDate = date;
	else
	{
		replDate = btc.getData().begin()->first;
		for (std::map<std::string, double>::iterator it = btc.getData().begin(); it->first < date; it++)
			replDate = it->first;
	}
	double result = btc.getData().find(replDate)->second * i;
	std::cout << date << " => " << i << " = " << result << std::endl;
}

int getInput(BitcoinExchange& btc, std::string input)
{
	std::string line;
	std::fstream file(input);
	
	if (!file)
	{
		file.close();
		return (Error("can't open file", 6));
	}
	std::getline(file, line);
	if (line != "date | value")
	{
		file.close();
		return (Error("wrong input file", 5));
	}
	std::getline(file, line);
	while (!line.empty() && line.length())
	{
		try
		{
			int isLimiter = line.find("|");
			double i = std::stof(line.substr(isLimiter + 1));
			std::string date = line.substr(0, isLimiter);
			if (!checkData(i, date, btc))
			{
				if (isLimiter == - 1 || i > 1000)
					throw BitcoinExchange::RandomBadInputException();
				print(btc, date, i);
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
		std::getline(file, line);
	}
	file.close();
	return (0);
}

int getDataBase(BitcoinExchange& btc)
{
	std::string line;
	std::fstream file("data.csv");
	
	if (!file)
	{
		file.close();
		return (Error("can't open file", 1));
	}
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		file.close();
		return (Error("wrong database", 2));
	}
	std::getline(file, line);
	while (!line.empty() && line.length())
	{
		try
		{
			int isLimiter = line.find(",");
			double i = std::stof(line.substr(isLimiter + 1));
			std::string date = line.substr(0, isLimiter);
			if (!checkData(i, date, btc))
			{
				if (isLimiter == - 1)
					throw BitcoinExchange::RandomBadInputException();
				btc.getData().insert(std::pair<std::string, double>(date, i));
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
		std::getline(file, line);
	}
	file.close();
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return Error("usage : ./btc <input.txt>", 777);
	BitcoinExchange Btc;
	getDataBase(Btc);
	getInput(Btc, av[1]);

}
