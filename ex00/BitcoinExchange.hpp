/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:52:58 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/04 10:20:14 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& cpy);

		std::map<std::string, double>& getData();
		void print();
		
		class RandomBadInputException : public std::exception{
		public:
			 const char *what() const throw(){ return "invalid or missing value";};
		};
	private:
		std::map<std::string, double> data;
};
