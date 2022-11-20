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
#include "../inc/Form.hpp"
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
	std::cout << Bureaucrat1 << std::endl;
	tic_tac(500000, 2, GREEN);

	Bureaucrat Bureaucrat2("Joseph", 150);
	std::cout << Bureaucrat2 << std::endl;
	tic_tac(500000, 2, GREEN);

	std::cout << GREEN << "Should work" << NC << std::endl;
	try {
		Form Form1("Phantom Blood", 1, 1);
		std::cout << Form1 << std::endl;
		Form1.beSigned(Bureaucrat1); // Should work
		std::cout << Form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, GREEN);

	std::cout << GREEN << "Should work" << NC << std::endl;
	try {
		Form Form2("Battle Tendency", 150, 150); // Both grade are correct
		std::cout << Form2 << std::endl;
		Form2.beSigned(Bureaucrat1);
		std::cout << Form2 << std::endl;
		Form2.beSigned(Bureaucrat2);
		std::cout << Form2 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, RED);

	std::cout << RED << "Should throw two exception" << NC << std::endl;
	try {
		Form Form3("Stardust Crusaders", 0, 0); // Both grade are incorrect (0 is too high)
		std::cout << Form3 << std::endl;
		Form3.beSigned(Bureaucrat2); // Should throw an exception as it is out of range
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	tic_tac(500000, 2, RED);

	std::cout << RED << "Should throw an exception" << NC << std::endl;
	try {
		Form Form4("Diamond is Unbreakable", 151, 151);
		std::cout << Form4 << std::endl;
		Form4.beSigned(Bureaucrat1); // Should throw an exception as it is out of range
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	tic_tac(500000, 2, GREEN);
	return (0);
}