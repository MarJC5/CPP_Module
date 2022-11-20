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
		tic_tac(500000, 1, GREEN);
		Fixed b(a);
		tic_tac(500000, 1, GREEN);
		Fixed c;
		tic_tac(500000, 2, GREEN);

		c = b;
		std::cout << "a = " << a.getRawBits() << std::endl;
		tic_tac(500000, 1, GREEN);
		std::cout << "b = " << b.getRawBits() << std::endl;
		tic_tac(500000, 1, GREEN);
		std::cout << "c = " << c.getRawBits() << std::endl;
		tic_tac(500000, 1, GREEN);
	}
	{
		tic_tac(500000, 5, NC);
		Fixed a;
		tic_tac(500000, 1, RED);
		Fixed const b(10); // value = 10 * 2^8 = 2560
		tic_tac(500000, 1, RED);
		Fixed const c(42.42f); // value = 42.42 * 2^8 = 10923.328 = 10923
		tic_tac(500000, 1, RED);
		Fixed const d(b);
		tic_tac(500000, 1, RED);

		/*
		 * Use the assignation operator to assign
		 * a new value to the Fixed point number
		 */
		a = Fixed(1234.4321f); // value = 1234.4321 * 2^8 = 318906.88 = 318906
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
		tic_tac(500000, 5, NC);
		Fixed const a(42); // value = 42 * 2^8 = 10752
		tic_tac(500000, 1, CYAN);
		Fixed const b(10); // value = 10 * 2^8 = 2560
		tic_tac(500000, 2, CYAN);

		std::cout << "a is "
					<< a << " and is "
					<< CYAN
					<< a.toFloat()
					<< NC
					<< " as float." << std::endl;
		tic_tac(500000, 1, CYAN);
		std::cout << "b is "
					<< b << " and is "
					<< CYAN
					<< b.toFloat()
					<< NC
					<< " as float." << std::endl;
		tic_tac(500000, 1, CYAN);
	}
	return (0);
}