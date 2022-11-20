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
#include "../inc/AForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
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

	/*
	 * ShrubberyCreationForm test
	 * must be signed by a bureaucrat of grade 145 or lower
	 * must be executed by a bureaucrat of grade 137 or lower
	 */
	std::cout << GREEN << "Should work" << NC << std::endl;
	try {
		ShrubberyCreationForm ShrubberyCreationForm1("home");
		std::cout << ShrubberyCreationForm1 << std::endl;
		ShrubberyCreationForm1.beSigned(Bureaucrat1);
		std::cout << ShrubberyCreationForm1 << std::endl;
		Bureaucrat1.executeForm(ShrubberyCreationForm1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, RED);

	/*
	 * Will throw an exception as the bureaucrat has a grade of 150
	 * and the form needs a grade of 137 or lower to be executed
	 */
	std::cout << RED << "Should not work" << NC << std::endl;
	try {
		Bureaucrat2.executeForm(ShrubberyCreationForm1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, GREEN);

	/*
	 * RobotomyRequestForm test
	 * must be signed by a bureaucrat of grade 72 or lower
	 * must be executed by a bureaucrat of grade 45 or lower
	 */
	std::cout << GREEN << "Should work and Robotomy success 50% of the time" << NC << std::endl;
	try {
		RobotomyRequestForm RobotomyRequestForm1("home-robot");
		std::cout << RobotomyRequestForm1 << std::endl;
		RobotomyRequestForm1.beSigned(Bureaucrat1);
		std::cout << RobotomyRequestForm1 << std::endl;
		tic_tac(500000, 1, GREY);
		Bureaucrat1.executeForm(RobotomyRequestForm1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, RED);

	/*
	 * Will not work because the bureaucrat has not the right grade
	 * to execute the form
	 */
	std::cout << RED << "Should not work" << NC << std::endl;
	try {
		Bureaucrat2.executeForm(RobotomyRequestForm1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, GREEN);
	/*
	 * PresidentialPardonForm test
	 * must be signed by a bureaucrat of grade 25 or lower
	 * must be executed by a bureaucrat of grade 5 or lower
	 */
	std::cout << GREEN << "Should work" << NC << std::endl;
	try {
		PresidentialPardonForm PresidentialPardonForm1("home-president");
		std::cout << PresidentialPardonForm1 << std::endl;
		PresidentialPardonForm1.beSigned(Bureaucrat1);
		std::cout << PresidentialPardonForm1 << std::endl;
		tic_tac(500000, 1, GREY);
		Bureaucrat1.executeForm(PresidentialPardonForm1);
	}   catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	tic_tac(500000, 2, RED);

	/*
	 * Will not work because the bureaucrat has not the right grade
	 * to execute the form
	 */
	std::cout << RED << "Should not work" << NC << std::endl;
	try {
		Bureaucrat2.executeForm(PresidentialPardonForm1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}