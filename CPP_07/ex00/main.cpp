/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:07 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:08 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <unistd.h>

# define GREEN	"\033[1;32m"
# define RED 	"\033[1;31m"
# define ORANGE	"\033[1;33m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GREY   "\033[1;37m"
# define NC     "\033[0m"

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << " " << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void){
	{
		tic_tac(100000, 1, ORANGE);
		std::string a = "chaine1";
		std::string b = "chaine2";

		std::cout << ORANGE << "====== STRING TEMPLATES TEST ======" << NC << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, ORANGE);
		std::cout << ORANGE << "=== SWAP ===" << NC << std::endl;
		std::cout << "Before swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << std::endl;
		::swap<std::string>(a, b);
		std::cout << "After swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, ORANGE);
		std::cout << ORANGE << "=== MAX ===" << NC << std::endl;
		std::cout << "::max<std::string>( a, b ) = "
		          << ::max<std::string>(a, b)
		          << std::endl;

		tic_tac(100000, 1, ORANGE);
		std::cout << ORANGE << "=== MIN ===" << NC << std::endl;
		std::cout << "::min<std::string>( a, b ) = "
		          << ::min<std::string>(a, b)
		          << std::endl;
	}
	{
		tic_tac(100000, 1, GREEN);
		int a = 2;
		int b = 3;

		std::cout << GREEN << "====== INT TEMPLATES TEST ======" << NC << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, GREEN);
		std::cout << GREEN << "=== SWAP ===" << NC << std::endl;
		std::cout << "Before swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << std::endl;
		::swap<int>(a, b);
		std::cout << "After swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, GREEN);
		std::cout << GREEN << "=== MAX ===" << NC << std::endl;
		std::cout << "::max<int>( a, b ) = "
		          << ::max<int>(a, b)
		          << std::endl;

		tic_tac(100000, 1, GREEN);
		std::cout << GREEN << "=== MIN ===" << NC << std::endl;
		std::cout << "::min<int>( a, b ) = "
		          << ::min<int>(a, b)
		          << std::endl;
	}
	{
		tic_tac(100000, 1, CYAN);
		float a = 2.2f;
		float b = 3.3f;

		std::cout << CYAN << "====== FLOAT TEMPLATES TEST ======" << NC << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, CYAN);
		std::cout << CYAN << "=== SWAP ===" << NC << std::endl;
		std::cout << "Before swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << std::endl;
		::swap<float>(a, b);
		std::cout << "After swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, CYAN);
		std::cout << CYAN << "=== MAX ===" << NC << std::endl;
		std::cout << "::max<float>( a, b ) = "
		          << ::max<float>(a, b)
		          << std::endl;

		tic_tac(100000, 1, CYAN);
		std::cout << CYAN << "=== MIN ===" << NC << std::endl;
		std::cout << "::min<float>( a, b ) = "
		          << ::min<float>(a, b)
		          << std::endl;
	}
	{
		tic_tac(100000, 1, RED);
		double a = 2.2;
		double b = 3.3;

		std::cout << RED << "====== DOUBLE TEMPLATES TEST ======" << NC << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, RED);
		std::cout << RED << "=== SWAP ===" << NC << std::endl;
		std::cout << "Before swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << std::endl;
		::swap<double>(a, b);
		std::cout << "After swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, RED);
		std::cout << RED << "=== MAX ===" << NC << std::endl;
		std::cout << "::max<double>( a, b ) = "
		          << ::max<double>(a, b)
		          << std::endl;

		tic_tac(100000, 1, RED);
		std::cout << RED << "=== MIN ===" << NC << std::endl;
		std::cout << "::min<double>( a, b ) = "
		          << ::min<double>(a, b)
		          << std::endl;
	}
	{
		tic_tac(100000, 1, PURPLE);
		char a = 'a';
		char b = 'b';

		std::cout << PURPLE << "====== CHAR TEMPLATES TEST ======" << NC << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, PURPLE);
		std::cout << PURPLE << "=== SWAP ===" << NC << std::endl;
		std::cout << "Before swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << std::endl;
		::swap<char>(a, b);
		std::cout << "After swap(a, b):" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		tic_tac(100000, 1, PURPLE);
		std::cout << PURPLE << "=== MAX ===" << NC << std::endl;
		std::cout << "::max<char>( a, b ) = "
		          << ::max<char>(a, b)
		          << std::endl;

		tic_tac(100000, 1, PURPLE);
		std::cout << PURPLE << "=== MIN ===" << NC << std::endl;
		std::cout << "::min<char>( a, b ) = "
		          << ::min<char>(a, b)
		          << std::endl;
	}
	return (0);
}