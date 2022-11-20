/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:22:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <unistd.h>

static void	tic_tac(int usleep_time, int duration, std::string color)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << color << "↓" << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	Bureaucrat Bureaucrat1("Jonathan", 1);
	try {
		std::cout << Bureaucrat1 << std::endl;
		tic_tac(500000, 2, RED);
		std::cout << RED << "Error: Incremente Grade" << NC << std::endl;
		Bureaucrat1.incrementGrade(); // Should throw an exception as grade is already 1 (highest possible)
		std::cout << Bureaucrat1 << std::endl;
		tic_tac(500000, 2, GREEN);
		std::cout << GREEN << "Success: Decremente Grade" << NC << std::endl;
		Bureaucrat1.decrementGrade(); // Should work
		std::cout << Bureaucrat1 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, GREEN);

	Bureaucrat Bureaucrat2("Joseph", 150);
	try {
		std::cout << Bureaucrat2 << std::endl;
		tic_tac(500000, 2, RED);
		std::cout << RED << "Error: Decremente Grad" << NC << std::endl;
		Bureaucrat2.decrementGrade(); // Should throw an exception as grade is already 150 (lowest possible)
		std::cout << Bureaucrat2 << std::endl;
		tic_tac(500000, 2, GREEN);
		std::cout << GREEN << "Success: Incremente Grade" << NC << std::endl;
		Bureaucrat2.incrementGrade(); // Should work
		std::cout << Bureaucrat2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}