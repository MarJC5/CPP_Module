/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:42 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/25 10:38:19 by jmartin          ###   ########.fr       */
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
		std::cout << color << " " << NC << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	Bureaucrat Bureaucrat1("Jonathan", 1);
	std::cout << Bureaucrat1 << std::endl;
	Bureaucrat Bureaucrat2("Joseph", 150);
	std::cout << Bureaucrat2 << std::endl;
	tic_tac(500000, 2, GREEN);

	/*
	 * ShrubberyCreationForm test
	 * must be signed by a bureaucrat of grade 145 or lower
	 * must be executed by a bureaucrat of grade 137 or lower
	 */
	{
		try {
			ShrubberyCreationForm ShrubberyCreationForm1("home");
			std::cout << ShrubberyCreationForm1 << std::endl;
			tic_tac(500000, 1, GREEN);
			
			try {
				std::cout << GREEN << "Should work" << NC << std::endl;
				tic_tac(500000, 1, GREEN);
				
				Bureaucrat1.signForm(ShrubberyCreationForm1);
				tic_tac(500000, 1, GREEN);

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
			try {
				std::cout << RED << "Should not work" << NC << std::endl;
				tic_tac(500000, 1, RED);
				
				Bureaucrat2.executeForm(ShrubberyCreationForm1);
				tic_tac(500000, 1, RED);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	/*
	 * RobotomyRequestForm test
	 * must be signed by a bureaucrat of grade 72 or lower
	 * must be executed by a bureaucrat of grade 45 or lower
	 */
	{
		try {
			RobotomyRequestForm RobotomyRequestForm1("robot");
			std::cout << RobotomyRequestForm1 << std::endl;
			tic_tac(500000, 1, GREEN);
			
			try {
				std::cout << GREEN << "Should work" << NC << std::endl;
				tic_tac(500000, 1, GREEN);
				
				Bureaucrat1.signForm(RobotomyRequestForm1);
				tic_tac(500000, 1, GREEN);

				std::cout << RobotomyRequestForm1 << std::endl;
				Bureaucrat1.executeForm(RobotomyRequestForm1);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			tic_tac(500000, 2, RED);

			/*
			* Will throw an exception as the bureaucrat has a grade of 150
			* and the form needs a grade of 137 or lower to be executed
			*/
			try {
				std::cout << RED << "Should not work" << NC << std::endl;
				tic_tac(500000, 1, RED);
				
				Bureaucrat2.executeForm(RobotomyRequestForm1);
				tic_tac(500000, 1, RED);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	/*
	 * PresidentialPardonForm test
	 * must be signed by a bureaucrat of grade 25 or lower
	 * must be executed by a bureaucrat of grade 5 or lower
	 */
	{
		try {
			PresidentialPardonForm PresidentialPardonForm1("Dio");
			std::cout << PresidentialPardonForm1 << std::endl;
			tic_tac(500000, 1, GREEN);
			
			try {
				std::cout << GREEN << "Should work" << NC << std::endl;
				tic_tac(500000, 1, GREEN);
				
				Bureaucrat1.signForm(PresidentialPardonForm1);
				tic_tac(500000, 1, GREEN);

				std::cout << PresidentialPardonForm1 << std::endl;
				Bureaucrat1.executeForm(PresidentialPardonForm1);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			tic_tac(500000, 2, RED);

			/*
			* Will throw an exception as the bureaucrat has a grade of 150
			* and the form needs a grade of 137 or lower to be executed
			*/
			try {
				std::cout << RED << "Should not work" << NC << std::endl;
				tic_tac(500000, 1, RED);
				
				Bureaucrat2.executeForm(PresidentialPardonForm1);
				tic_tac(500000, 1, RED);
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}