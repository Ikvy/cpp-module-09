/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:20:02 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/04 19:45:23 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<stack>
#include <exception>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& vpy);
		RPN& operator=(const RPN& cpy);

		std::stack<double>& getStack();

		class bebouException : public std::exception{
		public:
			 const char *what() const throw(){ return "unknown symbol";};
		};

		class notEnoughException : public std::exception{
		public:
			 const char *what() const throw(){ return "invalid input";};
		};

		class invalidOperationException : public std::exception{
		public:
			 const char *what() const throw(){ return "invalid operation";};
		};
	private:
		std::stack<double> stack;
};
