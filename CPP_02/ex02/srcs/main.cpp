/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:19:40 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:19:41 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <unistd.h>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << "." << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void) {
	{
		Fixed const a(42);
		Fixed const b(21);
		Fixed c;

		std::cout << "a = "
					<< a
					<< std::endl;
		tic_tac(500000, 1, NC);
		std::cout << "b = "
					<< b
					<< std::endl;
		tic_tac(500000, 5, NC);

		// Greater than
		std::cout << "a > b ? "
					<< GREEN
					<< (a > b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);
		// Less than
		std::cout << "a < b ? "
					<< GREEN
					<< (a < b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);
		// Greater or equal
		std::cout << "a >= b ? "
					<< GREEN
					<< (a >= b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);
		// Less or equal
		std::cout << "a <= b ? "
					<< GREEN
					<< (a <= b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);
		// Equal
		std::cout << "a == b ? "
					<< GREEN
					<< (a == b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);
		// Not equal
		std::cout << "a != b ? "
					<< GREEN
					<< (a != b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, GREEN);

		// Addition
		std::cout << "a + b = "
					<< RED
					<< a + b
					<< NC
					<< std::endl;
		tic_tac(500000, 1, RED);
		// Substraction
		std::cout << "a - b = "
					<< RED
					<< a - b
					<< NC
					<< std::endl;
		tic_tac(500000, 1, RED);
		// Multiplication
		std::cout << "a * b = "
					<< RED
					<< a * b
					<< NC
					<< std::endl;
		tic_tac(500000, 1, RED);
		// Division
		std::cout << "a / b = "
					<< RED
					<< a / b
					<< NC
					<< std::endl;
		tic_tac(500000, 1, RED);

		/*
		 * why this increment value is + 0.00390625 and not 1 ?
		 * because we have 8 bits for the fractional part and 8 bits for the integer part
		 * so 2^8 = 256  1/256 = 0.00390625
		 * we increment/decrement by 1/256 each time we call the operator ++ or --
		 */

		// Increment
		std::cout << "c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		++c;
		std::cout << "++c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		tic_tac(500000, 1, ORANGE);
		std::cout << "c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		c++;
		std::cout << "c++ = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		tic_tac(500000, 1, ORANGE);
		// Decrement
		std::cout << "c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		--c;
		std::cout << "--c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		tic_tac(500000, 1, ORANGE);
		std::cout << "c = "
		          << ORANGE
		          << c
		          << NC
		          << std::endl;
		c--;
		std::cout << "c-- = "
					<< ORANGE
					<< c
					<< NC
					<< std::endl;
		tic_tac(500000, 1, ORANGE);

		// Max
		std::cout << "max(a, b) = "
					<< CYAN
					<< Fixed::max(a, b)
					<< NC
					<< std::endl;
		tic_tac(500000, 1, CYAN);
		// Min
		std::cout << "min(a, b) = "
					<< CYAN
					<< Fixed::min(a, b)
					<< NC
					<< std::endl;
	}
	return (0);
}