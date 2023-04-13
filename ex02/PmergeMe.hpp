/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:00:35 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/05 18:37:03 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(const PmergeMe& cpy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& cpy);

		std::vector<int>& getVector();
		std::deque<int>& getDeque();

	private:
		std::vector<int> vectorStock;
		std::deque<int> dequeStock;
};
