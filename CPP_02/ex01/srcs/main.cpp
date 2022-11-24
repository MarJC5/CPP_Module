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
		std::cout << color << "↓" << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void) {
	{
		Fixed a;
		Fixed const b(10.10f); // value = 10 * 2^8
		Fixed const c(42.42f); // value = 42.42 * 2^8
		Fixed const d(b);

		/*
		 * Use the assignation operator to assign
		 * a new value to the Fixed point number
		 */
		a = Fixed(1234.4321f); // value = 1234.4321 * 2^8
		std::cout << RED << "Fixed int" << NC << std::endl;
		tic_tac(500000, 2, RED);

		std::cout << "a is "
					<< a << " and is "
					<< RED
					<< a.toInt()
					<< NC
					<< " as int." << std::endl;
		tic_tac(500000, 1, RED);
		std::cout << "b is "
					<< b << " and is "
					<< RED
					<< b.toInt()
					<< NC
					<< " as int." << std::endl;
		tic_tac(500000, 1, RED);
		std::cout << "c is "
					<< c << " and is "
					<< RED
					<< c.toInt()
					<< NC
					<< " as int." << std::endl;
		tic_tac(500000, 1, RED);
		std::cout << "d is "
					<< d << " and is "
					<< RED
					<< d.toInt()
					<< NC
					<< " as int." << std::endl;
		tic_tac(500000, 1, RED);
	}
	{
		tic_tac(500000, 2, NC);
		Fixed const a(42.42f); // value = 42 * 2^8
		Fixed const b(10.10f); // value = 10 * 2^8

		std::cout << CYAN << "Fixed float" << NC << std::endl;
		tic_tac(500000, 2, CYAN);

		std::cout << "a is "
					<< a << " and is "
					<< CYAN
					<< a.toFloat()
					<< NC
					<< " as float." << std::endl;
		tic_tac(500000, 1, CYAN);
		std::cout << "b raw is "
					<< b << " and is "
					<< CYAN
					<< b.toFloat()
					<< NC
					<< " as float." << std::endl;
		tic_tac(500000, 1, CYAN);
	}
	return (0);
}