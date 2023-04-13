/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:58:25 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/03 10:49:58 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	*this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
	this->data = cpy.data;
	return (*this);
}

std::map<std::string, double>& BitcoinExchange::getData()
{
	return data;
}

void BitcoinExchange::print()
{
	for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
		std::cout << it->first << " --- " << it->second << std::endl;
}
