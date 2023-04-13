/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:55:49 by mmidon            #+#    #+#             */
/*   Updated: 2023/04/05 19:06:13 by mmidon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <chrono>


#include "PmergeMe.hpp"

void print(std::deque<int> deque)
{
	for (std::deque<int>::iterator i = deque.begin(); i != deque.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}


void print(std::vector<int> vector)
{
	for (std::vector<int>::iterator i = vector.begin(); i != vector.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void merge(std::deque<int>& deque, int beginning, int cut, int end)
{
	int n1 = cut - beginning + 1;
	int n2 = end - cut;

	int cpy1[n1], cpy2[n2];

	for (int i = 0; i < n1; i++)
		cpy1[i] = deque[beginning + i];
	for (int j = 0; j < n2; j++)
		cpy2[j] = deque[cut + 1 + j];
	
	int i = 0, j = 0, k = beginning;

	while (i < n1 && j < n2)
	{
		if (cpy1[i] <= cpy2[j])
		{
			deque[k] = cpy1[i];
			k++;
			i++;
		}
		else
		{
			deque[k] = cpy2[j];
			k++;
			j++;
		}
	}

	while (i < n1)
	{
		deque[k] = cpy1[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		deque[k] = cpy2[j];
		j++;
		k++;
	}
}

void mergeSort(std::deque<int>& deque, int beginning, int end)
{
	if (beginning >= end)
		return ;
	int cut = (beginning + end) / 2;
	mergeSort(deque, beginning, cut);
	mergeSort(deque, cut + 1, end);
	merge(deque, beginning, cut, end);
}

void fill(std::deque<int>& deque, char **str)
{
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			while (str[i][j] == ' ')
				j++;
			std::string nbr = str[i] + j;
			nbr = nbr.substr(0, nbr.find_first_of(' '));
			deque.push_back(std::stoi(nbr));
			j += nbr.size() - 1;
		}
	}
}

void merge(std::vector<int>& vector, int beginning, int cut, int end)
{
	int n1 = cut - beginning + 1;
	int n2 = end - cut;

	int cpy1[n1], cpy2[n2];

	for (int i = 0; i < n1; i++)
		cpy1[i] = vector[beginning + i];
	for (int j = 0; j < n2; j++)
		cpy2[j] = vector[cut + 1 + j];
	
	int i = 0, j = 0, k = beginning;

	while (i < n1 && j < n2)
	{
		if (cpy1[i] <= cpy2[j])
		{
			vector[k] = cpy1[i];
			k++;
			i++;
		}
		else
		{
			vector[k] = cpy2[j];
			k++;
			j++;
		}
	}

	while (i < n1)
	{
		vector[k] = cpy1[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vector[k] = cpy2[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int>& vector, int beginning, int end)
{
	if (beginning >= end)
		return ;
	int cut = (beginning + end) / 2;
	mergeSort(vector, beginning, cut);
	mergeSort(vector, cut + 1, end);
	merge(vector, beginning, cut, end);
}

int parse(char **str)
{
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			if (str[i][j] != ' ' && !std::isdigit(str[i][j]))
				return 1;
		}
	}
	return 0;
}


void fill(std::vector<int>& vector, char **str)
{
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; str[i][j]; j++)
		{
			while (str[i][j] == ' ')
				j++;
			std::string nbr = str[i] + j;
			nbr = nbr.substr(0, nbr.find_first_of(' '));
			vector.push_back(std::stoi(nbr));
			j += nbr.size() - 1;
		}
	}
}

int main(int ac, char **av)
{
	if (ac <= 1 || parse(av + 1))
	{
		std::cout << "Use : ./PmergeMe <positive integer sequence>" << std::endl;
		return 666;
	}


	std::vector<int>cpy;
	PmergeMe data;
	fill(cpy, av + 1);

	std::chrono::time_point<std::chrono::high_resolution_clock> startVector = std::chrono::high_resolution_clock::now();

	fill(data.getVector(), av + 1);
	mergeSort(data.getVector(), 0, data.getVector().size() - 1);

	std::chrono::time_point<std::chrono::high_resolution_clock> endVector = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds durationVector = std::chrono::duration_cast<std::chrono::microseconds>(endVector - startVector);

	std::chrono::time_point<std::chrono::high_resolution_clock> startDeque = std::chrono::high_resolution_clock::now();

	fill(data.getDeque(), av + 1);
	mergeSort(data.getDeque(), 0, data.getVector().size() - 1);

	std::chrono::time_point<std::chrono::high_resolution_clock> endDeque = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds durationDeque = std::chrono::duration_cast<std::chrono::microseconds>(endDeque - startDeque);

	std::cout << "Before : ";
	print(cpy);
	std::cout << "After [vector]: ";
	print(data.getVector());
	std::cout << "Time taken: " << durationVector.count() << " microseconds" << std::endl;
	std::cout << "After [deque] : ";
	print(data.getDeque());
	std::cout << "Time taken: " << durationDeque.count() << " microseconds" << std::endl;
}
