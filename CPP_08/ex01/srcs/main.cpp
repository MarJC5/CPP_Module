/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:57 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:58 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define CYAN	"\033[1;36m"
# define GREY   "\033[1;37m"
# define NC     "\033[0m"

int main(void)
{
	{
		std::cout << CYAN << "---------------------------------" << std::endl;
		std::cout << "void\taddNumber(int n);" << std::endl;
		std::cout << "---------------------------------" << NC << std::endl;
		Span sp = Span(0);

		try {
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		sp = Span(1);

		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Span[ " << sp << " ]" << std::endl;

		/*
		 * why 2 & 14 ? because 3 & 11 are the closest numbers in the vector
		 * and 2 & 14 are the closest numbers in the vector after the sort
		 * (the vector is sorted in the shortestSpan function)
		 */
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;

		std::cout << std::endl;

		try {
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << ORANGE << "---------------------------------" << std::endl;
		std::cout << "void\taddNumber(begin, end);" << std::endl;
		std::cout << "---------------------------------" << NC << std::endl;

		Span sp = Span(5);
		std::vector<int> v;

		std::cout << "vector[ ";
		for (int i = 0; i < 5; i++) {
			v.push_back(rand() % 42);
			std::cout << v[i];
			if (i < 4)
				std::cout << ", ";
		}
		std::cout << " ]" << std::endl;

		try {
			sp.addNumber(v.begin(), v.end());
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}