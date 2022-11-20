/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:23:32 by jmartin           #+#    #+#             */
/*   Updated: 2022/11/08 15:23:33 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

const std::string	Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

/******************************************************************************
 * CONSTRUCTORS / DESTRUCTORS
 */

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const &instance)
{
	*this = instance;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

/******************************************************************************
 * OPERATORS
 */

Intern	&Intern::operator=(Intern const &rhs)
{
	(void )rhs;
	return (*this);
}

/******************************************************************************
 * MEMBER FUNCTIONS
 */

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	if (name.empty() || target.empty())
		throw Intern::FormNotFoundException();

	for (int i = 0; i < 3; i++)
	{
		if (name == Intern::_formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			switch (i) {
				case 0:
					return (new ShrubberyCreationForm(target));
					break;
				case 1:
					return (new RobotomyRequestForm(target));
					break;
				case 2:
					return (new PresidentialPardonForm(target));
					break;
				default:
					break;
			}
		}
	}
	std::cout << "Intern can't create " << name << std::endl;
	throw Intern::FormNotFoundException();
	return (NULL);
}

/******************************************************************************
 * EXCEPTIONS
 */

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Intern Error: Form not found");
}