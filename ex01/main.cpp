/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:31:28 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/04 19:45:52 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <cctype>

int whichOp(char c)
{
	if (c == '+')
		return 1;
	else if (c == '-')
		return 2;
	else if (c == '*')
		return 3;
	else if (c == '/')
		return 4;
	return -1;
}

void print(RPN data)
{
	if (data.getStack().size() == 0)
		return ;
	double i = data.getStack().top();
	data.getStack().pop();
	print(data);
	std::cout << i << std::endl;
}

void operation(RPN& data, char op)
{
	double i = data.getStack().top();
	data.getStack().pop();
	double j = data.getStack().top();
	data.getStack().pop();
	int type = whichOp(op);

	if (type == 1)
		data.getStack().push(i + j);
	else if (type == 2)
		data.getStack().push(j - i);
	else if (type == 3)
		data.getStack().push(i * j);
	else if (type == 4)
	{
		if (i == 0)
			throw RPN::invalidOperationException();
		data.getStack().push(j / i);
	}
	else
		throw RPN::bebouException();
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Use : ./RPN <\"operation\">" << std::endl;
		return 666;
	}

	RPN	data;
	std::string line = av[1];

	for (size_t i = 0; i != line.length(); i++)
	{
		if (std::isspace(line[i]))
			continue ;
		else if (std::isdigit(line[i]))
		{
			int nbr = line[i] - '0';
			data.getStack().push(nbr);
		}
		else if (whichOp(line[i]))
		{
			try
			{
				if (data.getStack().size() < 2)
					throw RPN::notEnoughException();
				operation(data, line[i]);
			}
			catch (std::exception &e)
			{
				std::cout << "Exception caught : " << e.what() << std::endl;
				return -666;
			}
		}
	}
	print(data);
}


