/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:10:31 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/05 18:37:21 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
	this->dequeStock = cpy.dequeStock;
	this->vectorStock = cpy.vectorStock;
}

PmergeMe::~PmergeMe()
{
	return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cpy)
{
	this->dequeStock = cpy.dequeStock;
	this->vectorStock = cpy.vectorStock;
	return (*this);
}

std::vector<int>& PmergeMe::getVector()
{
	return (this->vectorStock);
}

std::deque<int>& PmergeMe::getDeque()
{
	return (this->dequeStock);
}
