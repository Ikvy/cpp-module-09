/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:25:07 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/04 19:32:59 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

RPN::RPN()
{
	return ;
}

RPN::~RPN()
{
	return ;
}

RPN::RPN(const RPN& cpy)
{
	this->stack = cpy.stack;
}

RPN& RPN::operator=(const RPN& cpy)
{
	this->stack = cpy.stack;
	return (*this);
}

std::stack<double>& RPN::getStack()
{
	return this->stack;
}
