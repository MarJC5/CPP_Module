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

#include "../inc/Intern.hpp"
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
	Intern   someRandomIntern;
	AForm*   rrf;
	AForm*   scf;
	AForm*   ppf;
	AForm*   fail;
	tic_tac(500000, 2, GREEN);

	/* RobotomyRequestForm */
	try {
		std::cout << GREEN << "Should work" << NC << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Gin");
		std::cout << *rrf << std::endl;
		tic_tac(500000, 2, GREEN);
		rrf->beSigned(Bureaucrat1);
		std::cout << *rrf << std::endl;
		Bureaucrat1.executeForm(*rrf);
		tic_tac(500000, 2, GREEN);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	/* ShrubberyCreationForm */
	try {
		std::cout << GREEN << "Should work" << NC << std::endl;
		ppf = someRandomIntern.makeForm("presidential pardon", "Kilua");
		std::cout << *ppf << std::endl;
		tic_tac(500000, 2, GREEN);
		ppf->beSigned(Bureaucrat1);
		std::cout << *ppf << std::endl;
		Bureaucrat1.executeForm(*ppf);
		tic_tac(500000, 2, GREEN);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	/* PresidentialPardonForm */
	try {
		std::cout << GREEN << "Should work" << NC << std::endl;
		scf = someRandomIntern.makeForm("shrubbery creation", "Gon");
		std::cout << *scf << std::endl;
		tic_tac(500000, 2, GREEN);
		scf->beSigned(Bureaucrat1);
		std::cout << *scf << std::endl;
		Bureaucrat1.executeForm(*scf);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	/* Fail */
	tic_tac(500000, 2, RED);
	try {
		std::cout << RED << "Should not work" << NC << std::endl;
		fail = someRandomIntern.makeForm("fake form", "Kurapika");
		std::cout << *fail << std::endl;
		tic_tac(500000, 2, RED);
		fail->beSigned(Bureaucrat1);
		std::cout << *fail << std::endl;
		Bureaucrat1.executeForm(*fail);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	delete scf;
	delete ppf;
	delete fail;

	return (0);
}