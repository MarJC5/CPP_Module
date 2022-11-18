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

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << "." << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void) {
	Fixed a;
	tic_tac(500000, 1, GREEN);
	Fixed b(a);
	tic_tac(500000, 1, GREEN);
	Fixed c;
	tic_tac(500000, 2, NC);

	c = b;
	std::cout << "a = "
				<< RED
				<< a.getRawBits()
				<< NC
				<< std::endl;
	tic_tac(500000, 1, RED);
	std::cout << "b = "
				<< CYAN
				<< b.getRawBits()
				<< NC
				<< std::endl;
	tic_tac(500000, 1, CYAN);
	std::cout << "c = "
				<< GREEN
				<< c.getRawBits()
				<< NC
				<< std::endl;
	tic_tac(500000, 1, GREEN);

	return (0);
}